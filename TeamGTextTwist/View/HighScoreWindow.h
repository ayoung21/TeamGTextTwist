#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include "OkCancelWindow.h"
#include <Fl/Fl_Input.H>

namespace view
{
    class HighScoreWindow : public OkCancelWindow
    {
        public:
            HighScoreWindow();
            virtual ~HighScoreWindow();

        protected:

        private:
            void okHandler();
            void cancelHandler();
    };
}

#endif // HIGHSCOREWINDOW_H
