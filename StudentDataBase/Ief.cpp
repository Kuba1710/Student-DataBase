#include "Ief.hpp"
#include <iomanip>
#include <string>
#include <utility>
#include <map>

double Ief::countGPA(std::vector<std::string> rates)
{
	double numberOfRates = rates.size();
	double sumOfRates = 0;
	double gpa = 0;
	double sumOfEcts = 0;
	for (const auto& el : rates)
	{
		int rate = std::stoi(el);
		sumOfRates += rate;
	};
	//double divider = numberOfRates * sumOfEcts;
	gpa = sumOfRates / numberOfRates;

	return gpa;
}

int Ief::countECTS(std::vector<std::string> rates)
{
	/*std::map<std::string, int> ratesWithECTS
	{
		{rates[0],1},
		{rates[1],1},
		{rates[2],3},
		{rates[3],2},
		{rates[4],2},
		{rates[6],2},
		{rates[7],2},
		{rates[8],1},
		{rates[9],2}
	};*/
	int ectsCount = 0;
	for (auto& el : rates)
	{
		int rate = std::stoi(el);
		if (rate == 2)
			ectsCount++;
	};

	return ectsCount;
}

void Ief::addCoursesToDataBase(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, std::vector<std::string> marks, std::string index)
{
	System::String^ indeks = gcnew System::String(index.c_str());
	System::String^ tm = gcnew System::String(marks[0].c_str());
	System::String^ pes = gcnew System::String(marks[1].c_str());
	System::String^ openlab = gcnew System::String(marks[2].c_str());
	System::String^ montaz = gcnew System::String(marks[3].c_str());
	System::String^ tp = gcnew System::String(marks[4].c_str());
	System::String^ mm = gcnew System::String(marks[5].c_str());
	System::String^ o2 = gcnew System::String(marks[6].c_str());
	System::String^ s2 = gcnew System::String(marks[7].c_str());
	System::String^ oo = gcnew System::String(marks[8].c_str());


	try
	{
		sqlCmd->CommandText = "INSERT INTO `db_students`.`ief` (`index`, `TechnikaMikrofalowa`, `PES`, `Openlab`, `Montaz`, `TechnikaProzni`, `ModelowanieMikro`, `opto2`, `swiatlo2`, `OptoObrazowa`) VALUES('" + indeks + "', '" + tm + "', '" + pes + "','" + openlab + "', '" + montaz + "', '" + tp + "', '" + mm + "', '" + o2 + "', '" + s2 + "', '" + oo + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
}