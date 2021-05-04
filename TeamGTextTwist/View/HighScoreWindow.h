#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include "OkCancelWindow.h"
#include <Fl/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include "Leaderboard.h"
#include "Player.h"
using namespace model;

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

            Fl_Text_Buffer *leaderBoardBuffer;
            Fl_Text_Display *leaderBoardTextDisplay;

            Leaderboard leaderBoard;
    };
}

#endif // HIGHSCOREWINDOW_H
