#include "Modify.hpp"
#include <mysql.h>

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

void modify::Modify::add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student)
{
	System::String^ firstName = gcnew System::String(student->name.c_str());
	System::String^ secondName = gcnew System::String(student->secondName.c_str());
	System::String^ index = gcnew System::String(student->name.c_str());
	System::String^ pesel = gcnew System::String(student->name.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student->name.c_str());
	System::String^ specialization = gcnew System::String(student->name.c_str());
	System::String^ degree = gcnew System::String(student->name.c_str());
	System::String^ ects = gcnew System::String(student->name.c_str());
	System::String^ yearOfStudy = gcnew System::String(student->name.c_str());
	System::String^ gpa = gcnew System::String(student->name.c_str());

	sqlCmd->CommandText = "INSERT INTO `db_students`.`allstudents` (`Firstname`, `Secondname`, `index`, `pesel`, `fieldOfStudy`, `Specialization`, `degree`, `ects`, `yearOfStudy`, `gpa`) VALUES('" + firstName +"', '" + secondName + "', '" + index + "', '" + pesel + "', '" + fieldOfStudy + "', '" + specialization + "', '" + degree + "', '" + ects + "', '" + yearOfStudy + "', '" + gpa + "') ";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
};