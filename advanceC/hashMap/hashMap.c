#include <stdlib.h>
#include <pthread.h>
#include "hashMap.h"

struct HashMap
{
	List** m_buckets;
	HashFunction m_hashFunc;
	EqualityFunction m_keysEqualFunc;
	size_t m_capacity; 
	size_t m_numOfItems;
};

typedef struct Pair
{
	const void* m_key;
	void* m_value;
}Pair;

typedef struct Pack
{
	const void* m_key;
	EqualityFunction m_keysEqualFunc;
}Pack;


/*--------------------------Static-Functions----------------------------------*/
static int IsPrime(size_t _n)
{
	size_t i;
	if(_n<2)
	{
		return FALSE;
	}
	for(i=2; i<=_n/2; i++)
	{
		if(_n%i == 0)
		{
			return FALSE;
		}
	}
	return TRUE;
}

static size_t NextPrime(size_t _n)
{
	while(!IsPrime(_n))
	{
		_n++;
	}
	return _n;
}

static void* GetValue(Pair* _pair)
{
	if(_pair == NULL)
	{
		return NULL;
	}
	return (void*)_pair->m_value;
}


static void* GetKey(Pair* _pair)
{
	if(_pair == NULL)
	{
		return NULL;
	}
	return (void*)_pair->m_key;
}

static void PairDestroy(ListItr _itr, KeyDestroy _keyDestroy, ValDestroy _valDestroy)
{
	Pair* data;
	void* key;
	void* value;
	data = (Pair*)ListItr_Remove(_itr);
	key = GetKey(data);
	if(key == NULL)
	{
		return;
	}
	_keyDestroy(key);
	value = GetValue(data);
	if(value == NULL)
	{
		return;
	}
	_valDestroy(value);
	free(data);
}

static Pair* CreatePair(const void* _key, const void* _value)
{
	Pair* pair;
	pair = (Pair*)malloc(sizeof(Pair));
	if(pair == NULL)
	{
		return NULL;
	}
	pair->m_key = (void*)_key;
	pair->m_value = (void*)_value;
	return pair;
}


static int Perdicate(void * _element, void* _context)
{
	const void* key;
	EqualityFunction equal;
	if (_element == NULL)
	{
		return -1;
	}
	key =  ((Pack*)_context)->m_key;
	equal = ((Pack*)_context)->m_keysEqualFunc;
	return equal(((Pair*)_element)->m_key, key);
}

static void* FindDupKey(const HashMap* _map, size_t _index, const void* _searchKey)
{
	ListItr begin;	
	ListItr end;	
	Pack* pack;
	void* result;
	if (_map == NULL || _searchKey == NULL)
	{
		return NULL;
	}

	begin = ListItr_Begin(_map->m_buckets[_index]);
	end = ListItr_End(_map->m_buckets[_index]);
	pack = (Pack*)malloc(sizeof(Pack));
	if (pack == NULL)
	{
		return NULL;
	}	
	pack->m_key = _searchKey;
	pack->m_keysEqualFunc = _map->m_keysEqualFunc;

	result = ListItr_FindFirst(begin, end, Perdicate ,pack);
	if (result == NULL || result == end)
	{
		free(pack);
		return 	NULL;
	}
	return result;
}


/*-------------------------Main-Functions-----------------------------------*/

HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	HashMap* hash;
	List** list;
	size_t size = 0;
	if(_hashFunc == NULL || _keysEqualFunc == NULL)
	{
		return NULL;
	}
	hash = (HashMap*)malloc(sizeof(HashMap));
	if(hash == NULL)
	{
		return NULL;
	}
	if(_capacity == 0)
	{
		free(hash);
		return NULL;
	}
	size = NextPrime(_capacity);
	list = (List**)calloc(sizeof(List*),size);
	if(list == NULL)
	{
		free(hash);
		return NULL;
	}
	hash->m_buckets = list;
	hash->m_capacity = size;
	hash->m_keysEqualFunc = _keysEqualFunc;
	hash->m_hashFunc = _hashFunc;
	hash->m_numOfItems = 0;
	return hash;
}


