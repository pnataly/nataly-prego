#include <stdio.h>
#include <stdlib.h>
#include "ADTErr.h"
#include "doubleList.h"
#define MAGIC_NUMBER 0XBEEFBEEF


typedef struct Node Node;

struct Node 
{
	int m_data;
	Node* m_next;
	Node* m_prev;
};


struct List
{
	unsigned int m_magicNumber;
	Node m_head;
	Node m_tail;
};


List* ListCreate(void)
{
	List* _list;
	_list = (List*) malloc(sizeof(List));
	if(_list == NULL)
	{
		return NULL;
	}
	_list->m_magicNumber = MAGIC_NUMBER;
	_list->m_head.m_next = &(_list->m_tail);
	_list->m_head.m_prev = NULL;
	_list->m_tail.m_prev = &(_list->m_head);
	_list->m_tail.m_next = NULL;

	return _list;
}

void ListDestroy(List* _list)
{
	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	_list->m_magicNumber = 0;

	while(_list->m_head.m_next != &(_list->m_tail))
	{
		_list->m_head = *(_list->m_head.m_next);
		free(_list->m_head.m_prev);
	}
	free(_list);
	return;
}

/*TODO function- CheckParam and CreateNode */
ADTErr ListPushHead(List* _list, int _data)
{
	Node* _newNode;
	/*
	ADTErr status = ERR_OK;
	if(status = CheckParam((void*)_list) != ERR_OK)
	{
		return status;
	}

	if(_newNode = CreateNode(_data) == NULL)
	{
		return ERR_NO_MEMORY;
	}

	ListPush(_newNode, _list->m_head.m_next);
	return ERR_OK;
	*/
	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}

	_newNode = (Node*) malloc(sizeof(Node));
	if(_newNode == NULL)
	{
		return ERR_	EMPTY;
	}
	_newNode->m_data = _data;

	_newNode->m_prev = &(_list->m_head);
	_newNode->m_next = _list->m_head.m_next;
	_list->m_head.m_next->m_prev = _newNode;
	_list->m_head.m_next = _newNode;

	return ERR_OK;
}

ADTErr ListPushTail(List* _list, int _data)
{
	Node* _newNode;
	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}

	_newNode = (Node*) malloc(sizeof(Node));
	if(_newNode == NULL)
	{
		return ERR_	EMPTY;
	}
	_newNode->m_data = _data;
	
	_newNode->m_prev = _list->m_tail.m_prev;
	_newNode->m_next = &(_list->m_tail);
	_list->m_tail.m_prev->m_next = _newNode;
	_list->m_tail.m_prev = _newNode;

	return ERR_OK;
}

ADTErr ListPopHead(List* _list, int* _data)
{
	Node* _temp;

	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	_temp = _list->m_head.m_next;
	if(_temp == &(_list->m_tail))
	{
		return ERR_UNDERFLOW;
	}

	*_data = _temp->m_data;
	_list->m_head.m_next = _temp->m_next;
	_list->m_head.m_next->m_next->m_prev = _temp->m_prev;
	_list->m_head.m_next = _temp->m_next;
	free(_temp);

	return ERR_OK;
}


ADTErr ListPopTail(List* _list, int* _data)
{
	Node* _temp;
	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	_temp = _list->m_tail.m_prev;
	if(_temp == &(_list->m_head))
	{
		return ERR_UNDERFLOW;
	}
	*_data = _temp->m_data;
	_list->m_tail.m_prev = _temp->m_prev;
	_list->m_tail.m_prev->m_prev->m_next = &(_list->m_tail);
	_list->m_tail.m_prev = _temp->m_prev;
	free(_temp);

	return ERR_OK;
}


size_t ListCountItems(const List* _list)
{
	size_t count = 0;
	Node* _temp;

	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return 0;
	}

	_temp = _list->m_head.m_next;

	while(_temp != &(_list->m_tail))
	{
		count++;
		_temp = _temp->m_next;
	}
	return count;
}



int ListIsEmpty(const List* _list)
{
	if(_list == NULL ||_list->m_magicNumber != MAGIC_NUMBER)
	{
		return TRUE;
	}
	if(_list->m_head.m_next == _list->m_tail.m_prev)
	{
		return TRUE;
	}
	return FALSE;
}

void ListPrint(List* _list)
{
	Node* _temp;
	_temp = _list->m_head.m_next;
	printf("The data in the list:\n");
	while(_temp != &(_list->m_tail))
	{
		printf("%d, ", _temp->m_data);
		_temp = _temp->m_next;
	}
	printf("\n");
	
}

