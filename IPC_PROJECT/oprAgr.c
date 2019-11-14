#include <stdlib.h>
#include <string.h>
#include "oprAgr.h"
#include <stdio.h>

struct OprAgr
{
	SafeHashMap* m_oprHash;
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

static int KeyValueAction(const void* _key, void* _value, void* _context)
{
	if (_key == NULL || _value == NULL)
	{
		return 0;
	}
	PrintOpr((Operator*)_value);
	return 0;
}

static void SetOprData(Operator* _opr, CDR* _cdr)
{
	int type = 0;
	SetOprKey(_opr, GetOperatorTuple(_cdr));
	type = GetCallType(_cdr);
	switch (type)
	{
		/*out call*/
		case 1: 
				SetOprCall(_opr,OUT, GetCallDuration(_cdr));
				break;
		/*in call*/
		case 2:
				SetOprCall(_opr, IN, GetCallDuration(_cdr));
				break;
		/*out SMS*/
		case 3:
				SetOprSMS(_opr, OUT);
				break;
		/*in SMS*/
		case 4:
				SetOprSMS(_opr, IN);
				break;
	}
}

static void* funcUpdate(void* _value, void* _context)
{
	Operator* opr;
	if (_value == NULL) /*not found in the hash- create opr*/
	{
		opr = CreateOperator();
		if (opr == NULL)
		{
			return NULL;
		}
		SetOprData(opr, _context);
		return (void*)opr;
	}
	else /*found - update the value*/
	{
		SetOprData((Operator*)_value, _context);
	}
	return _value;
}

static void* funcGet(void* _value)
{
	Operator* opr;
	if (_value == NULL) 
	{
		return NULL;
	}
	opr = CopyOpr((Operator*)_value);
	if (opr == NULL)
	{
		return NULL;
	}
	return opr;
}


/******************Main-Functions************************/
OprAgr* CreateOprAgr(size_t _numOfOpr, size_t _numOfLock)
{
	SafeHashMap* safeHash;
	OprAgr* oprAgr;
	if (_numOfOpr == 0)
	{
		return NULL;
	}
	oprAgr = (OprAgr*)malloc(sizeof(OprAgr));
	if (oprAgr == NULL)
	{
		return NULL;
	}
	safeHash = SafeHashMap_Create(_numOfOpr, HashFunc, keysEqualFunc, _numOfLock);
	if (safeHash == NULL)
	{
		free(oprAgr);
		return NULL;
	}
	oprAgr->m_oprHash = safeHash;
	return oprAgr;
}

void DestroyOprAgr(OprAgr** _oprAgr)
{
	if (_oprAgr == NULL || *_oprAgr == NULL)
	{
		return;
	}
	SafeHashMap_Destroy(&(*_oprAgr)->m_oprHash,keyDestroy, valDestroy);
	free(*_oprAgr);
	*_oprAgr = NULL;
}

Opr_Result UpdateOprAgr(CDR* _cdr, OprAgr* _oprAgr)
{
	Safe_Map_Result result;
	size_t* key;
	key = (size_t*)malloc(sizeof(size_t));
	if (key == NULL)
	{
		return OPR_ERROR;
	}
	key = (size_t*)GetOperatorTuple(_cdr);	
	result = SafeHashMap_Update(_oprAgr->m_oprHash, key, funcUpdate, _cdr);
	if (result == SAFE_MAP_UPDATE_ERROR)
	{
		return OPR_ERROR;
	}
	return OPR_SUCCESS;
}

void GetOprAgr(OprAgr* _oprAgr, void* _key) 
{
	void* value;
	value = SafeHashMap_Get(_oprAgr->m_oprHash, _key, funcGet);
	if (value == NULL)
	{
		return;
	}
	PrintOpr((Operator*)value);
}

void GetAllOprAgr(OprAgr* _oprAgr)
{
	if (_oprAgr == NULL)
	{
		return;
	}
	SafeHashMap_ForEach(_oprAgr->m_oprHash, KeyValueAction, NULL);
}

