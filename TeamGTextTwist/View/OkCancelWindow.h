#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H


#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view
{

    //
    // Abstract class that can be used for any window that needs Ok and Cancel buttons on it.
    //
    class OkCancelWindow : public Fl_Window
    {
    public:
        enum WindowResult {OK, CANCEL, NONE};

    private:
        Fl_Button* okButton;
        Fl_Button* cancelButton;

        WindowResult buttonInvoked;

    public:
        OkCancelWindow(int width, int height, const char* title);
        virtual ~OkCancelWindow();

        void setOKLocation(int x, int y);
        void setCancelLocation(int x, int y);

        static void cbOk(Fl_Widget* widget, void* data);
        virtual void okHandler() = 0;

        static void cbCancel(Fl_Widget* widget, void* data);
        virtual void cancelHandler() = 0;

        OkCancelWindow::WindowResult setWindowResult(OkCancelWindow::WindowResult result);
        OkCancelWindow::WindowResult getWindowResult();
    };

}

#endif // OKCANCELWINDOW_H
