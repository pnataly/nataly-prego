#include <stdio.h>
#include <stdlib.h>
#include "Bit.h"

int main()
{
	size_t _NumOfFeatures;
	size_t _bit;
	int choice = 0;
	char decToBinary[9];
	BitMap* _newBitMap;
	_newBitMap = NULL;
	DecimalToBinary(8, decToBinary);

	while (choice != 6)
	{
		printf("*Please choose an option:\n");
		printf("1) Create BitMaps\n");
		printf("2) Destroy BitMaps\n");
		printf("3) Bit On\n");
		printf("4) Bit Off\n");
		printf("5) Is Bit ON OR OFF\n");
		printf("6) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:

				printf("Please enter number of features\n");
				scanf("%lu", &_NumOfFeatures);

				_newBitMap = CreateBitMap(_NumOfFeatures);
				if(_newBitMap == NULL)
				{
					printf("NULL ERROR- BitMap not created\n");
					break;
				}
				printf("The BitMap is created.\n");
				printf("\n");	
				break;

			case 2:
				if(_newBitMap == NULL)
				{
					printf("ERROR - please create a BitMap first\n");
					printf("\n");	
					break;
				}
			
				DestroyBitMap(_newBitMap);
				_newBitMap = NULL;
				printf("Your BitMap has been Destroyed.\n");
				printf("\n");		
				break;
			
			case 3:
				printf("Enter a Bit number:\n");
				scanf("%lu", &_bit);
				if((BitOn(_newBitMap, _bit)) == 1)
				{
					printf("The bit is on\n");
					printf("\n");		
					break;
				}
				printf("Error- the bit is off\n");
				printf("\n");		
				break; 

			case 4:
				printf("Enter a Bit number:\n");
				scanf("%lu", &_bit);
				if((BitOff(_newBitMap, _bit)) == 1)
				{
					printf("The bit is on\n");
					printf("\n");		
					break;
				}
				printf("Error- the bit is off\n");
				printf("\n");		
				break;

			case 5:


			case 6:
				printf("* Exit *\n");
				return 0;
		
			default:
				printf("Please enter a number between 1-6.\n");
				printf("\n");	
				choice = 0;
						
				printf("\n");
				break;

		}
	}

	return 0;
}
