#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "aggregator.h"
#include "subscriber.h"
#include "subAgr.h"
#include "oprAgr.h"
#include "QM.h"
#include "CDR.h"
#include "MSQ.h"

#define NUM_OF_SUB 10
#define BUF_LEN 1024
#define ACK_MESSAGE "I got the Query request" 

int main()
{
	Aggregator* agr;
	SubAgr* subAgr;
	OprAgr* oprAgr;
	int id;
	void* pid;
	int msgType;
	void* key;

	id = CreateMessageQ(MSQ_FILE_PATH);
	agr = CreateAggregator();
	if (agr == NULL)
	{
		perror ("CreateAggregator");
		return 0;
	}
	subAgr = CreateSubAgr(NUM_OF_SUB ,NUM_OF_LOCK);
	if (subAgr == NULL)
	{
		perror ("CreateSubAgr");
		return 0;
	}
	oprAgr = CreateOprAgr(NUM_OF_SUB , NUM_OF_LOCK);
	if (oprAgr == NULL)
	{
		perror ("CreateOprAgr");
		return 0;
	}
	
	InitAggregator(agr, subAgr, oprAgr);
	ThreadsCreate(agr, NUM_OF_THREADS);	

	while(1)
	{
		/*hand-shake message recieve */
		pid = ReadMessage(id, sizeof(size_t), 2);
		msgType = (((*(int*)pid)*2)+1);
	printf("pid--> %d\n", *(pid_t*)pid);
	printf("message type: %d\n", msgType);
		/*query request message recieve */
		key = ReadMessage(id, sizeof(size_t), msgType);
	printf("key--> %lu\n", *(size_t*)key);
		sleep(1);	
		SendMessage(id, ACK_MESSAGE ,BUF_LEN, msgType); 
		GetQuery(GetSub(agr), key, SUB);
	}	
	DestroyAggregator(&agr);
	return 0;
} 
	
/*	GetQuery(GetSub(agr), (size_t*)1, SUB);
	GetQuery(GetSub(agr), (size_t*)16, SUB);	
	GetQuery(GetOpr(agr), (size_t*)42503, OPR);
	GetReport(GetOpr(agr), OPR);
	GetReport(GetSub(agr), SUB);	*/
/*	void* cdr1;
	void* cdr2;
	void* cdr3;
	void* cdr4;	
	size_t* key1 = NULL;
	size_t* key3 = NULL;
	size_t* tuple1 = NULL;	
	size_t* tuple2 = NULL;	*/
/*	cdr1 = ReadMessage(CreateMessageQ(MSQ_FILE_PATH), sizeof(CDR), MSG_TYPE);
	cdr2 = ReadMessage(CreateMessageQ(MSQ_FILE_PATH), sizeof(CDR), MSG_TYPE);
	cdr3 = ReadMessage(CreateMessageQ(MSQ_FILE_PATH), sizeof(CDR), MSG_TYPE);
	cdr4 = ReadMessage(CreateMessageQ(MSQ_FILE_PATH), sizeof(CDR), MSG_TYPE);	*/

/*	key1 = (size_t*) GetKey(cdr2);
	key3 = (size_t*) GetKey(cdr4);	
	printf("key1--> %lu\n", (size_t)key1);
	printf("key4--> %lu\n", (size_t)key3);	
	tuple1 = (size_t*)GetOperatorTuple(cdr1); 
	tuple2 = (size_t*)GetOperatorTuple(cdr3);	*/

/*	RunAggregator(agr, cdr1);
	RunAggregator(agr, cdr2);
	RunAggregator(agr, cdr3);
	RunAggregator(agr, cdr4);	*/
