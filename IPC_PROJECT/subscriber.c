#include <stdlib.h>
#include <stdio.h>
#include "subscriber.h"
#define SUB_ERROR -1

struct Subscriber
{
	size_t m_key;
	size_t m_InVoiceCallOut;			/*Outgoing voice calls duration to a subscriber within the mobile operator*/
	size_t m_InVoiceCallIn;				/*Incoming voice calls duration to a subscriber within the mobile operator*/
	size_t m_OutVoiceCallOut;			/*Outgoing voice calls duration to a subscriber outside the mobile operator*/
	size_t m_OutVoiceCallIn;			/*Incoming voice calls duration to a subscriber outside the mobile operator*/
	size_t m_InSMSsent;					/*SMS messages sent within the mobile operator*/
	size_t m_InSMSrec;					/*SMS messages received within the mobile operator*/
	size_t m_OutSMSsent;				/*SMS messages sent outside the mobile operator*/
	size_t m_OutSMSrec;					/*SMS messages received outside the mobile operator*/
	size_t m_Download;					/*MB downloaded*/
	size_t m_upload;					/*MB uploaded*/
};


Subscriber* CreateSubscriber()
{
	Subscriber* sub;
	sub = (Subscriber*)calloc(sizeof(Subscriber),1);
	if (sub == NULL)
	{
		return NULL;
	}
	return sub;
}

void DestroySubscriber(Subscriber** _sub)
{
	if (_sub == NULL || *_sub == NULL)
	{
		return;
	}
	free(*_sub);
	*_sub = NULL;
}

/******************************************************/
Subscriber* CopySub(Subscriber* _sub)
{
	Subscriber* newSub;
	newSub = CreateSubscriber();
	if (newSub == NULL)
	{
		return NULL;
	}
	newSub->m_key = _sub->m_key;
	newSub->m_InVoiceCallOut = _sub->m_InVoiceCallOut;
	newSub->m_InVoiceCallIn = _sub->m_InVoiceCallIn;
	newSub->m_OutVoiceCallOut = _sub->m_OutVoiceCallOut;
	newSub->m_OutVoiceCallIn = _sub->m_OutVoiceCallIn;
	newSub->m_InSMSsent = _sub->m_InSMSsent;
	newSub->m_InSMSrec = _sub->m_InSMSrec;
	newSub->m_OutSMSsent = _sub->m_OutSMSsent;
	newSub->m_OutSMSrec = _sub->m_OutSMSrec;
	newSub->m_Download = _sub->m_Download;
	newSub->m_upload = _sub->m_upload;
	return newSub;
}

void PrintSub(Subscriber* _sub)
{
	printf("key: %lu\n", _sub->m_key);
	printf("Outgoing voice calls duration within the mobile: %lu\n", _sub->m_InVoiceCallOut);
	printf("Incoming voice calls duration within the mobile: %lu\n", _sub->m_InVoiceCallIn);
	printf("Outgoing voice calls duration outside the mobile: %lu\n", _sub->m_OutVoiceCallOut);
	printf("Incoming voice calls duration outside the mobile: %lu\n", _sub->m_OutVoiceCallIn);
	printf("SMS messages sent within the mobile: %lu\n", _sub->m_InSMSsent);
	printf("SMS messages received within the mobile: %lu\n", _sub->m_InSMSrec);
	printf("SMS messages sent outside the mobile: %lu\n", _sub->m_OutSMSsent);
	printf("SMS messages received outside the mobile: %lu\n", _sub->m_OutSMSrec);
	printf("MB download: %lu\n", _sub->m_Download);
	printf("MB upload: %lu\n", _sub->m_upload);
	printf("********************\n");
}

void SetSubKey(Subscriber* _sub, size_t _key)
{
	_sub->m_key =_key;
}

void SetInternet(Subscriber* _sub, size_t _down, size_t _up)
{
	_sub->m_Download +=_down;
	_sub->m_upload += _up;
}

void SetSubSMS(Subscriber* _sub, int _type, int _flag)
{
	switch(_type)
	{
		/*outgoing message*/
		case 3:
			if (_flag == IN)
			{
				_sub->m_InSMSsent += 1;
			}
			else
			{
				_sub->m_OutSMSsent += 1;
			}
			break;
		/*incoming message*/
		case 4:
			if (_flag == IN)
			{
				_sub->m_InSMSrec += 1;
			}
			else
			{
				_sub->m_OutSMSrec += 1;
			}
			break;
	}
}

void SetSubCall(Subscriber* _sub, int _type, int _flag, size_t _duration)
{
	switch(_type)
	{
		/*outgoing voice call*/
		case 1:
			if (_flag == IN)
			{
				_sub->m_InVoiceCallOut += _duration;
			}
			else
			{
				_sub->m_OutVoiceCallOut += _duration;
			}
			break;
		/*incoming voice call*/
		case 2:
			if (_flag == IN)
			{
				_sub->m_InVoiceCallIn += _duration;
			}
			else
			{
				_sub->m_OutVoiceCallIn += _duration;
			}
			break;
	}
}


