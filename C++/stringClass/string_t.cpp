#include <string.h>
#include <stdio.h>
#include <iostream>
#include "string_t.h"
using namespace std;

size_t string_t:: s_capacity = 64;
bool string_t:: s_caseSens = true;

size_t string_t:: nextPowerOf2(size_t n)
{
	n--;
	while (n&n-1)
	{
		n = n&n-1;	
	}
	return n << 1;
}

void string_t:: createFrom(const char* str)
{
	if(str == NULL)
	{
			my_string = new char[s_capacity];
			m_capacity = s_capacity;
			my_string[0] = '\0';
	}
	else
	{
		int len = nextPowerOf2(strlen(str)+1);
		my_string = new char(len); 
		m_capacity = len;
		strcpy(my_string, str);
	}
}



string_t& string_t:: operator=(const string_t&st)
{
	if(this != &st)
	{
		delete[]my_string;
		createFrom(st.my_string);
	}
	return *this;
}


string_t& string_t:: operator+=(const char* str)
{
	if(str)
	{
		int len = strlen(str) + strlen(my_string);
		char* temp = new char[len];
		strcpy(temp, my_string);
		strcat(temp, " ");
		strcat(temp, str);
		delete[]my_string;
		createFrom(temp);
		delete[]temp;
	}
	return *this;
}

string_t& string_t:: operator+=(const string_t&st)
{
	return operator+=(st.my_string);
}


bool string_t:: operator==(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) == 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) == 0?true:false;
}


bool string_t:: operator!=(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) != 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) != 0?true:false;
}

bool string_t:: operator>(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) > 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) > 0?true:false;
}

bool string_t:: operator>=(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) >= 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) >= 0?true:false;
}


bool string_t:: operator<(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) < 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) < 0?true:false;
}

bool string_t:: operator<=(const string_t&st) const
{
	if(s_caseSens)
	{
		return strcmp(my_string, st.my_string) <= 0?true:false;
	}
	return strcasecmp(my_string, st.my_string) <= 0?true:false;
}

string_t& string_t:: prepend(const char* str)
{
	int len = strlen(str) + strlen(my_string);
	char* temp = new char[len];
	strcpy(temp, str);
	strcat(temp, " ");
	strcat(temp, my_string);
	delete[]my_string;
	createFrom(temp);
	delete[]temp;
	return *this;
}

string_t& string_t:: prepend(const string_t&st)
{
	return prepend(st.my_string);
}

int string_t:: GetLenth() const
{
	return strlen(my_string);
}

void string_t::SetString(const char* str)
{
	if(str)
	{
		delete[]my_string;
		createFrom(str);
	}
}

int string_t:: compare(const char* str) const
{
	int res;
	if(str)
	{
		res = strcmp(this->my_string, str);
		if(res == 0)
		{
			return 0;
		}
		else if(res<0)
		{
			return 1; 	//if the object string less than parameter
		}
		else
		{
			return 2;	//if the object string greater than parameter
		}
	}
	return -1;
}

string_t& string_t:: Upper()
{
	int len = strlen(my_string);
	for(int i=0; i<len; i++)
	{
		char c = my_string[i];
		my_string[i] = toupper(c);
	}
	return *this;
}

string_t& string_t:: Lower()
{
	int len = this->GetLenth();
	for(int i=0; i<len; i++)
	{
		char c = my_string[i];
		my_string[i] = tolower(c);
	}
	return *this;
}


bool string_t:: contain(const char* str) const
{
	if(str)
	{
		char* res = strstr(my_string, str);
		if(res)
		{
		    return true;
		}
	}
	return false;
}


int string_t::FirstOccurrence(const char str) const
{
	char* pch;
	if(str)
	{
		pch = strchr(my_string, str);
	}
	return pch-my_string;
}

int string_t::LastOccurrence(const char str) const
{
	char* pch;
	if(str)
	{
		pch = strrchr(my_string, str);
	}
	return pch-my_string;
}

string_t string_t:: operator()(size_t start, size_t len) const
{
	char* temp = new char[len+1];
	int length = strlen(my_string);
	if(start+len > length)
	{
		string_t str;
		return str;
	}
	for(size_t i=start; i<start+len; i++)
	{
		temp[i-start] = my_string[i];
	}
	string_t str(temp);
	strcpy(str.my_string, temp);
	delete[]temp;
	return str;
}

