#pragma once
#include <mysql.h>
#include "DataBase.hpp"

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
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Button^ updataButton;
	private: System::Windows::Forms::TextBox^ textBoxFirstname;
	private: System::Windows::Forms::TextBox^ textBoxSecondname;
	private: System::Windows::Forms::TextBox^ textBoxIndex;
	private: System::Windows::Forms::TextBox^ textBoxPesel;
	private: System::Windows::Forms::TextBox^ textBoxFieldOfStudy;
	private: System::Windows::Forms::TextBox^ textBoxSpecialization;
	private: System::Windows::Forms::TextBox^ textBoxDegree;
	private: System::Windows::Forms::TextBox^ textBoxYearOfStudy;
	private: System::Windows::Forms::TextBox^ textBoxGpa;
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
	private: System::Windows::Forms::TextBox^ textBoxEcts;
	private: System::Windows::Forms::Button^ ResetButton;

		   DataBase* students = new DataBase();

	public:

		TextBox^ getTextBoxFirstname()	// czy takie gettery?
		{
			return textBoxFirstname;
		}

		void resetLabel()
		{
			try
			{
				textBoxFirstname->Text = "";
				textBoxSecondname->Text = "";
				textBoxIndex->Text = "";
				textBoxPesel->Text = "";
				textBoxFieldOfStudy->Text = "";
				textBoxSpecialization->Text = "";
				textBoxDegree->Text = "";
				textBoxEcts->Text = "";
				textBoxYearOfStudy->Text = "";
				textBoxGpa->Text = "";
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

		void showCells()
		{
			textBoxFirstname->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
			textBoxSecondname->Text = dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString();
			textBoxIndex->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
			textBoxPesel->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
			textBoxFieldOfStudy->Text = dataGridView1->SelectedRows[0]->Cells[4]->Value->ToString();
			textBoxSpecialization->Text = dataGridView1->SelectedRows[0]->Cells[5]->Value->ToString();
			textBoxDegree->Text = dataGridView1->SelectedRows[0]->Cells[6]->Value->ToString();
			textBoxEcts->Text = dataGridView1->SelectedRows[0]->Cells[7]->Value->ToString();
			textBoxYearOfStudy->Text = dataGridView1->SelectedRows[0]->Cells[8]->Value->ToString();
			textBoxGpa->Text = dataGridView1->SelectedRows[0]->Cells[9]->Value->ToString();
		}

		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete students;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->updataButton = (gcnew System::Windows::Forms::Button());
			this->textBoxFirstname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSecondname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxIndex = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPesel = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFieldOfStudy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSpecialization = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDegree = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearOfStudy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGpa = (gcnew System::Windows::Forms::TextBox());
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
			this->textBoxEcts = (gcnew System::Windows::Forms::TextBox());
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(48, 99);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(537, 515);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(495, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// updataButton
			// 
			this->updataButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->updataButton->Location = System::Drawing::Point(135, 70);
			this->updataButton->Name = L"updataButton";
			this->updataButton->Size = System::Drawing::Size(75, 23);
			this->updataButton->TabIndex = 2;
			this->updataButton->Text = L"updata";
			this->updataButton->UseVisualStyleBackColor = true;
			this->updataButton->Click += gcnew System::EventHandler(this, &MyForm::updataButton_Click);
			// 
			// textBoxFirstname
			// 
			this->textBoxFirstname->Location = System::Drawing::Point(757, 99);
			this->textBoxFirstname->Name = L"textBoxFirstname";
			this->textBoxFirstname->Size = System::Drawing::Size(122, 20);
			this->textBoxFirstname->TabIndex = 6;
			// 
			// textBoxSecondname
			// 
			this->textBoxSecondname->Location = System::Drawing::Point(757, 150);
			this->textBoxSecondname->Name = L"textBoxSecondname";
			this->textBoxSecondname->Size = System::Drawing::Size(122, 20);
			this->textBoxSecondname->TabIndex = 7;
			// 
			// textBoxIndex
			// 
			this->textBoxIndex->Location = System::Drawing::Point(757, 200);
			this->textBoxIndex->Name = L"textBoxIndex";
			this->textBoxIndex->Size = System::Drawing::Size(122, 20);
			this->textBoxIndex->TabIndex = 8;
			// 
			// textBoxPesel
			// 
			this->textBoxPesel->Location = System::Drawing::Point(757, 255);
			this->textBoxPesel->Name = L"textBoxPesel";
			this->textBoxPesel->Size = System::Drawing::Size(122, 20);
			this->textBoxPesel->TabIndex = 9;
			// 
			// textBoxFieldOfStudy
			// 
			this->textBoxFieldOfStudy->Location = System::Drawing::Point(757, 309);
			this->textBoxFieldOfStudy->Name = L"textBoxFieldOfStudy";
			this->textBoxFieldOfStudy->Size = System::Drawing::Size(122, 20);
			this->textBoxFieldOfStudy->TabIndex = 10;
			// 
			// textBoxSpecialization
			// 
			this->textBoxSpecialization->Location = System::Drawing::Point(757, 357);
			this->textBoxSpecialization->Name = L"textBoxSpecialization";
			this->textBoxSpecialization->Size = System::Drawing::Size(122, 20);
			this->textBoxSpecialization->TabIndex = 11;
			// 
			// textBoxDegree
			// 
			this->textBoxDegree->Location = System::Drawing::Point(757, 411);
			this->textBoxDegree->Name = L"textBoxDegree";
			this->textBoxDegree->Size = System::Drawing::Size(122, 20);
			this->textBoxDegree->TabIndex = 12;
			// 
			// textBoxYearOfStudy
			// 
			this->textBoxYearOfStudy->Location = System::Drawing::Point(757, 519);
			this->textBoxYearOfStudy->Name = L"textBoxYearOfStudy";
			this->textBoxYearOfStudy->Size = System::Drawing::Size(122, 20);
			this->textBoxYearOfStudy->TabIndex = 13;
			// 
			// textBoxGpa
			// 
			this->textBoxGpa->Location = System::Drawing::Point(757, 578);
			this->textBoxGpa->Name = L"textBoxGpa";
			this->textBoxGpa->Size = System::Drawing::Size(122, 20);
			this->textBoxGpa->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(620, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 20);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Firstname";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(620, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Secondname";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(620, 200);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 17;
			this->label3->Text = L"index";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(620, 255);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 20);
			this->label4->TabIndex = 18;
			this->label4->Text = L"pesel";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(620, 309);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 20);
			this->label5->TabIndex = 19;
			this->label5->Text = L"fieldOfStudy";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(620, 357);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(121, 20);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Specialization";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(620, 411);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 20);
			this->label7->TabIndex = 21;
			this->label7->Text = L"degree";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(620, 464);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 20);
			this->label8->TabIndex = 22;
			this->label8->Text = L"ects";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(620, 519);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(108, 20);
			this->label9->TabIndex = 23;
			this->label9->Text = L"yearOfStudy";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(620, 578);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(39, 20);
			this->label10->TabIndex = 24;
			this->label10->Text = L"gpa";
			// 
			// textBoxEcts
			// 
			this->textBoxEcts->Location = System::Drawing::Point(757, 466);
			this->textBoxEcts->Name = L"textBoxEcts";
			this->textBoxEcts->Size = System::Drawing::Size(122, 20);
			this->textBoxEcts->TabIndex = 25;
			// 
			// ResetButton
			// 
			this->ResetButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ResetButton->Location = System::Drawing::Point(386, 70);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(75, 23);
			this->ResetButton->TabIndex = 26;
			this->ResetButton->Text = L"reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &MyForm::ResetButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 653);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->textBoxEcts);
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
			this->Controls->Add(this->textBoxGpa);
			this->Controls->Add(this->textBoxYearOfStudy);
			this->Controls->Add(this->textBoxDegree);
			this->Controls->Add(this->textBoxSpecialization);
			this->Controls->Add(this->textBoxFieldOfStudy);
			this->Controls->Add(this->textBoxPesel);
			this->Controls->Add(this->textBoxIndex);
			this->Controls->Add(this->textBoxSecondname);
			this->Controls->Add(this->textBoxFirstname);
			this->Controls->Add(this->updataButton);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		//students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);
		//dataGridView1->DataSource = sqlDt;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (dataGridView1 == nullptr || dataGridView1->Rows->Count == 0)
		{
			students->connectToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd);	//wywolujemy metode na obiekcie students -
			// - z klasy DataBase.
			dataGridView1->DataSource = sqlDt;
		}
		else
			dataGridView1->Rows->Clear();	// ponowne nacisniecie przycisku czysci dataGridView1
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		this->showCells();
	}

	private: System::Void updataButton_Click(System::Object^ sender, System::EventArgs^ e) {

		try 
		{
			students->AddToDataBase(sqlConn, sqlCmd, sqlDt, sqlDta, sqlRd); // metoda dodaje nowego studenta do bazy danych
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Data entry form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}
	}
	private: System::Void ResetButton_Click(System::Object^ sender, System::EventArgs^ e) {

	this->resetLabel();
	}
};
}
