#include "HighScoreWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <FL/fl_types.h>
#include <sstream>
using namespace std;

namespace view
{
    HighScoreWindow::HighScoreWindow() : OkCancelWindow(330, 185, "High Scores!")
    {
        begin();
        this->setOKLocation(90, 140);
        this->setCancelLocation(170, 140);

        this->leaderBoardBuffer = new Fl_Text_Buffer();
        this->leaderBoardTextDisplay = new Fl_Text_Display(45, 30, 200, 100);
        this->leaderBoardTextDisplay->textfont(FL_COURIER);
        this->leaderBoardTextDisplay->buffer(leaderBoardBuffer);
        end();
    }

    //
    // The instance handler when OK is invoked
    //
    // @precondition none
    // @postcondition none
    //
    void HighScoreWindow::okHandler()
    {
        try
        {
            this->hide();
        }
        catch (const char* message)
        {
            fl_message("%s", message);
        }

    }

    //
    // The instance handler when cancel is invoked
    //
    // @precondition none
    // @postcondition none
    //
    void HighScoreWindow::cancelHandler()
    {
        this->hide();
    }

    //
    // Destructor that cleans up all allocated resources for the window
    //
    HighScoreWindow::~HighScoreWindow()
    {
        //dtor
    }
}
