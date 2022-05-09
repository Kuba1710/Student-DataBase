#pragma once
#include "FieldOfStudy.hpp"
#include <mysql.h>
using namespace modify;

using namespace MySql::Data::MySqlClient;
using namespace System::Data;
using namespace System::Windows::Forms;


void FieldOfStudy::viewStudents(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd)
{
	sqlCmd->CommandText = "Select * from db_students.allstudents";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	
}

void FieldOfStudy::update(modify::operations operation, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn, ComboBox^ combo)
{
	switch (operation)
	{
	case modify::operations::add:
		modify->add(sqlCmd, sqlDt, sqlRd, student);
		break;

	case modify::operations::deleteStudent:
		modify->deleteStudent(sqlCmd, sqlDt, sqlRd, student);
		break;

	case modify::operations::updateStudent:
		modify->updateStudent(sqlCmd, student);
		break;

	case modify::operations::searchStudent:
		modify->searchStudent( sqlCmd,  sqlDt,  sqlAd, student, dataGrid, search, conn);
		break;

	case modify::operations::group:
		modify->groupStudent(sqlCmd, sqlDt, sqlAd, student, dataGrid, search, conn, combo);
		break;

	}
}

//std::vector<Student> FieldOfStudy::getVectorOfStudents()
//{
	// TODO : ru bedziemy wyciagac wktor studentow'
//}

//bool FieldOfStudy::ectsNotification(/*moze tutaj bedzie jakis argument*/)
//{

//}

//bool FieldOfStudy::scholarshipNotification()
//{

//}

