#include "Player.h"

namespace model
{
//Constructor for the player
//
//@param name
//      the name of the player
//@param score
//      the score of the player
//@param time
//      the time for the player
//
//@precondition none
//@postcondition none
Player::Player(const string& name, int score, int time)
{
    this->name = name;
    this->score = score;
    this->time = time;
}

Player::~Player()
{
    //dtor
}

//Gets the name of the player
const string& Player::getName()
{
    return this->name;
}

//Gets the score of the player
const int Player::getScore()
{
    return this->score;
}

//Gets the time for the player
const int Player::getTime()
{
    return this->time;
}

//Returns a string representation of the player
//
//@precondition none
//@postcodition none
//
//@returns string representation of the player
const string Player::toString()
{
    return this->name + " " + to_string(this->score) + " points " + to_string(this->time) + " seconds";
}

//Compare two players
//
//@precondition none
//@postcondition none
//
//@param otherPlayer
//      the player to compare to
//
//@return
int Player::compareTo(Player* otherPlayer)
{
    if (this->score < otherPlayer->getScore())
    {
        return -1;
    }
    else if (this->score > otherPlayer->getScore())
    {
        return 1;
    }
    else
    {
        if (this->time < otherPlayer->getTime())
        {
            return -1;
        }
        else if (this->time > otherPlayer->getTime())
        {

        }
        else
        {
            return 0;
        }
    }
}
}
