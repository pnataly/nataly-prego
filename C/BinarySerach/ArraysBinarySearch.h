# include <stdio.h>
# define NOT_FOUND -1
# define ERROR -2
# define DONE 0

/* @Description: Bubble sorting for an array of ints from smallest to largest.
 * @Input Arg: _array[] = an unsorted array.
 * @Input Arg: _size - the size of the array.
 * @Return: int DONE (1)
 * @Error: ERROR (-2)
*/ 

int BubbleSort(int _array[], int _size);

/* @Description: Searching a number in a sorted array of ints.
 * @Input Arg: _array[] = a sorted array of ints.
 * @Input Arg: _size - the size of the array.
 * @Input Arg: _numToSearch -the number to be searched in the array.
 * @Return: int NOT_FOUND (-1) FOUND (index)
 * @Error: ERROR (-2)
*/ 

int BinarySearch(int _array[], int _size, int _numToSearch);

/* @Description: Searching a number in a sorted array of ints.
 * @Input Arg: _array[] = a sorted array of ints.
 * @Input Arg: _size - the size of the array.
 * @Input Arg: _numToSearch -the number to be searched in the array.
 * @Return: int DONE (1)
 * @Error: ERROR (-2)
*/ 
int* CreateArray(int _size, int *_numOfElements);

/* @Description: Adding a new number to the array, and changing the array's size.
 * @Input Arg: _array[] = a pointer to sorted array of ints.
 * @Input Arg: _size - a pointer to the size of the array.
 * @Input Arg: _numToBeAdded -the number to be added in the array (int).
 * @Return: int* _array
 * @Error: ERROR (-2)
*/ 


void* Destroy(int* _array);


int* AddNumber(int **_array, int *_size, int *_numOfElements, int _numToAdd, int increase);

/* @Description: Removing a number from the array, and changing the array's size.
 * @Input Arg: _array[] = a pointer to sorted array of ints.
 * @Input Arg: _size - a pointer to the size of the array.
 * @Input Arg: _numToBeRemoved -the number to be removed from the array (int).
 * @Return: int* _array
 * @Error: ERROR (-2)
*/ 
int* RemoveNumber(int *_array, int* _size, int _search);






