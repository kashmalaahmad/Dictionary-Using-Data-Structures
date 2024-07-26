#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int Asize = 26;

class TrieNode
{
public:
    char data;
    TrieNode* children[Asize];
    bool isEndOfWord;
    string meaning;
    string s_meaning;

    TrieNode(char ch = ' ') : data(ch), isEndOfWord(false)
    {
        for (int i = 0; i < Asize; ++i)
        {
            children[i] = nullptr;
        }
    }

    void search()
    {
        string a;
        cout << "Enter word To search: ";
        cin >> a;
        bool found = SearchWord(a);
    }

    ~TrieNode()
    {
        for (int i = 0; i < Asize; ++i)
        {
            delete children[i];
        }
    }

    void insertWord(const string& word, const string& mean)
    {
        TrieNode* current = this;
        for (char ch : word)
        {
            if (!islower(ch)) {
                cerr << "Invalid character: " << ch << endl;
                return ;
            }
            int index = ch - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode(ch);
            }
            current = current->children[index];
        }
        if (!current->isEndOfWord)
        {
            current->isEndOfWord = true;
            current->meaning = mean;
            
        }
 
    }

    TrieNode* SearchWord(const string& word)
    {
        TrieNode* current = this;
        for (char ch : word)
        {
            if (!islower(ch)) {
                cerr << "Invalid character: " << ch << endl;
                return NULL;
            }
            int index = ch - 'a';

            if (!current->children[index])
            {
                cout << "Word not found " << endl;
                return NULL;
            }

            current = current->children[index];
        }
            if (current->isEndOfWord)
            {
                cout << "Word Found " << endl;
                cout << "Meaning: " << current->meaning << endl;
                s_meaning = current->meaning;
                return current;
            }
            else
            {
                cout << "Not found" << endl;
                return NULL;
            }
    }
    void suggestWord(ofstream& file, string prefix, int& count)
    {
        if (count < 10 && isEndOfWord)
        {
            if (file.is_open())
            {
                file << prefix << "\n";
                count++;
            }
        }
        if (count > 10) {
            return;
        }
        for (int i = 0; i < Asize; ++i)
        {
            if (children[i])
            {
                children[i]->suggestWord(file,prefix + char('a' + i), count);
            }
        }
    }
    void sWords(string a)
    {
        int count = 0;
        ofstream file("suggestion.txt");
        
        suggestWord(file,a, count);
    }
    void update(const string& filename, const string& wordToUpdate, const string& newMeaning)
    {
        ifstream inputFile(filename);
        ofstream tempFile("temp.txt");

        if (inputFile.is_open() && tempFile.is_open())
        {
            string word, meaning;
            bool wordUpdated = false;

            while (inputFile >> word >> meaning)
            {
                // Check if the current word matches the word to update
                if (word == wordToUpdate)
                {
                    tempFile << word << " " << newMeaning << endl;
                    wordUpdated = true;
                }
                else
                {
                    tempFile << word << " " << meaning << endl;
                }
            }

            inputFile.close();
            tempFile.close();

            if (wordUpdated)
            {
                remove(filename.c_str()); // Delete the original file
                rename("temp.txt", filename.c_str()); // Rename the temporary file
                cout << "Word updated successfully." << endl;
            }
            else
            {
                cout << "Word not found for update." << endl;
                remove("temp.txt"); // Delete the temporary file if no word was updated
            }
        }
        else
        {
            cout << "Unable to open file(s) for update." << endl;
        }
    }


    void displayWords(string prefix)
    {
        if (isEndOfWord)
        {
            cout << prefix;
            if (!meaning.empty())
            {
                cout << "\tMeaning: " << meaning << endl;
            }
            cout << endl;
        }
        for (int i = 0; i < Asize; ++i)
        {
            if (children[i])
            {
                children[i]->displayWords(prefix + char('a' + i));
            }
        }
    }
    void loadWordsFromFile(const string& filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string word;
            while (file >> word >> meaning)
            {
                insertWord(word, meaning);
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file: " << filename << endl;
        }
    }


    void insert_user(string a,string b)
    {
        insertWord(a, b);
        // Save the newly inserted words to the file
        saveWordsToFile("dictionary.txt");
    }

    void saveWordsToFile(const string& filename)
    {
        ofstream file(filename, ios::out); // Open the file for writing (truncating existing content)
        if (file.is_open())
        {
            saveWordsToFileHelper(this, "", file);
            file.close();
        }
        else
        {
            cout << "Unable to open file for writing: " << filename << endl;
        }
    }
 
    void deleteWordFromFile(const string& filename, const string& wordToDelete)
    {
        ifstream inputFile(filename);
        ofstream tempFile("temp.txt");

        if (inputFile.is_open() && tempFile.is_open())
        {/*
            this->isEndOfWord = false;*/
            string word, meaning;
            bool wordDeleted = false;

            while (inputFile >> word >> meaning)
            {
                // Check if the current word matches the word to delete
                if (word == wordToDelete)
                {
                    wordDeleted = true;
                }
                else
                {
                    // Write the non-deleted words to the temporary file
                    tempFile << word << " " << meaning << endl;
                }
            }

            inputFile.close();
            tempFile.close();

            if (wordDeleted)
            {
                remove(filename.c_str()); // Delete the original file
                rename("temp.txt", filename.c_str()); // Rename the temporary file
            }
            else
            {
                cout << "Word not found for deletion." << endl;
                remove("temp.txt"); // Delete the temporary file if no word was deleted
            }
        }
        else
        {
            cout << "Unable to open file(s) for deletion." << endl;
        }
    }
    void input(string& a, string& b)
    {
        insert_user(a, b);
       
    }

private:
    void saveWordsToFileHelper(TrieNode* node, const string& prefix, ofstream& file)
    {
        if (node->isEndOfWord)
        {
            file << prefix << " " << node->meaning << endl;
        }
        for (int i = 0; i < Asize; ++i)
        {
            if (node->children[i])
            {
                saveWordsToFileHelper(node->children[i], prefix + char('a' + i), file);
            }
        }
    }
   
};

//int main()
//{
//    TrieNode t1(' ');
//    t1.loadWordsFromFile("dictionary.txt");
//    string a = "basim";
//    string b = "hsg";
//
//    t1.insert_user("dictionary.txt", a, b);
//
//    t1.update();
//    system("pause");
//    return 0;
//}