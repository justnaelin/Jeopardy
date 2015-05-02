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
        Contestant player1, player2, player3;
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

        void runGame();
        // Summary: Runs the game
        // Preconditions: Grid is initialized
        // Postconditions:
        //************************************************************************
        //***********,*************************************************************
        static void addToScoreboard(Contestant player);
        //************************************************************************
        static void addToScoreboard(Contestant player, int grid_point_value);
        // Summary: Gets player's score and adds it to the scoreboard array
        // Preconditions:
        // Postconditions: Score is added at player's index
        //************************************************************************
        //************************************************************************
        void displayWinner(int id);
        // Summary: Displays the winner according to the ID
        // Preconditions:
        // Postconditions:
        //************************************************************************

        void whosIsPlaying();
        Contestant whichContestant();

};


#endif // JEOPARDY_H_INCLUDED
