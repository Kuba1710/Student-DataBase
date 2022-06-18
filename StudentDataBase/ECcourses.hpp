#pragma once
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "Student.hpp"
#include "Ec.hpp";
#include "DataBase.hpp"
#include "Modify.hpp"

namespace StudentDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for ECcourses
	/// </summary>
	public ref class ECcourses : public System::Windows::Forms::Form
	{

		Student* studentEC = new Student();
		Ec* ec = new Ec();
		DataBase* ecCourses = new DataBase();
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::Label^ label6;
		   MySqlDataReader^ sqlRd;

	public:
		ECcourses(Student* studentEC_) : studentEC{ studentEC_}
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ECcourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ TechnikaMikrofalowaTB;
	private: System::Windows::Forms::TextBox^ PEStb;
	private: System::Windows::Forms::TextBox^ openlabTB;
	private: System::Windows::Forms::TextBox^ montazTB;
	private: System::Windows::Forms::TextBox^ poTB;
	private: System::Windows::Forms::TextBox^ pulTB;
	private: System::Windows::Forms::TextBox^ PStb;
	private: System::Windows::Forms::TextBox^ wsoTB;
	private: System::Windows::Forms::TextBox^ wscTB;
	private: System::Windows::Forms::Button^ okButton;











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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->TechnikaMikrofalowaTB = (gcnew System::Windows::Forms::TextBox());
			this->PEStb = (gcnew System::Windows::Forms::TextBox());
			this->openlabTB = (gcnew System::Windows::Forms::TextBox());
			this->montazTB = (gcnew System::Windows::Forms::TextBox());
			this->poTB = (gcnew System::Windows::Forms::TextBox());
			this->pulTB = (gcnew System::Windows::Forms::TextBox());
			this->PStb = (gcnew System::Windows::Forms::TextBox());
			this->wsoTB = (gcnew System::Windows::Forms::TextBox());
			this->wscTB = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 81);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Technika Mikrofalowa";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(12, 126);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(280, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Podstawy eksploatacji systemów";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 172);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"openlab";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(12, 225);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Monta¿ ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(442, 275);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(282, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Weryfikacja systemów cyfrowych";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(9, 20);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(318, 48);
			this->label7->TabIndex = 6;
			this->label7->Text = L"General Courses";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(440, 20);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(419, 48);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Specialization Courses";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(442, 81);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(234, 24);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Programowanie obiektowe";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(442, 126);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(317, 24);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Programowanie uk³adów logicznych";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(442, 172);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(194, 24);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Procesory sygna³owe";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(442, 225);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(289, 24);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Wbudowane systemy operacyjne";
			// 
			// TechnikaMikrofalowaTB
			// 
			this->TechnikaMikrofalowaTB->Location = System::Drawing::Point(254, 84);
			this->TechnikaMikrofalowaTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TechnikaMikrofalowaTB->Name = L"TechnikaMikrofalowaTB";
			this->TechnikaMikrofalowaTB->Size = System::Drawing::Size(76, 20);
			this->TechnikaMikrofalowaTB->TabIndex = 12;
			// 
			// PEStb
			// 
			this->PEStb->Location = System::Drawing::Point(254, 128);
			this->PEStb->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PEStb->Name = L"PEStb";
			this->PEStb->Size = System::Drawing::Size(76, 20);
			this->PEStb->TabIndex = 13;
			// 
			// openlabTB
			// 
			this->openlabTB->Location = System::Drawing::Point(254, 175);
			this->openlabTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->openlabTB->Name = L"openlabTB";
			this->openlabTB->Size = System::Drawing::Size(76, 20);
			this->openlabTB->TabIndex = 14;
			// 
			// montazTB
			// 
			this->montazTB->Location = System::Drawing::Point(254, 228);
			this->montazTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->montazTB->Name = L"montazTB";
			this->montazTB->Size = System::Drawing::Size(76, 20);
			this->montazTB->TabIndex = 15;
			// 
			// poTB
			// 
			this->poTB->Location = System::Drawing::Point(788, 81);
			this->poTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->poTB->Name = L"poTB";
			this->poTB->Size = System::Drawing::Size(76, 20);
			this->poTB->TabIndex = 16;
			// 
			// pulTB
			// 
			this->pulTB->Location = System::Drawing::Point(788, 126);
			this->pulTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pulTB->Name = L"pulTB";
			this->pulTB->Size = System::Drawing::Size(76, 20);
			this->pulTB->TabIndex = 17;
			// 
			// PStb
			// 
			this->PStb->Location = System::Drawing::Point(788, 175);
			this->PStb->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PStb->Name = L"PStb";
			this->PStb->Size = System::Drawing::Size(76, 20);
			this->PStb->TabIndex = 18;
			// 
			// wsoTB
			// 
			this->wsoTB->Location = System::Drawing::Point(788, 225);
			this->wsoTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->wsoTB->Name = L"wsoTB";
			this->wsoTB->Size = System::Drawing::Size(76, 20);
			this->wsoTB->TabIndex = 19;
			// 
			// wscTB
			// 
			this->wscTB->Location = System::Drawing::Point(788, 277);
			this->wscTB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->wscTB->Name = L"wscTB";
			this->wscTB->Size = System::Drawing::Size(76, 20);
			this->wscTB->TabIndex = 20;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(13, 316);
			this->okButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(951, 37);
			this->okButton->TabIndex = 21;
			this->okButton->Text = L"ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &ECcourses::okButton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(0, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"label6";
			// 
			// ECcourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 410);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->wscTB);
			this->Controls->Add(this->wsoTB);
			this->Controls->Add(this->PStb);
			this->Controls->Add(this->pulTB);
			this->Controls->Add(this->poTB);
			this->Controls->Add(this->montazTB);
			this->Controls->Add(this->openlabTB);
			this->Controls->Add(this->PEStb);
			this->Controls->Add(this->TechnikaMikrofalowaTB);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ECcourses";
			this->Text = L"ECcourses";
			this->Load += gcnew System::EventHandler(this, &ECcourses::ECcourses_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ECcourses_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	public:
		std::vector<std::string> collectMarks()
		{
			msclr::interop::marshal_context context;
			System::String^ technikaMikrofalowaTemp = this->TechnikaMikrofalowaTB->Text;
			System::String^ PESTemp = this->PEStb->Text;
			System::String^ openlabTemp = this->openlabTB->Text;
			System::String^ montazTemp = this->montazTB->Text;
			System::String^ poTemp = this->poTB->Text;
			System::String^ pulTemp = this->pulTB->Text;
			System::String^ psTemp = this->PStb->Text;
			System::String^ wsoTemp = this->wsoTB->Text;
			System::String^ wscTemp = this->wscTB->Text;

			std::vector<std::string> ratesVector{
			context.marshal_as<std::string>(technikaMikrofalowaTemp),
			context.marshal_as<std::string>(PESTemp),
			context.marshal_as<std::string>(openlabTemp),
			context.marshal_as<std::string>(montazTemp),
			context.marshal_as<std::string>(poTemp),
			context.marshal_as<std::string>(pulTemp),
			context.marshal_as<std::string>(psTemp),
			context.marshal_as<std::string>(wsoTemp),
			context.marshal_as<std::string>(wscTemp),
			};

			return ratesVector;
		};
private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<std::string> marks = this->collectMarks();
	studentEC->gpa = std::to_string(ec->countGPA(marks));
	studentEC->ects = std::to_string(ec->countECTS(marks));
	ecCourses->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
	ec->addCoursesToDataBase(sqlCmd, sqlDt,sqlRd, marks, studentEC->index);
	ecCourses->disconnectDataBase(sqlRd, sqlConn);
	this->Hide();
}
};
}
