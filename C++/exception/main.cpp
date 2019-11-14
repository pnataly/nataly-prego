#include <iostream>
#include "TException_t.h"

using namespace std;

int main()
{
	int x= 13;
	try
	{
		throw TException_t<int> (13, __FILE__, __LINE__, "catch");
	} 
	catch (TException_t<int>& ex)
	{
		int data = ex.GetData();
		cout << ex << endl;
	}
	return 0;
}
