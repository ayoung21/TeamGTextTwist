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

#include "GameManager.h"
using namespace controller;

#include "Utils.h"
#include "SettingsWindow.h"
#include "HighScoreWindow.h"

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
            ** Constants
            */
            const int DEFAULT_PADDING = 45;
            const int MIN_LETTERS_TO_SUBMIT = 3;

            /*
            ** Private Member Variables
            */
            // FileIO fileIO;
            GameManager gameManager;
            int windowWidth;
            int windowHeight;
            int centerXPosition;
            int centerYPosition;
            Fl_Button* newGameButton;
            Fl_Button* startGameButton;
            Fl_Button* settingsButton;
            Fl_Button* highScoreButton;
            Fl_Button* submitWordButton;
            Fl_Button* twistLettersButton;
            Fl_Button* undoLetterButton;
            Fl_Button* undoAllButton;
            vector<Fl_Button*> letterButtons;
            vector<string> letters;
            vector<Fl_Button*> buttonsSelected;
            string userWord;
            Fl_Text_Buffer *currentUserGuessBuffer;
            Fl_Text_Display *currentUserGuessDisplay;
            Fl_Text_Buffer *currentScoreBuffer;
            Fl_Text_Display *currentScoreDisplay;
            Fl_Text_Buffer *validWordsSubmittedBuffer;
            Fl_Text_Display *validWordsSubmittedDisplay;
            Fl_Output *currentScoreLabel;
            Fl_Output *duplicateWordSubmissionLabel;
            Fl_Output *timerLabel;
            int score = 0;
            int gameTime = 60;

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
            static void cbTwistLetters(Fl_Widget* widget, void* data);
            static void cbUndoLetter(Fl_Widget* widget, void* data);
            static void cbUndoAll(Fl_Widget* widget, void* data);
            static void cbStartGame(Fl_Widget* widget, void* data);
            static void cbOnTick(void* data);
            static void cbOpenSettings(Fl_Widget* widget, void* data);
            static void cbOpenScoreBoard(Fl_Widget* widget, void* data);
            void enableLetterButtons();
            void clearUserGuess();
            void addToScore(int wordLength);
            void updateScoreDisplay();
            void reduceScore();
            void updateValidWordsDisplay();
            bool isDuplicatedWordSubmission(string& userSubmittedWord);
            void undoLastGuess();
            void updateTimerLabel();
            void onTick();
            void startGame();
            void disableGameplayUI();
            void enableGameplayUI();
            void stopTick();
    };
}
#endif // TEXTTWISTWINDOW_H
