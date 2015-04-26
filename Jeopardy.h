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
        int row, // The row the player picks
            col; // The column the player picks
    public:
        //************************************************************************
        Jeopardy();
        // Summary: Initializes grid to respective categories and point values
        // Preconditions:
        // Postconditions: Grid contains category names and point values
        //************************************************************************
        //************************************************************************
        void displayBoard();
        // Summary: Displays the categories and point values in grid form
        // Preconditions: Jeopardy grid is initialized
        // Postconditions:
        //************************************************************************
        //************************************************************************
        void displayGameOver();
        // Summary: Displays "GAME OVER" if the game is over
        // Preconditions: isGameOver() is true
        // Postconditions:
        //************************************************************************
        //************************************************************************
        bool isGameOver();
        // Summary: Checks if the game is over
        // Preconditions: All questions have been chosen or not
        // Postconditions: Returns true if all questions have been chosen.
        // Otherwise, return false
        //************************************************************************
        //************************************************************************
        bool whoWon();
        // Summary: Checks scoreboard to see who has the highest points
        // Preconditions: Each player has a score and isGameOver() is true
        // Postconditions: Displays winner and winner's score
        //************************************************************************
        //************************************************************************
        bool checkEndGame();
        // Summary: Checks if the game is over
        // Preconditions:
        // Postconditions:
        //************************************************************************
        //************************************************************************
        void runGame();
        // Summary: Runs the game
        // Preconditions: Grid is initialized
        // Postconditions:
        //************************************************************************

};
#endif // JEOPARDY_H_INCLUDED
