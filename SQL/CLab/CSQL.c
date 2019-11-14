#include <stdio.h>
#include <mysql/mysql.h>

int main()
{
	MYSQL* MySql = NULL;
	MYSQL* Retval;
	int Retvali;
	MYSQL_RES* res;
	my_ulonglong Number_of_row;
	unsigned int Number_of_col;
	MYSQL_FIELD* field;
	MYSQL_ROW row;
	
	puts("Starting program");
	MySql = mysql_init(NULL); 
	if (MySql == NULL) {
      	fprintf(stderr, "error connecting to mysql errno: %d Msg: %s\n", 
			mysql_errno(MySql), mysql_error(MySql));
     	exit(1);
  	} else {
		puts("mysql_init Succedded");
	}
	Retval = mysql_real_connect(MySql, "localhost", "nataly", "Mn120517", NULL, 0, NULL, 0);
	if (Retval == NULL) 
	{
      	fprintf(stderr, "mysql_real_connect failed errno: %d Msg: %s\n", mysql_errno(MySql), mysql_error(MySql));
		mysql_close(MySql);
     	exit(1);
  	} else {
		puts("mysql_real_connect Succedded");
	}
	Retvali = mysql_query(MySql, "INSERT INTO vet.table1 VALUES (5,'1992-09-20', 'Tom', 'prego', 'M')");
	Retvali = mysql_query(MySql, "INSERT INTO vet.table1 VALUES (2,'1992-07-24', 'Matan', 'Cohen', 'M')");
	Retvali = mysql_query(MySql, "DELETE FROM vet.table1 WHERE id = 3");
	Retvali = mysql_query(MySql, "SELECT * FROM vet.table1");
	if(Retvali != 0)
	{
	    fprintf(stderr, "mysql_real_connect failed errno: %d Msg: %s\n", mysql_errno(MySql), mysql_error(MySql));
		mysql_close(MySql);
     	exit(1);
	}
	else
	{
		puts("mysql_query Succedded");
	}
	
	res = mysql_store_result(MySql);
	if((res == NULL) && (mysql_errno(MySql) != 0))
	{
		fprintf(stderr, "mysql_store_result failed errno: %d Msg: %s\n", mysql_errno(MySql), mysql_error(MySql));
		mysql_close(MySql);
     	exit(1);
	}
	else
	{
		puts("mysql_store_result Succedded");
	}
	if(res==NULL)
	{
		puts("Result is NULL");
	}
	else
	{
		Number_of_col = mysql_num_fields(res);
		Number_of_row = mysql_num_rows(res);
		printf("Number_of_col: %d Number_of_row: %lld\n", Number_of_col, Number_of_row);
		printf(":");
		for(int i =0; i<Number_of_col; ++i)
		{
			field=mysql_fetch_field(res);
			printf(" %s,",field->name);
		}
		printf("\n");
		for(int i=0; i<Number_of_row; ++i)
		{
			row = mysql_fetch_row(res);
			for(int j=0; j<Number_of_col; ++j)
			{
				printf(" %s :", row[j]);
			}
			printf("\n");
		}
	}
	
	mysql_free_result(res);
  	mysql_close(MySql);
	puts("Press enter to terminate");
	getchar();
	return(0);
}
