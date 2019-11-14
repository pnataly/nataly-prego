#include <stdlib.h>
#include <stdio.h>
#include "operator.h"
#define OPR_ERROR -1


struct Operator
{
	size_t m_tuple;		/*id of the operator*/
	size_t m_InCall;	/*incoming calls duration in seconds*/
	size_t m_OutCall;	/*outgoing calls duration in seconds*/
	size_t m_InSMS;		/*incoming SMS*/
	size_t m_OutSMS;	/*outgoing SMS*/
};

Operator* CreateOperator()
{
	Operator* opr;
	opr = (Operator*)calloc(sizeof(Operator),1);
	if (opr == NULL)
	{
		return NULL;
	}
	return opr;
}

void DestroyOperator(Operator** _opr)
{
	if (_opr == NULL || *_opr == NULL)
	{
		return;
	}
	free(*_opr);
	*_opr = NULL;
}

/***********************************************/

void SetOprKey(Operator* _opr, size_t _key)
{
	_opr->m_tuple = _key;
}

void SetOprCall(Operator* _opr, int _flag, size_t _duration)
{
		/*incoming voice call*/
		if (_flag == IN)
		{
			_opr->m_InCall += _duration;
		}
		/*outgoing voice call*/
		else
		{
			_opr->m_OutCall += _duration;
		}
}

void SetOprSMS(Operator* _opr, int _flag)
{
			/*incoming message*/
		if (_flag == IN)
		{
			_opr->m_InSMS += 1;
		}
		/*outgoing message*/
		else
		{
			_opr->m_OutSMS += 1;
		}
}

Operator* CopyOpr(Operator* _opr)
{
	Operator* newOpr;
	newOpr = CreateOperator();
	if (newOpr == NULL)
	{
		return NULL;
	}
	newOpr->m_tuple = _opr->m_tuple;
	newOpr->m_InCall = _opr->m_InCall;
	newOpr->m_OutCall = _opr->m_OutCall;
	newOpr->m_InSMS = _opr->m_InSMS;
	newOpr->m_OutSMS = _opr->m_OutSMS;
	return newOpr;
}

void PrintOpr(Operator* _opr)
{
	printf("Opreator key %lu\n", _opr->m_tuple);
	printf("Incoming calls duration: %lu\n", _opr->m_InCall);
	printf("Outgoing calls duration in seconds: %lu\n", _opr->m_OutCall);
	printf("Incoming SMS: %lu\n", _opr->m_InSMS);
	printf("Outgoing SMS: %lu\n", _opr->m_OutSMS);
	printf("********************\n");
}


