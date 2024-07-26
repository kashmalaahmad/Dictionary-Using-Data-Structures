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
	/// Summary for Search
	/// </summary>
	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Form^ backPage;
		Search(Form^ tempPage)
		{
			InitializeComponent();
			backPage = tempPage;
		}
		Search(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void update_call()
		{
			TrieNode t;
			System::String^ userInput = textBox1->Text;
			std::string userStdString = msclr::interop::marshal_as<std::string>(userInput);
			t.SearchWord(userStdString);
			System::String^ mean = updateT->Text;
			std::string m1 = msclr::interop::marshal_as<std::string>(mean);
			t.update("dictionary.txt", userStdString, m1);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ updateT;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::TextBox^ suggest;
	private: System::Windows::Forms::Button^ back_search;

	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->updateT = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->suggest = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->back_search = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(186, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 2;
			this->label1->Click += gcnew System::EventHandler(this, &Search::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 69);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Search::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(219, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Search::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(489, 114);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Suggest";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Search::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(618, 34);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Update";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Search::button4_Click);
			// 
			// updateT
			// 
			this->updateT->Location = System::Drawing::Point(410, 37);
			this->updateT->Name = L"updateT";
			this->updateT->Size = System::Drawing::Size(177, 20);
			this->updateT->TabIndex = 9;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(618, 105);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Search::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->suggest);
			this->panel1->Controls->Add(this->richTextBox2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->updateT);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(25, 286);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(705, 228);
			this->panel1->TabIndex = 10;
			this->panel1->Visible = false;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Search::panel1_Paint);
			// 
			// suggest
			// 
			this->suggest->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->suggest->Location = System::Drawing::Point(442, 76);
			this->suggest->Name = L"suggest";
			this->suggest->Size = System::Drawing::Size(100, 20);
			this->suggest->TabIndex = 12;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(15, 94);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(397, 96);
			this->richTextBox2->TabIndex = 11;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"New Meaning:";
			this->label2->Click += gcnew System::EventHandler(this, &Search::label2_Click);
			// 
			// back_search
			// 
			this->back_search->Location = System::Drawing::Point(25, 161);
			this->back_search->Name = L"back_search";
			this->back_search->Size = System::Drawing::Size(75, 23);
			this->back_search->TabIndex = 11;
			this->back_search->Text = L"Back";
			this->back_search->UseVisualStyleBackColor = true;
			this->back_search->Click += gcnew System::EventHandler(this, &Search::back_search_Click);
			// 
			// Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(756, 526);
			this->Controls->Add(this->back_search);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Search";
			this->Text = L"Search";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Show();

		TrieNode t;
		t.loadWordsFromFile("dictionary.txt");
		System::String^ userInput = textBox1->Text;
		std::string userStdString = msclr::interop::marshal_as<std::string>(userInput);
		t.SearchWord(userStdString);

		string s = t.s_meaning;
		System::String^ meaning = msclr::interop::marshal_as<System::String^>(s);
		textBox2->Text = meaning;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		TrieNode t;
		t.loadWordsFromFile("dictionary.txt");
		System::String^ delword = textBox1->Text;
		std::string dword = msclr::interop::marshal_as<std::string>(delword);

		// Display a confirmation dialog
		System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete the word?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		// Check the user's response
		if (result == System::Windows::Forms::DialogResult::Yes) {
			// User clicked Yes, proceed with the deletion
			t.deleteWordFromFile("dictionary.txt", dword);
		}
		else {
			// User clicked No, do nothing or handle accordingly
		}
	}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	TrieNode t;
	System::String^ userInput = textBox1->Text;
	std::string userStdString = msclr::interop::marshal_as<std::string>(userInput);

	// Display a confirmation dialog
	System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to update the data?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	// Check the user's response
	if (result == System::Windows::Forms::DialogResult::Yes) {
		// User clicked Yes, proceed with the update
		t.SearchWord(userStdString);
		System::String^ mean = updateT->Text;
		std::string m1 = msclr::interop::marshal_as<std::string>(mean);
		t.update("dictionary.txt", userStdString, m1);
	}
	else {
		// User clicked No, do nothing or handle accordingly
	}
}

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		TrieNode obj;
		obj.loadWordsFromFile("dictionary.txt");
		System::String^ input1 = suggest->Text;
		std::string suggestString = msclr::interop::marshal_as<std::string>(input1);
		obj.sWords(suggestString);
		String^ filePath = "C:/Users/Mala/Desktop/newww/data project - Copy (2)/data project/suggestion.txt";
		DisplayFileContent(filePath, richTextBox2);
	}
private: System::Void back_search_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	backPage->Show();
}
};
}
