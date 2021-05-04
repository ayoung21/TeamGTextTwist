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

void FileIO::createWordListFromFile(vector<string>& wordList)
{
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

void FileIO::createLeaderBoardFromFile(Leaderboard board)
{
    string fileName = "./leaderboard.txt";
    ifstream file(fileName);
    string line;
    while (getline(file, line))
    {
        vector<string> fields;
        fields.reserve(3);
        fields.clear();
        stringstream s_stream(line);
        while(s_stream.good())
        {
            string substring;
            getline(s_stream, substring, ',');
            fields.push_back(substring);
        }
        string name = fields[this->nameField];
        int score = stoi(fields[this->pointsField]);
        int time = stoi(fields[this->timeField]);
        Player player = Player(name, score, time);
        //cout << player.toString() << endl;
        board.addPlayer(player);
    }
}
}
