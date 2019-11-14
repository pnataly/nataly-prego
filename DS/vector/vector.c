#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "ADTErr.h"
#define MAGIC_NUMBER 0XBEEFBEEF



struct Vector
{
	unsigned int m_magicNumber;
	int* m_items;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nitems;
	size_t m_blockSize;
};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBlockSize)
{
	Vector* _vector;
	if(_initialSize == 0 && _extensionBlockSize==0)
	{
		return NULL;
	}
	_vector = (Vector*) malloc(sizeof(Vector));
	if(_vector == NULL)
	{
		return NULL;
	}
	_vector->m_items = (int*)calloc(_initialSize, sizeof(int));
	if(_vector->m_items == NULL)
	{
		free(_vector);
		return NULL;
	}
	_vector->m_originalSize = _initialSize;
	_vector->m_size = _initialSize;
	_vector->m_blockSize = _extensionBlockSize;
	_vector->m_nitems=0;

	_vector->m_magicNumber = MAGIC_NUMBER;
	return _vector;
}


void VectorDestroy(Vector* _vector)
{
	if(_vector == NULL || _vector->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}

	_vector->m_magicNumber = 0;
	free(_vector->m_items);
	free(_vector);
}



ADTErr VectorAdd(Vector* _vector, int _item)
{
	int _check;
	if(_vector == NULL || _vector->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED; 
	}

	_check = VectorItemsNum(_vector,&_vector->m_nitems);

	if(_check == ERR_UNINITINALAIZED)
	{
		return ERR_UNINITINALAIZED;
	}
	if(_vector->m_size == _vector->m_nitems && _vector->m_blockSize == 0)
	{
		return ERR_OVERFLOW;
	}
	if(_vector->m_size == _vector->m_nitems)
	{

	_vector->m_size += _vector->m_blockSize;
	_vector->m_items = (int*)realloc(_vector->m_items, _vector->m_size*sizeof(int));
	
		if(_vector->m_items == NULL)
		{
			return ERR_ALLOC_FAIL;
		}
	}

	_vector->m_items[_vector->m_nitems] = _item;
	_vector->m_nitems++;

	return ERR_OK;	
}


ADTErr VectorDelete(Vector* _vector, int* _item)
{
	if(_vector == NULL || _vector->m_magicNumber != MAGIC_NUMBER || _item == NULL)
	{
		return ERR_UNINITINALAIZED; 
	}

	if(_vector->m_nitems == 0)
	{
		return ERR_UNDERFLOW;
	}
	
	*_item = _vector->m_items[_vector->m_nitems];
	_vector->m_nitems--;
	return ERR_OK;
}



ADTErr VectorGet(const Vector* _vector, size_t _index, int* _item)
{
	if (_vector == NULL)
	{
		return ERR_UNINITINALAIZED;
	}	

	if (_index < _vector->m_nitems)
	{
	 	* _item =_vector->m_items[_index];
		return ERR_OK;
	}
	
	return ERR_ITEM_NOT_FOUND;
}


ADTErr VectorSet(Vector* _vector, size_t _index, int _item)
{
	if (_vector == NULL)
	{
		return ERR_UNINITINALAIZED;
	}	
	if (_index < _vector->m_nitems)
	{
	 	_vector->m_items[_index] = _item;
		return ERR_OK;
	}
	return ERR_ITEM_NOT_FOUND;
}



ADTErr VectorItemsNum(Vector* _vector, size_t* _numOfItems)
{
	
	if(_vector == NULL || _vector->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	if(_vector->m_nitems == 0)
	{
		return ERR_UNDERFLOW;
	}
	*_numOfItems = _vector->m_nitems;

	return ERR_OK;
}


void VectorPrint(const Vector* _vector)
{
	int i;
	for(i =0; i<_vector->m_nitems; i++)
	{
		printf("vector index %d: %d\n",i, _vector->m_items[i]);
	}
	printf("\n");

}


