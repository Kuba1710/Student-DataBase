#pragma once
#include "MyForm1.h"
#include "LoginDataBase.h"
#include <mysql.h>

namespace StudentDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
		MySqlCommand^ sqlCmd; 
		DataTable^ sqlDt; 
		MySqlDataReader^ sqlRd;
		DataBase* students; 
		DataSet^ set; 
		MySqlConnection^ sqlConn; 
		MySqlDataAdapter^ sqlDta; 

		LoginDataBase *loginDataBase;
	public:
		login(void)
		{
			InitializeComponent();
			loginDataBase = new LoginDataBase();
			set = gcnew DataSet();
			sqlConn = gcnew MySqlConnection();
			sqlDta = gcnew MySqlDataAdapter();
			students = new DataBase();
			sqlCmd = gcnew MySqlCommand();
			sqlDt = gcnew DataTable();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
				delete loginDataBase;
				delete students;
			}
		}
	private: System::Windows::Forms::Button^ loginButton;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ loginBox;
	private: System::Windows::Forms::TextBox^ passBox;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loginBox = (gcnew System::Windows::Forms::TextBox());
			this->passBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// loginButton
			// 
			this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->loginButton->Location = System::Drawing::Point(97, 228);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(139, 53);
			this->loginButton->TabIndex = 0;
			this->loginButton->Text = L"Apply";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &login::loginButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(21, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(21, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Password";
			// 
			// loginBox
			// 
			this->loginBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->loginBox->Location = System::Drawing::Point(152, 67);
			this->loginBox->Name = L"loginBox";
			this->loginBox->Size = System::Drawing::Size(167, 35);
			this->loginBox->TabIndex = 3;
			// 
			// passBox
			// 
			this->passBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passBox->Location = System::Drawing::Point(152, 126);
			this->passBox->Name = L"passBox";
			this->passBox->Size = System::Drawing::Size(167, 35);
			this->passBox->TabIndex = 4;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(331, 341);
			this->Controls->Add(this->passBox);
			this->Controls->Add(this->loginBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->loginButton);
			this->Name = L"login";
			this->Text = L"login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: void clearTextBoxes()
		{
			this->passBox->Text = "";
			this->loginBox->Text = "";
		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {

		students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		if (loginDataBase->checkLoginPass(sqlConn,  sqlDta, set, loginBox, passBox))
		{
			this->Hide();
			MyForm ^form = gcnew MyForm();
			form->Show();
		}
		else
		{
			MessageBox::Show("Wrong login or password", "Error");
		}
		students->disconnectDataBase(sqlRd, sqlConn);
	}
};
}
