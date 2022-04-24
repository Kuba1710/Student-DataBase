#pragma once
#include "FieldOfStudy.hpp"
#include <memory>
#include <mysql.h>
using namespace System::Data;
using namespace MySql::Data::MySqlClient;



class DataBase
{
public:
	DataBase();
	void sploadToDataBase();
	void saveToDataBase();
	void AddToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd);
	void connectToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd);
private:
	std::unique_ptr<FieldOfStudy> Students;
};
