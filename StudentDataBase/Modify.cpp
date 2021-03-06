#include "Modify.hpp"
#include <mysql.h>
#include <cliext/vector>

using namespace MySql::Data::MySqlClient;
using namespace System::Data;
using namespace System::Windows::Forms;


/*void castingStudent(System::String^ str, const Student* student)
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
} */


/*System::String^ stdToSysytem(const Student& student, int i)
{	
	cliext::vector<System::String^> datas;
	datas.push_back(gcnew System::String(student.name.c_str()));
	datas.push_back(gcnew System::String(student.secondName.c_str()));
	datas.push_back(gcnew System::String(student.index.c_str()));
	datas.push_back(gcnew System::String(student.pesel.c_str()));
	datas.push_back(gcnew System::String(student.fieldOfStudy.c_str()));
	datas.push_back(gcnew System::String(student.specialization.c_str()));
	datas.push_back(gcnew System::String(student.degreeOfStudy.c_str()));
	datas.push_back(gcnew System::String(student.ects.c_str()));
	datas.push_back(gcnew System::String(student.yearOfStudy.c_str()));
	datas.push_back(gcnew System::String(student.gpa.c_str()));

	/*System::String^ firstName = gcnew System::String(student.name.c_str());
	System::String^ secondName = gcnew System::String(student.secondName.c_str());
	System::String^ index = gcnew System::String(student.index.c_str());
	System::String^ pesel = gcnew System::String(student.pesel.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student.fieldOfStudy.c_str());
	System::String^ specialization = gcnew System::String(student.specialization.c_str());
	System::String^ degree = gcnew System::String(student.degreeOfStudy.c_str());
	System::String^ ects = gcnew System::String(student.ects.c_str());
	System::String^ yearOfStudy = gcnew System::String(student.yearOfStudy.c_str());
	System::String^ gpa = gcnew System::String(student.gpa.c_str());

	return datas[i];

}*/


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
		sqlCmd->CommandText = "INSERT INTO db_students.allstudents (Firstname, Secondname, allstudents.index, pesel, fieldOfStudy, Specialization, degree, ects, yearOfStudy, gpa) VALUES('" + firstName + "', '" + secondName + "', '" + index + "','" + pesel + "', '" + fieldOfStudy + "', '" + specialization + "', '" + degree + "', '" + ects + "', '" + yearOfStudy + "', '" + gpa + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		MessageBox::Show("Pomyslnie dodano Studenta: "+firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
};

void modify::Modify::deleteStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student)
{
	System::String^ index = gcnew System::String(student->index.c_str());
	System::String^ firstName = gcnew System::String(student->name.c_str());
	
	if (index == "")
	{
		System::Windows::Forms::MessageBox::Show("Index nie mo???e by??? pusty", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
	else
	{
		try
		{
			sqlCmd->CommandText = "DELETE FROM db_students.allstudents WHERE allstudents.index ='" + index + "'";
			sqlRd = sqlCmd->ExecuteReader();
			sqlDt->Load(sqlRd);
			MessageBox::Show("Pomy???lnie usuni???to Studenta: " + firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ ex)	
		{
			System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}
};

void modify::Modify::updateStudent(MySqlCommand^ sqlCmd, const Student* student)
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
		sqlCmd->CommandText = "update db_students.allstudents set Firstname = '" + firstName + "', Secondname = '" + secondName + "', allstudents.index = '" + index + "', pesel = '" + pesel + "', fieldOfStudy = '" + fieldOfStudy + "', Specialization = '" + specialization + "', degree = '" + degree + "', ects = '" + ects + "', yearOfStudy = '" + yearOfStudy + "', gpa = '" + gpa + "' where allstudents.index = '" + index + "'";
		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Pomy???lnie nadpisano Studenta: " + firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};

void modify::Modify::searchStudent( MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn)
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
		sqlAd = gcnew MySqlDataAdapter("select * from db_students.allstudents where Firstname like '%" + search->Text + "%' or Secondname like '%" + search->Text + "%' or pesel like '%" + search->Text + "%' or allstudents.index like '%" + search->Text + "%' or fieldOfStudy like '%" + search->Text + "%' or degree like '%" + search->Text + "%' or Specialization like '%" + search->Text + "%' or ects like '%" + search->Text + "%' or yearOfStudy like '%" + search->Text + "%' or gpa like '%" + search->Text + "%'", conn);
		sqlCmd->ExecuteNonQuery();
		sqlDt = gcnew DataTable();
		sqlAd->Fill(sqlDt);
		dataGrid->DataSource = sqlDt;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void modify::Modify::groupStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn, ComboBox^ combo)
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
		if (combo->Text == "ALL")
			sqlAd = gcnew MySqlDataAdapter("select * from db_students.allstudents", conn);
		else
			sqlAd = gcnew MySqlDataAdapter("select * from  db_students.allstudents where Specialization = '" + combo->Text + "'", conn);
		
		sqlCmd->ExecuteNonQuery();
		sqlDt = gcnew DataTable();
		sqlAd->Fill(sqlDt);
		dataGrid->DataSource = sqlDt;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}


