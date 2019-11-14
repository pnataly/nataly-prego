#include <stdio.h>
#include <iostream>
#include "string_t.h"
using namespace std;


int main()
{
	int res, len;
	size_t cap; 
	const char* string;
	string_t s1;
	cap = s1.GetDefCapactiy();
	cout<<"the capacity: "<<cap<<"\n";
	cin>>s1;
	cout<<s1;
	
	string_t s2("hello");
	string_t s3(s2);
	s1=s2;
	printf("s1 ");
	cout<<s1;
	
	len = s1.GetLenth();
	printf("len: %d\n", len);
	
	printf("s2 ");
	cout<<s2;
	printf("s3 ");
	cout<<s3;
	
	string = s3.GetString();
	printf("get string: %s\n", string);
	
	s1.SetString("nataly");
	s1.Upper();
	cout<<"s1 "<<s1;
	s1.Lower();
	cout<<"s1 "<<s1;
	
	s1 += s2;
	cout<<"s1 "<<s1;
	
	s3 += "world";
	cout<<"s3 "<<s3;
	
	s1.prepend(s2);
	cout<<"s1 "<<s1;
	
	s3.prepend("world");
	cout<<"s3 "<<s3;
	
	res = s1.contain("ata");
	cout<<"res: "<<res << "\n";
	
	res = s1.compare("prego");
	printf("res: %d\n", res);
	
	string_t s4("c");
	string_t s5("c++");
	res = s4 == s5;
	cout<<"res: "<<res<<"\n";
	
	res = s4 != s5;
	cout<<"res: "<<res<<"\n";
	
	res = s4 > s5;
	cout<<"res: "<<res<<"\n";
	
	res = s4 < s5;
	cout<<"res: "<<res<<"\n";
	
	res = s4 <= s5;
	cout<<"res: "<<res<<"\n";
	
	s4.SetString("c++");
	res = s4 >= s5;
	cout<<"res: "<<res<<"\n";
	
	char c = s4.GetString()[2];
	cout<<c<<"\n";
	
	c = s3.GetString()[7];
	cout<<c<<"\n";	
	
	res = s1.FirstOccurrence('h');
	cout<<"The index of first occurence: "<<res<<"\n";	

	res = s1.LastOccurrence('h');
	cout<<"The index of last occurence: "<<res<<"\n";	
	
	cap = string_t:: GetDefCapactiy();
	cout<<"The capacity: "<<cap<<"\n";	
	
	int caseSense = string_t:: GetCaseSens();
	cout<<"The flag: "<<caseSense<<"\n";
	
	string_t s6("HeLLo");
	cap = s6.GetCapactiy();
	cout<<"the capacity: "<<cap<<"\n";
	res = s6==s2;
	cout<<"res for flag 1: "<<res<<"\n";
	
	
	string_t::SetCaseSens(false);
	res = s6==s2;
	cout<<"res for flag 0: "<<res<<"\n";
	cout<<s3;
	string_t s7 = s3(0,5);
	cout<<"the substring: "<<s7.GetString()<<"\n";
	return 0;
}
