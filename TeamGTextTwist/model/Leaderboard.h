#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
using namespace std;

#include "Player.h"

namespace model
{
class Leaderboard
{
public:
    Leaderboard();
    virtual ~Leaderboard();

    void addPlayer(Player& player);
    int getNumberOfPlayers();

protected:

private:
    vector<Player> players;
    int numberOfPlayers;

};
}

#endif // LEADERBOARD_H
