#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Utils.h"

#include <string>
using namespace std;

#include "FileIO.h"
using namespace fileIO;

namespace controller
{
    class GameManager
    {
        public:
            GameManager();
            virtual ~GameManager();

            bool isValidWord(string word);

        protected:

        private:
            FileIO fileIO;
            vector<string> wordList;
    };
}

#endif // GAMEMANAGER_H
