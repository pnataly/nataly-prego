#include <stdlib.h>
#include <string.h>
#include "subAgr.h"
#include <stdio.h>

struct SubAgr
{
	SafeHashMap* m_subHash;
};

/*****************Static-Functions************************/
static size_t HashFunc(const void* _key)
{
	if(_key == NULL)
	{
		return 0;
	}
	return (size_t)_key;
}

static int keysEqualFunc (const void* _firstKey, const void* _secondKey)
{
	if(_firstKey == NULL || _secondKey == NULL)
	{
		return FALSE;
	}
	return (_firstKey == _secondKey);
}

static void keyDestroy(void* _key)
{
	if(_key == NULL)
	{
		return;
	}
	free(_key);
}

static void valDestroy(void* _value)
{
	if(_value == NULL)
	{
		return;
	}
	free(_value);
}

static void SetSubData(Subscriber* _sub, CDR* _cdr)
{
	int type = 0;
	size_t tuple = 0;
	size_t partyOpr = 0;
	SetSubKey(_sub, GetKey(_cdr));
	type = GetCallType(_cdr);
	tuple = GetOperatorTuple(_cdr);
	partyOpr = GetPartyOpertaor(_cdr);
	switch (type)
	{
		/*outgoing call */
		case 1: 
			if (tuple == partyOpr)
			{
				SetSubCall(_sub, type, IN, GetCallDuration(_cdr));
			}
			else
			{
				SetSubCall(_sub, type, OUT, GetCallDuration(_cdr));
			}
			break;
			
		/*incoming call*/
		case 2:
			if (tuple == partyOpr)
			{
				SetSubCall(_sub, type, IN, GetCallDuration(_cdr));
			}
			else
			{
				SetSubCall(_sub, type, OUT, GetCallDuration(_cdr));
			}
				break;
				
		/*outgoing message*/
		case 3:
			if (tuple == partyOpr)
			{
				SetSubSMS(_sub, type, IN);
			}
			else
			{
				SetSubSMS(_sub, type, OUT);
			}
				break;
				
		/*incoming message*/
		case 4:
			if (tuple == partyOpr)
			{
				SetSubSMS(_sub, type, IN);
			}
			else
			{
				SetSubSMS(_sub, type, OUT);
			}
			break;
			
		/*internet*/
		case 5:
			SetInternet(_sub, GetDownload(_cdr), GetUpload(_cdr));
			break;
	}
}

static int KeyValueAction(const void* _key, void* _value, void* _context)
{
	if (_key == NULL || _value == NULL)
	{
		return 0;
	}
	PrintSub((Subscriber*)_value);
	return 0;
}

static void* funcUpdate(void* _value, void* _context)
{
	Subscriber* sub;
	if (_value == NULL) /*not found in the hash- create sub*/
	{
		sub = CreateSubscriber();
		if (sub == NULL)
		{
			return NULL;
		}
		SetSubData(sub, _context);
		return (void*)sub;
	}
	else /*found - update the value*/
	{
		SetSubData((Subscriber*)_value, _context);
	}
	return _value;
}

static void* funcGet(void* _value)
{
	Subscriber* sub;
	if (_value == NULL) 
	{
		return NULL;
	}
	sub = CopySub((Subscriber*)_value);
	if (sub == NULL)
	{
		return NULL;
	}
	return sub;
}


/******************Main-Functions************************/
SubAgr* CreateSubAgr(size_t _numOfSub, size_t _numOfLock)
{
	SafeHashMap* safeHash;
	SubAgr* subAgr;
	if (_numOfSub == 0)
	{
		return NULL;
	}
	subAgr = (SubAgr*)malloc(sizeof(SubAgr));
	if (subAgr == NULL)
	{
		return NULL;
	}
	safeHash = SafeHashMap_Create(_numOfSub, HashFunc, keysEqualFunc, _numOfLock);
	if (safeHash == NULL)
	{
		free(subAgr);
		return NULL;
	}
	subAgr->m_subHash = safeHash;
	return subAgr;
}

void DestroySubAgr(SubAgr** _subAgr)
{
	if (_subAgr == NULL || *_subAgr == NULL)
	{
		return;
	}
	SafeHashMap_Destroy(&(*_subAgr)->m_subHash,keyDestroy, valDestroy);
	free(*_subAgr);
	*_subAgr = NULL;
}

Sub_Result UpdateSubAgr(CDR* _cdr, SubAgr* _subAgr)
{
	Safe_Map_Result result;
	size_t* key;
	key = (size_t*)malloc(sizeof(size_t));
	if (key == NULL)
	{
		return SUB_ERROR;
	}
	key = (size_t*)GetKey(_cdr);	
	
	result = SafeHashMap_Update(_subAgr->m_subHash, key, funcUpdate, _cdr);
	if (result == SAFE_MAP_UPDATE_ERROR)
	{
		return SUB_ERROR;
	}
	return SUB_SUCCESS;
}

void GetSubAgr(SubAgr* _subAgr, void* _key) 
{
	void* value;
	if (_subAgr == NULL || _key == NULL)
	{
		return;
	}
	value = SafeHashMap_Get(_subAgr->m_subHash, _key, funcGet);
	if (value == NULL)
	{
		return;
	}
	PrintSub((Subscriber*)value);
}

void GetAllSubAgr(SubAgr* _subAgr)
{
	if (_subAgr == NULL)
	{
		return;
	}
	SafeHashMap_ForEach(_subAgr->m_subHash, KeyValueAction, NULL);
}

