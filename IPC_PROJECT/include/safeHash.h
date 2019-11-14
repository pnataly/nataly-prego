/*
 *  @file safe threads HashMap.h
 *  @brief Generic Hash map of key-value pairs implemented with separate chaining using linked lists .
 *  @details  The hash map (sometimes called dictionary or associative array)
 *  is a set of distinct keys (or indexes) mapped (or associated) to values.
 *  size of allocated table will be the nearest prime number greater than requested capacity.
 *  Lists used for chaining will be allocated eagerly.
 *
 *  @author Nataly Prego.
 */
#ifndef __SAFEHASH_H__
#define __SAFEHASH_H__

#include "hashMap.h"
#include "locker.h"

typedef struct SafeHashMap SafeHashMap;

typedef enum Safe_Map_Result {
	SAFE_MAP_SUCCESS = 0,
	SAFE_MAP_UPDATE_ERROR,
	SAFE_MAP_UPDATE_SUCCESS,
	SAFE_MAP_REMOVE_ERROR,
	SAFE_MAP_INSERT_ERROR,
	SAFE_MAP_FIND_ERROR,
	SAFE_MAP_GET_SUCCESS,
	SAFE_MAP_GET_ERROR
}Safe_Map_Result;

/* the function get the key and do an action on it that return the index of the bucket that the key will insert to */
typedef size_t (*HashFunction)(const void* _key);

/*check if the keys is equals. if they equals return TRUE else return FALSE */
typedef int (*EqualityFunction)(const void* _firstKey, const void* _secondKey);

/* action on the key-value */
typedef int	(*KeyValueActionFunction)(const void* _key, void* _value, void* _context);

/* update the value of a specific key */
typedef void*(*FuncUpdate)(void* _value, void* _context);

typedef void* FuncGet(void* _value);
/*
 * @brief Create a new safe hash
 * @param[in] _capacity - Expected max capacity actuall capacity will be equal to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys.
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @param[in] _numOfLock - number of lockers. 
 * @return newly created safe hash or NULL on failure.
 */
SafeHashMap* SafeHashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc, size_t _numOfLock);

/* 
 * @brief Update the value by key.
 * @param[in] _safeHash - Hash to use, must be initialized.
 * @param[in] _searchKey - key to serve as index for search.
 * @param[in] _context - the value to update.
 * @param[in] _funcUpdate - the update function.
 * @return Success indicator
 * @retval  SAFE_MAP_UPDATE_SUCCESS on success of update the value.
 * @retval  SAFE_MAP_UPDATE_SUCCESS if the update success.
 * 
 * @warning key must be unique and destinct.
 */
Safe_Map_Result SafeHashMap_Update(SafeHashMap* _safeHash, const void* _searchKey, FuncUpdate _funcUpdate, void* _context);

/*
 * @brief Remove a key-value pair from the safe hash.
 * @param[in] _safeHash - Hash to use, must be initialized.
 * @param[in] _searchKey - key to to search for in the safe hash.
 * @param[out] _pKey - pointer to variable that will get the key stored in the map equaling _searchKey.
 * @param[out] _pValue - pointer to variable that will get the value stored in the map corresponding to find key.
 * @return Success indicator
 * @retval  SAFE_MAP_SUCCESS on success
 * @retval  SAFE_MAP_REMOVE_ERROR if the remove is fail.
 *
 * @warning key must be unique and destinct
 */
Safe_Map_Result SafeHashMap_Remove(SafeHashMap* _safeHash, const void* _searchKey, void** _pKey, void** _pValue);

/*
 * @brief Iterate over all key-value pairs in the safe hash and call a function for each pair
 * The user provided KeyValueActionFunction will be called for each element.  
 * Iteration will stop if the called function returns a zero for a given pair
 * @param[in] _safeHash - Hash to use, must be initialized.
 * @param[in] _action - User provided function pointer to be invoked for each element
 * @param[in] _context - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked, or 0 if NULL.
 */
size_t SafeHashMap_ForEach(const SafeHashMap* _safeHash, KeyValueActionFunction _action, void* _context);

/*
 * copy the value.  
 * Iteration will stop if the called function returns a zero for a given pair
 * @param[in] _safeHash - Hash to use, must be initialized.
 * @param[in] _funcGet - User provided function pointer to be invoked for each element
 * @param[in] _searchKey - key to to search for in the safe hash.
 * @return: pointer to the value.
 */
void* SafeHashMap_Get(SafeHashMap* _safeHash, const void* _searchKey, FuncGet _funcGet);


void SafeHashMap_Destroy(SafeHashMap** _safeHash, KeyDestroy _keyDestroy, ValDestroy _valDestroy);

#endif /*__SAFEHASH_H__*/ 
