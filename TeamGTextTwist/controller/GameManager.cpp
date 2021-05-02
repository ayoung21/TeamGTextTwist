#include "GameManager.h"

namespace controller
{
    GameManager::GameManager()
    {
        this->fileIO.createWordListFromFile(this->wordList);
    }

    GameManager::~GameManager()
    {
    }

    bool GameManager::isValidWord(string word)
    {
        string userInputUpper = toUpperCase(word);
        for (string word : this->wordList)
        {
            string wordUpper = toUpperCase(word);

            if (userInputUpper.compare(wordUpper) == 0)
            {
                return true;
            }
        }

        return false;
    }
}
