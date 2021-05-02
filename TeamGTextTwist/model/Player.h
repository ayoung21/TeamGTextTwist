#ifndef PLAYER_H
#define PLAYER_H

#include <string>
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
    int compareTo(Player* otherPlayer);

protected:

private:
    string name;
    int score;
    int time;
};
}

#endif // PLAYER_H
