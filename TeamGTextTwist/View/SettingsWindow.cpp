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
    SettingsWindow::SettingsWindow() : OkCancelWindow(330, 200, "Settings")
    {

        begin();
        this->createAndDisplayTimeSettingOptions();
        this->createAndDisplayLetterReuseOptions();
        this->setOKLocation(90, 155);
        this->setCancelLocation(170, 155);
        end();
    }

    //
    // Destructor that cleans up all allocated resources for the window
    //
    SettingsWindow::~SettingsWindow()
    {
        //dtor
    }

    /*
    ** PRIVATE METHODS
    */

    void SettingsWindow::createAndDisplayTimeSettingOptions()
    {
        const int X_RADIO_GROUP = 75;
        const int Y_RADIO_GROUP = 45;
        const int WIDTH_RADIO_GROUP = 250;
        const int HEIGHT_RADIO_GROUP = 100;


        this->timeSettingsRadioGroup = new Fl_Group(5, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP, "Game Duration [in minutes]");
        this->timeSettingsRadioGroup->begin();

        for (int index = 0; index < NUMBER_OF_TIME_OPTIONS; index++)
        {
            this->timeDurationLabels[index] = new string(to_string(index + 1) + " Min(s)");
            this->timeSettingsRadioGroupButton[index] = new Fl_Round_Button(25 + (index * 100), Y_RADIO_GROUP + 10, 12, 12, timeDurationLabels[index]->c_str());
            this->timeSettingsRadioGroupButton[index]->type(FL_RADIO_BUTTON);
            this->timeSettingsRadioGroupButton[index]->callback(cbTimeSettingChanged, this);
        }

        this->timeSettingsRadioGroup->end();
        this->timeSettingsRadioGroupButton[0]->set();
        this->currentDurationOption = ONE;
    }

    void SettingsWindow::createAndDisplayLetterReuseOptions()
    {
        const int X_RADIO_GROUP = 35;
        const int Y_RADIO_GROUP = 100;
        const int WIDTH_RADIO_GROUP = 100;
        const int HEIGHT_RADIO_GROUP = 100;


        this->toggleReuseRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP, "Reuse of Letters");
        this->toggleReuseRadioGroup->begin();

        for (int index = 0; index < 2; index++)
        {
            this->timeDurationLabels[index] = (index == 0) ? new string("False") : new string("True");
            this->toggleReuseRadioGroupButton[index] = new Fl_Round_Button(25 + (index * 100), Y_RADIO_GROUP + 10, 12, 12, timeDurationLabels[index]->c_str());
            this->toggleReuseRadioGroupButton[index]->type(FL_RADIO_BUTTON);
            this->toggleReuseRadioGroupButton[index]->callback(cbReuseLettersChanged, this);
        }

        this->toggleReuseRadioGroup->end();
        this->toggleReuseRadioGroupButton[0]->set();
        this->currentReuseOption = FALSE;
    }

    void SettingsWindow::cbTimeSettingChanged(Fl_Widget* widget, void* data)
    {
        SettingsWindow* window = (SettingsWindow*)data;

        for (int index = 0; index < NUMBER_OF_TIME_OPTIONS; index++)
        {
            if (window->timeSettingsRadioGroupButton[index]->value())
            {
                window->currentDurationOption = (DURATION_IN_MINUTES)index;
            }
        }
    }

    void SettingsWindow::cbReuseLettersChanged(Fl_Widget* widget, void* data)
    {
        SettingsWindow* window = (SettingsWindow*)data;

        for (int index = 0; index < NUMBER_OF_TOGGLE_OPTIONS; index++)
        {
            if (window->toggleReuseRadioGroupButton[index]->value())
            {
                window->currentReuseOption = (REUSE_LETTERS)index;
            }
        }
    }

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

    void SettingsWindow::cancelHandler()
    {
        this->hide();
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
