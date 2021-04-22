#include "TextTwistWindow.h"

#include <FL/fl_types.h>
#include <Fl/fl_draw.H>



#include <iostream>
#include <vector>
#include <FL/Fl_Button.H>
using namespace std;

namespace view {
    TextTwistWindow::TextTwistWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
    {
        begin();
        this->windowWidth = width;
        this->windowHeight = height;
        centerXPosition = (width / 2) + 30;
        centerYPosition = (height / 2) - 30;

        this->newGameButton = new Fl_Button(45, 50, 125, 50, "New Game");
        this->newGameButton->callback(cbNewGame, this);
        this->lettersLabel = new Fl_Output(this->centerXPosition, height - 125, 0, 0, "Letters:");


        this->initializeGamePlayButtons();
        end();
    }

    TextTwistWindow::~TextTwistWindow()
    {
        //dtor
    }

    //
    // Callback when a button is invoked
    //
    // @precondition widget != 0 AND data != 0
    // @postcondition none
    //
    // @param widget The widget that initiated the callback
    // @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    //
    void TextTwistWindow::cbLetterSelected(Fl_Widget* widget, void* data)
    {
        widget->deactivate();
    }

    void TextTwistWindow::cbNewGame(Fl_Widget* widget, void* data)
    {
        TextTwistWindow* window = (TextTwistWindow*)data;
        window->resetGame();
    }

    void TextTwistWindow::resetGame()
    {
        for (auto & button: letterButtons)
        {
            button->activate();
        }
    }

    /*
    ** PRIVATE METHODS
    */

    void TextTwistWindow::initializeGamePlayButtons()
    {
        int paddingLeft = 45;
        for (int index = 0; index < 7; index++) {
            int xPosition = (index * 75) + paddingLeft;
            Fl_Button* buttonToAdd = new Fl_Button(xPosition, this->windowHeight - 100, 50, 50, "test");
            buttonToAdd->callback(cbLetterSelected, this);
            this->letterButtons.push_back(buttonToAdd);
        }
    }
}
