#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void) 
{
	cout << "Running 'SELECT * FROM employees.employees LIMIT 10'" << endl;
	try {
		sql::Driver* driver;
		driver = get_driver_instance();
		cout << driver << endl;
		cout << "driver->getMajorVersion: " << driver->getMajorVersion()<< endl;
		cout << "driver->getMinorVersion: " << driver->getMinorVersion()<< endl;
		cout << "driver->getName: " << driver->getName()<< endl;
		cout << "driver->getPatchVersion: " << driver->getPatchVersion()<< endl;
		
		sql::Connection* con;
		con = driver->connect("localhost", "nataly", "Mn120517");
		con->setSchema("vet");
		
		cout << "con->isValid: " << con->isValid() << endl;
		cout << "con->getClientInfo: " << con->getClientInfo() << endl;
		
		sql::Statement* sts;
		sts = con->createStatement();
		
		sql::ResultSet* res;
		sts->execute("INSERT INTO vet.table1 VALUES (3,'1988-05-06', 'Jeff', 'Villano', 'M')");
		sts->execute("INSERT INTO vet.table1 VALUES (6,'1955-06-16', 'Marcela', 'Prego', 'F')");
		sts->execute("DELETE FROM vet.table1 WHERE id = 4");

		res = sts->executeQuery("SELECT * FROM table1");
		cout << "res->rowsCount: " << res->rowsCount() << endl;
		cout << "res->getMetaData->getColumnCount: " << res->getMetaData()->getColumnCount() << endl;
		
		int Number_of_col = res->getMetaData()->getColumnCount();
		cout << "Number of columns is: " << Number_of_col << endl;
		
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
		
		delete res;
		delete sts;
		delete con;
	}
	catch (sql::SQLException& e) {
		cout << "***** Error: " << e.what();
		cout << "MySQL code: " << e.getErrorCode();
		cout << "SQLState: " << e.getSQLState() << endl;
	return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
