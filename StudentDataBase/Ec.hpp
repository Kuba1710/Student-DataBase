#pragma once
#include "FieldOfStudy.hpp"
#include <vector>

class Ec : public FieldOfStudy
{
public:
	double countGPA(std::vector<std::string>);
	int countECTS(std::vector<std::string>);
	void addCoursesToDataBase(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, std::vector<std::string>, std::string);

private:
	std::vector<Student> onlyEcStudents;
};