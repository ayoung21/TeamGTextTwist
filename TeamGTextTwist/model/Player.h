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

protected:

private:
    string name;
    int score;
    int time;
};
}

#endif // PLAYER_H
