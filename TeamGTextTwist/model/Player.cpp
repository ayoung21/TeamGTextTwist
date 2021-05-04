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

//Deconstructor for the player object
Player::~Player()
{
    //dtor
}

//Gets the name of the player
//
//@precondition none
//@postcondition none
//
//@return the name of the player
const string& Player::getName()
{
    return this->name;
}

//Gets the score of the player
//
//@precondition none
//@postconditoin none
//
//@return the player score
const int Player::getScore()
{
    return this->score;
}

//Gets the time for the player
//
//@precondition none
//@postcondition none
//
//@return the time for the player on the given puzzle
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
}
