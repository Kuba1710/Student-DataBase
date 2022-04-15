#include <mysql.h>

int main()
{

	MYSQL students; // tworzymy zmienn¹ typu MYSQL

	mysql_init(&students); // inicjalizacja

	mysql_real_connect(&students, "localhost", "Kuba1710", "", "db_students", 3306, NULL, 0);
	return 0;
}