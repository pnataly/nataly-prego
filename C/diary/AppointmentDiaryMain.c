# include <stdio.h>
# include <stdlib.h>
# include "AppointmentDiary.h"

int main ()
{

	int _choice = 0;
	struct AD _calendar;
	struct AD* _pCalendar = &_calendar;
	struct AD* _tempArray;
	int _check;

	while ((_choice>= 1 || _choice <= 8) && (_pCalendar == NULL))
	{
		printf("Welcome!\n Please choose one of the following options:\n");
		printf("(1) Create Appointment Diary\n");
		printf("(2) Create Meeting\n");
		printf("(3) Insert an Appointment into Diary\n");
		printf("(4) Remove an Appointment from Diary\n");
		printf("(5) Find an Appointment in Diary\n");
		printf("(6) Destroy Appointment Diary\n");
		printf("(7) Print Appointment Diary\n");
		printf("(8) Exit\n");
		printf("******\n");
		scanf("%d",&_choice);

		while ((_choice != 1 && _choice !=5) && (_pCalendar == NULL))
		{		
			printf("ERROR! Please create your Appointment Diary first\n");
			printf("Select from menu\n");
			scanf("%d", &_choice);
		}

	switch (_choice)
	{
		case 1:
			/*(1) Create Appointment Diary*/
			printf("\n(1) Create Appointment Diary\n");
		
			printf("\nPlease enter the size of your appointment diary:\n");
			scanf("%d", &_pCalendar->_sizeAD);
			
			_tempArray = CreateAD(_pCalendar->_sizeAD, _pCalendar->_increaseBlock);
			
			if (_tempArray == NULL)
			{
				printf("ERROR! Appointment Diary hasn't been created.\n");	
				break;
			}
			_calendar = *_tempArray;
			PrintDiary(_pCalendar);

			printf("\n");				
			break;
		
		case 2:
			/*(2) Create Meeting*/
			printf("\n(2) Create Meeting\n");

			printf("\nEnter start time:\n");
			scanf("%2f", &_pCalendar->_requestedMeeting->_beginHour);
			printf("\nEnter end time:\n");
			scanf("%2f", &_pCalendar->_requestedMeeting->_endHour);
			printf("\nEnter room number:\n");
			scanf("%d", &_pCalendar->_requestedMeeting->_roomNUm);

			_check = CreateMeeting(_pCalendar);
			
			if (_check == EMPTY)
			{
				printf("ERROR! Please create you Appointment Diary first.\n");
				break;
			}
			else if (_check == OVERLAP)
			{
				printf("ERROR! Meeting cannot be added at this slot.\n");
				break;
			}
			else if (_check == NULL_POINTER)
			{
				printf("ERROR! the meeting hasn't been created.\n");
				break;
			}
	
			printf("The meeting has been added to Appointment Diary successfully.\n");
			PrintDiary(_pCalendar);
			
			_requestedMeeting = NULL;
			
			printf("\n");		
			break;
		
		case 3:
			/*(3) Insert an Appointment into Diary*/						
			printf("\n(3) Insert an Appointment into Diary\n");	
			printf("\nEnter start time:\n");
			scanf("%2f", &_pCalendar->_requestedMeeting->_beginHour);
			printf("\nEnter end time:\n");
			scanf("%2f", &_pCalendar->_requestedMeeting->_endHour);
			printf("\nEnter room number:\n");
			scanf("%d", &_pCalendar->_requestedMeeting->_roomNUm);

			_check = CreateMeeting(_pCalendar);
			
			if (_check == EMPTY)
			{
				printf("ERROR! Please create you Appointment Diary first.\n");
				break;
			}
			else if (_check == OVERLAP)
			{
				printf("ERROR! Meeting cannot be added at this slot.\n");
				break;
			}
			else if (_check == NULL_POINTER)
			{
				printf("ERROR! the meeting hasn't been created.\n");
				break;
			}
	
			printf("The meeting has been added to Appointment Diary successfully.\n");
			PrintDiary(_pCalendar);
			
			_requestedMeeting = NULL;			

			printf("\n");		
			break;
		
		case 4:
			/*(4) Remove an Appointment from Diary*/
			printf("\n(4) Remove an Appointment from Diary\n");

			printf("\nEnter a meeting to delete:\n");
			scanf("%d", &_pCalendar->_day->_index);

			_check = RemoveMeeting(_pCalendar);
			
			if (_check == EMPTY)
			{
				printf("ERROR! Please create you Appointment Diary first.\n");
				break;
			}
			
			else if (_check == UNDER_FLOW)
			{
				printf("ERROR! There are no meetings.\n");
				break;
			}
	
			printf("The meeting has been removed from Appointment Diary successfully.\n");
			PrintDiary(_pCalendar);
			
			_requestedMeeting = NULL;
			
			printf("\n");		
			break;
		
		case 5:
			/*(5) Find an Appointment in Diary*/					
			printf("\n(5) Find an Appointment in Diary\n");
		
			printf("\n");		
			break;
		
		case 6:
			/*(6) Destroy Appointment Diary*/
			
			printf("\n(6) Destroy Appointment Diary\n");
		
			if (_pCalendar == NULL)
			{
				printf("ERROR! Please Create your Appointment Diary first\n");
				break;
			}
			
			Destroy(_pCalendar);
			_pCalendar->_day = NULL;
			printf("\nYour Appointment Diary has been Destroyed.\n");
			
			printf("\n");		
			break;
		
		case 7:
			/*(7) Print Appointment Diary*/
			printf("\n(7) Print Appointment Diary\n");
			PrintDiary(_pCalendar);
			
			printf("\n");		
			break;
		
		case 8:
			/*(8) Exit*/
			printf("\n(8) Exit\n");
			printf("Bye Bye!\n");
			return DONE;

			break;		
		
		default:
			/*Default*/
			printf("\nPlease enter a number between 1-8.\n");
			_choice = 0;
			
			printf("\n");
			break;
		}

	}	
	return DONE;
}
