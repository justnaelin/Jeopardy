#ifndef JEOPARDY_H_INCLUDED
#define JEOPARDY_H_INCLUDED

//************************************************************************
// Class name: Jeopardy
// Description:
// Authors: Naelin Aquino
// Last modified:
//************************************************************************

#include "Grid.h"
#include "Contestant.h"

class Jeopardy
{
    private:
        Grid board[6][5];
        Contestant player1,
                   player2,
                   player3;
        static int scoreboard[3];
        void initGrid();

    public:
        Jeopardy();
        void displayBoard();
        void displayGameOver();
        bool isGameOver();
        void whoWon();
        bool checkEndGame();
        void runGame(Contestant player);
        void startGame();
        static void addToScoreboard(Contestant player, int grid_point_value);
        void displayWinner(int id);

};


#endif // JEOPARDY_H_INCLUDED
