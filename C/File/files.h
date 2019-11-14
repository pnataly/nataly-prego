#ifndef _FILES_H
#define _FILES_H


/* @Description: read from a file and prints the last N lines.
 * @Input: _name - the name of the file we want to read.
 * @Input: _numOfNLines - the number of the last line to print.
 * @Return: void.
*/ 
void ReadNLines(const char* _name, int _numOfNLines);

/* @Description: read from a file and print the frequency of each character int the file.
 * @Input: _name - the name of the file we want to read.
 * @Return: void.
*/ 
void CountLetters(const char* _name);


/* @Description: read from a file and print the frequency of each word int the file.
 * @Input: _name - the name of the file we want to read.
 * @Return: void.
*/ 
int CountWords(const char* _name);

#endif /*_FILES_H*/ 
