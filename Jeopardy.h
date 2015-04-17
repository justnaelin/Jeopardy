#ifndef JEOPARDY_H_INCLUDED
#define JEOPARDY_H_INCLUDED

//************************************************************************
// Class name: Jeopardy
// Description:
// Authors: Naelin Aquino, Miriam Flores, Bianca Hernandez
// Last modified:
//************************************************************************

#include "Grid.h"
#include "Contestant.h"

class Jeopardy
{
    private:
        Grid board[6][5];
        Contestant player1, player2, player3;
    public:
        Jeopardy();
        void displayBoard();
        void displayGameOver();
        bool isGameOver();
        bool whoWon();
        bool checkEndGame();
        void runGame();

};
#endif // JEOPARDY_H_INCLUDED
