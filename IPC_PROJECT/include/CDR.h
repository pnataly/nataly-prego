#ifndef __CDR_H__
#define __CDR_H__
#define CDR_ERROR -1
#define IN 1
#define OUT 2
#include <stdlib.h>

typedef enum CALL_TYPE
{
	MOC =1,	/*outgoing voice call*/
	MTC,	/*incoming voice call*/
	SMS_MO,	/*outgoing message*/
	SMS_MT,	/*incoming message*/
	GPRS	/*internet*/
} CALL_TYPE;

struct CDR
{
	size_t m_ID;				/*Number uniquely identifying a subscription in a mobile network*/
	size_t m_OprTuple;			/*Mobile Code*/
	int m_type;					/*Call type*/
	size_t	m_CallDuration;		/*in seconds*/
	size_t 	m_download;			/* MB downloaded */
	size_t 	m_upload;			/* MB uploaded */
/*	size_t 	m_PartyMSISDN;		Corresponding party in this call*/
	size_t 	m_PartyOperator;	/*Corresponding party’s mobile operator in this call*/
};

typedef struct CDR CDR;


/*
 * @brief: Create a new CDR.
 * @param[in] _line - line from the file.
 * @return: pointer to the newly created CDR or NULL on failure.
 */
CDR CreateCDR(char* _line);


/*
 * @brief: destroy the CDR.
 * @param[in] _cdr - pointer to the CDR to be destroyed.
 * @return: void.
 */
void DestroyCDR(CDR* _cdr);

/*
 * @brief get the key of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: the key.
 */
size_t GetKey(CDR* _cdr);

/*
 * @brief get the call duration of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: the duration call.
 */
size_t GetCallDuration(CDR* _cdr);

/*
 * @brief get the call type of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: the type.
 */
int GetCallType(CDR* _cdr);


/*
 * @brief get the internet download of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: MB download.
 */
size_t GetDownload(CDR* _cdr);

/*
 * @brief get the internet upload of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: MB upload.
 */
size_t GetUpload(CDR* _cdr);

/*
 * @brief get the operator tuple of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: the operator tuple.
 */
size_t GetOperatorTuple(CDR* _cdr);

/*
 * @brief get the party operator of subscriber paramter from the CDR.
 * @param[in] _cdr : pointer to the CDR.
 * @return: the party operator.
 */
size_t GetPartyOpertaor(CDR* _cdr);


/*
 * @brief: copy the data of the CDR.
 * @param[in]: _cdr : the CDR to copy.
 * @return: pointer to the new CDR.
 */
CDR CopyCdr(CDR* _cdr);

#endif /*__CDR_H__*/ 

