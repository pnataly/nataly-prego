# include <stdio.h>
# include <stdlib.h>
# include "AppointmentDiary.h"

struct AD* CreateAD (unsigned int _sizeAD,unsigned int _increaseBlock)
{
	struct AD* _pCalendar;
	_increaseBlock = SIZE;

	if (_sizeAD < 0 || _increaseBlock < 0 || (_sizeAD == 0 && _increaseBlock == 0))
	{
		return NULL;
	}
	_pCalendar = (struct AD*)malloc(_sizeAD*sizeof(struct AD));
	if (_pCalendar == NULL)
	{
		return NULL;
	}
		_pCalendar->_day =(struct Meeting**) malloc(_sizeAD*sizeof(struct Meeting *));
		if (_pCalendar->day == NULL)
		{	
			free(_pCalendar);
			return NULL;
		}
		
			_pCalendar->_meetingsSoFar = 0;
			_pCalendar->_sizeAD = _sizeAD;
			_pCalendar->_increaseBlock = SIZE;
		
	return _pCalendar;
}

void Destroy (struct AD* _pCalendar)
{
	int i=0;
	if (_pCalendar == NULL)
	{
		return;	
	
	while(_pCalendar
	free(_pCalendar->_day);
	free(_pCalendar);
	
}


enum STATUS CreateMeeting (struct AD* _pCalendar)
{
	int _check;

	_check = CheckSize(_pCalendar);
	if (_check == DONE)
	{
		_check = CheckOverlap(_pCalendar);
		if (_check != OVERLAP)
		{
			_pCalendar->_day[_OVERLAP]->_beginHour += _pCalendar->_requestedMeeting->_beginHour;
			_pCalendar->_day[_OVERLAP]->_endHour += _pCalendar->_requestedMeeting->_endHour;
			_pCalendar->_day[_OVERLAP]->_roomNum += _pCalendar->_requestedMeeting->_roomNum;
			return DONE;	

		}
	}	
	return OVERLAP;
}


enum STATUS CheckSize(struct AD* _pCalendar)
{
	if ((_pCalendar._sizeAD == _pCalendar._meetingsSoFar) && (_pCalendar._sizeAD > _pCalendar._increaseBlock))
	{
		if (_pCalendar->_increaseBlock == 0)
		{
			return OVER_FLOW;
		}

		if (_pCalendar->_meeting == NULL)
		{
			return UNDER_FLOW;
		}
	
		_pCalendar->_sizeAD += _pCalendar->_increaseBlock;
		_pCalendar->*_day = (int*)realloc(_pCalendar->_day, _pCalendar->_sizeAD*sizeof(int));
	}
	
	if (_pCalendar == NULL)
	{
		free(_pCalendar);
		return NULL;
	}
	return DONE;
}

int CheckOverlap (struct AD* _pcalendar)
{	
	int i = 0;
	
	if (_pCalendar->_requestedMeeting->_beginHour => _pCalendar->_day>_beginHour+(_meetingsSoFar-1))
		{	
			_pCalendar->_day->_endHour+(_meetingsSoFar-1);
			return (_meetingsSoFar-1);
		}
		
		while (i < _sizeAD-1)
		{
			if ((_pCalendar->_requestedMeeting->_beginHour <= _pCalendar->_day->_beginHour+i) && (_beginHour<=_endHour+i))
		{		
			RotateToRight(_pCalendar);
			return i;
		}					
			i++;
		}
	else
	{	
		return OVERLAP;
	}
return DONE;
}
			
void RotateToRight(struct Meeting* _pCalendar)
{	
		while (0 < _sizeAD-1)
		{
			_meeting[_sizeAD] = _meeting[sizeAD-1];
			newsize--;
		}
}

void RotateToLeft(struct Meeting* _pCalendar)
{	
		int i = 0;		
		while (0 < _requestedMeeting)
		{
			_meeting[i] = _meeting[i+1];
			newsize++;
		}
}

enum STATUS RemoveNumber(_pCalendar)
{

int _check;

	if (_pCalendar == NULL)
	{
		free(_pCalendar);
		return EMPTY;
	}

	while (i<_index-1)
	{
		RotateToLeft(_pCalendar);	
	}	

	_pCalendar->_meetingsSoFar--;
	return DONE;
	}
	return UNDER_FLOW;	
}	


enum STATUS FindMeeting()
{

	return DONE;
}

enum STATUS PrintDiary(_calendar);
{
	int i;
		
	if (_pCalendar == NULL)
	{
		return NULL_POINTER;
	}

	for (i = 0; i<_calendar->_day->_sizeAD; i++)
	{
		printf("Meeting Num. %d\n", i);		
		printf("Begin Hour: %d", _calendar[i]._day._beginHour);
		printf("End Hour: %d", _calendar[i]._day._endHour);
		printf("Room Num. %d\n", _calendar[i]._day._roomNum);
	}
	return DONE;
}	





