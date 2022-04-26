#pragma once
#include <mysql.h>
#include "Student.hpp"

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

namespace modify
{
	enum class operations
	{
		add,
		deleteStudent
	};

	class Modify
	{
	public:
		void add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student);
		void deleteStudent(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student);
	};
}