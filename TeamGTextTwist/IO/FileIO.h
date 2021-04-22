#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>
using namespace std;

namespace fileIO
{
    class FileIO
    {
        public:
            FileIO();
            virtual ~FileIO();
            void createWordListFromFile(vector<string>& wordList);

        protected:

        private:
    };
}

#endif // FILEIO_H
