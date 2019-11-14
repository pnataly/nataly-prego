#ifndef __CGF_H__
#define __CGF_H__
#include "subAgr.h"
#define SUB 1
#define OPR 2

/*
 * @brief get query for specific key.
 * @param[in] _agr - pointer to the aggregator.
 * @param[in] _key - the key.
 * @param[in] _flag - which aggregator.
 * @return void. 
 */
void GetQuery(void* _agr, void* _key, int _flag);

/*
 * @brief get report for for the aggregator.
 * @param[in] _agr - pointer to the aggregator.
 * @param[in] _flag - which aggregator.
 * @return void. 
 */
void GetReport(void* _agr, int _flag);

#endif /*__CGF_H__*/ 
