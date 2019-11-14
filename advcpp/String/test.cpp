#include <iostream>
#include "String.h"
#include "mu_test.h"

using namespace advcpp;

UNIT(char_test)	
	String<char> s("hi");
	std::cout<<"s: "<<s<<'\n';
	String<char> s1("c++");
	std::cout<<"s1: "<<s1<<'\n';
	String<char> s2(s1);
	std::cout<<"s2: "<<s2<<'\n';
	
	ASSERT_THAT(s1 == s2);	
	ASSERT_THAT(s != s1);	
	ASSERT_THAT(s1 >= s2);	
	ASSERT_THAT(s1 <= s2);	
	ASSERT_THAT(s > s2);
	ASSERT_THAT(s1 < s);

	s1 = s;
	std::cout<<"s1 after assigment: "<<s1<<'\n';
	std::cout<<"s: "<<s<<'\n';
	ASSERT_THAT(s1 == s);
	ASSERT_THAT(s2 != s1);
	s1 += s2;
	std::cout<<"s1 after +=: "<<s1<<'\n';
	
	String<char> s3("lol");
	s3 = s+s2;
	std::cout<<"s3 after operator +: "<<s3<<'\n';
//	ASSERT_THAT(*s1[0] == 'h');		

//	s1[0] = 'g';
//	ASSERT_THAT(s1[0] == 'g');	
//	std::cout<<"s1: "<<s1<<'\n';
	
/*	ASSERT_THAT(s2<s1);
	ASSERT_THAT(s1>s2);
	
	ASSERT_THAT(s1!=s2);	
	s1[0] = 'C';
	ASSERT_THAT(s2<=s1);
	ASSERT_THAT(s1 >= s2);

	const String<char> s3("hello");
	const char c  = s3[0];
//	std::cout<<c<<'\n';
	ASSERT_THAT(c == 'h');	

	advcpp::String<char> s4("hey");
//	s4 = s3 + s2;
//	std::cout<<s4<<'\n';
	s1+=s2;
//	std::cout<<s1<<'\n'; 
//	String<char> ch;
//	std::cin>>ch;
//	std::cout<<ch.GetString()<<'\n'; */
	
END_UNIT

/*
UNIT(wchar_test)
	String<wchar_t> s(L"hello");
	std::cout<<"s: "<<s<<'\n';
	String<wchar_t> s1(L"c++");
	std::cout<<"s1: "<<s1<<'\n';
	String<wchar_t> s2(s1);
	std::cout<<"s2: "<<s2<<'\n';

	
	ASSERT_THAT(s1 == s2);	
	ASSERT_THAT(s != s1);	
	ASSERT_THAT(s1 >= s2);	
	ASSERT_THAT(s1 <= s2);	
	ASSERT_THAT(s > s2);
	ASSERT_THAT(s1 < s);

	s1 = s;
	std::cout<<"s1 after assigment: "<<s1<<'\n';
	std::cout<<"s: "<<s<<'\n';
	ASSERT_THAT(s1 == s);
	ASSERT_THAT(s2 != s1);	
END_UNIT */


TEST_SUITE(C Unit Test Demo for mu_test!)
	TEST(char_test)
//	TEST(wchar_test)
END_SUITE

