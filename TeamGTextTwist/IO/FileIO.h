#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "Leaderboard.h"
#include "Player.h"
using namespace model;

namespace fileIO
{
class FileIO
{
public:
    FileIO();
    virtual ~FileIO();
    void createWordListFromFile(vector<string>& wordList);
    void createLeaderBoardFromFile(Leaderboard board);

protected:

private:
    const int nameField = 0;
    const int pointsField = 1;
    const int timeField = 2;
};
}

#endif // FILEIO_H
