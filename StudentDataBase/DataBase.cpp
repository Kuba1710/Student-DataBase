#include "DataBase.hpp"
#include <mysql.h>
//zmiany
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
using namespace System::Windows::Forms;

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
	//zmiany
	/*sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	const std::string server = "mysqlserver-to-po.database.windows.net";
	const std::string username = "azureuser";
	const std::string password = "mypass253882PO";

	driver = get_driver_instance();
	con = driver->connect(server, username, password);*/

	//sqlConn->ConnectionString = "Data Source=mysqlserver-to-po.database.windows.net;Initial Catalog=db_students;User ID=azureuser;Password=mypass253882PO";
	sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = mypass; database = db_students"; //Persist Security Info=False;
	
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
}

void DataBase::refreshDataBase(MySqlConnection^ sqlConn, DataTable^ sqlDt, MySqlDataAdapter^ sqlDta, DataGridView^ dataGrid)
{
	sqlDta = gcnew MySqlDataAdapter("select * from allstudents order by allstudents.index", sqlConn);
	sqlDt = gcnew DataTable();
	sqlDta->Fill(sqlDt);
	dataGrid->DataSource = sqlDt;	
};
