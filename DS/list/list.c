#include <stdio.h>
#include <string.h>
#include "list.h"



Person* ListInsertHead(Person* _head, Person* _p)
{
	if(_p == NULL)
	{
		return _head;
	}	
	_p->m_next = _head;
	_head = _p;

	return _head;	 
}

Person* ListRemoveHead(Person* _head, Person** _item)
{
	if(_item == NULL)
	{
		return _head;
	}
	if(_head == NULL)
	{
		*_item = NULL;
		return _head;
	}

	*_item = _head;
	return _head->m_next;	
}

Person* ListInsertByKey(Person* _head, int _key, Person* _p)
{
	Person* originalHead = _head;

	if(_head == NULL || _key < _head->m_id)
	{
		return ListInsertHead(_head, _p);
	}
	while(_head->m_next != NULL)
	{
		if(_key< _head->m_next->m_id)
		{
			break;
		}
		_head = _head->m_next;
	}

	_p->m_next = _head->m_next;
	_head->m_next =_p;
	return originalHead;
}

Person* ListRemoveByKey(Person* _head, int _key, Person** _item)
{
	Person* _temp = _head;
	Person* prev;

	if(_item == NULL)
	{
		return _head;
	}
	if(_temp == NULL)
	{
		*_item = NULL;
		return _temp;

	}
	if(_temp != NULL && _temp->m_id == _key)
	{
		*_item = _temp;
		_head = _temp->m_next;
	}
 	while (_temp != NULL && _temp->m_id != _key)
	{
		prev = _temp;
		_temp = _temp->m_next;	
	} 
	*_item = _temp;
	prev->m_next = _temp->m_next; 
	return _head;
}

Person* InsertByKeyRec(Person* _head, int _key, Person* _p)
{
	if(_head->m_next == NULL)
	{
		_head->m_next = _p;
		_p->m_next =NULL;
		return _head;
	}
	if(_key > _head->m_next->m_id)
	{
		_p->m_next = _head->m_next;
		_head->m_next = _p;
		return _head;
	}
	
	return InsertByKeyRec(_head->m_next, _key, _p);
	
}

Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p)
{
	if(_head==NULL || _head->m_id < _key)
	{
		return ListInsertHead(_head, _p);
	}
	if(_p == NULL)
	{
		return _head;
	}
	InsertByKeyRec(_head, _key, _p);
	return _head;
}

void PrintListRec(const Person* _head, int* counter)
{
	if(_head == NULL)
	{
		return;
	}
	PrintListRec(_head->m_next, counter);

	printf("\nID: %d\t\n", _head->m_id);
	printf("Name: %s\t\n", _head->m_name);
	printf("Age: %d\t\n", _head->m_age);
	
	*counter += 1;
	return;
}


Person* Flip(Person* _head)
{
	Person* revPerson;
	if(_head == NULL || _head->m_next == NULL)
	{
		return _head;
	}
	revPerson = Flip(_head->m_next);
	_head->m_next->m_next = _head;
	_head->m_next = NULL;

	return revPerson;
}



void PrintList(const Person* _head)
{
	int counter = 0;
	if(_head == NULL)
	{
		return;
	}
	
	PrintListRec(_head, &counter);
	printf("Number of items: %d\n", counter);
	return;
}
