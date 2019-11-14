# include <stdio.h>
# include <stdlib.h>
# include "ArraysBinarySearch.h"

int main()
{
	int _size;
	int *_tempArray;
	int *_array;
	int _userNum;
	int *_newArray;
	int _numToBeAdded;
	int _numToBeRemoved;
	int _result;
	int _numOfElements;
	int increase;


	printf("Choose from the following options:\n");
	printf("1. Create\n");
	printf("2. Destroy\n");
	printf("3. Add\n");
	printf("4. Remove\n");
	printf("5. Exit\n");
	scanf("%d\n", &_userNum);
	
	while ((_userNum >= 1) || (_userNum <= 6))
	{
		switch (_userNum)
		{
		
		case 1:

			/*Creating a new array*/
			printf("1. Create:\n");

			printf("Type the size of the array:\n");
			scanf("%d\n", &_size);
			_tempArray = CreateArray(_size, &_numOfElements);
				
			if(_tempArray == NULL)
			{
				printf("NULL ERROR");
			}
			else
			{
				_array = _tempArray;
			}
			printf("\n");
			break;	

		case 2:
		
			/*Destory the array*/
			printf("2. Destroys:\n");
			if(_array == NULL)
			{
				printf("Error\n);
			}
			else
			{
			Destroy(_array);
			printf("The array is destroed\n");
			}
			break;

		case 3:
			/*Adding a number to the array*/ 
			printf("3. Add:\n");	
			increase = 5;
			if(_array == NULL)
			{
				printf("Type the size of the array:\n");
				scanf("%d\n", &_size);
				_tempArray = CreateArray(_size, &_numOfElements);	
				_array = _tempArray;
				if(_array == NULL)
				{
					printf("error NULL);
				}
			}
			printf("enter a number to add: ");
			scanf("%d", &_numToAdd);
			_result;_=AddNumber(int **_array, int *_size, int *_numOfElements, int _numToAdd, int increase);
			if(_result != 0)
			{
				printf("Error\n");
			}
			

			printf("\n");
			break;
			
		case 4:
			/*Removing a number to the array
			printf("4. Remove:\n");	

			if (!_array)
			{
				printf("Type the size of the array:\n");
				scanf("%d\n", &_size);
				_array = CreateArray(_size);	
			}
				
			printf("Type a number to be removed from the array:\n");		
			scanf("%d", &_numToBeRemoved);
			
			_search = BinarySearch(_array,_size,_numToBeRemoved);
		
			if (_search==-1)
			{
				printf("Number wasn't found in the array.\n");
			}
			else
			{	
				_newArray = RemoveNumber(_array, &_size, _search);
				_array = _newArray;
			}
					

			printf("\n");
			break;	
	*/
		case 5:
			/*Exit*/
			printf("5. Exit:\n");
			return 0;

		}	
	}		
return 0;	

}
