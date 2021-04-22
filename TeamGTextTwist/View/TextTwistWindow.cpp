#include "TextTwistWindow.h"

#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl_Button.H>

#include <iostream>
#include <vector>
#include <algorithm>
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

        this->initializeLetters();
        this->initializeGamePlayButtons();

        this->fileIO.createWordListFromFile(this->wordList);

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
        cout << widget->label() << endl;
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

    void TextTwistWindow::initializeLetters()
    {
        const int MAX_FREQUENCY = 11;
        for (int index = 0; index < MAX_FREQUENCY; index++)
        {
            if (index < 1)
            {

                this->letters.push_back("j");
                this->letters.push_back("k");
                this->letters.push_back("q");
                this->letters.push_back("x");
                this->letters.push_back("z");

            }
            if (index < 2)
            {
                this->letters.push_back("b");
                this->letters.push_back("c");
                this->letters.push_back("g");
                this->letters.push_back("g");
                this->letters.push_back("m");
                this->letters.push_back("p");
                this->letters.push_back("v");

            }
            if (index < 3)
            {

                this->letters.push_back("d");
                this->letters.push_back("u");
                this->letters.push_back("w");
                this->letters.push_back("y");

            }
            if (index < 4)
            {
                this->letters.push_back("l");
            }
            if (index < 5)
            {
                this->letters.push_back("h");
                this->letters.push_back("r");
            }
            if (index < 6)
            {
                this->letters.push_back("a");
                this->letters.push_back("i");
                this->letters.push_back("n");
                this->letters.push_back("s");
            }
            if (index < 8)
            {
                this->letters.push_back("o");
            }
            if (index < 9)
            {
                this->letters.push_back("t");
            }

            this->letters.push_back("e");
        }

        cout << "Size of Letters: " << endl;
        cout << this->letters.size();
    }

    void TextTwistWindow::initializeGamePlayButtons()
    {
        int paddingLeft = 45;
        for (int index = 0; index < 7; index++) {
            int xPosition = (index * 75) + paddingLeft;

            string letter = this->getRandomLetter();
            char* letterToAdd = new char[letter.length() + 1];
            strcpy(letterToAdd, letter.c_str());

            Fl_Button* buttonToAdd = new Fl_Button(xPosition, this->windowHeight - 100, 50, 50, letterToAdd);
            buttonToAdd->callback(cbLetterSelected, this);
            this->letterButtons.push_back(buttonToAdd);
        }
    }

    string TextTwistWindow::getRandomLetter()
    {
        srand(time(0));
        random_shuffle(this->letters.begin(), this->letters.end());
        string letter = this->letters.at(0);
        return letter;
    }
}
