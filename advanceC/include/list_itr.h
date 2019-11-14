/**
 *  @file list_itr.h
 *  @brief Create a List Iterator.
 *  @author Author Nataly 
 */ 

#ifndef __LIST_ITR_H__
#define __LIST_ITR_H__

#include <stdlib.h>
#include "genericDoubleList.h"
#include "listStruct.h"
#define TRUE 1
#define FALSE 0

typedef void* ListItr;

/** 
 * @brief Get itertator to the list's beginning
 *
 * @params _list : list to return begin iterator, pointing at first element
 *                 or at the end if list is empty
 * @return iterator pointing at the list's beginning
 */
ListItr ListItr_Begin(const List* _list);

/** 
 * @brief Get itertator to the list end
 *
 * @params _list : list to return end iterator
 * @return an iterator pointing at the list's end
 */
ListItr ListItr_End(const List* _list);

/** 
 * @brief retruns TRUE if _a and _b iterators refer to same node, else return FALSE.
 */
int ListItr_Equals(const ListItr _a, const ListItr _b);

/** 
 * @brief Get itertator to the next element from a given iterator.
 * @params _itr : A list iterator.
 * @warning if _itr is end iterator it will be returned.
 */
ListItr ListItr_Next(ListItr _itr);

/** 
 * @brief Get itertator to the previous element.
 * @params _itr : A list iterator.
 * @warning if _itr is begin iterator it will be returned.
 */
ListItr ListItr_Prev(ListItr _itr);

/** 
 * @brief Get data from the list node the iterator is pointing to.
 *
 * @params _itr : A list iterator.
 * @return the data the iterator is pointing at or NULL if pointing to the end.
 */
void* ListItr_Get(ListItr _itr);

/** 
 * @brief Set data at the node where the iterator is pointing at.
 * @params _itr : A list iterator.
 * @params _element : the element to be set.
 * @return the data from the node that changed.
 */
void* ListItr_Set(ListItr _itr, void* _element);

/** 
 * @brief Inserts a new node before node the iterator is pointing at.
 * @params _itr : A list iterator.
 * @params _element : the data to be insert.
 * @return an iterator pointing at the element inserted or NULL on error
 */
ListItr ListItr_InsertBefore(ListItr _itr, void* _element);

/** 
 * @brief Removes the node the iterator is pointing at.
 *
 * @params _itr : A list iterator.
 * @return the removed data.
 */
void* ListItr_Remove(ListItr _itr);

#endif /*__LIST_ITR_H__*/ 

