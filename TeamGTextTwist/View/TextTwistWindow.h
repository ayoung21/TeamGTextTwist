#ifndef TEXTTWISTWINDOW_H
#define TEXTTWISTWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

namespace view {
    class TextTwistWindow : public Fl_Window
    {
        public:
            TextTwistWindow(int width, int height, const char* title);
            virtual ~TextTwistWindow();

        protected:

        private:

            Fl_Output *lettersLabel;
            static void cbLetterSelected(Fl_Widget* widget, void* data);
    };
}
#endif // TEXTTWISTWINDOW_H
