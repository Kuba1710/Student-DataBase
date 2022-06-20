#pragma once
#include <mysql.h>
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

class LoginDataBase
{
public:
	bool checkLoginPass(MySqlConnection^ sqlConn, MySqlDataAdapter^ sqlDta, DataSet^ set, TextBox^ login, TextBox^ pass);
	DataSet^ selectData(MySqlConnection^ sqlConn, MySqlDataAdapter^ sqlDta, DataSet ^set, TextBox^ login, TextBox^ pass);

};

