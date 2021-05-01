#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include "Student.h"
using namespace model;

#include <Fl/Fl_Input.H>

namespace view
{
    class HighScoreWindow : public OKCancelWindow
    {
        public:
            HighScoreWindow();
            virtual ~HighScoreWindow();
            void okHandler();

        protected:

        private:
            Fl_Output *highScoreLabel;
    };
}

#endif // HIGHSCOREWINDOW_H
