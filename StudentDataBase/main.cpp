#include <mysql.h>
#include "MyForm1.h"
#include "login.h"
using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//StudentDataBase::MyForm form;
	StudentDataBase::login loginToApp;
	Application::Run(% loginToApp);
}