#pragma once
#include <vector>
#include <memory>
#include "Student.hpp"
#include "Modify.hpp"


class FieldOfStudy
{
public:
	FieldOfStudy() = default;
	virtual void viewStudents();
	virtual std::vector<Student> getVectorOfStudents();
	bool ectsNotification(/*moze tutaj bedzie jakis argument*/);
	bool scholarshipNotification();
	

private:
	std::vector<Student> groupOfStudents;
	std::unique_ptr<Modify> modify = ;
};
