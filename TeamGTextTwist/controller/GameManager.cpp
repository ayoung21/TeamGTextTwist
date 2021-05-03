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

    void GameManager::addPlayerGuess(string word)
    {
        this->validWordsSubmitted.push_back(word);
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

    bool GameManager::isDuplicateWordSubmission(string userSubmittedWord)
    {
        string userInputUpper = toUpperCase(userSubmittedWord);
        for (string word : this->validWordsSubmitted)
        {
            string wordUpper = toUpperCase(word);
            if (userInputUpper.compare(wordUpper) == 0)
            {
                return true;
            }
        }

        return false;
    }

    vector<string> GameManager::getValidWordsSubmitted()
    {
        return this->validWordsSubmitted;
    }

    void GameManager::resetGame()
    {
        this->validWordsSubmitted.clear();
    }
}
