#ifndef __SORT_H__
#define __SORT_H__
#include "ADTErr.h"
#include "vector.h"

#define TRUE 1
#define FALSE 0

typedef int (*funcSort)(int, int);

/* @Description: Bubble sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr BubbleSort(Vector* _vec, int (*funcSort)(int, int));




#endif /*__SORT_H__*/ 
