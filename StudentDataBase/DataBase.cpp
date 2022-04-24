#include "DataBase.hpp"
#include <mysql.h>
//#include <MyForm1.h>

DataBase::DataBase() {
 // tutaj w konstruktorze bedzie tworzona baza dancyh
}

void DataBase::saveToDataBase()
{

}

void DataBase::sploadToDataBase()
{

}

void DataBase::AddToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd)
{
	sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = Kuba1710; database = db_students";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;

	//sqlCmd->CommandText = "insert into db_students.allstudents (Firstname, Secondname, index, pesel, fieldOfStudy, Specialization, degree, ects, gpa)"
		//"values('" + ... //do dokonczenia

	sqlRd = sqlCmd->ExecuteReader();
	sqlConn->Close();
	connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd); // aby odswiezyc baze danych
}

void DataBase::connectToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd)
{
	sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = Kuba1710; database = db_students";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = "Select * from db_students.allstudents";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	sqlRd->Close();
	sqlConn->Close();
}
