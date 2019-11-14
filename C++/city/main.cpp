#include <iostream>
#include <string>
#include "Building_t.h"
#include "Street_t.h"
#include "City_t.h"


int main()
{

	Building_t<int> b1(3);
	Building_t<int>	b2(10);
	Street_t<int,float>	s1(1.23);
	s1.AddBuilding2Street(&b1);
	s1.AddBuilding2Street(&b2);
	
	City_t<int,float, string> c1("Tel-Aviv");
	c1.AddStreet(&s1);
	
	int res1 = b1.GetBuildingID();
	cout<<"b1 ID: "<<res1<<endl;
	
	res1 = b2.GetBuildingID();
	cout<<"b2 ID: "<<res1<<endl;
	
	b1.SetBuildingID(20);
	res1 = b1.GetBuildingID();
	cout<<"b1 ID: "<<res1<<endl;
	
	float res2 = s1.GetStreetID();
	cout<<"s1 ID: "<<res2<<endl;
	
	res1 = s1.GetBuilding(0)->GetBuildingID();
	cout<<"building ID: "<<res1<<endl;
	
	res1 = s1.GetBuilding(1)->GetBuildingID();
	cout<<"building ID: "<<res1<<endl;
	
	string name = c1.GetCityID();
	cout<<"c1 ID: "<<name<<endl;
	c1.SetCityID("Afula");
	name = c1.GetCityID();
	cout<<"c1 ID: "<<name<<endl;
	
	res2 = c1.GetStreet(0)->GetStreetID();
	cout<<"street id: "<<res2<<endl;
	
	res1 = c1.GetStreet(0)->GetBuilding(0)->GetBuildingID();
	cout<<"building ID: "<<res1<<endl;
	return 0;
}
