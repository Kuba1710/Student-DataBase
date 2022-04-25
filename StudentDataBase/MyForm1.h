#pragma once
#include <memory>
#include <mysql.h>
#include "DataBase.hpp"
#include "FieldOfStudy.hpp"
#include "Modify.hpp"
#include <msclr\marshal_cppstd.h>
#include <map>

namespace StudentDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		DataBase* students = new DataBase();
		Student* student = new Student();
		FieldOfStudy* mainField = new FieldOfStudy();

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;

	private: System::Windows::Forms::TextBox^ FirstNameTB;
	private: System::Windows::Forms::TextBox^ SecondNameTB;
	private: System::Windows::Forms::TextBox^ degreeTB;
	private: System::Windows::Forms::TextBox^ yearOfStudyTB;
	private: System::Windows::Forms::TextBox^ gpaTB;
	private: System::Windows::Forms::TextBox^ IndexTB;
	private: System::Windows::Forms::TextBox^ FieldOfStudyTB;
	private: System::Windows::Forms::TextBox^ peselTB;
	private: System::Windows::Forms::TextBox^ specializationTB;
	private: System::Windows::Forms::TextBox^ ectsTB;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
	private: System::Windows::Forms::Button^ addButton;
		   /// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete students;
				delete mainField;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button1;


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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->FirstNameTB = (gcnew System::Windows::Forms::TextBox());
			this->SecondNameTB = (gcnew System::Windows::Forms::TextBox());
			this->degreeTB = (gcnew System::Windows::Forms::TextBox());
			this->yearOfStudyTB = (gcnew System::Windows::Forms::TextBox());
			this->gpaTB = (gcnew System::Windows::Forms::TextBox());
			this->IndexTB = (gcnew System::Windows::Forms::TextBox());
			this->FieldOfStudyTB = (gcnew System::Windows::Forms::TextBox());
			this->ectsTB = (gcnew System::Windows::Forms::TextBox());
			this->peselTB = (gcnew System::Windows::Forms::TextBox());
			this->specializationTB = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 290);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(1616, 322);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(1401, 15);
			this->addButton->Margin = System::Windows::Forms::Padding(4);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(100, 28);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"ADD";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// FirstNameTB
			// 
			this->FirstNameTB->Location = System::Drawing::Point(16, 28);
			this->FirstNameTB->Margin = System::Windows::Forms::Padding(4);
			this->FirstNameTB->Name = L"FirstNameTB";
			this->FirstNameTB->Size = System::Drawing::Size(132, 22);
			this->FirstNameTB->TabIndex = 2;
			this->FirstNameTB->Text = L"FirstName";
			// 
			// SecondNameTB
			// 
			this->SecondNameTB->Location = System::Drawing::Point(157, 28);
			this->SecondNameTB->Margin = System::Windows::Forms::Padding(4);
			this->SecondNameTB->Name = L"SecondNameTB";
			this->SecondNameTB->Size = System::Drawing::Size(132, 22);
			this->SecondNameTB->TabIndex = 3;
			this->SecondNameTB->Text = L"Secondname";
			// 
			// degreeTB
			// 
			this->degreeTB->Location = System::Drawing::Point(581, 28);
			this->degreeTB->Margin = System::Windows::Forms::Padding(4);
			this->degreeTB->Name = L"degreeTB";
			this->degreeTB->Size = System::Drawing::Size(132, 22);
			this->degreeTB->TabIndex = 4;
			this->degreeTB->Text = L"degree";
			// 
			// yearOfStudyTB
			// 
			this->yearOfStudyTB->Location = System::Drawing::Point(864, 28);
			this->yearOfStudyTB->Margin = System::Windows::Forms::Padding(4);
			this->yearOfStudyTB->Name = L"yearOfStudyTB";
			this->yearOfStudyTB->Size = System::Drawing::Size(132, 22);
			this->yearOfStudyTB->TabIndex = 5;
			this->yearOfStudyTB->Text = L"yearOfStudy";
			// 
			// gpaTB
			// 
			this->gpaTB->Location = System::Drawing::Point(1005, 28);
			this->gpaTB->Margin = System::Windows::Forms::Padding(4);
			this->gpaTB->Name = L"gpaTB";
			this->gpaTB->Size = System::Drawing::Size(132, 22);
			this->gpaTB->TabIndex = 6;
			this->gpaTB->Text = L"GPA";
			// 
			// IndexTB
			// 
			this->IndexTB->Location = System::Drawing::Point(299, 28);
			this->IndexTB->Margin = System::Windows::Forms::Padding(4);
			this->IndexTB->Name = L"IndexTB";
			this->IndexTB->Size = System::Drawing::Size(132, 22);
			this->IndexTB->TabIndex = 7;
			this->IndexTB->Text = L"index";
			// 
			// FieldOfStudyTB
			// 
			this->FieldOfStudyTB->Location = System::Drawing::Point(440, 28);
			this->FieldOfStudyTB->Margin = System::Windows::Forms::Padding(4);
			this->FieldOfStudyTB->Name = L"FieldOfStudyTB";
			this->FieldOfStudyTB->Size = System::Drawing::Size(132, 22);
			this->FieldOfStudyTB->TabIndex = 8;
			this->FieldOfStudyTB->Text = L"FieldOfStudy";
			// 
			// ectsTB
			// 
			this->ectsTB->Location = System::Drawing::Point(723, 28);
			this->ectsTB->Margin = System::Windows::Forms::Padding(4);
			this->ectsTB->Name = L"ectsTB";
			this->ectsTB->Size = System::Drawing::Size(132, 22);
			this->ectsTB->TabIndex = 9;
			this->ectsTB->Text = L"ECTS";
			// 
			// peselTB
			// 
			this->peselTB->Location = System::Drawing::Point(1144, 28);
			this->peselTB->Name = L"peselTB";
			this->peselTB->Size = System::Drawing::Size(100, 22);
			this->peselTB->TabIndex = 10;
			this->peselTB->Text = L"pesel";
			// 
			// specializationTB
			// 
			this->specializationTB->Location = System::Drawing::Point(1284, 41);
			this->specializationTB->Name = L"specializationTB";
			this->specializationTB->Size = System::Drawing::Size(100, 22);
			this->specializationTB->TabIndex = 11;
			this->specializationTB->Text = L"Specialization";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1648, 628);
			this->Controls->Add(this->specializationTB);
			this->Controls->Add(this->peselTB);
			this->Controls->Add(this->ectsTB);
			this->Controls->Add(this->FieldOfStudyTB);
			this->Controls->Add(this->IndexTB);
			this->Controls->Add(this->gpaTB);
			this->Controls->Add(this->yearOfStudyTB);
			this->Controls->Add(this->degreeTB);
			this->Controls->Add(this->SecondNameTB);
			this->Controls->Add(this->FirstNameTB);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		void /*std::map<std::string, System::String^>*/ collectData()
		{
			msclr::interop::marshal_context context;
			System::String^ firstNameTBtemp = this->FirstNameTB->Text;
			System::String^ secondNameTBtemp = this->SecondNameTB->Text;
			System::String^ indexTBtemp = this->IndexTB->Text;
			System::String^ peselTBtemp = this->peselTB->Text;
			System::String^ fieldOfStudyTBtemp = this->FieldOfStudyTB->Text;
			System::String^ specializationTBtemp = this->specializationTB->Text;
			System::String^ degreeTBtemp = this->degreeTB->Text;
			System::String^ ectsTBtemp = this->ectsTB->Text;
			System::String^ yearOfStudyTBtemp = this->yearOfStudyTB->Text;
			System::String^ gpaTBtemp = this->gpaTB->Text;

			student->name = context.marshal_as<std::string>(firstNameTBtemp);
			student->secondName = context.marshal_as<std::string>(secondNameTBtemp);
			student->index = context.marshal_as<std::string>(indexTBtemp);
			student->pesel = context.marshal_as<std::string>(peselTBtemp);
			student->fieldOfStudy = context.marshal_as<std::string>(fieldOfStudyTBtemp);
			student->specialization = context.marshal_as<std::string>(specializationTBtemp);
			student->degreeOfStudy = context.marshal_as<std::string>(degreeTBtemp);
			student->ects = context.marshal_as<std::string>(ectsTBtemp);
			student->yearOfStudy = context.marshal_as<std::string>(yearOfStudyTBtemp);
			student->gpa = context.marshal_as<std::string>(gpaTBtemp);

			/*std::map<std::string, System::String^> datas;
			datas["firstName"] = this->FirstNameTB->Text;
			datas["secondName"] = this->SecondNameTB->Text;
			datas["index"] = this->IndexTB->Text;
			datas["pesel"] = this->peselTB->Text;
			datas["fieldOfStudy"] = this->FieldOfStudyTB->Text;
			datas["specialization"] = this->specializationTB->Text;;
			datas["degree"] = this->degreeTB->Text;
			datas["ects"] = this->ectsTB->Text;
			datas["yearOfStudy"] = this->yearOfStudyTB->Text;
			datas["gpa"] = this->gpaTB->Text;

			return datas;*/
		};
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		mainField->viewStudents(sqlCmd, sqlDt, sqlRd);
		students->disconnectDataBase(sqlRd, sqlConn);
		dataGridView1->DataSource = sqlDt;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->collectData();
		//std::map<std::string, System::String^>* datas2 = &datas;
		students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		mainField->update(modify::operations::add, sqlCmd, sqlDt, sqlRd, student);
		mainField->viewStudents(sqlCmd, sqlDt, sqlRd);
		students->disconnectDataBase(sqlRd, sqlConn);
		dataGridView1->DataSource = sqlDt;
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
}
