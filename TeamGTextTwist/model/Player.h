#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <algorithm>
using namespace std;

namespace model
{
class Player
{
public:
    Player(const string& name, int score, int time);
    virtual ~Player();

    const string& getName();
    const int getScore();
    const int getTime();

    const string toString();

    bool operator<(const Player player) const
    {
        if (score != player.score)
        {
            return score < player.score;
        }

        return time < player.time;
    }

    bool operator>(const Player player) const
    {
        if (score != player.score)
        {
            return score > player.score;
        }

        return time < player.time;
    }

protected:

private:
    string name;
    int score;
    int time;
};
}

#endif // PLAYER_H
