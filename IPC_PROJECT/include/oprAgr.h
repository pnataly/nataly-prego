/*Filter- take from CDR the relevat Data*/
#ifndef __OPRAGR_H__
#define __OPRAGR_H__
#include "CDR.h"
#include "operator.h"
#include "safeHash.h"


typedef struct OprAgr OprAgr;

typedef enum Opr_Result 
{
	OPR_SUCCESS = 0,
	OPR_ERROR 		
} Opr_Result;

/*
 * @brief Create a operators aggregator.
 * @param[in] _numOfOpr - the number of operators.
 * @param[in] _numOfLock - number of lockers.
 * @return pointer to newly created operators aggregator or NULL on failure.
 */
OprAgr* CreateOprAgr(size_t _numOfOpr, size_t _numOfLock);

/*
 * @brief destroy the operators aggregator.
 * @param[in] _oprAgr : operators aggregator to be destroyed.
 * @return: void.
 */
void DestroyOprAgr(OprAgr** _oprAgr);

/*
 * @brief update the operators aggregator.
 * @param[in] _cdr - pointer to the CDR.
 * @param[in] _oprAgr : pointer to the operators aggregator.
 * @return Success indicator 
 * @retval  OPR_SUCCESS	on success.
 * @retval  OPR_ERROR if the update fail.
 */
Opr_Result UpdateOprAgr(CDR* _cdr, OprAgr* _oprAgr);

/*
 * @brief get data of given a specific key.
 * @param[in] _key - the key.
 * @param[in] _oprAgr : pointer to the operators aggregator.
 * @return: void.
 */
void GetOprAgr(OprAgr* _oprAgr, void* _key);

/*
 * @brief get data of given a operators aggregator.
 * @param[in] _oprAgr - pointer to the operators aggregator.
 * @return: void.
 */
void GetAllOprAgr(OprAgr* _oprAgr);

#endif /*__OPRAGR_H__*/ 
