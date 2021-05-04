#include "SettingsWindow.h"



#include "Utils.h"

#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{

//
// Constructs a settings window creating and initializing all the widgets that will be displayed
//
// @precondition none
// @postcondition none
//
SettingsWindow::SettingsWindow() : OkCancelWindow(330, 185, "Settings")
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
// @postcondition current settings will be applied
//
void SettingsWindow::okHandler()
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
void SettingsWindow::cancelHandler()
{
    this->hide();
}

//
// Destructor that cleans up all allocated resources for the window
//
SettingsWindow::~SettingsWindow()
{
    //dtor
}
}
