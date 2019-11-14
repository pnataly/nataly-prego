#include "car_t.h"
#include "bus_t.h"
#include "private_t.h"
#include <string>
#include <iostream>


int main()
{
	int cont = 1;			
	unsigned int option;
	bus_t bus;
	bus_t bus2(1000,100,15);
	private_t prv;
	private_t prv2(2500, 15, 15);
	size_t id, cap, seat, line, acc, spd;
	string name;
	car_t::GearType_e gr;
	bool res;
	while (cont) 
	{
		cout << "Choose option: " << endl;
		cout << "****************" << endl;
		cout << "1: Get ID" << endl;
		cout << "2: Get Name" << endl;
		cout << "3: Get Gear Type" << endl;
		cout << "4: Get capacity" << endl;
		cout << "5: Get default capacity" << endl;
		cout << "6: operator <  " << endl;
		cout << "7: operator =  " << endl;
		cout << "8: Compare function" << endl;
		cout << "9: Get number of seats" << endl;
		cout << "10: Set number of seats" << endl;
		cout << "11: Get line" << endl;
		cout << "12: Set line" << endl;
		cout << "13: Get accelerate" << endl;
		cout << "14: Set accelerate" << endl;
		cout << "15: Get reduce speed" << endl;
		cout << "16: Set reduce speed" << endl;
		cout << "Any another number - stop" << endl;
		cout << endl;
		cin >>  option;
		switch (option) 
		{
			case 1:
				id = bus.GetId();
				cout<<"The bus id: "<<id<<endl;
				id = prv.GetId();
				cout<<"The private id: "<<id<<endl;
				id = bus2.GetId();
				cout<<"The bus id: "<<id<<endl;
				break;
				
			case 2:
				name =bus.GetName();
				cout<<"The bus name: "<<name<<endl;
				name = prv.GetName();
				cout<<"The private name: "<<name<<endl;
				break;
				
			case 3:
				gr =bus.GetGearType();
				cout<<"The bus gear type: "<<gr<<endl;
				gr = prv.GetGearType();
				cout<<"The private gear type: "<<gr<<endl;
				break;
				
			case 4:
				cap = bus.GetCapacity();
				cout<<"The bus capacity: "<<cap<<endl;
				cap = prv.GetCapacity();
				cout<<"The private capacity: "<<cap<<endl;
				cap = prv2.GetCapacity();
				cout<<"The private capacity: "<<cap<<endl;
				break;
				
			case 5:
				cap = car_t::GetDefCapactiy();
				cout<<"The default capacity: "<<cap<<endl;
				break;
			
			case 6:
				res = bus < prv;
				if(res == 0)
				{
					cout<<"the bus is not less then privte "<<endl;
					break;
				}
				cout<<"the bus is less then privte "<<endl;
				break;
				
			case 7:
				cap = prv.GetCapacity();
				cout<<"before. The private capacity: "<<cap<<endl;
				prv = prv2;
				cap = prv.GetCapacity();
				cout<<"after. The private capacity: "<<cap<<endl;
				break;

			case 8:
				res = bus.Compare(bus2);
				if(res == 0)
				{
					cout<<"the sampe type"<<endl;
				}
				else
				{
					cout<<"not the sampe type "<<endl;
				}
				
				res = bus.Compare(prv);
				if(res == 0)
				{
					cout<<"the sampe type"<<endl;
					break;
				}
				cout<<"not the sampe type "<<endl;
				break;

			case 9:
				seat = bus.GetNumOfSeats();
				cout<<"Number of seats: "<<seat<<endl;
				seat = bus2.GetNumOfSeats();
				cout<<"Number of seats: "<<seat<<endl;
				break;
				
			case 10:
				seat = bus.GetNumOfSeats();
				cout<<"Number of seats: "<<seat<<endl;
				bus.SetNumOfSeats(67);
				seat = bus.GetNumOfSeats();
				cout<<"after set. the number of seats: "<<seat<<endl;
				break;
				
			case 11:
				line = bus.GetLine();
				cout<<"line number: "<<line<<endl;
				line = bus2.GetLine();
				cout<<"line number: "<<line<<endl;
				break;
				
			case 12:
				line = bus.GetLine();
				cout<<"line number: "<<line<<endl;
				bus.SetLine(870);
				seat = bus.GetLine();
				cout<<"after set. line number: "<<seat<<endl;
				break;
				
			case 13:
				acc = prv.GetAccelerate();
				cout<<"the accelerate: "<<acc<<endl;
				acc = prv2.GetAccelerate();
				cout<<"the accelerate: "<<acc<<endl;
				break;
				
			case 14:
				acc = prv.GetAccelerate();
				cout<<"the accelerate: "<<acc<<endl;
				prv.SetAccelerate(20);
				acc = prv.GetAccelerate();
				cout<<"after set. the accelerate: "<<acc<<endl;
				break;
				
			case 15:
				spd = prv.GetReduceSpeed();
				cout<<"the reduce speed: "<<spd<<endl;
				spd = prv2.GetReduceSpeed();
				cout<<"the reduce speed: "<<spd<<endl;
				break;
				
			case 16:
				spd = prv.GetReduceSpeed();
				cout<<"the reduce speed: "<<spd<<endl;
				prv.SetReduceSpeed(20);
				spd = prv.GetReduceSpeed();
				cout<<"after set. the reduce speed: "<<spd<<endl;
				break;
				
			default: cont = 0;	break;
		}
	}

	return 0;
}
