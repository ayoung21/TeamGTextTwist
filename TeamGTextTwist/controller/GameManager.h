#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Utils.h"

#include <string>
using namespace std;

#include "FileIO.h"
using namespace fileIO;

namespace controller
{
class GameManager
{
public:
    GameManager();
    virtual ~GameManager();

    void addPlayerGuess(string word);
    bool isValidWord(string word);
    bool isDuplicateWordSubmission(string word);
    vector<string> getValidWordsSubmitted();
    void resetGame();

protected:

private:
    FileIO fileIO;
    vector<string> wordList;
    vector<string> validWordsSubmitted;
};
}

#endif // GAMEMANAGER_H
