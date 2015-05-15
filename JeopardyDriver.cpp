//************************************************************************
// Filename: JeopardyDriver.cpp
// Description: Creates a Jeopardy game and runs it
// Author: Naelin Aquino & Miriam Flores
// Last modified: 05-15-15
//************************************************************************


#include "Jeopardy.h"
#include <iostream>
using namespace std;

int main()
{
    Jeopardy game1;
    cout << "***************************************\n";
    cout << "*        Welcome to Jeopardy!         *\n";
    cout << "***************************************\n";
    game1.startGame();
    return 0;
}
