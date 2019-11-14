#ifndef __GENERICSORT_H__
#define __GENERICSORT_H__


#define TRUE 1
#define FALSE 0
#define UNITIALIZED_ERROR -1
#define ERR_ALLOC_FAIL -2
#define SORT_OK 0

typedef int (*funcSort)(const void* , const void*);

/* @Description: Bubble sort a vector of ints from smallest to largest.
 * @Input: _elements- pointer to vector.
 * @Input: _n- number of elements.
 * @Input: _size- the size of element.
 * @Input: _less- the sort function.
 * @Return: UNITIALIZED_ERROR- if _elements is NULL;
 * 			ERR_ALLOC_FAIL - if alloca fail
 * 			SORT_OK - if the sort success.
 *  		
*/ 
int BubbleSort(void* _elements, size_t _n, size_t _size, int(*_less)(const void*, const void*));




#endif /*__GENERICSORT_H__*/ 
