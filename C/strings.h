#ifndef _STRINGS_H
#define _STRINGS_H


/* @Description: return the length of the string.
 * @Input: _str -
 * @Return:  The length of _str. 
*/ 
size_t StrLen(const char* _str);

/* @Description: return the length of the string with recursion.
 * @Input: _str -
 * @Return:  The length of _str. 
*/ 
size_t StrLenRec(const char* _str);


/* @Description: Comparing the characters of each string.
 * @Input: _s1- the first string to be compare.
 * @Input: _s2- the second string to be compare.
 * @Return: 0 - if the strings are equal.
 * 	   >0 - if the contents of the first string is higher.
 *	   <0 - if the contents of the second string is higher.
 * 		-1 - if one of the strings is NULL.
*/ 
int StrCompare(const char* _s1, const char* _s2);

/* @Description: Comparing the characters of each string with recursion.
 * @Input: _s1- the first string to be compare.
 * @Input: _s2- the second string to be compare.
 * @Return: 0 - if the strings are equal.
 * 	   >0 - if the contents of the first string is higher.
 *	   <0 - if the contents of the second string is higher.
 * 		-1 - if one of the strings is NULL.
*/ 
int StrCompareRec(const char* _s1, const char* _s2);

/* @Description: Copies the string source into the destination.
 * @Input: _destination -the destination string where the source is to be copied.
 * @Input: _source - the string to be copied.
 * @Return: pointer to the destination.
*/ 
char* StrCopy(char* _destination, const char* _source);

/* @Description: Copies the string source into the destination with recursion.
 * @Input: _destination -the destination string where the source is to be copied.
 * @Input: _source - the string to be copied.
 * @Return: pointer to the destination.
*/ 
char* StrCopyRec(char* _destination, const char* _source);

/* @Description: Copies the string source into the destination.
 * @Input: _destination - the destination string where the source is to be copied.
 * @Input: _source - the string to be copied.
 * @Input: _num - the number of characters to be copied from source.
 * @Return: pointer to the destination.
*/ 
char* StrNCopy(char* _destination, const char* _source, size_t _num);

/* @Description: Copies the string source into the destination with recursion.
 * @Input: _destination - the destination string where the source is to be copied.
 * @Input: _source - the string to be copied.
 * @Input: _num - the number of characters to be copied from source.
 * @Return: pointer to the destination.
*/ 
char* StrNCopyRec(char* _destination, const char* _source, size_t _num);

/* @Description: Appends a copy of the source string to the end of the destination string
 * @Input: _destination - the destination string where the source is to be copied.
 * @Input: _source - the string to be copied.
 * @Return: pointer to the destination.
*/ 
char* StrConcat(char* _destination, const char* _source);

/* @Description: 
 * @Input: _str - the string that scanned.
 * @Input: _search -the string containing the sequence of characters to match.
 * @Return: pointer to the first occurrence of string search in str,  or a null pointer if the sequence is not present in str1.
*/ 
char* StrSubString(const char* _str, const char* _search);

#endif /*_STRINGS_H*/ 
