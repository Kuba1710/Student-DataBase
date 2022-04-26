#include "DataBase.hpp"
#include <mysql.h>

DataBase::DataBase() {
 // tutaj w konstruktorze bedzie tworzona baza dancyh
}

void DataBase::saveToDataBase()
{

}

void DataBase::sploadToDataBase()
{

}

void DataBase::disconnectDataBase(MySqlDataReader^ sqlRd, MySqlConnection^ sqlConn)
{
	//sqlRd->Close(); jak odkomentuje ta linijke to wywala blad nie wiem czmu potem sprawdze ale narazie dziala
	sqlConn->Close();
}

void DataBase::connectToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd)
{
	sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = mypass; database = db_students; sslmode = None";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
}

