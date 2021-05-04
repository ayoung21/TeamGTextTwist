#include "HighScoreWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <FL/fl_types.h>
#include <sstream>
using namespace std;

namespace view
{

//Constructor for the high score window
HighScoreWindow::HighScoreWindow() : OkCancelWindow(330, 185, "High Scores!")
{
    begin();
    this->setOKLocation(90, 140);
    this->setCancelLocation(170, 140);

    this->leaderBoardBuffer = new Fl_Text_Buffer();
    this->leaderBoardTextDisplay = new Fl_Text_Display(30, 20, 275, 100);
    this->leaderBoardTextDisplay->textfont(FL_COURIER);
    this->leaderBoardTextDisplay->buffer(leaderBoardBuffer);

    //this->reader.createLeaderBoardFromFile(this->leaderBoard);
    this->leaderBoard = Leaderboard();

    Player player1 = Player("David", 354, 10);
    Player player2 = Player("Jim", 354, 12);
    Player player3 = Player("Tim", 400, 14);
    Player player4 = Player("Tom", 360, 13);
    Player player5 = Player("John", 200, 14);

    this->leaderBoard.addPlayer(player1);
    this->leaderBoard.addPlayer(player2);
    this->leaderBoard.addPlayer(player3);
    this->leaderBoard.addPlayer(player4);
    this->leaderBoard.addPlayer(player5);

    string boardString = this->leaderBoard.print();
    this->leaderBoardBuffer->text(boardString.c_str());
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
