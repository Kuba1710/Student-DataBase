#pragma once
#include "FieldOfStudy.hpp"
#include <mysql.h>

using namespace MySql::Data::MySqlClient;
using namespace System::Data;


void FieldOfStudy::viewStudents(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd)
{
	sqlCmd->CommandText = "Select * from db_students.allstudents";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	
}

void FieldOfStudy::update(modify::operations operation, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student)
{
	switch (operation)
	{
	case modify::operations::add:
		modify->add(sqlCmd, sqlDt, sqlRd, student);
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

