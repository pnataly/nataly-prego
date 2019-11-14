#include <stdio.h>
#include <stdlib.h>
#include "genericDoubleList.h"
#include "listStruct.h"


List* List_Create(void)
{
	List* _list;
	_list = (List*) malloc(sizeof(List));
	if(_list == NULL)
	{
		return NULL;
	}
	_list->m_head.m_next = &(_list->m_tail);
	_list->m_head.m_prev = NULL;
	_list->m_tail.m_prev = &(_list->m_head);
	_list->m_tail.m_next = NULL;

	return _list;
}

void List_Destroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* temp;
	if(_pList == NULL || *_pList == NULL)
	{
		return;
	}
	temp = (*_pList)->m_head.m_next;

	while(temp != &((*_pList)->m_tail))
	{
		if(_elementDestroy != NULL)
		{
			_elementDestroy(temp->m_data);
		}
		temp = temp->m_next;
		free(temp->m_prev);
	}
	free(*_pList);
	*_pList = NULL;
}

void PushToList(Node* _newNode, Node* _next)
{
	_newNode->m_prev = _next->m_prev;
	_newNode->m_next = _next;
	_next->m_prev->m_next = _newNode;
	_next->m_prev = _newNode;
}

void PopFromList(Node* _Node, void** _data)
{
	*_data = _Node->m_data;
	_Node->m_next->m_prev = _Node->m_prev;
	_Node->m_prev->m_next = _Node->m_next;
	free(_Node);
}

List_Result List_PushHead(List* _list, void* _item)
{
	Node* newNode;
	if(_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_item == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	newNode = (Node*) malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	newNode->m_data = _item;
	PushToList(newNode, _list->m_head.m_next);

	return LIST_SUCCESS;
}

List_Result List_PushTail(List* _list, void* _item)
{
	Node* newNode;
	if(_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_item == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	newNode = (Node*) malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	newNode->m_data = _item;
	PushToList(newNode, &(_list->m_tail));
	return LIST_SUCCESS;
}

List_Result List_PopHead(List* _list, void** _pItem)
{
	Node* temp;

	if(_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_pItem == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}

	temp = _list->m_head.m_next;
	if(temp == &(_list->m_tail))
	{
		return LIST_UNDERFLOW_ERROR;
	}

	PopFromList(_list->m_head.m_next,_pItem);
	return LIST_SUCCESS;
}


List_Result List_PopTail(List* _list, void** _pItem)
{
	if(_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_pItem == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}

	if(_list->m_tail.m_prev == &(_list->m_head))
	{
		return LIST_UNDERFLOW_ERROR;
	}

	PopFromList(_list->m_tail.m_prev,_pItem);
	return LIST_SUCCESS;
}

size_t List_Size(const List* _list)
{
	Node* temp;
	size_t count = 0;
	if(_list == NULL)
	{
		return 0;
	}

	temp = _list->m_head.m_next;
	while(temp != &(_list->m_tail))
	{
		count++;
		temp = temp->m_next;
	}
	return count;
}

void ListPrint(List* _list)
{
	Node* temp;
	temp = _list->m_head.m_next;
	printf("The data in the list:\n");
	while(temp != &(_list->m_tail))
	{
		printf("%d, ", *(int*)temp->m_data);
		temp = temp->m_next;
	}
	printf("\n");	
}

