#ifndef __SORT_H__
#define __SORT_H__
#include "ADTErr.h"
#include "vector.h"



/* @Description: Bubble sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr BubbleSort(Vector* _vec);


/* @Description: Shake sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr ShakeSort(Vector* _vec);

/* @Description: Quick sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr QuickSort(Vector* _vec);

/* @Description: Insertion sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr InsertionSort(Vector* _vec);

/* @Description: Shell sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr ShellSort(Vector* _vec);

/* @Description: Selection sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr SelctionSort(Vector* _vec);


/* @Description: Counting sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr CountingSort(Vector* _vec, int m_maxValue);

/* @Description: Radix sort a vector of ints from smallest to largest.
 * @Input: _vec- pointer to vector.
 * @Return: 
 *  		ERR_OK- if the sorting success.
 * 			ERR_EMPTY- if the vector is empty;
 * 			ERR_UNINITINALAIZED - the pointer to the vector is NULL.
*/ 
ADTErr RadixSort(Vector* _vec, int _nDigits);

#endif /*__SORT_H__*/ 
