#pragma once
#include "FieldOfStudy.hpp"
#include <vector>

class Ec : public FieldOfStudy
{
public:
	//void viewStudents() override;
	//std::vector<Student> getVectorOfStudents() override;
	Ec() = default;
	void updateECcourses(MySqlCommand^ sqlCmd, array <TextBox^>^ coursesTextBoxes);
	void deleteECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes);
	void addECcourses(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, array <TextBox^>^ coursesTextBoxes);
	static std::string calculateAverrage(array <TextBox^>^ coursesTextBoxes);
	static std::string calculateECTS(array <TextBox^>^ coursesTextBoxes);

private:
	std::vector<Student> onlyEcStudents;
};