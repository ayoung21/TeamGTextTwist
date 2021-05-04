#include "GameManager.h"


namespace controller
{

//Istantates a new GameManager
//
//@precondition none
//@postcondition none
GameManager::GameManager()
{
    this->fileIO.createWordListFromFile(this->wordList);
}

//Deconstructor for Game Manager object
GameManager::~GameManager()
{
}

//Adds a word to the guesses made by the player
//
//@precondition none
//@postcondition none
//
//@param word
//      The word guessed by the player
void GameManager::addPlayerGuess(string word)
{
    this->validWordsSubmitted.push_back(word);
}

//Determines if the given word is a valid word
//
//@precondition none
//@postcondition none
//
//@param word
//      The word guessed by the player
//
//@return true if the word is valid, false otherwise
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

//Determines if the word submitted has already been guessed
//
//@precondition none
//@postcondition none
//
//@param userSubmittedWord
//      The word submmited by the user
//
//@return true if the word has already been submitted, false otherwise
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

//Gets the valid words submitted
//
//@precondition none
//@postcondition none
//
//@return the valid words submitted by the player
vector<string> GameManager::getValidWordsSubmitted()
{
    return this->validWordsSubmitted;
}

//Resets the list of valid words submitted
//
//@precondition none
//@postcondition none
void GameManager::resetGame()
{
    this->validWordsSubmitted.clear();
}
}
