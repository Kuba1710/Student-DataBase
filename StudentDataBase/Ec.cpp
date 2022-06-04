#include "Ec.hpp"
#include <msclr/marshal_cppstd.h>
#include <string>

//void Ec::viewStudents() {};
//std::vector<Student> Ec::getVectorOfStudents() {};

std::string Ec::calculateAverrage(array <TextBox^>^ coursesTextBoxes)
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
	return std::to_string((sum / (6 - nullCourse)));
}

std::string Ec::calculateECTS(array <TextBox^>^ coursesTextBoxes)
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
	return std::to_string(ECTS);
}

void Ec::updateECcourses(MySqlCommand^ sqlCmd, array <TextBox^>^ coursesTextBoxes)
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

void Ec::addECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes)
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

void Ec::deleteECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes)
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