#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main()
{
	int choice = 0;
	int Number_of_col;
	sql::Driver* driver;
	driver = get_driver_instance();

	sql::Connection* con;
	con = driver->connect("localhost", "nataly", "Mn120517");
	con->setSchema("vet");

	sql::Statement* sts;
	sts = con->createStatement();
	
	sql::ResultSet* res;

	while (choice != 9)
	{
		cout << "Please choose an option:" << endl;
		cout << "1) Add Owner" << endl;
		cout << "2) Delete Owner" << endl;
		cout << "3) Update Owner" << endl;
		cout << "4) Search Owner" << endl;
		cout << "5) Add Pet" << endl;	
		cout << "6) Delete Pet" << endl;
		cout << "7) Update Pet" << endl;
		cout << "8) Search Pet" << endl;
		cout << "9) Exit" << endl;
		cout << "********************" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			
			/*	int id;
				char name[20];
				char phone[9];
				cout << "please enter id: " << endl;
				cin >> id;
				cout << "please enter name: " << endl;
				cin >> name;
				cout << "please enter phone: " << endl;
				cin >> phone;	*/
				sts->execute("INSERT INTO vet.owners VALUES (5, 'Matan', '050-99999')");
				res = sts->executeQuery("SELECT * FROM vet.owners");

				Number_of_col = res->getMetaData()->getColumnCount();
		
				while(res->next())
				{
					cout << "*";
					cout << res->getRow() <<".";
					for(int i =1; i<=Number_of_col; ++i)
					{
						cout << " " <<res->getString(i);
					}
					cout << "*" << endl;
				}
				break;
			
			case 2:
				//int id;
				//cout << "Enter the id to delete: " << endl;
				//cin >> id;
				sts->execute("DELETE FROM vet.owners WHERE Id = 2");
				res = sts->executeQuery("SELECT * FROM vet.owners");
				Number_of_col = res->getMetaData()->getColumnCount();
		
				while(res->next())
				{
					cout << "*";
					cout << res->getRow() <<".";
					for(int i =1; i<=Number_of_col; ++i)
					{
						cout << " " <<res->getString(i);
					}
					cout << "*" << endl;
				}
				break;
			
			case 4:
				res = sts->executeQuery("SELECT Name from vet.owners where Name like 'Matan'");
				Number_of_col = res->getMetaData()->getColumnCount();
		
				while(res->next())
				{
					cout << "*";
					cout << res->getRow() <<".";
					for(int i =1; i<=Number_of_col; ++i)
					{
						cout << " " <<res->getString(i);
					}
					cout << "*" << endl;
				}
				break;
				
			case 5:
				sts->execute("INSERT INTO vet.pets VALUES (1, 'Linda', 8, 'F')");
				res = sts->executeQuery("SELECT * FROM vet.pets");

				Number_of_col = res->getMetaData()->getColumnCount();
		
				while(res->next())
				{
					cout << "*";
					cout << res->getRow() <<".";
					for(int i =1; i<=Number_of_col; ++i)
					{
						cout << " " <<res->getString(i);
					}
					cout << "*" << endl;
				}
				break;
			
			case 6:
				sts->execute("DELETE FROM vet.pets WHERE Name = 'Amigo'");
				res = sts->executeQuery("SELECT * FROM vet.pets");
				Number_of_col = res->getMetaData()->getColumnCount();
		
				while(res->next())
				{
					cout << "*";
					cout << res->getRow() <<".";
					for(int i =1; i<=Number_of_col; ++i)
					{
						cout << " " <<res->getString(i);
					}
					cout << "*" << endl;
				}
				break;
			
			
			case 9: 
				cout << "* Exit *" << endl;
				delete res;
				delete sts;
				delete con;
				return 0;	

			default:
				cout << "Please enter a number between 1-9." << endl;
				choice = 0;
				cout << "\n" << endl;
				break;
		}
	}
	return 0;
}
