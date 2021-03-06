#include "TextTwistWindow.h"

#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <FL/Fl_Button.H>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include "Utils.h"

namespace view
{
TextTwistWindow::TextTwistWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->windowWidth = width;
    this->windowHeight = height;
    centerXPosition = (width / 2);
    centerYPosition = (height / 2);

    this->newGameButton = new Fl_Button(DEFAULT_PADDING, DEFAULT_PADDING, 125, 50, "New Game");
    this->newGameButton->callback(cbNewGame, this);

    this->startGameButton = new Fl_Button(DEFAULT_PADDING, DEFAULT_PADDING * 3, 125, 50, "Start Game");
    this->startGameButton->callback(cbStartGame, this);

    this->submitWordButton = new Fl_Button(45, height - 100, 125, 50, "Submit");
    this->submitWordButton->callback(cbSubmitWord, this);

    this->settingsButton = new Fl_Button(DEFAULT_PADDING * 5, DEFAULT_PADDING, 125, 50, "Settings");
    this->settingsButton->callback(cbOpenSettings, this);


    this->highScoreButton = new Fl_Button(DEFAULT_PADDING * 5, DEFAULT_PADDING * 3, 125, 50, "Scoreboard");
    this->highScoreButton->callback(cbOpenScoreBoard, this);

    this->twistLettersButton = new Fl_Button(200, height - 100, 125, 50, "Twist Letters");
    this->twistLettersButton->callback(cbTwistLetters, this);

    this->undoLetterButton = new Fl_Button(200, this->windowHeight - 250, 75, 25, "Undo");
    this->undoLetterButton->callback(cbUndoLetter, this);

    this->undoAllButton = new Fl_Button(300, this->windowHeight - 250, 75, 25, "Undo All");
    this->undoAllButton->callback(cbUndoAll, this);

    this->initializeLetters();
    this->initializeGamePlayButtons();

    this->currentUserGuessBuffer = new Fl_Text_Buffer();
    this->currentUserGuessDisplay = new Fl_Text_Display(45, this->windowHeight - 250, 125, 25);
    this->currentUserGuessDisplay->textfont(FL_COURIER);
    this->currentUserGuessDisplay->buffer(currentUserGuessBuffer);

    this->currentScoreLabel = new Fl_Output(this->windowWidth - 100, 55, 0, 0, "Current Score:");
    this->duplicateWordSubmissionLabel = new Fl_Output(300, this->windowHeight - 260, 100, 0, "Word has already been submitted...");
    this->duplicateWordSubmissionLabel->hide();

    this->currentScoreBuffer = new Fl_Text_Buffer();
    this->currentScoreDisplay = new Fl_Text_Display(this->windowWidth - 100, DEFAULT_PADDING, 50, 25);
    this->currentScoreDisplay->textfont(FL_COURIER);
    this->currentScoreDisplay->buffer(currentScoreBuffer);
    this->updateScoreDisplay();

    this->validWordsSubmittedBuffer = new Fl_Text_Buffer();
    this->validWordsSubmittedDisplay = new Fl_Text_Display(this->windowWidth - (150 + DEFAULT_PADDING), 100, 150, 275);
    this->validWordsSubmittedDisplay->textfont(FL_COURIER);
    this->validWordsSubmittedDisplay->buffer(validWordsSubmittedBuffer);

    this->gameTimeBuffer = new Fl_Text_Buffer();
    this->gameTimeDisplay = new Fl_Text_Display(45, this->windowHeight - 300, 50, 25);
    this->gameTimeDisplay->textfont(FL_COURIER);
    this->gameTimeDisplay->buffer(gameTimeBuffer);

    this->disableGameplayUI();
    this->updateTimerLabel();

    end();
}

TextTwistWindow::~TextTwistWindow()
{
    //dtor
}

