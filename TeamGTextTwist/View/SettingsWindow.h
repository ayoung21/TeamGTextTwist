#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "OkCancelWindow.h"
#include <Fl/Fl_Input.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>

#include <string>
using namespace std;

namespace view
{
class SettingsWindow : public OkCancelWindow
{
public:
    SettingsWindow();
    virtual ~SettingsWindow();

            //
            // Defines the game time in minutes
            //
            enum DURATION_IN_MINUTES { ONE, TWO, THREE };
            //
            // Defines the options to reuse letters
            //
            enum REUSE_LETTERS { FALSE, TRUE };

        protected:

        private:
            static const int NUMBER_OF_TIME_OPTIONS = 3;
            static const int NUMBER_OF_TOGGLE_OPTIONS = 2;

            string* timeDurationLabels[NUMBER_OF_TIME_OPTIONS];
            string* toggleReuseLabels[NUMBER_OF_TOGGLE_OPTIONS];

            Fl_Group *timeSettingsRadioGroup;
            Fl_Group *toggleReuseRadioGroup;
            Fl_Round_Button *timeSettingsRadioGroupButton[NUMBER_OF_TIME_OPTIONS];
            Fl_Round_Button *toggleReuseRadioGroupButton[NUMBER_OF_TOGGLE_OPTIONS];

            DURATION_IN_MINUTES currentDurationOption;
            REUSE_LETTERS currentReuseOption;

            static void cbTimeSettingChanged(Fl_Widget* widget, void* data);
            static void cbReuseLettersChanged(Fl_Widget* widget, void* data);

            void createAndDisplayTimeSettingOptions();
            void createAndDisplayLetterReuseOptions();
            void okHandler();
            void cancelHandler();
    };
}


#endif // SETTINGSWINDOW_H
