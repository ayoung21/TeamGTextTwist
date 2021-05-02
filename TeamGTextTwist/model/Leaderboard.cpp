#include "Leaderboard.h"

namespace model
{
//Instantiates a new leaderboard
Leaderboard::Leaderboard()
{

}

Leaderboard::~Leaderboard()
{
    //dtor
}

//Adds a player to the leader board
//
//@precondition none
//@postcondition none
//
//@param player
//      The player to add to the leader board
void Leaderboard::addPlayer(Player& player)
{
    if (this->numberOfPlayers == 0)
    {
        this->players.push_back(player);
    }
    this->numberOfPlayers++;

}

int Leaderboard::getNumberOfPlayers()
{
    return this->numberOfPlayers;
}
}

