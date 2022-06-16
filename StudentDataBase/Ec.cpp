#include "Ec.hpp"
#include <iomanip>
#include <string>
#include <utility>
#include <map>

double Ec::countGPA(std::vector<std::string> rates)
{
	double numberOfRates = rates.size();
	double sumOfRates = 0;
	double gpa = 0;
	double sumOfEcts = 0;
	int i = 0;
	std::map<std::string, double> ratesWithECTS
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
	};
	for (const auto& el : rates)
	{
		int rate = std::stoi(el);
		sumOfRates += rate* ratesWithECTS[el];
		sumOfEcts += ratesWithECTS[el];
	};
	//double divider = numberOfRates * sumOfEcts;
	gpa = sumOfRates / numberOfRates;

	return gpa;
}

int Ec::countECTS(std::vector<std::string> rates)
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

void Ec::addCoursesToDataBase(MySqlCommand^ sqlCmd, DataTable^ sqlDt, MySqlDataReader^ sqlRd, std::vector<std::string> marks, std::string index)
{
	System::String^ indeks = gcnew System::String(index.c_str());
	System::String^ tm = gcnew System::String(marks[0].c_str());
	System::String^ pes = gcnew System::String(marks[1].c_str());
	System::String^ openlab = gcnew System::String(marks[2].c_str());
	System::String^ montaz = gcnew System::String(marks[3].c_str());
	System::String^ po = gcnew System::String(marks[4].c_str());
	System::String^ pul = gcnew System::String(marks[5].c_str());
	System::String^ ps = gcnew System::String(marks[6].c_str());
	System::String^ wso = gcnew System::String(marks[7].c_str());
	System::String^ wsc = gcnew System::String(marks[8].c_str());


	try
	{
		sqlCmd->CommandText = "INSERT INTO `db_students`.`ec` (`index`, `TechnikaMikrofalowa`, `PodstawyEksploatacjiSystemów`, `Openlab`, `Montaz`, `ProgramowanieObiektowe`, `ProgramowanieUk³adówLogicznych`, `ProcesorySygna³owe`, `WbudowaneSystemyOperacyjne`, `WeryfikacjaSystemowCyfrowych`) VALUES('" + indeks + "', '" + tm + "', '" + pes + "','" + openlab + "', '" + montaz + "', '" + po + "', '" + pul + "', '" + ps + "', '" + wso + "', '" + wsc + "')";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message, "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	}
}