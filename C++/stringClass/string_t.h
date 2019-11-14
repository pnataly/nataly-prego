#ifndef __STRING_T_H__
#define __STRING_T_H__

#include <string.h>
#include <iostream>
using namespace std;

class string_t
{
	public:
		string_t(){createFrom(NULL);}							//default CTOR.
		string_t(const char* str){createFrom(str);}				//CTOR from const char*.
		string_t(const string_t&st){createFrom(st.my_string);}	//copy CTOR.
		~string_t(){delete[] my_string;}						//DTOR.
		
		string_t& operator=(const string_t&st);					//assignment operator.
		string_t& operator+=(const string_t&st);				//Addition assignment operator.
		string_t& operator+=(const char* str);					//Addition assignment operator.
		bool operator==(const string_t&st) const;				//compare operator.
		bool operator!=(const string_t&st) const;				//compare operator.
		bool operator>(const string_t&st) const;				//Greater than operator.
		bool operator>=(const string_t&st) const;				//Greater than or equal to operator.
		bool operator<(const string_t&st) const;				//Less than operator.
		bool operator<=(const string_t&st) const;				//Less than or equal to operator.
		const char& operator[](size_t index) const;				//Subscript operator. (get)	
		char& operator[](size_t index);							//Subscript operator.  (set)
		string_t operator()(size_t start, size_t len) const;
		
		string_t& prepend(const string_t&st);
		string_t& prepend(const char* str);
		string_t& Upper();
		string_t& Lower();
		
		
		int FirstOccurrence(char str) const;				//returns index of first occurrence of some character in the object string.
		int LastOccurrence(char str) const;					//returns index of last occurrence of some character in string.
		int compare(const char* str) const;					//compare function which compares 2 strings- the object string and the paramter string.
		bool contain(const char* str) const;				//check if the substring is found in the object string.
		
		size_t GetCapactiy(){return m_capacity;}
		int GetLenth() const; 						
		void SetString(const char* str);			
		const char* GetString() const {return my_string;}				
		void Print() const {printf("The string: %s\n", my_string);}		
						
		static size_t GetDefCapactiy() {return s_capacity;}
		static void SetDefCapactiy(size_t cap) {s_capacity = cap;}
		static int GetCaseSens() {return s_caseSens;}
		static void SetCaseSens(bool num) {s_caseSens = num;}
		
	private:
		static size_t s_capacity;
		static bool s_caseSens;
		char* my_string;
		size_t m_capacity;
		void createFrom(const char* str);
		size_t nextPowerOf2(size_t n);
};	

inline const char& string_t:: operator[](size_t index) const
{	
	int len = strlen(my_string);
	if(index > len)
	{
		return my_string[len];
	}
	return my_string[index];
}

inline char& string_t:: operator[](size_t index)		
{
	int len = strlen(my_string);
	if(index > len)
	{
		return my_string[len];
	}
	return my_string[index];
}

inline ostream& operator<< (ostream& os, const string_t& st) 			//left-shift operator.
{
	os << "The String: "<< st.GetString() << "\n";
	return os;
}

inline istream& operator>> (istream&is, string_t& st) 					//right-shift operator.
{
	char str[1024];
	is >> str;
	st.SetString(str);
	return is;
}



#endif /*__STRING_T_H__*/ 

