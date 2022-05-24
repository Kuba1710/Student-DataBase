#pragma once
#include "FieldOfStudy.hpp"
#include <memory>
#include <mysql.h>

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

class DataBase
{
public:
	DataBase();
	void sploadToDataBase();
	void saveToDataBase();
	void connectToDataBase(MySqlConnection^ sqlConn, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, MySqlDataReader^ sqlRd);
	void disconnectDataBase(MySqlDataReader^ sqlRd, MySqlConnection^ sqlConn);
	void refreshDataBase(MySqlConnection^ sqlConn, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, DataGridView^ dataGrid);
	void refreshStudentsECMarks(MySqlConnection^ sqlConn, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, DataGridView^ dataGrid);
};
