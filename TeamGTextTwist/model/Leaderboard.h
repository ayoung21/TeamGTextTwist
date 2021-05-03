#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <algorithm>
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
    vector<Player> getPlayers();

protected:

private:
    vector<Player> players;
    int numberOfPlayers;
    void sortPlayers();

};
}

#endif // LEADERBOARD_H
