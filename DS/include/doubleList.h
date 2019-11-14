#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__
#include "ADTErr.h"

#define TRUE 1
#define FALSE 0


typedef struct List List;

/* @Description: Create a double linked list.
 * @Input: void.
 * @Return: pointer to the created double linked list or NULL- if unsuccesful.
*/ 
List* ListCreate(void);


/* @Description: Destroy the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Return: void.
*/ 
void ListDestroy(List* _list);


/* @Description: Add data to start of the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Input: _data- the data we want to insert.
 * @Return: 
 * ERR_OK- if the number add to the double linked list.
 * ERR_UNINITINALAIZED - the pointer to the double linked list is NULL.
 * ERR_NO_MEMORY - if the memory allocation not succssed
*/ 
ADTErr ListPushHead(List* _list, int _data);


/* @Description: Add data to end of the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Input: _data- the data we want to insert.
 * @Return: 
 * ERR_OK- if the data added to the double linked list.
 * ERR_UNINITINALAIZED - the pointer to the double linked list is NULL.
 * ERR_NO_MEMORY - if the memory allocation not succssed
*/ 
ADTErr ListPushTail(List* _list, int _data);

/* @Description: Remove data from the start of the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Input: _data- the data that removed from the double linked list.
 * @Return: 
 * ERR_OK- if the data removed from the double linked list.
 * ERR_UNINITINALAIZED - if the pointer to the double linked list is NULL.
 * ERR_UNDERFLOW- if the double linked list is empty.
*/ 
ADTErr ListPopHead(List* _list, int* _data);


/* @Description: Remove data from the end of the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Input: _data- the data that removed from the double linked list.
 * @Return: 
 * ERR_OK- if the data removed from the double linked list.
 * ERR_UNINITINALAIZED - if the pointer to the double linked list is NULL.
 * ERR_UNDERFLOW- if the double linked list is empty.
*/ 
ADTErr ListPopTail(List* _list, int* _data);


/* @Description: counts the number of items that in the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Return: the number of items that in the double linked list.
*/ 
size_t ListCountItems(List* _list);


/* @Description: Check if the double linked list is empty.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Return: TRUE- if the double linked list is empty or NULL.
 * 	    FALSE- if the double linked list is not empty.
*/
int ListIsEmpty(List* _list);


/* @Description: Prints the data in the double linked list.
 * @Input: _list- pointer to double linked list created by ListCreate().
 * @Return: void.
*/
void ListPrint(List* _list);

#endif /*__DOUBLELIST_H__*/ 
