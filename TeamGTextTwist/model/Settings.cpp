#include "Settings.h"

namespace model
{
    Settings::Settings(int gameplayTime, bool reuseLetters)
    {
        this->gameplayTime = gameplayTime;
        this->reuseLetters = reuseLetters;
    }

    Settings::~Settings()
    {
        //dtor
    }

    // gets the current game play time
    // @precondition none
    // @postcondition none
    int Settings::getGameplayTime()
    {
        return this->gameplayTime;
    }

    // gets the current option for reusing letters
    // @precondition none
    // @postcondition none
    bool Settings::getReuseLetters()
    {
        return this->reuseLetters;
    }
}
