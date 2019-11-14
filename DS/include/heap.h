/* 
* heap.h
 * Max Heap
 * a framework to create an Max Heap. 
 * Version: 0.01
 *      Author: Nataly Prego.  
 */


#ifndef __HEAP_H__
#define __HEAP_H__
#include "ADTErr.h"
#include "vector.h"

typedef struct Heap Heap;

/* @Description: Create a Max haep.
 * @Input: _vec- pointer to vector.
 * @Return: pointer to the created Max haep or NULL- if unsuccesful.
*/ 
Heap* HeapBuild(Vector* _vec);

/* @Description: Destroy the Max haep.
 * @Input: _heap- pointer to Max haep created by HeapBuild().
 * @Return: void.
*/ 
void HeapDestroy(Heap* _heap);


/* @Description: insert data to the Max haep.
 * @Input: _heap- pointer to Max haep created by HeapBuild().
 * @Input: _data- the data we want to insert.
 * @Return: 
 *		ERR_OK- if the data add to the Max haep.
 * 		ERR_UNINITINALAIZED - the pointer to the Max haep is NULL.
 * 		ERR_ALLOC_FAIL - if the memory allocation of a new Node not succssed.
*/ 
ADTErr HeapInsert(Heap* _heap, int _data);


/* @Description: get the max value in the heap.
 * @Input: _heap- pointer to Max haep created by HeapBuild().
 * @Input: _data- get the value.
 * @Return: 
 *		ERR_OK- if get the max value.
 * 		ERR_UNINITINALAIZED - the pointer to the Max haep is NULL.
 * 		ERR_UNDERFLOW - if the heap is empty.
*/ 
ADTErr HeapMax(Heap* _heap, int* _data);

/* @Description: Remove the max data in the heap.
 * @Input: _heap- pointer to Max haep created by HeapBuild().
 * @Input: _data- the data that remove from the heap.
 * @Return: 
 *		EER_OK- if the max data remove from the heap.
 *		ERR_UNDERFLOW- if the heap is empty.
 * 		ERR_UNINITINALAIZED - the pointer to the Max haep is NULL.
*/ 
ADTErr HeapExtractMax(Heap* _heap, int* _data);

/* @Description: count the number of items in the heap.
 * @Input: _heap- pointer to Max haep created by HeapBuild().
 * @Return: the number of items in the heap or -1 if the heap is NULL.
*/ 
int HeapItemsNum(Heap* _heap);

/* @Description: prints the heap.
 * @Input: _heap -pointer to Max haep created by HeapBuild().
 * @Return: void.
*/ 
void HeapPrint(const Heap* _heap);



#endif /*__HEAP_H__*/ 
