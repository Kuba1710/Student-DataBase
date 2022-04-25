#pragma once
#include <mysql.h>
#include "Student.hpp"

using namespace MySql::Data::MySqlClient;
using namespace System::Data;

namespace modify
{
	enum class operations
	{
		add
	};

	class Modify
	{
	public:
		void add(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, const Student* student);
	};
}