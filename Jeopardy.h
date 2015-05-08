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
        int counter;
        void initGrid();

    public:
        //************************************************************************
        Jeopardy();
        // Summary: Assigns each player an ID, initializes the grid with category
        // numbers and point-values
        // Preconditions: ---
        // Postconditions: Grid is initialized
        //************************************************************************
        //************************************************************************
        void displayBoard();
        // Summary: Displays the scoreboard and the grid
        // Preconditions: The grid is initialized
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void displayGameOver();
        // Summary: Displays the winner and the final grid
        // Preconditions: isGameOver is true
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        bool isGameOver();
        // Summary: Checks if the game is over by seeing if all questions are chosen
        // Preconditions: All the questions are chosen
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void whoWon();
        // Summary: Compares the scores of all 3 players
        // Preconditions: isGameOver is true
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void runGame(Contestant player);
        // Summary: Displays the grid, asks the player to pick a question, gets
        // the players answer, checks if the answer if correct
        // Preconditions: The grid is initialized, players are initialized
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void startGame();
        // Summary: Starts the game by sending each Contestant object into the
        // runGame method
        // Preconditions: Everything is initialized
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        static void addToScoreboard(Contestant player, int grid_point_value);
        // Summary: Adds the player's score to the scoreboard
        // Preconditions: ---
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void displayWinner(int id);
        // Summary: Displays the player who won
        // Preconditions: isGameOver() is true
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        bool isDoubleJeopardy();
        // Summary: checks if the grid is double jeopardy
        // Preconditions:
        // Postconditions:
        //************************************************************************
        void dailyDouble();
        void finalJeopardy();


};
#endif // JEOPARDY_H_INCLUDED
