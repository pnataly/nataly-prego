#ifndef __AGGREGATOR_H__
#define __AGGREGATOR_H__
#include "CDR.h"
#include "subAgr.h"
#include "oprAgr.h"

#define MSQ_FILE_PATH "messageQ.txt"
#define NUM_OF_THREADS	4
#define NUM_OF_LOCK 2
#define MSG_TYPE 1

typedef struct Aggregator Aggregator;

/*
 * @brief: Create Aggregator.
 * @return: pointer to the created Aggregator.
 */
Aggregator* CreateAggregator();

/*
 * @brief: destroy the Aggregator.
 * @param[in]: _agr : the Aggregator to be destroyed.
 * @return: void.
 */
void DestroyAggregator(Aggregator** _agr);

/*
 * @brief: running the Aggregator.
 * @param[in]: _agr : the dispatcher to run.
 * @param[in]: _cdr : pointer to CDR.
 * @return: void.
 */
void RunAggregator(Aggregator* _agr, CDR* _cdr);

/*
 * @brief: initialized the Aggregator.
 * @param[in]: _agr : the Aggregator to run.
 * @param[in]: _subAgr : pointer to subscribers aggregator.
 * @param[in]: _oprAgr : pointer to operators aggregators.
 * @return: void.
 */
void InitAggregator(Aggregator* _agr, SubAgr* _subAgr, OprAgr* _oprAgr);

/*
 * @brief: get the pointer to subscribers aggregator.
 * @param[in]: _agr : the Aggregator.
 * @return: pointer to subscribers aggregator.
 */
SubAgr* GetSub(Aggregator* _agr);

/*
 * @brief: get the pointer to operators aggregator.
 * @param[in]: _agr : the Aggregator.
 * @return: pointer to operators aggregator.
 */
OprAgr* GetOpr(Aggregator* _agr);

/*
 * @brief: create threads.
 * @param[in]: _agr : the Aggregator to run.
 * @param[in]: _numOfThr : the number of threads to create.
 * @return: void.
 */
void ThreadsCreate(Aggregator* _agr, size_t _numOfThr);


#endif /*__AGGREGATOR_H__*/ 

