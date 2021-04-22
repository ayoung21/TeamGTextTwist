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

#include <vector>
#include <string>
using namespace std;

#include "FileIO.h"
using namespace fileIO;

namespace view {
    class TextTwistWindow : public Fl_Window
    {
        public:
            /*
            ** Constructor and Deconstructor
            */
            TextTwistWindow(int width, int height, const char* title);
            virtual ~TextTwistWindow();

        protected:

        private:
            /*
            ** Private Member Variables
            */
            FileIO fileIO;
            int windowWidth;
            int windowHeight;
            int centerXPosition;
            int centerYPosition;
            Fl_Button* newGameButton;
            Fl_Button* submitWordButton;
            vector<string> wordList;
            vector<Fl_Button*> letterButtons;
            vector<string> letters;
            string userWord;

            /*
            ** Private Methods
            */
            void initializeGamePlayButtons();
            void initializeLetters();
            string getRandomLetter();
            static void cbNewGame(Fl_Widget* widget, void* data);
            void resetGame();
            static void cbLetterSelected(Fl_Widget* widget, void* data);
            static void cbSubmitWord(Fl_Widget* widget, void* data);
            bool isValidWord();
    };
}
#endif // TEXTTWISTWINDOW_H
