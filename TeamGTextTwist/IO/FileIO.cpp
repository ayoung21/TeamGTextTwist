#include "FileIO.h"

#include <iostream>
#include <fstream>
using namespace std;

namespace fileIO
{
    FileIO::FileIO()
    {
        //ctor
    }

    FileIO::~FileIO()
    {
        //dtor
    }

    void FileIO::createWordListFromFile(vector<string>& wordList) {
        string fileName = "./words.txt";
        ifstream file(fileName);
        string word;

        if (!file.good())
        {
            cout << "--- FILE DOES NOT EXIST ---" << endl;
            return;
        }
        while (file.peek() != EOF)
        {
            getline(file, word, '\n');
            wordList.push_back(word);
        }

        file.close();
    }
}
