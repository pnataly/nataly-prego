#include <stdlib.h>
#include <pthread.h>
#include "safeHash.h"
#include "hashMap.h"
#include "locker.h"

struct SafeHashMap
{
	HashMap* m_hash;
	HashFunction m_hashFunc;
	Locker* m_lock;
	size_t m_capacity;
	size_t m_NumOfItems;
};

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

/*-------------------------Main-Functions-----------------------------------*/

SafeHashMap* SafeHashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc, size_t _numOfLock)
{
	SafeHashMap* safeHash;
	HashMap* hash;
	Locker* lock;
	size_t size = 0;
	safeHash = (SafeHashMap*)malloc(sizeof(SafeHashMap));
	if (safeHash == NULL)
	{
		return NULL;
	}
	size = NextPrime(_capacity);
	hash = HashMap_Create(_capacity, _hashFunc, _keysEqualFunc);
	if (hash == NULL)
	{
		free(safeHash);
		return NULL;
	}
	lock = LockerCreate(_numOfLock);
	if (lock == NULL)
	{
		free(safeHash);
		free(hash);
		return NULL;
	}
	safeHash->m_hash = hash;
	safeHash->m_lock = lock;
	safeHash->m_hashFunc = _hashFunc;
	safeHash->m_capacity = size;
	safeHash->m_NumOfItems = 0;
	return safeHash;
}

Safe_Map_Result SafeHashMap_Update(SafeHashMap* _safeHash, const void* _searchKey, FuncUpdate _funcUpdate, void* _context)
{
	size_t index;
	Map_Result status;
	void* value = NULL;
	index = _safeHash->m_hashFunc(_searchKey) % _safeHash->m_capacity;
	Lock(_safeHash->m_lock, index);
	status = HashMap_Find(_safeHash->m_hash, _searchKey, &value);
	if (status == MAP_SUCCESS)
	{
		/*update the value*/
		value =_funcUpdate(value, _context);
		UnLock(_safeHash->m_lock, index);
		return SAFE_MAP_UPDATE_SUCCESS;
	}
	else
	{
		/*the value not found - create new subscriber and insert*/
		value = _funcUpdate(value, _context);
		if (HashMap_Insert(_safeHash->m_hash, _searchKey, value) == MAP_SUCCESS)
		{
			_safeHash->m_NumOfItems++;
			UnLock(_safeHash->m_lock, index);
			return SAFE_MAP_UPDATE_SUCCESS;
		}
	}
	UnLock(_safeHash->m_lock, index);
	return SAFE_MAP_UPDATE_ERROR;
}


Safe_Map_Result SafeHashMap_Remove(SafeHashMap* _safeHash, const void* _searchKey, void** _pKey, void** _pValue)
{
	size_t index;
	Map_Result status;
	index = _safeHash->m_hashFunc(_searchKey) % _safeHash->m_capacity;
	Lock(_safeHash->m_lock, index);
	status = HashMap_Remove(_safeHash->m_hash, _searchKey, _pKey, _pValue);
	if (status != MAP_SUCCESS)
	{
		UnLock(_safeHash->m_lock, index);
		return SAFE_MAP_REMOVE_ERROR;
	}
	UnLock(_safeHash->m_lock, index);
	return SAFE_MAP_SUCCESS;
}


void* SafeHashMap_Get(SafeHashMap* _safeHash, const void* _searchKey, FuncGet _funcGet)
{
	size_t index;
	Map_Result status;
	void* value = NULL;
	index = _safeHash->m_hashFunc(_searchKey) % _safeHash->m_capacity;
	Lock(_safeHash->m_lock, index);
	status = HashMap_Find(_safeHash->m_hash, _searchKey, &value);
	if (status == MAP_SUCCESS)
	{
		value = _funcGet(value);
		if (value == NULL)
		{
			UnLock(_safeHash->m_lock, index);
			return NULL;
		}
	}
	UnLock(_safeHash->m_lock, index);
	return value;
}

size_t SafeHashMap_ForEach(const SafeHashMap* _safeHash, KeyValueActionFunction _action, void* _context)
{
	size_t res;
	Lock(_safeHash->m_lock, _safeHash->m_capacity);
	
	res = HashMap_ForEach(_safeHash->m_hash, _action, _context);
	UnLock(_safeHash->m_lock, _safeHash->m_capacity);
	return res;
}

void SafeHashMap_Destroy(SafeHashMap** _safeHash, KeyDestroy _keyDestroy, ValDestroy _valDestroy)
{
	size_t index = 0;
	size_t i = 0;
	for (i=0; i<(*_safeHash)->m_NumOfItems-1; i++)
	{
		index = (*_safeHash)->m_hashFunc((void*)i) % (*_safeHash)->m_capacity;
		Lock((*_safeHash)->m_lock, index);
	}
	HashMap_Destroy(&(*_safeHash)->m_hash, _keyDestroy,_valDestroy);
	free(*_safeHash);
	_safeHash = NULL;
}

