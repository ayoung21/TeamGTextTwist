#include "Utils.h"

#include <algorithm>

//
// Converts and returns string in uppercase
//
// @precondition none
// @postcondition none
//
// @return Uppercase version of the string
//
const string toUpperCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    text.erase(std::remove(text.begin(), text.end(), '-'), text.end());

    return text;
}

//Initializes the letters for the buttons
//
//@precondition none
//@postcondition none
void initalizeLetters(vector<string> &letterList)
{
    const int MAX_FREQUENCY = 11;
    for (int index = 0; index < MAX_FREQUENCY; index++)
    {
        if (index < 1)
        {

            letterList.push_back("j");
            letterList.push_back("k");
            letterList.push_back("q");
            letterList.push_back("x");
            letterList.push_back("z");

        }
        if (index < 2)
        {
            letterList.push_back("b");
            letterList.push_back("c");
            letterList.push_back("g");
            letterList.push_back("g");
            letterList.push_back("m");
            letterList.push_back("p");
            letterList.push_back("v");

        }
        if (index < 3)
        {

            letterList.push_back("d");
            letterList.push_back("u");
            letterList.push_back("w");
            letterList.push_back("y");

        }
        if (index < 4)
        {
            letterList.push_back("l");
        }
        if (index < 5)
        {
            letterList.push_back("h");
            letterList.push_back("r");
        }
        if (index < 6)
        {
            letterList.push_back("a");
            letterList.push_back("i");
            letterList.push_back("n");
            letterList.push_back("s");
        }
        if (index < 8)
        {
            letterList.push_back("o");
        }
        if (index < 9)
        {
            letterList.push_back("t");
        }

        letterList.push_back("e");

    }

    cout << "Size of Letters Vector: " << letterList.size() << endl;
}
