#include "LoginDataBase.h"

bool LoginDataBase::checkLoginPass(MySqlConnection^ sqlConn, MySqlDataAdapter^ sqlDta, DataSet^ set, TextBox^ login, TextBox^ pass)
{
    set = gcnew DataSet();
    set = selectData(sqlConn, sqlDta, set, login, pass);

    if (set->Tables[0]->Rows->Count != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DataSet^ LoginDataBase::selectData(MySqlConnection^ sqlConn, MySqlDataAdapter^ sqlDta, DataSet^ set, TextBox^ login, TextBox^ pass)
{
	sqlDta = gcnew MySqlDataAdapter("select * from administrator where login = " + "'" + login->Text + "'" + " and password = " +  "'" + pass->Text + "'", sqlConn);
	set = gcnew DataSet();
	sqlDta->Fill(set);
    return set;
}