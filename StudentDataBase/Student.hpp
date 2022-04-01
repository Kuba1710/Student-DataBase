#pragma once
#include <string>
#include <map>

struct Student
{
	std::string name;
	std::string secondName;
	std::string index;
	std::string adress;
	std::string pesel;
	std::string fieldOfStudy;
	std::string specialization;
	unsigned int degreeOfStudy;
	unsigned int ects;
	unsigned int yearOfStudy;
	std::vector<std::map<std::string, unsigned int>> classes; // vector zajec ktory przyjmuje mape key = nazwa zajeci, value =  liczba ects
	float gpa;
};
