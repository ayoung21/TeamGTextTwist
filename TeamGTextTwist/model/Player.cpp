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
