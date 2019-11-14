#include <stdlib.h>
#include <string.h>
#include "CDR.h"
#define SIZE 64

static void CDRInit(CDR* _cdr, char* _line)
{
	char* token;

	token = strtok(_line, "|");
	_cdr->m_ID = (size_t)atoi(token);

	token = strtok(NULL, "|");
	_cdr->m_OprTuple = (size_t)atoi(token);
	
	token = strtok(NULL, "|");
	_cdr->m_type = atoi(token);		
	
	token = strtok(NULL, "|");
	_cdr->m_CallDuration = (size_t)atoi(token);

	token = strtok(NULL, "|");
	_cdr->m_download = (size_t)atoi(token);

	token = strtok(NULL, "|");
	_cdr->m_upload = (size_t)atoi(token);

	token = strtok(NULL, "|");
	_cdr->m_PartyOperator = (size_t)atoi(token);
}

CDR CreateCDR(char* _line)
{
	CDR cdr;
	if (_line == NULL)
	{
		abort();
	}
	CDRInit(&cdr, _line);
	return cdr;
}

/****************************************************/

size_t GetKey(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_ID;
}


size_t GetDownload(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_download;
}

size_t GetUpload(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_upload;
}

int GetCallType(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_type;
}

size_t GetCallDuration(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_CallDuration;
}

size_t GetOperatorTuple(CDR* _cdr)
{
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_OprTuple;
}

size_t GetPartyOpertaor(CDR* _cdr)
{	
	if (_cdr == NULL)
	{
		return CDR_ERROR; 
	}
	return _cdr->m_PartyOperator;
}

CDR CopyCdr(CDR* _cdr)
{
	CDR newCDR;
	if (_cdr == NULL)
	{
		abort();
	}
	newCDR.m_ID = _cdr->m_ID;
	newCDR.m_OprTuple = _cdr->m_OprTuple;
	newCDR.m_type = _cdr->m_type;
	newCDR.m_CallDuration = _cdr->m_CallDuration;
	newCDR.m_download = _cdr->m_download;
	newCDR.m_upload = _cdr->m_upload;
	newCDR.m_PartyOperator = _cdr->m_PartyOperator;
	return newCDR;
}

