#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ADTErr.h"
#define MAGIC_NUMBER 0XBEEFBEEF

#define FACTOR 1.3


typedef enum
{
	EMPTY,
	FULL,
	DELETE
}status;

struct Hash
{
	unsigned int m_magicNumber;
	int* m_data;
	char* m_status;
	size_t m_hashSize;
	size_t m_capacity;
	size_t m_numOfItems;
	size_t m_maxOfRehashOpertation;
	size_t m_counterOfInsertions;
	size_t m_allRehashOperation;
};

static int HashFunc(int _data)
{
	return _data*2;
}

static int ReHash(int _index)
{
	return _index+1;
}

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


Hash* HashCreate(const size_t _size)
{
	Hash* hash;
	int* data;
	char* status;
	size_t size;
	hash = (Hash*)calloc(sizeof(Hash),1);
	if(NULL == hash)
	{
		return NULL;
	}
	if(_size == 0)
	{
		free(hash);
		return NULL;
	}
	hash->m_capacity = _size;
	size = NextPrime(_size*FACTOR);
	data = (int*)calloc(sizeof(int), _size*FACTOR);
	if(NULL == data)
	{
		free(hash);
		return NULL;
	}
	status = (char*)calloc(sizeof(char), _size*FACTOR);
	if(NULL == status)
	{
		free(hash);
		return NULL;
	}	
	hash->m_data = data;
	hash->m_status = status;
	hash->m_hashSize = size;
	hash->m_capacity = _size;
	hash->m_maxOfRehashOpertation = 0;
	hash->m_magicNumber = MAGIC_NUMBER;
	return hash;
}

void HashDestroy(Hash* _hash)
{
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	_hash->m_magicNumber = 0;
	free(_hash->m_data);
	free(_hash->m_status);
	free(_hash);
}


ADTErr HashInsert(Hash* _hash, int _data)
{
	size_t  index;
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	index = HashFunc(_data) % _hash->m_hashSize;
	if(_hash->m_numOfItems == _hash->m_capacity)
	{
		return ERR_OVERFLOW;
	}
	while(_hash->m_status[index] == FULL)
	{
		if(_hash->m_data[index] == _data)
		{
			return ERR_DUP_DATA;
		}

		index = ReHash(index) % _hash->m_hashSize;
		_hash->m_allRehashOperation++;
		_hash->m_maxOfRehashOpertation++;

	}	
	_hash->m_data[index] = _data;
	_hash->m_status[index] = FULL;
	_hash->m_numOfItems++;
	_hash->m_counterOfInsertions++;
	return ERR_OK;
}

ADTErr HashRemove(Hash* _hash, int _data)
{
	int index;
	int count = 0;
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	if(_hash->m_numOfItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	index = HashFunc(_data) % _hash->m_hashSize;

	while(_hash->m_status[index] != FULL && count < _hash->m_maxOfRehashOpertation)
	{
		index = ReHash(index) % _hash->m_hashSize;
		if(_hash->m_status[index] == EMPTY)
		{
			break;
		}	
		count++;

	}
	if(_hash->m_status[index] == FULL && _hash->m_data[index] == _data)
	{
			_hash->m_status[index] = DELETE;
			_hash->m_numOfItems--;
			return ERR_OK;
	}
	return ERR_ITEM_NOT_FOUND;

}

int HashIsFound(const Hash* _hash, int _data)
{
	int index;
	int count=0;
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return FALSE;
	}
	if(_hash->m_numOfItems == 0)
	{
		return FALSE;
	}
	index = HashFunc(_data);
	index = index % _hash->m_hashSize;

	while(_hash->m_status[index] != FULL && count < _hash->m_maxOfRehashOpertation)
	{
		index = ReHash(index) % _hash->m_hashSize;
		if(_hash->m_status[index] == EMPTY)
		{
			break;
		}
		count++;
	}
	if(_hash->m_status[index] == FULL)
	{
		if(_hash->m_data[index] == _data)
		{
			return TRUE;
		}
	}
	return FALSE;
}


size_t HashNumOfItems(const Hash* _hash)
{
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return 0;
	}
	return _hash->m_numOfItems;
}

size_t HashCapacity(const Hash* _hash)
{
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return 0;
	}
	return _hash->m_capacity;
}

double HashAverageRehashes(const Hash* _hash)
{
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return -1;
	}

	if(_hash->m_counterOfInsertions == 0)
	{
		return 0;
	}

	return (double)_hash->m_allRehashOperation/_hash->m_counterOfInsertions;
}

size_t HashMaxReHash(const Hash* _hash)
{
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return 0;
	}

	return _hash->m_maxOfRehashOpertation;
}


void HashPrint(const Hash* _hash)
{
	int i;
	if(_hash == NULL || _hash->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	printf("The items in the Hash: ");
	for(i=0; i<= _hash->m_capacity; i++)
	{
		if(_hash->m_status[i] == FULL)
		{
			printf("%d, ", _hash->m_data[i]);
		}
	}
	printf("\n");
}
