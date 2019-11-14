#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "aggregator.h"
#include "MSQ.h"
#include "subAgr.h"
#include "oprAgr.h"


struct Aggregator
{
	SubAgr* m_subAgr;
	OprAgr* m_oprAgr;
};


Aggregator* CreateAggregator()
{
	Aggregator* agr;
	agr = (Aggregator*)malloc(sizeof(Aggregator));
	if (agr == NULL)
	{
		return NULL;
	}
	return agr;	
}

void DestroyAggregator(Aggregator** _agr)
{
	if (_agr == NULL || *_agr == NULL)
	{
		return;
	}
	DestroySubAgr(&(*_agr)->m_subAgr);
	DestroyOprAgr(&(*_agr)->m_oprAgr);
	free(*_agr);
	*_agr = NULL;
}

void RunAggregator(Aggregator* _agr, CDR* _cdr)
{
	if (_agr == NULL)
	{
		return;
	}
	UpdateSubAgr(_cdr, _agr->m_subAgr);
	UpdateOprAgr(_cdr, _agr->m_oprAgr);
}

void InitAggregator(Aggregator* _agr, SubAgr* _subAgr, OprAgr* _oprAgr)
{
	if (_agr == NULL || _subAgr == NULL || _oprAgr == NULL)
	{
		return;
	}
	_agr->m_subAgr = _subAgr;
	_agr->m_oprAgr = _oprAgr;
}


SubAgr* GetSub(Aggregator* _agr)
{
	return _agr->m_subAgr;
}

OprAgr* GetOpr(Aggregator* _agr)
{
	return _agr->m_oprAgr;
}

static void* RunAgr(void* param)
{
	void* cdr; 
	if (param == NULL)
	{
		return NULL;
	}
	while(1)
	{
		cdr = ReadMessage(CreateMessageQ(MSQ_FILE_PATH), sizeof(CDR), MSG_TYPE);
		RunAggregator((Aggregator*)param, cdr);
	}
	return param;
}

void ThreadsCreate(Aggregator* _agr, size_t _numOfThr)
{
	int i;
	pthread_t thread;
	if (_agr == NULL)
	{
		return;
	}
	for (i=0; i<_numOfThr; i++)
	{		
		if (pthread_create(&thread, NULL, RunAgr, (void*)_agr) != 0)
		{
			perror ("create thread");
			return;
		}
	}
}


