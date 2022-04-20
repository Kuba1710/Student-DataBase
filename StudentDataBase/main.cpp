#include <mysql.h>
#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	StudentDataBase::MyForm form;
	Application::Run(% form);
}