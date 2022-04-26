#include "Modify.hpp"
#include <mysql.h>

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

void modify::Modify::add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student)
{
	System::String^ firstName = gcnew System::String(student->name.c_str());
	System::String^ secondName = gcnew System::String(student->secondName.c_str());
	System::String^ index = gcnew System::String(student->index.c_str());
	System::String^ pesel = gcnew System::String(student->pesel.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student->fieldOfStudy.c_str());
	System::String^ specialization = gcnew System::String(student->specialization.c_str());
	System::String^ degree = gcnew System::String(student->degreeOfStudy.c_str());
	System::String^ ects = gcnew System::String(student->ects.c_str());
	System::String^ yearOfStudy = gcnew System::String(student->yearOfStudy.c_str());
	System::String^ gpa = gcnew System::String(student->gpa.c_str());

	try
	{
		sqlCmd->CommandText = "INSERT INTO db_students.allstudents (Firstname, Secondname, allstudents.index, pesel, fieldOfStudy, Specialization, degree, ects, yearOfStudy, gpa) VALUES('" + firstName +"', '" + secondName + "', '" + index + "','" + pesel + "', '" + fieldOfStudy + "', '" + specialization + "', '" + degree + "', '" + ects + "', '" + yearOfStudy + "', '" + gpa + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
};

void modify::Modify::deleteStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student)
{
	System::String^ firstName = gcnew System::String(student->name.c_str());
	System::String^ secondName = gcnew System::String(student->secondName.c_str());
	System::String^ index = gcnew System::String(student->index.c_str());
	System::String^ pesel = gcnew System::String(student->pesel.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student->fieldOfStudy.c_str());
	System::String^ specialization = gcnew System::String(student->specialization.c_str());
	System::String^ degree = gcnew System::String(student->degreeOfStudy.c_str());
	System::String^ ects = gcnew System::String(student->ects.c_str());
	System::String^ yearOfStudy = gcnew System::String(student->yearOfStudy.c_str());
	System::String^ gpa = gcnew System::String(student->gpa.c_str());

	if (pesel == "")
	{
		System::Windows::Forms::MessageBox::Show("Pesel nie mo¿e byæ pusty", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
	else
	{
		try
		{
			sqlCmd->CommandText = "DELETE FROM allstudents WHERE pesel =" + pesel + "";
			sqlRd = sqlCmd->ExecuteReader();
			sqlDt->Load(sqlRd);
		}
		catch (System::Exception^ ex)	
		{
			System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}
};