#pragma once
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "Student.hpp"
#include "Ief.hpp";
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
	/// Summary for IEFcourses
	/// </summary>
	public ref class IEFcourses : public System::Windows::Forms::Form
	{
		Student* studentIEF = new Student();
		Ief* ief = new Ief();
		DataBase* iefCourses = new DataBase();
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	public:
		IEFcourses(Student* studentIEF_) : studentIEF{ studentIEF_ }
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
		~IEFcourses()
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
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ TMtb;
	private: System::Windows::Forms::TextBox^ PEStb;
	private: System::Windows::Forms::TextBox^ opentb;
	private: System::Windows::Forms::TextBox^ montaztb;
	private: System::Windows::Forms::TextBox^ tptb;
	private: System::Windows::Forms::TextBox^ MMtb;
	private: System::Windows::Forms::TextBox^ O2tb;
	private: System::Windows::Forms::TextBox^ S2tb;
	private: System::Windows::Forms::TextBox^ M2tb;
	private: System::Windows::Forms::TextBox^ OOtb;
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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->TMtb = (gcnew System::Windows::Forms::TextBox());
			this->PEStb = (gcnew System::Windows::Forms::TextBox());
			this->opentb = (gcnew System::Windows::Forms::TextBox());
			this->montaztb = (gcnew System::Windows::Forms::TextBox());
			this->tptb = (gcnew System::Windows::Forms::TextBox());
			this->MMtb = (gcnew System::Windows::Forms::TextBox());
			this->O2tb = (gcnew System::Windows::Forms::TextBox());
			this->S2tb = (gcnew System::Windows::Forms::TextBox());
			this->M2tb = (gcnew System::Windows::Forms::TextBox());
			this->OOtb = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"General Courses";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(648, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 48);
			this->label2->TabIndex = 1;
			this->label2->Text = L"IEF courses";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(43, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(221, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Technika Mikrofalowa";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(43, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(326, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Podstawy eksploatacji systemów";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(43, 253);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"OpenLab";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(43, 310);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Monta¿";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(651, 142);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(165, 25);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Technika pró¿ni";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(651, 199);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(292, 25);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Modelowanie mikrosystemów";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(651, 253);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(175, 25);
			this->label9->TabIndex = 8;
			this->label9->Text = L"optoelektronika II";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(651, 310);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(147, 25);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Œwiat³owody II";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(651, 372);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(160, 25);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Mikrosystemy II";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(651, 439);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(262, 25);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Optoelektronika obrazowa";
			// 
			// TMtb
			// 
			this->TMtb->Location = System::Drawing::Point(393, 148);
			this->TMtb->Name = L"TMtb";
			this->TMtb->Size = System::Drawing::Size(100, 20);
			this->TMtb->TabIndex = 12;
			// 
			// PEStb
			// 
			this->PEStb->Location = System::Drawing::Point(393, 204);
			this->PEStb->Name = L"PEStb";
			this->PEStb->Size = System::Drawing::Size(100, 20);
			this->PEStb->TabIndex = 13;
			// 
			// opentb
			// 
			this->opentb->Location = System::Drawing::Point(393, 259);
			this->opentb->Name = L"opentb";
			this->opentb->Size = System::Drawing::Size(100, 20);
			this->opentb->TabIndex = 14;
			// 
			// montaztb
			// 
			this->montaztb->Location = System::Drawing::Point(393, 316);
			this->montaztb->Name = L"montaztb";
			this->montaztb->Size = System::Drawing::Size(100, 20);
			this->montaztb->TabIndex = 15;
			// 
			// tptb
			// 
			this->tptb->Location = System::Drawing::Point(975, 142);
			this->tptb->Name = L"tptb";
			this->tptb->Size = System::Drawing::Size(100, 20);
			this->tptb->TabIndex = 16;
			// 
			// MMtb
			// 
			this->MMtb->Location = System::Drawing::Point(975, 199);
			this->MMtb->Name = L"MMtb";
			this->MMtb->Size = System::Drawing::Size(100, 20);
			this->MMtb->TabIndex = 17;
			// 
			// O2tb
			// 
			this->O2tb->Location = System::Drawing::Point(975, 258);
			this->O2tb->Name = L"O2tb";
			this->O2tb->Size = System::Drawing::Size(100, 20);
			this->O2tb->TabIndex = 18;
			// 
			// S2tb
			// 
			this->S2tb->Location = System::Drawing::Point(975, 316);
			this->S2tb->Name = L"S2tb";
			this->S2tb->Size = System::Drawing::Size(100, 20);
			this->S2tb->TabIndex = 19;
			// 
			// M2tb
			// 
			this->M2tb->Location = System::Drawing::Point(975, 378);
			this->M2tb->Name = L"M2tb";
			this->M2tb->Size = System::Drawing::Size(100, 20);
			this->M2tb->TabIndex = 20;
			// 
			// OOtb
			// 
			this->OOtb->Location = System::Drawing::Point(975, 444);
			this->OOtb->Name = L"OOtb";
			this->OOtb->Size = System::Drawing::Size(100, 20);
			this->OOtb->TabIndex = 21;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(29, 484);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(1232, 36);
			this->okButton->TabIndex = 22;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &IEFcourses::okButton_Click);
			// 
			// IEFcourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1289, 546);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->OOtb);
			this->Controls->Add(this->M2tb);
			this->Controls->Add(this->S2tb);
			this->Controls->Add(this->O2tb);
			this->Controls->Add(this->MMtb);
			this->Controls->Add(this->tptb);
			this->Controls->Add(this->montaztb);
			this->Controls->Add(this->opentb);
			this->Controls->Add(this->PEStb);
			this->Controls->Add(this->TMtb);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
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
			this->Name = L"IEFcourses";
			this->Text = L"IEFcourses";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::string> marks = this->collectMarks();
		studentIEF->gpa = std::to_string(ief->countGPA(marks));
		studentIEF->ects = std::to_string(ief->countECTS(marks));
		iefCourses->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		ief->addCoursesToDataBase(sqlCmd, sqlDt, sqlRd, marks, studentIEF->index);
		iefCourses->disconnectDataBase(sqlRd, sqlConn);
		this->Hide();
	}
	public:
		std::vector<std::string> collectMarks()
		{
			msclr::interop::marshal_context context;
			System::String^ technikaMikrofalowaTemp = this->TMtb->Text;
			System::String^ PESTemp = this->PEStb->Text;
			System::String^ openlabTemp = this->opentb->Text;
			System::String^ montazTemp = this->montaztb->Text;
			System::String^ tpTemp = this->tptb->Text;
			System::String^ mmlTemp = this->MMtb->Text;
			System::String^ o2Temp = this->O2tb->Text;
			System::String^ s2Temp = this->S2tb->Text;
			System::String^ ooTemp = this->OOtb->Text;

			std::vector<std::string> ratesVector{
			context.marshal_as<std::string>(technikaMikrofalowaTemp),
			context.marshal_as<std::string>(PESTemp),
			context.marshal_as<std::string>(openlabTemp),
			context.marshal_as<std::string>(montazTemp),
			context.marshal_as<std::string>(tpTemp),
			context.marshal_as<std::string>(mmlTemp),
			context.marshal_as<std::string>(o2Temp),
			context.marshal_as<std::string>(s2Temp),
			context.marshal_as<std::string>(ooTemp),
			};

			return ratesVector;
		};
};
}
