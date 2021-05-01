#include "HighScoreWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{
    HighScoreWindow::HighScoreWindow() : OKCancelWindow(330, 185, "High Scores!")
    {
        this->highScoreLabel = new Fl_Output(this->windowWidth - 100, 55, 0, 0, "High Scores:");
        this->setOKLocation(90, 140);
    }

    HighScoreWindow::~HighScoreWindow()
    {
        //dtor
    }

    void HighScoreWindow::okHandler()
    {

    }
}
