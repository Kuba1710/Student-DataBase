#pragma once
#include <vector>
#include <memory>
#include "Student.hpp"
#include "Modify.hpp"
#include <mysql.h>
using namespace modify;

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

class FieldOfStudy
{
public:
	FieldOfStudy() = default;
	virtual void viewStudents(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd);
	virtual void viewStudentsECMarks(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd);
	void update(modify::operations, MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, MySqlDataAdapter^ sqlAd, const Student* student, DataGridView^ dataGrid, TextBox^ search, MySqlConnection^ conn, ComboBox^ combo, array <TextBox^>^ coursesTextBoxes);
	//virtual std::vector<Student> getVectorOfStudents();
	//bool ectsNotification(/*moze tutaj bedzie jakis argument*/);
	//bool scholarshipNotification();
	
private:
	std::vector<Student> groupOfStudents;
protected:
	std::unique_ptr<modify::Modify> modify ;
};
