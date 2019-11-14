/*
 *  @file HashMap.h
 *  @brief Generic Hash map of key-value pairs implemented with separate chaining using linked lists .
 *  @details  The hash map (sometimes called dictionary or associative array)
 *  is a set of distinct keys (or indexes) mapped (or associated) to values.
 *  size of allocated table will be the nearest prime number greater than requested capacity.
 *  Lists used for chaining will be allocated eagerly.
 *
 *  @author Nataly Prego.
 */

#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stdlib.h>
#include "genericDoubleList.h"
#include "list_itr.h"
#include "listFunction.h"
#include "listStruct.h"
#define FALSE 0
#define TRUE 1

typedef struct HashMap HashMap;

typedef enum Map_Result {
	MAP_SUCCESS = 0,
	MAP_UNINITIALIZED_ERROR, 		
	MAP_KEY_NULL_ERROR, 			
	MAP_KEY_DUPLICATE_ERROR, 		
	MAP_KEY_NOT_FOUND_ERROR, 		
	MAP_ALLOCATION_ERROR, 			
	MAP_UPDATE_ERROR
} Map_Result;

/* the function get the key and do an action on it that return the index of the bucket that the key will insert to */
typedef size_t (*HashFunction)(const void* _key);

/*check if the keys is equals. if they equals return TRUE else return FALSE */
typedef int (*EqualityFunction)(const void* _firstKey, const void* _secondKey);

/* action on the key-value */
typedef int	(*KeyValueActionFunction)(const void* _key, void* _value, void* _context);

/* update the value of a specific key */
typedef void*(*FuncUpdate)(void* _value, void* _context);

/* destroy the key */
typedef void (*KeyDestroy)(void* _key); 

/* destroy the value */
typedef void (*ValDestroy)(void* _value);

/*
 * @brief Create a new hash map with given capcity and key characteristics.
 * @param[in] _capacity - Expected max capacity actuall capacity will be equal to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys.
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @return newly created map or NULL on failure.
 */
HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc);

/*
 * @brief destroy hash map and set *_map to null.
 * @param[in] _map : map to be destroyed
 * @param[optional] _keyDestroy : pointer to function to destroy keys
 * @param[optional] _valDestroy : pointer to function to destroy values 
 * @details optionally destroy all keys and values using user provided functions
 */
void HashMap_Destroy(HashMap** _map, KeyDestroy _keyDestroy, ValDestroy _valDestroy);


/*
 * @brief Insert a key-value pair into the hash map.
 * complexty(1)
 * @param[in] _map - Hash map to insert to, must be initialized.
 * @param[in] _key - key to serve as index (cannot be NULL).
 * @param[in] _value - the value to associate with the key 
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_DUPLICATE_ERROR	if key already present in the map.
 * @retval  MAP_KEY_NULL_ERROR if the key or value is NULL.
 * @retval  MAP_ALLOCATION_ERROR on failer to allocate key-value pair
 * @retval  MAP_UNINITIALIZED_ERROR if map is NULL.
 * @warning key must be unique and destinct.
 */
Map_Result HashMap_Insert(HashMap* _map, const void* _key, const void* _value);

/*
 * @brief Remove a key-value pair from the hash map.
 * complexty(?)
 * @param[in] _map - Hash map to remove pair from, must be initialized.
 * @param[in] _searchKey - key to to search for in the map.
 * @param[out] _pKey - pointer to variable that will get the key stored in the map equaling _searchKey.
 * @param[out] _pValue - pointer to variable that will get the value stored in the map corresponding to find key.
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_NULL_ERROR if the key is NULL.
 * @retval  MAP_KEY_NOT_FOUND_ERROR if key not found. 
 * @retval  MAP_UNINITIALIZED_ERROR if map is NULL.
 * 
 * @warning key must be unique and destinct
 */
Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue);

/* 
 * @brief Find a value by key.
 * complexty(1)
 * @param[in] _map - Hash map to use, must be initialized.
 * @param[in] _searchKey - key to serve as index for search.
 * @param[out] _pValue - pointer to variable that will get the value assoiciated with the search key.
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_NULL_ERROR if the key is NULL.
 * @retval  MAP_KEY_NOT_FOUND_ERROR if key not found.
 * @retval  MAP_UNINITIALIZED_ERROR if map is NULL.
 * 
 * @warning key must be unique and destinct.
 */
Map_Result HashMap_Find(const HashMap* _map, const void* _searchKey, void** _pValue);


/*
 * @brief Get number of key-value pairs inserted into the hash map.
 * @param[in] _map - Hash map to use, must be initialized.
 * @return the size of the hash map.
 *
 * @warning complexity can be O(n)
 */
size_t HashMap_Size(const HashMap* _map);


/*
 * @brief Iterate over all key-value pairs in the map and call a function for each pair
 * The user provided KeyValueActionFunction will be called for each element.  
 * Iteration will stop if the called function returns a zero for a given pair
 * 
 * @param[in] _map - Hash map to iterate over.
 * @param[in] _action - User provided function pointer to be invoked for each element
 * @param[in] _context - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked, or 0 if NULL.
 */
size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context);


typedef struct Map_Stats {
    size_t pairs;               /* number of pairs stored */
	size_t collisions;          /* total number of collisions encountered */
	size_t buckets;             /* total number of buckets */
	size_t chains;              /* none empty buckets (having non zero length list) */
	size_t maxChainLength;      /* length of longest chain */
	size_t averageChainLength;  /* average length of none empty chains */
} Map_Stats;

Map_Stats HashMap_GetStatistics(const HashMap* _map);



#endif /*__HASHMAP_H__*/ 
