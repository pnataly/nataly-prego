#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstring>
#include <cwchar>
#include "Buffer.h"

namespace advcpp {

template<class T>
class Util 
{

};


template<>
class Util<char> 
{
public:
	static int Compare(const char* a, const char* b); 
	static size_t Size(const char* str);	
	static char* ToUpper(char* str);
	static long ToLong(const char* str);
private:
	~Util();	
};




size_t Util<char>::Size(const char* str)
{
	return strlen(str);
}

int Util<char>::Compare(const char* a, const char* b)
{
	return strcmp(a, b);
}

char* Util<char>::ToUpper(char* str)
{
	size_t len = strlen(str);
	for(size_t i =0; i<len; ++i)
	{
		str[i] = (char)toupper(str[i]);
	}
	return str;
}

long Util<char>::ToLong(const char* str)
{
	return atol(str);	
}







template<>
class Util<wchar_t> 
{
public:
	static int Compare(const wchar_t* a, const wchar_t* b); 
	static size_t Size(const wchar_t* str);	
	static wchar_t* ToUpper(wchar_t* str);
	static long ToLong(const wchar_t* str);
private:
	~Util();	
};




size_t Util<wchar_t>::Size(const wchar_t* str)
{
	return wcslen(str);
}

int Util<wchar_t>::Compare(const wchar_t* a, const wchar_t* b)
{
	return wcscmp(a, b);
}


wchar_t* Util<wchar_t>::ToUpper(wchar_t* str)
{
	size_t len = wcslen(str);
	for(size_t i =0; i<len; ++i)
	{
		str[i] = (wchar_t)towupper(str[i]);
	}
	return str;
} 

long Util<wchar_t>::ToLong(const wchar_t* str)
{
	size_t len = wcslen(str);
	wchar_t* end = (wchar_t*)str+len;
	return wcstol(str, &end, 10);	
} 

}

#endif /*UTIL_H*/ 

