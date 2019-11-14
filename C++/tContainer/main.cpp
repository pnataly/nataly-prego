#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "tContainer_t.h"


using namespace std;

int main()
{
	int x = 5;
	int y = 6;
	tContainer_t<T,vector > con1;
	tContainer_t<T,list >  con2;
		
	con1.Insert(&x);
	con1.Insert(&y);
	cout << *(con1.GetFirstElem()) << endl;
	cout << *(con1.GetLastElem()) << endl;
	cout << "The number of element in vector: " << con1.NumOfElem() << endl;
	cout << con1.IsEmpty() << endl;

//	cout << *(con1[3]) << endl;
	con1.DeleteAll();
//	iArr.RemoveAllElem();
	cout << "The number of element in vector: " << con1.NumOfElem() << endl;
	cout << con1.IsEmpty() << endl;
	
	con2.Insert(&y);
	con2.Insert(&x);
	cout << "The number of element in list: " << con2.NumOfElem() << endl;
//	cout << *(con2[0]) << endl;
	cout << *(con2.FindElem(x)) << endl;
	con2.DeleteElem(x);
	cout << "The number of element in list: " << con2.NumOfElem() << endl;
	cout << *(con2[0]) << endl;
	return 0;
}
