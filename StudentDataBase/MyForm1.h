#pragma once
#include <memory>
#include <mysql.h>
#include "DataBase.hpp"
#include "FieldOfStudy.hpp"
#include "Modify.hpp"
#include <msclr\marshal_cppstd.h>
#include <map>
//a
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
		//std::unique_ptr<DataBase> students = std::make_unique<DataBase>();
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
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ refreshButton;
	private: System::Windows::Forms::TextBox^ ectsTB;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			std::unique_ptr<int> xxx = std::make_unique<int>();
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
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 236);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(1212, 262);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(37, 192);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(75, 23);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"ADD";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// FirstNameTB
			// 
			this->FirstNameTB->Location = System::Drawing::Point(24, 47);
			this->FirstNameTB->Name = L"FirstNameTB";
			this->FirstNameTB->Size = System::Drawing::Size(100, 20);
			this->FirstNameTB->TabIndex = 2;
			this->FirstNameTB->Text = L"FirstName";
			// 
			// SecondNameTB
			// 
			this->SecondNameTB->Location = System::Drawing::Point(130, 47);
			this->SecondNameTB->Name = L"SecondNameTB";
			this->SecondNameTB->Size = System::Drawing::Size(100, 20);
			this->SecondNameTB->TabIndex = 3;
			this->SecondNameTB->Text = L"Secondname";
			// 
			// degreeTB
			// 
			this->degreeTB->Location = System::Drawing::Point(608, 47);
			this->degreeTB->Name = L"degreeTB";
			this->degreeTB->Size = System::Drawing::Size(100, 20);
			this->degreeTB->TabIndex = 4;
			this->degreeTB->Text = L"degree";
			// 
			// yearOfStudyTB
			// 
			this->yearOfStudyTB->Location = System::Drawing::Point(820, 47);
			this->yearOfStudyTB->Name = L"yearOfStudyTB";
			this->yearOfStudyTB->Size = System::Drawing::Size(100, 20);
			this->yearOfStudyTB->TabIndex = 5;
			this->yearOfStudyTB->Text = L"yearOfStudy";
			// 
			// gpaTB
			// 
			this->gpaTB->Location = System::Drawing::Point(926, 47);
			this->gpaTB->Name = L"gpaTB";
			this->gpaTB->Size = System::Drawing::Size(100, 20);
			this->gpaTB->TabIndex = 6;
			this->gpaTB->Text = L"GPA";
			// 
			// IndexTB
			// 
			this->IndexTB->Location = System::Drawing::Point(236, 47);
			this->IndexTB->Name = L"IndexTB";
			this->IndexTB->Size = System::Drawing::Size(100, 20);
			this->IndexTB->TabIndex = 7;
			this->IndexTB->Text = L"index";
			// 
			// FieldOfStudyTB
			// 
			this->FieldOfStudyTB->Location = System::Drawing::Point(422, 47);
			this->FieldOfStudyTB->Name = L"FieldOfStudyTB";
			this->FieldOfStudyTB->Size = System::Drawing::Size(100, 20);
			this->FieldOfStudyTB->TabIndex = 8;
			this->FieldOfStudyTB->Text = L"FieldOfStudy";
			// 
			// ectsTB
			// 
			this->ectsTB->Location = System::Drawing::Point(714, 47);
			this->ectsTB->Name = L"ectsTB";
			this->ectsTB->Size = System::Drawing::Size(100, 20);
			this->ectsTB->TabIndex = 9;
			this->ectsTB->Text = L"ECTS";
			// 
			// peselTB
			// 
			this->peselTB->Location = System::Drawing::Point(341, 47);
			this->peselTB->Margin = System::Windows::Forms::Padding(2);
			this->peselTB->Name = L"peselTB";
			this->peselTB->Size = System::Drawing::Size(76, 20);
			this->peselTB->TabIndex = 10;
			this->peselTB->Text = L"pesel";
			// 
			// specializationTB
			// 
			this->specializationTB->Location = System::Drawing::Point(527, 47);
			this->specializationTB->Margin = System::Windows::Forms::Padding(2);
			this->specializationTB->Name = L"specializationTB";
			this->specializationTB->Size = System::Drawing::Size(76, 20);
			this->specializationTB->TabIndex = 11;
			this->specializationTB->Text = L"Specialization";
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(37, 80);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 12;
			this->clearButton->Text = L"CLEAR";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"FN";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(146, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"SN";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(268, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"INdex";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(459, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"FOS";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(635, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"degree";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(736, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Ects";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(847, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"YOS";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(956, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Gpa";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(361, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Pesel";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(561, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"S";
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(118, 192);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 23;
			this->deleteButton->Text = L"DELETE";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MyForm::deleteButton_Click);
			// 
			// refreshButton
			// 
			this->refreshButton->Location = System::Drawing::Point(130, 80);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(75, 23);
			this->refreshButton->TabIndex = 24;
			this->refreshButton->Text = L"REFRESH";
			this->refreshButton->UseVisualStyleBackColor = true;
			this->refreshButton->Click += gcnew System::EventHandler(this, &MyForm::refreshButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1236, 510);
			this->Controls->Add(this->refreshButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->clearButton);
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

		public:
			TextBox^ getFirstname()
			{
				return FirstNameTB;
			}
		public: void clearTextBoxes() {	// do czyszczenia textboxow (przycisk->CLEAR)
			FirstNameTB->Text = "";
			SecondNameTB->Text = "";
			degreeTB->Text = "";
			yearOfStudyTB->Text = "";
			gpaTB->Text = "";
			IndexTB->Text = "";
			FieldOfStudyTB->Text = "";
			peselTB->Text = "";
			specializationTB->Text = "";
			ectsTB->Text = "";
		};

		public: void showRow()	// do wyswietlania danych w textboxach w zaleznosci od wybrnego studenta z dataGridview1
		{
			try
			{
				FirstNameTB->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
				SecondNameTB->Text = dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString();
				IndexTB->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
				peselTB->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
				FieldOfStudyTB->Text = dataGridView1->SelectedRows[0]->Cells[4]->Value->ToString();
				specializationTB->Text = dataGridView1->SelectedRows[0]->Cells[5]->Value->ToString();
				degreeTB->Text = dataGridView1->SelectedRows[0]->Cells[6]->Value->ToString();
				ectsTB->Text = dataGridView1->SelectedRows[0]->Cells[7]->Value->ToString();
				yearOfStudyTB->Text = dataGridView1->SelectedRows[0]->Cells[8]->Value->ToString();
				gpaTB->Text = dataGridView1->SelectedRows[0]->Cells[9]->Value->ToString();
			}
			catch(Exception^ ex)	// zabezpieczenie zeby nie wywalalo od razu programu po zlym kliknieciu
			{
				MessageBox::Show("Aby wyœwietliæ studenta kliknij w kolumne z czarnym trójk¹tem.", "Tu nie klimamy!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

		}
					

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
	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->clearTextBoxes();
	}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	this->showRow();
}

private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

	this->collectData();
	students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
	mainField->update(modify::operations::deleteStudent, sqlCmd, sqlDt, sqlRd, student);
	mainField->viewStudents(sqlCmd, sqlDt, sqlRd);
	students->disconnectDataBase(sqlRd, sqlConn);
	dataGridView1->DataSource = sqlDt;
}
private: System::Void refreshButton_Click(System::Object^ sender, System::EventArgs^ e) {

	students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
	mainField->viewStudents(sqlCmd, sqlDt, sqlRd);
	students->disconnectDataBase(sqlRd, sqlConn);
	dataGridView1->DataSource = sqlDt;
}
};
}
