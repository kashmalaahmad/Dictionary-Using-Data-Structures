#pragma once
#include "dictionary.h"
#include <msclr/marshal_cppstd.h>
namespace dataproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Insert
	/// </summary>
	public ref class Insert : public System::Windows::Forms::Form
	{
	public:
		Form^ backPage;
		Insert(Form^ tempPage)
		{
			InitializeComponent();
			backPage = tempPage;
		}
		Insert(void)
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
		~Insert()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ WordI;
	protected:

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ MeanI;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ back_insert;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->WordI = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->MeanI = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->back_insert = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// WordI
			// 
			this->WordI->Location = System::Drawing::Point(337, 92);
			this->WordI->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->WordI->Name = L"WordI";
			this->WordI->Size = System::Drawing::Size(334, 31);
			this->WordI->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MeanI
			// 
			this->MeanI->Location = System::Drawing::Point(337, 182);
			this->MeanI->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->MeanI->Name = L"MeanI";
			this->MeanI->Size = System::Drawing::Size(334, 31);
			this->MeanI->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(247, 92);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Word:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(207, 185);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Meaning:";
			this->label2->Click += gcnew System::EventHandler(this, &Insert::label2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(1054, 496);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 44);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Insert";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Insert::button1_Click);
			// 
			// back_insert
			// 
			this->back_insert->BackColor = System::Drawing::Color::Gray;
			this->back_insert->ForeColor = System::Drawing::Color::White;
			this->back_insert->Location = System::Drawing::Point(70, 769);
			this->back_insert->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->back_insert->Name = L"back_insert";
			this->back_insert->Size = System::Drawing::Size(150, 44);
			this->back_insert->TabIndex = 6;
			this->back_insert->Text = L"Back";
			this->back_insert->UseVisualStyleBackColor = false;
			this->back_insert->Click += gcnew System::EventHandler(this, &Insert::back_insert_Click);
			// 
			// Insert
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->back_insert);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MeanI);
			this->Controls->Add(this->WordI);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"Insert";
			this->Text = L"Insert";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TrieNode t;
		t.loadWordsFromFile("dictionary.txt");
		System::String^ word = WordI->Text;
		std::string w1 = msclr::interop::marshal_as<std::string>(word);
		System::String^ mean = MeanI->Text;
		std::string m1 = msclr::interop::marshal_as<std::string>(mean);
		t.input(w1,m1);
	
	}
private: System::Void back_insert_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	backPage->Show();
}
};
}
