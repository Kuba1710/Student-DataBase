#pragma once
#include "FieldOfStudy.hpp"
#include <vector>

class Ec : public FieldOfStudy
{
public:
	void viewStudents() override;
	std::vector<Student> getVectorOfStudents() override;

private:
	std::vector<Student> onlyEcStudents;
};