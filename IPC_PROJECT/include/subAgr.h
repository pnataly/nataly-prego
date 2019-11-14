#ifndef __SUBAGR_H__
#define __SUBAGR_H__
#include "CDR.h"
#include "subscriber.h"
#include "safeHash.h"


typedef struct SubAgr SubAgr;

typedef enum Sub_Result 
{
	SUB_SUCCESS = 0,
	SUB_ERROR 		
} Sub_Result;


/*
 * @brief Create a subscribers aggregator.
 * @param[in] _numOfSub - the number of subscribers.
 * @param[in] _numOfLock - number of lockers.
 * @return pointer to newly created subscribers aggregator or NULL on failure.
 */
SubAgr* CreateSubAgr(size_t _numOfSub, size_t _numOfLock);

/*
 * @brief destroy the subscribers aggregator.
 * @param[in] _subAgr : subscribers aggregator to be destroyed.
 * @return: void.
 */
void DestroySubAgr(SubAgr** _subAgr);

/*
 * @brief update the subscribers aggregator.
 * @param[in] _cdr - pointer to the CDR.
 * @param[in] _subAgr - pointer to the subscribers aggregator.
 * @return Success indicator 
 * @retval  SUB_SUCCESS	on success.
 * @retval  SUB_ERROR if the update fail.
 */
Sub_Result UpdateSubAgr(CDR* _cdr, SubAgr* _subAgr);

/*
 * @brief get data of given a specific key.
 * @param[in] _key - the key.
 * @param[in] _subAgr - pointer to the subscribers aggregator.
 * @return: void.
 */
void GetSubAgr(SubAgr* _subAgr, void* _key);

/*
 * @brief get data of given a subscribers aggregator.
 * @param[in] _subAgr - pointer to the subscribers aggregator.
 * @return: void.
 */
void GetAllSubAgr(SubAgr* _subAgr);

#endif /*__SUBAGR_H__*/ 
