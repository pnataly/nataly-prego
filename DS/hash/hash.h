/* 
* hash.h
 * hash set
 * a framework to create an Hash set. 
 * Version: 0.01
 *      Author: Nataly Prego.  
 */


#ifndef __HASH_H__
#define __HASH_H__
#include "ADTErr.h"

#define TRUE 1
#define FALSE 0

typedef struct Hash Hash;


/* @Description: Create Hash set.
 * @Input: void.
 * @Return: pointer to the created Hash or NULL- if unsuccesful.
*/ 
Hash* HashCreate(const size_t _size);

/* @Description: Destroy the Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Return: void.
*/ 
void HashDestroy(Hash* _hash);

/* @Description: Add data to the Hash. cannot insert duplicate data.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Input: _data- the data we want to insert.
 * @Return: 
 *		ERR_OK- if the data add to the Hash.
 * 		ERR_UNINITINALAIZED - the pointer to the Hash is NULL.
 *		ERR_OVERFLOW- 
 * 		ERR_DUP_DATA- 
*/ 
ADTErr HashInsert(Hash* _hash, int _data);

/* @Description: Remove data from the Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Input: _data- the data that removed from the Hash.
 * @Return: 
 * 		ERR_OK- if the data removed.
 * 		ERR_UNINITINALAIZED - if the pointer to the Hash is NULL.
 * 		ERR_UNDERFLOW- if the Hash is empty.
 * 		ERR_ITEM_NOT_FOUND -
*/ 
ADTErr HashRemove(Hash* _hash, int _data);

/* @Description: Check if data found in the Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Input: _data- the data we want to search in the Hash.
 * @Return:
 * 		TRUE- if the data found.
 *		FALSE- if the data not found or if the Hash is NULL or empty.
*/
int HashIsFound(const Hash* _hash, int _data);

/* @Description: counts the number of items that in Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Return: the number of items that in the Hash or 0 if Hash is NULL.
*/ 
size_t HashNumOfItems(const Hash* _hash);

/* @Description: return the capacity of the Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Return: the capacity of the Hash or 0 if NULL.
*/
size_t HashCapacity(const Hash* _hash);

/* @Description: Calculate the average of rehash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Return: 
 * 		-1- if the pointer to Hash is NULL.
 * 		0- if the Hash is empty.
 * 		the avergae of the rehash.
*/ 
double HashAverageRehashes(const Hash* _hash);



size_t HashMaxReHash(const Hash* _hash);

/* @Description: Prints the data in the  Hash.
 * @Input: _hash- pointer to Hash created by HashCreate().
 * @Return: void.
*/
void HashPrint(const Hash* _hash);


#endif /*__HASH_H__*/ 
