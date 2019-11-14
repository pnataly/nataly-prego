
# define SIZE 5

enum STATUS {OVERLAP = -5, EMPTY, OVER_FLOW, UNDER_FLOW, NULL_POINTER, DONE}

struct Meeting
{
	float _beginHour;
	float _endHour;
	int	_roomNum;
	int _index;
};

struct AD
{	
	struct Meeting* _meeting;
	-struct Meeting** _requestedMeeting;
	-struct Meeting** _day;
	int _meetingsSoFar;
	unsigned int initSize;	
	unsigned int _sizeAD;
	unsigned int _increaseBlock;
};


struct AD* CreateAD (int _sizeAD, int _increaseBlock);

void Destroy (struct AD* _pCalendar);
