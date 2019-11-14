#include <stdio.h>
#include "hash.h"

int main()
{
	Hash* newHash;
	int data;
	int result;
	int choice = 0;
	int size;
	size_t numOfItems, capacity, maxReHash;
	double reHash;


	while (choice != 10)
	{
		printf("*Please choose an option:\n");
		printf("1) Create Hash set\n");
		printf("2) Destroy Hash set\n");
		printf("3) Hash insert\n");
		printf("4) Hash remove\n");
		printf("5) Is data found\n");
		printf("6) number of items\n");
		printf("7) capacity\n");
		printf("8) average Rehash\n");
		printf("9) Max Rehash\n");
		printf("10) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					printf("Please enter intial size: \n");
					scanf("%d", &size);
					newHash = HashCreate(size);
					if(newHash == NULL)
					{
						printf("ERROR- the Hash not created\n");
						printf("\n");	
						break;
					}
					printf("The Hash is created.\n");
					printf("\n");	
					break;

			case 2:
					if(newHash == NULL)
					{
						printf("ERROR- the Hash not created\n");
						printf("\n");	
						break;
					}
					HashDestroy(newHash);
					newHash = NULL;
					printf("The Hash has been Destroyed.\n");
					printf("\n");		
					break;

			case 3:
					printf("Please enter a data to insert: \n");
					scanf("%d", &data);
					result = HashInsert(newHash, data);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("Please create a Hash first\n");
						break;
					}
					if(result == ERR_OVERFLOW)
					{
						printf("The Hash is full\n");
						break;
					}
					if(result == ERR_DUP_DATA)
					{
						printf("The data alreday in the Hash\n");
						break;
					}
					printf("The data is added.\n");
					HashPrint(newHash);
					printf("\n");		
					break;

			case 4:
					printf("Please enter a data to remove: \n");
					scanf("%d", &data);
					result = HashRemove(newHash, data);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("Please create a Hash first\n");
						break;
					}
					if(result == ERR_UNDERFLOW)
					{
						printf("The Hash is empty\n");
						break;
					}
					if(result == ERR_ITEM_NOT_FOUND)
					{
						printf("The item not found\n");
						break;
					}
					printf("The data is removed\n");
					HashPrint(newHash);
					printf("\n");		
					break;

			case 5:
					printf("Please enter a data to find: \n");
					scanf("%d", &data);
					result = HashIsFound(newHash, data);
					if(result)
					{
						printf("The data is found\n");
						printf("\n");		
						break;
					}
					printf("The data not found\n");
					printf("\n");		
					break;

			case 6:
					numOfItems = HashNumOfItems(newHash);
					printf("There is %lu items in the Hash\n", numOfItems);
					printf("\n");		
					break;

			case 7:
					capacity = HashCapacity(newHash);
					if(capacity == 0)
					{
						printf("Please create a Hash first\n");
						break;
					}
					printf("The capacity of the Hash is: %lu\n", capacity);
					printf("\n");		
					break;

			case 8:
					reHash = HashAverageRehashes(newHash);
					if(reHash == -1)
					{
						printf("Please create a Hash first\n");
						break;
					}
					if(reHash == 0)
					{
						printf("The Hash is empty\n");
						break;
					}
					printf("The average is: %f", reHash);
					printf("\n");		
					break;

			case 9:
					maxReHash = HashMaxReHash(newHash);
					printf("The max reHash is: %lu", maxReHash);
					printf("\n");		
					break;

			case 10:
					printf("* Exit *\n");
					return 0;
		
			default:
					printf("Please enter a number between 1-10.\n");
					printf("\n");	
					choice = 0;
					break;

		}
	}

	return 0;
}
