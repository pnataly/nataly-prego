#include "memManager_t.h"
#include "memPage_t.h"
#include "memPool_t.h"
#include <iostream>
using namespace std;

void MM_test(memManager_t* _mem)
{
	size_t cont = 1;
	size_t option;
	size_t pos =0;
	size_t cap, res;
	int i;
	float f;
	while(cont)
	{
		cout << "Choose option: " 				<< endl;
		cout << "1. Get position: " 			<< endl;
		cout << "2. Set position: " 			<< endl;
		cout << "3. Get actual size: " 			<< endl;
		cout << "4. Get default capacity: " 	<< endl;
		cout << "5. Set default capacity: " 	<< endl;
		cout << "6. Get capacity: 	"			<< endl;
		cout << "7. Is empty		"			<< endl;
		cout << "8. Write int: " 				<< endl;
		cout << "9. Write float: " 				<< endl;
		cout << "10. Read int: " 				<< endl;
		cout << "11. Read float: " 				<< endl;
		cout << "Any another number - stop "	 << endl;
		cout << "**************" << endl;
		cout << endl;
		
		cin >> option;
		switch (option)
		{
			case 1:
				cout << "The position: " << _mem->GetPosition() << endl;
				break;
			
			case 2:
				cout << "Enter the new position: " << endl;
				cin>>pos;
				_mem->SetPosition(pos);
				cout << "The new position: " << _mem->GetPosition() << endl;
				break;
			
			case 3:
				cout << "The actual size: " << _mem->GetActualSize() << endl;
				break;
				
			case 4:
				cout << "The default capcity: " << memPage_t::GetDefCapactiy() << endl;
				break;
				
			case 5:
				cout << "Enter new default capacity:" << endl;
				cin>>cap;
				memPage_t::SetDefCapacity(cap);
				break;
				
			case 6:
				cout << "The capacity: " << ((memPage_t*)_mem)->GetCapacity() << endl;
				break;
				
			case 7:
				res = _mem->IsEmpty();
				if (res == 1)
				{
					cout << "Empty" << endl;
					break;
				}
				cout << "Not empty" << endl;
				break;
				
			case 8:
				cout << "Enter int to write: " << endl;
				cin>>i;
				cout << "Enter position: " << endl;
				cin>>pos;
				_mem->Write(&i, sizeof(int), pos); 
				break;
			
			case 9:
				cout << "Enter float to write: " << endl;
				cin>>f;
				cout << "Enter position: " << endl;
				cin>>pos;
				_mem->Write(&f, sizeof(float)); 
				break;
			
			case 10:
				cout << "Enter position: " << endl;
				cin>>pos;
				_mem->Read(&i, pos, sizeof(int)); 
				cout << "The read int: " << i << endl;
				break;
			
			case 11:
				cout << "Enter position: " << endl;
				cin>>pos;
				_mem->Read(&f, pos, sizeof(float)); 
				cout << "The read float: " << f << endl;
				break;
			
			default:
				cont = 0;
				break;
		}
	}
}

int main()
{
	size_t cont = 1;
	size_t option;
	memManager_t* mem =0;
	memPage_t mp;
	memPool_t mpl;
		
	while(cont)
	{
		cout << "Choose option: " 	<< endl;
		cout << "1. Test Pool " 	<< endl;
		cout << "2. Test Page " 	<< endl;
		cout << "Any another number - stop " << endl;
	
		cin>>option;
		switch (option)
		{
			case 1:
				mem = new memPool_t;
				MM_test(mem);
				break;
				
			case 2:
				mem = new memPage_t;
				MM_test(mem);
				break;
		
			default:
				cont = 0;
				break;
		}
	}	
	return 0;
}

