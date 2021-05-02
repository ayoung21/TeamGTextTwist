#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "OkCancelWindow.h"
#include <Fl/Fl_Input.H>

namespace view
{
    class SettingsWindow : public OkCancelWindow
    {
        public:
            SettingsWindow();
            virtual ~SettingsWindow();

        protected:

        private:
            void okHandler();
            void cancelHandler();
    };
}


#endif // SETTINGSWINDOW_H
