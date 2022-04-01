#pragma once
#include "FieldOfStudy.hpp"
#include <memory>
class DataBase
{
public:
	DataBase();
	void sploadToDataBase();
	void saveToDataBase();
private:
	std::unique_ptr<FieldOfStudy> Students;
};