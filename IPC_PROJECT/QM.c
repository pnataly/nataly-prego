#include <stdio.h>
#include "QM.h"
#include "subAgr.h"
#include "oprAgr.h"

void GetQuery(void* _agr, void* _key, int _flag) /*TODO*/
{
	void* item;
	if (_agr == NULL || _key == NULL)
	{
		return;
	}
	if (_flag == SUB)
	{
		printf("The Query for subscriber %lu:\n", *(size_t*)_key);
		GetSubAgr(_agr, _key);
		return;
	}
	printf("The Query for operator %lu:\n", *(size_t*)_key);
	GetOprAgr(_agr, _key);

}

void GetReport(void* _agr, int _flag)
{
	if (_agr == NULL)
	{
		return;
	}
	if (_flag == SUB)
	{
		printf("The Report for subscribers:\n");
		GetAllSubAgr(_agr);
		return;
	}
	printf("The Report for operators:\n");
	GetAllOprAgr(_agr);
}	
