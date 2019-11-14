#ifndef __VECTOR_H__
#define __VECTOR_H__
#include "ADTErr.h"


typedef struct Vector Vector;


/* @Description: Create a vector.
 * @Input: _initialSize- the size of the vector.
 * @Input: _extensionBlockSize- the size to increase the vector when we get the initial size.
 * @Return: pointer to the created vector or NULL- if unsuccesful.
*/ 
Vector* VectorCreate(size_t _initialSize, size_t _extensionBlockSize);


/* @Description: Destroy the vector.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Return: void.
*/ 
void VectorDestroy(Vector* _vector);


/* @Description: add data to the vector.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Input: _item- the data we want to insert.
 * @Return: 
 *		ERR_OK- if the data add to the vector.
 * 		ERR_UNINITINALAIZED - the pointer to the vector is NULL.
 * 		ERR_ALLOC_FAIL - if the memory allocation not succssed.
 * 		ERR_OVERFLOW - if we get to the initial size and the extension block size is 0.
*/ 
ADTErr VectorAdd(Vector* _vector, int _item);


/* @Description: remove data to the vector.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Input: _item- the data that remove from the vector.
 * @Return: 
 *		ERR_OK- if the data remove from the vector.
 * 		ERR_UNINITINALAIZED - the pointer to the vector is NULL.
 * 		ERR_UNDERFLOW - if the vector is empty.
*/ 
ADTErr VectorDelete(Vector* _vector, int* _item);



/* @Description: show the item in the index.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Input: _item- the data that found in the index.
 * @Input: _index- the index we want to get the item value.
 * @Return: 
 *		ERR_OK- if we get the value.
 * 		ERR_UNINITINALAIZED - the pointer to the vector is NULL.
 * 		ERR_ITEM_NOT_FOUND - if the index not found int the vector.
*/ 
ADTErr VectorGet(const Vector* _vector, size_t _index, int* _item);



/* @Description: change the item in the index.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Input: _item- the new data we want to set in the index.
 * @Input: _index- the index we want to set the new value.
 * @Return: 
 *		ERR_OK- if we set the value.
 * 		ERR_UNINITINALAIZED - the pointer to the vector is NULL.
 * 		ERR_ITEM_NOT_FOUND - if the index not found int the vector.
*/ 
ADTErr VectorSet(Vector* _vector, size_t _index, int _item);


/* @Description: count the number of items in the vector.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Return: 
 * 		ERR_UNINITINALAIZED - the pointer to the vector is NULL.
 * 		ERR_UNDERFLOW - if the vector is empty.
 *		ERR_OK- if count the number of items in the vector.
*/ 

ADTErr VectorItemsNum(Vector* _vector, size_t* _numOfItems);

/* @Description: prints the vector.
 * @Input: _vector- pointer to the vector created by VectorCreate().
 * @Return: void.
*/ 
void VectorPrint(const Vector* _vector);

#endif /*__VECTOR_H__*/
