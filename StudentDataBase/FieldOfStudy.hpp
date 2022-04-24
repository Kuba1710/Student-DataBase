#pragma once
#include <vector>
#include <memory>
#include "Student.hpp"
#include "Modify.hpp"
#include <mysql.h>

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

class FieldOfStudy
{
public:
	FieldOfStudy() = default;
	virtual void viewStudents(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd);
	void update();
	void setModify();
	//virtual std::vector<Student> getVectorOfStudents();
	//bool ectsNotification(/*moze tutaj bedzie jakis argument*/);
	//bool scholarshipNotification();
	

private:
	std::vector<Student> groupOfStudents;
	std::unique_ptr<Modify> modify ;
};
