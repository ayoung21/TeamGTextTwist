#include "Leaderboard.h"

namespace model
{
//Instantiates a new leaderboard
Leaderboard::Leaderboard()
{
    this->players.reserve(5);
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
    this->players.push_back(player);
    this->numberOfPlayers++;
    this->sortPlayers();

}

void Leaderboard::sortPlayers()
{
    sort(players.begin(), players.end(), greater<Player>());
}

//Gets the number of players
//
//@precondition none
//@postcondition none
//
//@return the number of players in the leaderboard
int Leaderboard::getNumberOfPlayers()
{
    return this->numberOfPlayers;
}

//Gets the players in the vector
//
//@precondition none
//@postcondition none
//
//@return the vector of players
vector<Player> Leaderboard::getPlayers()
{
    return this->players;
}

const string Leaderboard::print()
{
    string output = "";
    for (Player currPlayer : this->players)
    {
        output += currPlayer.toString() + "\n";
    }
    return output;
}
}