void TextTwistWindow::cbOpenSettings(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;

    SettingsWindow settingsWindow;
    settingsWindow.set_modal();
    settingsWindow.show();

    while (settingsWindow.shown())
    {
        Fl::wait();
    }

    if (settingsWindow.getWindowResult() == OkCancelWindow::WindowResult::OK)
    {
        Settings* settings = settingsWindow.getSettings();
        window->timeSettings = settings->getGameplayTime();
        window->gameTime = settings->getGameplayTime();
        window->reuseLettersSettings = settings->getReuseLetters();
        cout << window->reuseLettersSettings << endl;
        window->updateTimerLabel();
        window->resetGame();
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
}

void TextTwistWindow::cbOpenScoreBoard(Fl_Widget* widget, void* data)
{
    HighScoreWindow highScoreWindow;
    highScoreWindow.set_modal();
    highScoreWindow.show();

    while (highScoreWindow.shown())
    {
        Fl::wait();
    }

    if (highScoreWindow.getWindowResult() == OkCancelWindow::WindowResult::OK)
    {
        // TODO: Scoreboard logic
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
}

void TextTwistWindow::cbOnTick(void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->onTick();
    // window->updateTimerLabel();
    Fl::repeat_timeout(1.0, cbOnTick, window);
}

void TextTwistWindow::stopTick()
{
    Fl::remove_timeout(cbOnTick);
}

void TextTwistWindow::cbStartGame(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    Fl::add_timeout(1.0, cbOnTick, (void*) window);
    window->startGame();
    window->startGameButton->deactivate();
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
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->userWord.append(widget->label());
    window->currentUserGuessBuffer->text(window->userWord.c_str());
    window->buttonsSelected.push_back((Fl_Button*) widget);

    if (!window->reuseLettersSettings)
    {
        widget->deactivate();
    }

    if (window->userWord.length() >= window->MIN_LETTERS_TO_SUBMIT)
    {
        window->submitWordButton->activate();
    }
}

void TextTwistWindow::cbUndoLetter(Fl_Widget*, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;

    int sizeOfVector = window->buttonsSelected.size();
    if (sizeOfVector > 0)
    {
        window->buttonsSelected[sizeOfVector - 1]->activate();
        window->buttonsSelected.pop_back();

        window->undoLastGuess();
    }

}

void TextTwistWindow::cbUndoAll(Fl_Widget*, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;

    window->clearUserGuess();
    window->enableLetterButtons();
    window->submitWordButton->deactivate();
}

void TextTwistWindow::cbNewGame(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->resetGame();
}

void TextTwistWindow::resetGame()
{
    for (auto & button : letterButtons)
    {
        string letter = this->getRandomLetter();
        char* letterToAdd = new char[letter.length() + 1];
        strcpy(letterToAdd, letter.c_str());

        button->label(letterToAdd);
    }
    this->enableLetterButtons();
    this->submitWordButton->deactivate();
    this->score = 0;
    this->gameTime = this->timeSettings;
    this->updateScoreDisplay();
    this->duplicateWordSubmissionLabel->hide();
    this->gameManager.resetGame();
    this->updateValidWordsDisplay();
    this->disableGameplayUI();
    this->stopTick();
    this->updateTimerLabel();
    this->startGameButton->activate();
}

void TextTwistWindow::cbSubmitWord(Fl_Widget* widget, void* data)
{
    TextTwistWindow* window = (TextTwistWindow*)data;
    window->duplicateWordSubmissionLabel->hide();

    if (window->gameManager.isValidWord(window->userWord))
    {
        if (window->gameManager.isDuplicateWordSubmission(window->userWord))
        {
            window->duplicateWordSubmissionLabel->show();
        }
        else
        {
            window->addToScore(window->userWord.length());
            window->updateScoreDisplay();
            window->gameManager.addPlayerGuess(window->userWord);
            window->updateValidWordsDisplay();
        }

    }
    else
    {
        window->reduceScore();
        window->updateScoreDisplay();
    }

    window->enableLetterButtons();
    window->clearUserGuess();
    window->submitWordButton->deactivate();
}

void TextTwistWindow::cbTwistLetters(Fl_Widget* widget, void* data)
{
    int padding = 45;

    TextTwistWindow* window = (TextTwistWindow*)data;

    srand(time(0));
    random_shuffle(window->letterButtons.begin(), window->letterButtons.end());


    vector<string> currentLetters;
    int counter = 0;
    for (auto & currentButton : window->letterButtons)
    {
        currentButton->position((counter * 77) + padding, window->windowHeight - 200);
        counter++;
        currentButton->redraw();
    }
}

/*
** PRIVATE METHODS
*/

void TextTwistWindow::initializeLetters()
{
    // Utils::initalizeLetters
    initalizeLetters(this->letters);
}

void TextTwistWindow::initializeGamePlayButtons()
{
    int paddingLeft = 45;
    for (int index = 0; index < 7; index++)
    {
        int xPosition = (index * 77) + paddingLeft;

        string letter = this->getRandomLetter();
        char* letterToAdd = new char[letter.length() + 1];
        strcpy(letterToAdd, letter.c_str());

        Fl_Button* buttonToAdd = new Fl_Button(xPosition, this->windowHeight - 200, 50, 50, letterToAdd);
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

void TextTwistWindow::clearUserGuess()
{
    this->userWord = "";
    this->currentUserGuessBuffer->text("");
}

void TextTwistWindow::enableLetterButtons()
{
    for (auto & button : letterButtons)
    {
        button->activate();
    }
}

void TextTwistWindow::undoLastGuess()
{
    this->userWord = this->userWord.substr(0, this->userWord.size() - 1);
    char* newUserWord = new char[userWord.length() + 1];
    strcpy(newUserWord, userWord.c_str());

    this->currentUserGuessBuffer->text(newUserWord);
}

void TextTwistWindow::addToScore(int wordLength)
{
    const int multiplier = 10;
    int pointsPerLetter = multiplier * wordLength;
    this->score += pointsPerLetter * wordLength;
}

void TextTwistWindow::updateScoreDisplay()
{
    cout << "Score: " << to_string(this->score) << endl;
    this->currentScoreBuffer->text(to_string(this->score).c_str());
}

void TextTwistWindow::reduceScore()
{
    const int pointsToReduce = 10;
    this->score -= pointsToReduce;
}

void TextTwistWindow::updateValidWordsDisplay()
{
    string words = "";
    for (string word : this->gameManager.getValidWordsSubmitted())
    {
        words += word + "\n";
    }
    this->validWordsSubmittedBuffer->text(words.c_str());
}

void TextTwistWindow::onTick()
{
    if (this->gameTime <= 0)
    {
        this->onGameOver();
    }
    else
    {
        this->gameTime--;
        this->updateTimerLabel();
    }
}

void TextTwistWindow::onGameOver()
{
    this->stopTick();
    this->disableGameplayUI();
}

void TextTwistWindow::updateTimerLabel()
{
    this->gameTimeBuffer->text(to_string(this->gameTime).c_str());
}

void TextTwistWindow::startGame()
{
    this->enableGameplayUI();
    this->gameTimeBuffer->text(to_string(this->gameTime).c_str());
}

void TextTwistWindow::disableGameplayUI()
{
    for (Fl_Button* currentButton : this->letterButtons)
    {
        currentButton->deactivate();
    }

    this->submitWordButton->deactivate();
    this->twistLettersButton->deactivate();
    this->undoLetterButton->deactivate();
    this->undoAllButton->deactivate();
}

void TextTwistWindow::enableGameplayUI()
{
    this->enableLetterButtons();
    this->twistLettersButton->activate();
    this->undoLetterButton->activate();
    this->undoAllButton->activate();
}
}