void HashMap_Destroy(HashMap** _map, KeyDestroy _keyDestroy, ValDestroy _valDestroy)
{
	size_t i;
	ListItr itr;
	if(_map == NULL || *_map == NULL || _keyDestroy == NULL || _valDestroy == NULL)
	{
		return;
	}
	for(i=0; i<(*_map)->m_capacity; i++)
	{
		if((*_map)->m_buckets[i] != NULL)
		{
			itr = ListItr_Begin((*_map)->m_buckets[i]);
			while(!ListItr_Equals(itr, ListItr_Next(itr)))
			{
				PairDestroy(itr,_keyDestroy, _valDestroy);
				if (ListItr_Next(itr) == NULL)
				{
					break;
				}
				itr = ListItr_Next(itr);
			}
			List_Destroy(&((*_map)->m_buckets[i]), NULL);
		}
	}
	free((*_map)->m_buckets);
	free(*_map);
	*_map = NULL;
} 

Map_Result HashMap_Insert(HashMap* _map, const void* _key, const void* _value)
{
	size_t index;
	List* list;
	Pair* pair;
	List_Result ListResult;
	if(_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if(_key == NULL || _value == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	pair = CreatePair(_key, _value);
	if(pair == NULL)
	{
		return MAP_ALLOCATION_ERROR;
	}
	index = _map->m_hashFunc(_key) % _map->m_capacity;
	if (HashMap_Find(_map, _key, (void*)&_value) == MAP_SUCCESS) /*the key is already in the hash*/
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}
	else
	{
		ListResult = List_PushTail(_map->m_buckets[index], (void*)pair);
		if (ListResult != LIST_SUCCESS)
		{
			list = List_Create();
			if(list == NULL)
			{
				return MAP_ALLOCATION_ERROR;
			}
			_map->m_buckets[index] = list; 
			List_PushTail(_map->m_buckets[index], (void*)pair);
		}
	}
	_map->m_numOfItems++;
	return MAP_SUCCESS;
}


Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue)
{
	Pair* data;
	void* result;
	size_t index;
	if(_map == NULL || _pKey == NULL || _pValue == NULL) 
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if(_searchKey == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	index = _map->m_hashFunc(_searchKey) % _map->m_capacity;
	result = FindDupKey(_map, index, _searchKey);
	if (result == NULL)
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	data = ListItr_Remove(result);
	*_pKey = GetKey(data);
	free(data);
	_map->m_numOfItems--;
	return MAP_SUCCESS;	
}

Map_Result HashMap_Find(const HashMap* _map, const void* _searchKey, void** _pValue)
{
	size_t index;
	Pair* data;
	void* result;
	if(_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if(_searchKey == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	index = _map->m_hashFunc(_searchKey) % _map->m_capacity;
	if(_map->m_buckets[index] == NULL)
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	result = FindDupKey(_map, index, _searchKey);
	if(result == NULL)
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	data = ListItr_Get(result);
	*_pValue = data->m_value;
	return MAP_SUCCESS;
}

size_t HashMap_Size(const HashMap* _map)
{
	if(_map == NULL)
	{
		return 0;
	}
	return _map->m_numOfItems;
}

size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	size_t i;
	Pair* data;
	void* key;
	void* value;
	ListItr itr;	
	if(_map == NULL || _action == NULL)
	{
		return 0;
	}
	for(i=0; i<_map->m_capacity; i++)
	{
		if(_map->m_buckets[i] != NULL)
		{
			itr = ListItr_Begin(_map->m_buckets[i]);
			while(itr != ListItr_End(_map->m_buckets[i]))
			{
				data = ListItr_Get(itr);
				key = GetKey(data);
				value = GetValue(data);
				if(_action(key, value, _context) == 0)
				{		
					break;
				}
				itr = ListItr_Next(itr);
			}
		}
	}
	return i;
}

