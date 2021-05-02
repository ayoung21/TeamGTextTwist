#include "Player.h"

namespace model
{
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

const string Player::toString()
{
    return this->name + " " + to_string(this->score) + " points " + to_string(this->time) + " seconds";
}
}
