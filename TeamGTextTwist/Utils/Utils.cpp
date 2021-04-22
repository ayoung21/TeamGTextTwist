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
