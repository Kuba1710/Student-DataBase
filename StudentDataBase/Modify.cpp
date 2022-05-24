#include "Modify.hpp"
#include <mysql.h>
#include <msclr/marshal_cppstd.h>

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

void modify::Modify::updateECcourses(MySqlCommand^ sqlCmd, array <TextBox^>^ coursesTextBoxes)
{
	try
	{
		sqlCmd->CommandText = "update ec_courses set ec_courses.index = '" + coursesTextBoxes[0] + "', Wbudowane_systemy_operacyjne = '" + coursesTextBoxes[1] + "', Programowanie_obiektowe = '" + coursesTextBoxes[2] + "', Programowanie_ukladow_logicznych = '" + coursesTextBoxes[3]  + "', Procesory_sygnalowe = '" + coursesTextBoxes[4] + "', Weryfikacja_systemow_cyfrowych = '" + coursesTextBoxes[5] + "', Protokoly_i_interfejsy = '" + coursesTextBoxes[6] + "' where ec_courses.index = '" + coursesTextBoxes[0] + "'";
		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Pomyœlnie nadpisano liste kursów Studenta: " + coursesTextBoxes[0] + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void modify::Modify::addECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes)
{
	try
	{
		sqlCmd->CommandText = "INSERT INTO db_students.ec_courses (ec_courses.index , Wbudowane_systemy_operacyjne, Programowanie_obiektowe, Programowanie_ukladow_logicznych, Procesory_sygnalowe, Weryfikacja_systemow_cyfrowych, Protokoly_i_interfejsy) VALUES('" + coursesTextBoxes[0]->Text + "', '" + coursesTextBoxes[1]->Text + "', '" + coursesTextBoxes[2]->Text + "','" + coursesTextBoxes[3]->Text + "', '" + coursesTextBoxes[4]->Text + "', '" + coursesTextBoxes[5]->Text + "', '" + coursesTextBoxes[6]->Text + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		MessageBox::Show("Pomyœlnie dodano oceny studenta: " + coursesTextBoxes[0]->Text + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
}

void modify::Modify::deleteECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes)
{
	try
	{
		sqlCmd->CommandText = "DELETE FROM ec_courses WHERE ec_courses.index =" + coursesTextBoxes[0] + "";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		MessageBox::Show("Pomyœlnie usuniêto liste kursów studenta: " + coursesTextBoxes[0] + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
}

void modify::Modify::add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student, array <TextBox^>^ coursesTextBoxes)
{
	System::String^ firstName = gcnew System::String(student->name.c_str());
	System::String^ secondName = gcnew System::String(student->secondName.c_str());
	System::String^ index = gcnew System::String(student->index.c_str());
	System::String^ pesel = gcnew System::String(student->pesel.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student->fieldOfStudy.c_str());
	System::String^ specialization = gcnew System::String(student->specialization.c_str());
	System::String^ degree = gcnew System::String(student->degreeOfStudy.c_str());
	System::String^ ects = gcnew System::String((modify::Modify::calculateECTS(coursesTextBoxes)).ToString());
	System::String^ yearOfStudy = gcnew System::String(student->yearOfStudy.c_str());
	System::String ^gpa = gcnew System::String((modify::Modify::calculateAverrage(coursesTextBoxes)).ToString());

	try
	{
		sqlCmd->CommandText = "INSERT INTO db_students.allstudents (Firstname, Secondname, allstudents.index, pesel, fieldOfStudy, Specialization, degree, ects, yearOfStudy, gpa) VALUES('" + firstName +"', '" + secondName + "', '" + index + "','" + pesel + "', '" + fieldOfStudy + "', '" + specialization + "', '" + degree + "', '" + ects + "', '" + yearOfStudy + "', '" + gpa + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		MessageBox::Show("Pomyœlnie dodano Studenta: " + firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
		System::Windows::Forms::MessageBox::Show("Index nie mo¿e byæ pusty", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
	else
	{
		try
		{
			sqlCmd->CommandText = "DELETE FROM allstudents WHERE allstudents.index =" + index + "";
			sqlRd = sqlCmd->ExecuteReader();
			sqlDt->Load(sqlRd);
			MessageBox::Show("Pomyœlnie usuniêto Studenta: " + firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ ex)	
		{
			System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}
};

void modify::Modify::updateStudent(MySqlCommand^ sqlCmd, const Student* student, array <TextBox^>^ coursesTextBoxes)
{
	System::String^ firstName = gcnew System::String(student->name.c_str());
	System::String^ secondName = gcnew System::String(student->secondName.c_str());
	System::String^ index = gcnew System::String(student->index.c_str());
	System::String^ pesel = gcnew System::String(student->pesel.c_str());
	System::String^ fieldOfStudy = gcnew System::String(student->fieldOfStudy.c_str());
	System::String^ specialization = gcnew System::String(student->specialization.c_str());
	System::String^ degree = gcnew System::String(student->degreeOfStudy.c_str());
	System::String^ ects = gcnew System::String((modify::Modify::calculateECTS(coursesTextBoxes)).ToString());
	System::String^ yearOfStudy = gcnew System::String(student->yearOfStudy.c_str());
	System::String^ gpa = gcnew System::String((modify::Modify::calculateAverrage(coursesTextBoxes)).ToString());

	try
	{
		sqlCmd->CommandText = "update allstudents set Firstname = '" + firstName + "', Secondname = '" + secondName + "', allstudents.index = '" + index + "', pesel = '" + pesel + "', fieldOfStudy = '" + fieldOfStudy + "', Specialization = '" + specialization + "', degree = '" + degree + "', ects = '" + ects + "', yearOfStudy = '" + yearOfStudy + "', gpa = '" + gpa + "' where allstudents.index = '" + index + "'";
		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Pomyœlnie nadpisano Studenta: " + firstName + ".", "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
		sqlAd = gcnew MySqlDataAdapter("select * from allstudents where Firstname like '%" + search->Text + "%' or Secondname like '%" + search->Text + "%' or pesel like '%" + search->Text + "%' or allstudents.index like '%" + search->Text + "%' or fieldOfStudy like '%" + search->Text + "%' or degree like '%" + search->Text + "%' or Specialization like '%" + search->Text + "%' or ects like '%" + search->Text + "%' or yearOfStudy like '%" + search->Text + "%' or gpa like '%" + search->Text + "%'", conn);
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
			sqlAd = gcnew MySqlDataAdapter("select * from allstudents", conn);
		else
			sqlAd = gcnew MySqlDataAdapter("select * from allstudents where Specialization = '" + combo->Text + "'", conn);
		
		sqlCmd->ExecuteNonQuery();
		sqlDt = gcnew DataTable();
		sqlAd->Fill(sqlDt);
		dataGrid->DataSource = sqlDt;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Student db", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

float modify::Modify::calculateAverrage(array <TextBox^>^ coursesTextBoxes)
{
	float sum = 0;
	float nullCourse = 0;
	for (int i = 1; i < 7; i++) //zerowy pomijamy bo to nr index
	{
		std::string mark = msclr::interop::marshal_as<std::string>(coursesTextBoxes[i]->Text);
		if (mark != "0")
			sum += std::stof(mark);
		else
			nullCourse++;
	}
	return sum / (6 - nullCourse);
}

int modify::Modify::calculateECTS(array <TextBox^>^ coursesTextBoxes)
{
	int ECTS = 0;
	for (int i = 1; i < 7; i++)
	{
		std::string mark = msclr::interop::marshal_as<std::string>(coursesTextBoxes[i]->Text);
		if (std::stoi(mark) < 3)
		{
			ECTS++;
		}
	}
	return ECTS;
}


