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

	/// <summary>
	/// Summary for IEF_coursess
	/// </summary>
	public ref class IEF_courses : public System::Windows::Forms::Form
	{
	public:
		IEF_courses(void)
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
		~IEF_courses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ saveButton;
	protected:
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ m2Tb;
	private: System::Windows::Forms::TextBox^ s2Tb;
	private: System::Windows::Forms::TextBox^ mwmTb;
	private: System::Windows::Forms::TextBox^ tjpTb;
	private: System::Windows::Forms::TextBox^ IndexTB;
	private: System::Windows::Forms::TextBox^ ooTb;
	private: System::Windows::Forms::TextBox^ szoTb;

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
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->m2Tb = (gcnew System::Windows::Forms::TextBox());
			this->s2Tb = (gcnew System::Windows::Forms::TextBox());
			this->mwmTb = (gcnew System::Windows::Forms::TextBox());
			this->tjpTb = (gcnew System::Windows::Forms::TextBox());
			this->IndexTB = (gcnew System::Windows::Forms::TextBox());
			this->ooTb = (gcnew System::Windows::Forms::TextBox());
			this->szoTb = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveButton->Location = System::Drawing::Point(395, 163);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(115, 45);
			this->saveButton->TabIndex = 52;
			this->saveButton->Text = L"SAVE";
			this->saveButton->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(11, 105);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(201, 16);
			this->label10->TabIndex = 51;
			this->label10->Text = L"Techniki jonowe i plazmowe";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(11, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(115, 16);
			this->label9->TabIndex = 50;
			this->label9->Text = L"Mikrosystemy II";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(13, 192);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 16);
			this->label7->TabIndex = 49;
			this->label7->Text = L"Optoelektronika obrazowa";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(13, 163);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(200, 16);
			this->label6->TabIndex = 48;
			this->label6->Text = L"Mikrosystemy w motoryzacji";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(11, 134);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 16);
			this->label5->TabIndex = 47;
			this->label5->Text = L"Swiat³owody II";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(11, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(232, 16);
			this->label4->TabIndex = 46;
			this->label4->Text = L"Systemy zabezpieczeñ obiektów";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(11, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 16);
			this->label3->TabIndex = 45;
			this->label3->Text = L"Index";
			// 
			// m2Tb
			// 
			this->m2Tb->Location = System::Drawing::Point(280, 46);
			this->m2Tb->Margin = System::Windows::Forms::Padding(2);
			this->m2Tb->Name = L"m2Tb";
			this->m2Tb->Size = System::Drawing::Size(56, 20);
			this->m2Tb->TabIndex = 44;
			// 
			// s2Tb
			// 
			this->s2Tb->Location = System::Drawing::Point(280, 133);
			this->s2Tb->Margin = System::Windows::Forms::Padding(2);
			this->s2Tb->Name = L"s2Tb";
			this->s2Tb->Size = System::Drawing::Size(56, 20);
			this->s2Tb->TabIndex = 43;
			// 
			// mwmTb
			// 
			this->mwmTb->Location = System::Drawing::Point(280, 163);
			this->mwmTb->Name = L"mwmTb";
			this->mwmTb->Size = System::Drawing::Size(56, 20);
			this->mwmTb->TabIndex = 42;
			// 
			// tjpTb
			// 
			this->tjpTb->Location = System::Drawing::Point(280, 104);
			this->tjpTb->Name = L"tjpTb";
			this->tjpTb->Size = System::Drawing::Size(56, 20);
			this->tjpTb->TabIndex = 41;
			// 
			// IndexTB
			// 
			this->IndexTB->Location = System::Drawing::Point(280, 15);
			this->IndexTB->Name = L"IndexTB";
			this->IndexTB->Size = System::Drawing::Size(100, 20);
			this->IndexTB->TabIndex = 40;
			this->IndexTB->Text = L"index";
			// 
			// ooTb
			// 
			this->ooTb->Location = System::Drawing::Point(280, 192);
			this->ooTb->Name = L"ooTb";
			this->ooTb->Size = System::Drawing::Size(56, 20);
			this->ooTb->TabIndex = 39;
			// 
			// szoTb
			// 
			this->szoTb->Location = System::Drawing::Point(280, 73);
			this->szoTb->Name = L"szoTb";
			this->szoTb->Size = System::Drawing::Size(56, 20);
			this->szoTb->TabIndex = 38;
			// 
			// IEF_coursess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 227);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->m2Tb);
			this->Controls->Add(this->s2Tb);
			this->Controls->Add(this->mwmTb);
			this->Controls->Add(this->tjpTb);
			this->Controls->Add(this->IndexTB);
			this->Controls->Add(this->ooTb);
			this->Controls->Add(this->szoTb);
			this->Name = L"IEF_coursess";
			this->Text = L"IEF_coursess";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
