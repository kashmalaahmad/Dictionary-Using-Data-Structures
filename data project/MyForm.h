#pragma once
#include "Search.h"
#include "Insert.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>


namespace dataproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
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
			}
		}
	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::Button^ insert;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->search = (gcnew System::Windows::Forms::Button());
			this->insert = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// search
			// 
			this->search->BackColor = System::Drawing::Color::Gray;
			this->search->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->search->Location = System::Drawing::Point(31, 454);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(173, 39);
			this->search->TabIndex = 0;
			this->search->Text = L"Search";
			this->search->UseVisualStyleBackColor = false;
			this->search->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// insert
			// 
			this->insert->BackColor = System::Drawing::Color::Gray;
			this->insert->ForeColor = System::Drawing::Color::White;
			this->insert->Location = System::Drawing::Point(31, 508);
			this->insert->Name = L"insert";
			this->insert->Size = System::Drawing::Size(173, 40);
			this->insert->TabIndex = 1;
			this->insert->Text = L"Insert";
			this->insert->UseVisualStyleBackColor = false;
			this->insert->Click += gcnew System::EventHandler(this, &MyForm::insert_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(671, 384);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(572, 430);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(731, 560);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->insert);
			this->Controls->Add(this->search);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->BackgroundImageChanged += gcnew System::EventHandler(this, &MyForm::back);
			this->ResumeLayout(false);

		}
#pragma endregion
		void DisplayFileContent(String^ filePath, RichTextBox^ richTextBox)
		{
			std::ifstream file(msclr::interop::marshal_as<std::string>(filePath));

			if (file.is_open())
			{
				// Read the file content using std::istreambuf_iterator
				std::string fileContent((std::istreambuf_iterator<char>(file)),
					std::istreambuf_iterator<char>());

				// Convert the file content to System::String
				String^ content = gcnew String(fileContent.c_str());

				// Display the content in the RichTextBox
				richTextBox->Text = content;

				file.close();
			}
			else
			{
				MessageBox::Show("Unable to open file: " + filePath, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Search^ obj = gcnew Search(this);
		this->Hide();
		obj->ShowDialog();

	}

	private: System::Void insert_Click(System::Object^ sender, System::EventArgs^ e) {
		Insert^ obj = gcnew Insert(this);
		this->Hide();
		obj->ShowDialog();
	}


	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		/*OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Text Files|*.txt|All Files|*.*";
		openFileDialog1->Title = "Select a Text File";*/

		/*if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{*/
		String^ filePath = "C:/Users/Mala/Desktop/newww/data project - Copy (2)/data project/dictionary.txt";
			DisplayFileContent(filePath, richTextBox1);  // Assuming richTextBox1 is the name of your RichTextBox
	//}

	}
private: System::Void back_(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void back(System::Object^ sender, System::EventArgs^ e) {
}

};
}


