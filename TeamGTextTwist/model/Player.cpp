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
}
