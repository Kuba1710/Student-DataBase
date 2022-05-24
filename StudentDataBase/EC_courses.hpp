#pragma once
#include <memory>
#include <mysql.h>
#include "DataBase.hpp"
#include "FieldOfStudy.hpp"
#include "Modify.hpp"

namespace StudentDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Courses
	/// </summary>
	public ref class EC_courses : public System::Windows::Forms::Form
	{
		DataBase* studentDb = new DataBase();
		Student* students = new Student();

		FieldOfStudy* mainField = new FieldOfStudy();

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;

		DataGridView^ dataGrid = gcnew DataGridView();
		TextBox^ searchTB = gcnew TextBox();
		ComboBox^ cb = gcnew ComboBox();
		TextBox^ studentIndex = gcnew TextBox();
		
	
	private: array <TextBox^>^ coursesTextBoxes;

	public:
		EC_courses(DataGridView^ dt, TextBox^ search, ComboBox^ combo, Student* st, TextBox^ index)
		{
			InitializeComponent();
			coursesTextBoxes = gcnew array<TextBox^>{indexTb, wsopTb, poTb, pulTb, psTb, wscTb, PiITb};
			dataGrid = dt;
			searchTB = search;
			cb = combo;
			students = st;
			studentIndex = index;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EC_courses()
		{
			if (components)
			{
				delete components;
				delete students;
				delete mainField;
				delete studentDb;
			}
		}

	public:
	bool checkMarks()
	{
		for (int i = 1; i < 7; i++)
		{
			if (coursesTextBoxes[i]->Text != "0" || coursesTextBoxes[i]->Text != "2" || coursesTextBoxes[i]->Text != "3"
				|| coursesTextBoxes[i]->Text != "3.5" || coursesTextBoxes[i]->Text != "4" || coursesTextBoxes[i]->Text != "4.5"
				|| coursesTextBoxes[i]->Text != "5" || coursesTextBoxes[i]->Text != "5.5")
			{
				return false;
			}
		}
		return true;
	}

	private: System::Windows::Forms::Button^ updateButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label10;
	protected:
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ wsopTb;
	private: System::Windows::Forms::TextBox^ psTb;
	private: System::Windows::Forms::TextBox^ wscTb;




	private: System::Windows::Forms::TextBox^ pulTb;
	private: System::Windows::Forms::TextBox^ indexTb;


	private: System::Windows::Forms::TextBox^ PiITb;

	private: System::Windows::Forms::TextBox^ poTb;
	private: System::Windows::Forms::Button^ saveButton;


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
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->wsopTb = (gcnew System::Windows::Forms::TextBox());
			this->psTb = (gcnew System::Windows::Forms::TextBox());
			this->wscTb = (gcnew System::Windows::Forms::TextBox());
			this->pulTb = (gcnew System::Windows::Forms::TextBox());
			this->indexTb = (gcnew System::Windows::Forms::TextBox());
			this->PiITb = (gcnew System::Windows::Forms::TextBox());
			this->poTb = (gcnew System::Windows::Forms::TextBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(10, 110);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(257, 16);
			this->label10->TabIndex = 36;
			this->label10->Text = L"Programowanie uk³adów logicznych";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(10, 52);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(236, 16);
			this->label9->TabIndex = 35;
			this->label9->Text = L"Wbudowane systemy operacyjne";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(12, 197);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(152, 16);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Protoko³y i interfejsy";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(12, 168);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(234, 16);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Weryfikacja systemów cyfrowych";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(10, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 16);
			this->label5->TabIndex = 32;
			this->label5->Text = L"Procesory sygna³owe";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(10, 82);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(191, 16);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Programowanie obiektowe";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(10, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 16);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Index";
			// 
			// wsopTb
			// 
			this->wsopTb->Location = System::Drawing::Point(279, 51);
			this->wsopTb->Margin = System::Windows::Forms::Padding(2);
			this->wsopTb->Name = L"wsopTb";
			this->wsopTb->Size = System::Drawing::Size(56, 20);
			this->wsopTb->TabIndex = 29;
			// 
			// psTb
			// 
			this->psTb->Location = System::Drawing::Point(279, 138);
			this->psTb->Margin = System::Windows::Forms::Padding(2);
			this->psTb->Name = L"psTb";
			this->psTb->Size = System::Drawing::Size(56, 20);
			this->psTb->TabIndex = 28;
			// 
			// wscTb
			// 
			this->wscTb->Location = System::Drawing::Point(279, 168);
			this->wscTb->Name = L"wscTb";
			this->wscTb->Size = System::Drawing::Size(56, 20);
			this->wscTb->TabIndex = 27;
			// 
			// pulTb
			// 
			this->pulTb->Location = System::Drawing::Point(279, 109);
			this->pulTb->Name = L"pulTb";
			this->pulTb->Size = System::Drawing::Size(56, 20);
			this->pulTb->TabIndex = 26;
			// 
			// indexTb
			// 
			this->indexTb->Location = System::Drawing::Point(279, 20);
			this->indexTb->Name = L"indexTb";
			this->indexTb->ReadOnly = true;
			this->indexTb->Size = System::Drawing::Size(100, 20);
			this->indexTb->TabIndex = 25;
			this->indexTb->Text = L"index";
			// 
			// PiITb
			// 
			this->PiITb->Location = System::Drawing::Point(279, 197);
			this->PiITb->Name = L"PiITb";
			this->PiITb->Size = System::Drawing::Size(56, 20);
			this->PiITb->TabIndex = 24;
			// 
			// poTb
			// 
			this->poTb->Location = System::Drawing::Point(279, 78);
			this->poTb->Name = L"poTb";
			this->poTb->Size = System::Drawing::Size(56, 20);
			this->poTb->TabIndex = 23;
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveButton->Location = System::Drawing::Point(389, 200);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(106, 45);
			this->saveButton->TabIndex = 37;
			this->saveButton->Text = L"ADD";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &EC_courses::saveButton_Click);
			// 
			// updateButton
			// 
			this->updateButton->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->updateButton->Location = System::Drawing::Point(389, 138);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(106, 45);
			this->updateButton->TabIndex = 38;
			this->updateButton->Text = L"UPDATE";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &EC_courses::updateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(10, 226);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(357, 20);
			this->label1->TabIndex = 39;
			this->label1->Text = L"enter \"0\" if the student does not follow the course";
			// 
			// EC_courses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 260);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->wsopTb);
			this->Controls->Add(this->psTb);
			this->Controls->Add(this->wscTb);
			this->Controls->Add(this->pulTb);
			this->Controls->Add(this->indexTb);
			this->Controls->Add(this->PiITb);
			this->Controls->Add(this->poTb);
			this->Name = L"EC_courses";
			this->Text = L"EC_courses";
			this->Load += gcnew System::EventHandler(this, &EC_courses::EC_courses_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (checkMarks())
		{
			studentDb->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
			

			//dodawanie studenta + liczenie sredniej && ects
			mainField->update(modify::operations::add, sqlCmd, sqlDt, sqlRd, sqlDta, students, dataGrid, searchTB, sqlConn, cb, coursesTextBoxes);
			//dodawanie ocen
			mainField->update(modify::operations::addEC, sqlCmd, sqlDt, sqlRd, sqlDta, students, dataGrid, searchTB, sqlConn, cb, coursesTextBoxes);
			mainField->viewStudents(sqlCmd, sqlDt, sqlRd);
			studentDb->refreshDataBase(sqlConn, sqlDt, sqlDta, dataGrid);
			studentDb->disconnectDataBase(sqlRd, sqlConn);
			dataGrid->DataSource = sqlDt;
			this->Hide();
		}
		else
			MessageBox::Show("Write correct marks.");
	}
private: System::Void EC_courses_Load(System::Object^ sender, System::EventArgs^ e) {

	indexTb->Text = studentIndex->Text;
}
private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {

	if (checkMarks())
	{
		studentDb->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		mainField->update(modify::operations::updateStudent, sqlCmd, sqlDt, sqlRd, sqlDta, students, dataGrid, searchTB, sqlConn, cb, coursesTextBoxes);
		mainField->update(modify::operations::updateEC, sqlCmd, sqlDt, sqlRd, sqlDta, students, dataGrid, searchTB, sqlConn, cb, coursesTextBoxes);
		studentDb->refreshDataBase(sqlConn, sqlDt, sqlDta, dataGrid);
		studentDb->disconnectDataBase(sqlRd, sqlConn);
		this->Hide();
	}
	else
		MessageBox::Show("Write correct marks.");
}
};
}
