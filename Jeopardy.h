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
<<<<<<< HEAD
        void runGame(Contestant player);

=======
        void runGame();
>>>>>>> d0c14e002d59524727da4126529a84c11e27104b
        // Summary: Runs the game
        // Preconditions: Grid is initialized
        // Postconditions:
        //************************************************************************
<<<<<<< HEAD
        //***********,*************************************************************
        static void addToScoreboard(Contestant player);
=======
        //************************************************************************
        static void addToScoreboard(Contestant player, int grid_point_value);
>>>>>>> d0c14e002d59524727da4126529a84c11e27104b
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
<<<<<<< HEAD
        void whosIsPlaying();
=======
        Contestant whichContestant();
>>>>>>> d0c14e002d59524727da4126529a84c11e27104b

};


#endif // JEOPARDY_H_INCLUDED
