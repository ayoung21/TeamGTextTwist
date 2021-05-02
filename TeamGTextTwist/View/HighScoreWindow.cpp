#include "HighScoreWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{
    HighScoreWindow::HighScoreWindow() : OkCancelWindow(330, 185, "High Scores!")
    {
        begin();
        this->setOKLocation(90, 140);
        this->setCancelLocation(170, 140);

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
