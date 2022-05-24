#pragma once
#include <mysql.h>
#include "Student.hpp"

using namespace MySql::Data::MySqlClient;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace modify
{
	enum class operations
	{
		updateEC,
		deleteEC,
		addEC,
		add,
		deleteStudent,
		updateStudent,
		searchStudent,
		group,
	};

	class Modify
	{
	public:
		void updateECcourses(MySqlCommand^ sqlCmd, array <TextBox^>^ coursesTextBoxes);
		void deleteECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes);
		void addECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes);
		float calculateAverrage(array <TextBox^>^ coursesTextBoxes);
		int calculateECTS(array <TextBox^>^ coursesTextBoxes);
		void add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student, array <TextBox^>^ coursesTextBoxes);
		void deleteStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student);
		void updateStudent(MySqlCommand^ sqlCmd, const Student* student, array <TextBox^>^ coursesTextBoxes);
		void searchStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn);
		void groupStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn, ComboBox^ combo);
		//void castingStudent(System::String^ str, const Student* student);

	/*private:
		System::String^ firstName;
		System::String^ secondName;
		System::String^ index;
		System::String^ pesel;
		System::String^ fieldOfStudy;
		System::String^ specialization;
		System::String^ degree;
		System::String^ ects;
		System::String^ yearOfStudy;
		System::String^ gpa; */
	}; 

};