#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "TextTwistWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    TextTwistWindow mainWindow(600, 400, "Team G Text Twist");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
