#include <stdio.h>
#include "list_itr.h"
#include "listStruct.h"


ListItr ListItr_Begin(const List* _list)
{
	if(_list == NULL)
	{
		return NULL;
	}
	return (ListItr)_list->m_head.m_next;
}

ListItr ListItr_End(const List* _list)
{
	if(_list == NULL)
	{
		return NULL;
	}
	return (ListItr)&(_list->m_tail);
}

int ListItr_Equals(const ListItr _a, const ListItr _b)
{
	if(_a == NULL || _b == NULL)
	{
		return FALSE;
	}

	return (_a == _b);
}

/*tail next is tail */
ListItr ListItr_Next(ListItr _itr)
{
	if(_itr == NULL)
	{
		return NULL;
	}
	return ((Node*)_itr)->m_next;
}

/*head prev is head */
ListItr ListItr_Prev(ListItr _itr)
{
	if(_itr == NULL)
	{
		return NULL;
	}
	if(((Node*)_itr)->m_prev == ((Node*)_itr)->m_prev->m_prev)
	{
		return _itr;
	}
	return ((Node*)_itr)->m_prev;
}

void* ListItr_Get(ListItr _itr)
{
	if(_itr == NULL)
	{
		return NULL;
	}

	/* in case is tail NULL return */
	return ((Node*)_itr)->m_data;
}

void* ListItr_Set(ListItr _itr, void* _element)
{
	void* data;
	if(_itr == NULL || _element == NULL)
	{
		return NULL;
	}
	if(((Node*)_itr)->m_prev == ((Node*)_itr)->m_prev->m_prev)
	{
		return NULL;
	}
	data = ((Node*)_itr)->m_data;
	((Node*)_itr)->m_data = _element;
	return data;
}

ListItr ListItr_InsertBefore(ListItr _itr, void* _element)
{
	Node* newNode;
	if(_itr == NULL || _element == NULL)
	{
		return NULL;
	}
	newNode = (Node*) malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return NULL;
	}
	PushToList(newNode, (Node*)_itr);
	((Node*)_itr)->m_data = _element;
	return newNode;
}

void* ListItr_Remove(ListItr _itr)
{
	void* data;
	if(_itr == NULL)
	{
		return NULL;
	}

	if(((Node*)_itr)->m_next == ((Node*)_itr))
	{
		return NULL;
	}
	((Node*)_itr)->m_next->m_prev = ((Node*)_itr)->m_prev;
	((Node*)_itr)->m_prev->m_next = ((Node*)_itr)->m_next;
	data = ((Node*)_itr)->m_data;
	free(_itr);
	return data;
}
