#ifndef _RECURSIA_H
#define _RECURSIA_H


/* @Description: reverse string.
 * @Input: _str- pointer to the char of string.
 * @Input: start - index of start array.
*/ 
void ReverseString(char* str, int start);

/* @Description: check if the string is palindrom.
 * @Input: str- pointer to the string.
 * @Return - True if the string is palindrom or empty and else return FALSE. 
*/ 
int IsPolindrom(char* str);

/* @Description: calculate the average of the array.
 * @Input: array- pointer to array of int.
 * @Input: size- the size of the array.
 * @Input: start - index of start array.
*/ 
int average(int array[], int start, int size);






#endif /*_RECURSIA_H*/ 
