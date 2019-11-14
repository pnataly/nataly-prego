#include <stdlib.h>
#include "genericVector.h"


struct Vector
{
	void** m_items;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nitems;
	size_t m_blockSize;
};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBlockSize)
{
	Vector* vector;
	if(_initialSize == 0 && _extensionBlockSize==0)
	{
		return NULL;
	}
	vector = (Vector*) malloc(sizeof(Vector));
	if(vector == NULL)
	{
		return NULL;
	}
	vector->m_items = (void**)malloc(_initialSize*sizeof(void*));
	if(vector->m_items == NULL)
	{
		free(vector);
		return NULL;
	}
	vector->m_originalSize = _initialSize;
	vector->m_size = _initialSize;
	vector->m_blockSize = _extensionBlockSize;
	vector->m_nitems=0;

	return vector;
}


void VectorDestroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
	size_t i;
	if(_vector == NULL || *_vector == NULL)
	{
		return;
	}
	if(_elementDestroy != NULL)
	{
		i=Vector_Size(*_vector);
		while(i>0)
		{
			i--;
			_elementDestroy((*_vector)->m_items[i]);
		}
	}
	free((*_vector)->m_items);
	free(*_vector);
	*_vector = NULL;
}


Vector_Result Vector_Append(Vector* _vector, void* _item)
{
	void* temp;
	if(_vector == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR; 
	}
	if(_item == NULL)
	{
		return VECTOR_WRONG_DATA;
	}
	if(_vector->m_size == _vector->m_nitems && _vector->m_blockSize == 0)
	{
		return VECTOR_OVERFLOW_ERROR;
	}
	if(_vector->m_size == _vector->m_nitems)
	{
		temp = (void**)realloc(_vector->m_items+_vector->m_blockSize, _vector->m_size*sizeof(void*));
		if(temp == NULL)
		{
			return VECTOR_ALLOCATION_ERROR;
		}
		_vector->m_items = temp;
		_vector->m_size += _vector->m_blockSize;
	}

	_vector->m_items[_vector->m_nitems] = _item;
	_vector->m_nitems++;
	return VECTOR_SUCCESS;	
}


Vector_Result Vector_Remove(Vector* _vector, void** _pValue)
{
	void* temp;
	if(_vector == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR; 
	}
	if(_pValue == NULL)
	{
		return VECTOR_WRONG_DATA;
	}

	if(_vector->m_nitems == 0)
	{
		return VECTOR_UNDERFLOW_ERROR;
	}

	/*check if possibole to shrink the size */
	if((_vector->m_originalSize < _vector->m_size) && (_vector->m_size - _vector->m_nitems >= FACTOR*_vector->m_blockSize))
	{
		temp = (void**)realloc(_vector->m_items,(_vector->m_size-_vector->m_blockSize)*sizeof(void*));
		if(temp != NULL)
		{
			_vector->m_items = temp;
			_vector->m_size -= _vector->m_blockSize;
		}
		else
		{
			return VECTOR_ALLOCATION_ERROR;
		}
	}	
	*_pValue = _vector->m_items[(_vector->m_nitems)-1];
	_vector->m_nitems--;
	return VECTOR_SUCCESS;
}



Vector_Result Vector_Get(const Vector* _vector, size_t _index, void** _pValue)
{
	if (_vector == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}	

	if(_pValue == NULL)
	{
		return VECTOR_WRONG_DATA;
	}

	if( _index >= _vector->m_nitems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}

 	* _pValue =_vector->m_items[_index];
	return VECTOR_SUCCESS;
}


Vector_Result Vector_Set(Vector* _vector, size_t _index, void*  _value)
{
	if (_vector == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}	
	if(_value == NULL)
	{
		return VECTOR_WRONG_DATA;
	}

	if(_index >=_vector->m_nitems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}

 	_vector->m_items[_index] = _value;
	return VECTOR_SUCCESS;
}

size_t Vector_Capacity(const Vector* _vector)
{
	if(_vector == NULL)
	{
		return 0;
	}
	return _vector->m_size;
}

size_t Vector_Size(const Vector* _vector)
{
	if(_vector->m_nitems == 0 || _vector == NULL)
	{
		return 0;
	}

	return _vector->m_nitems;
}

size_t Vector_ForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	size_t i;
	void* elem;
	if(_vector == NULL || _action == NULL)
	{
		return 0;
	}

    for(i = 0; i < _vector->m_nitems; i++)
	{
         Vector_Get(_vector, i, &elem);
         if(_action(elem, i, _context) == 0)
				break;	
	}
	return i;
}



