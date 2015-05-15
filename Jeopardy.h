#ifndef JEOPARDY_H_INCLUDED
#define JEOPARDY_H_INCLUDED

//************************************************************************
// Class name: Jeopardy
// Description: This class runs the entire game. It handles each player's
// turn in the game, the scoreboard, and updating the Jeopardy board
// Authors: Naelin Aquino & Miriam Flores
// Last modified: 05-15-14
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
        void runGame(Contestant player, int id);
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
        bool isDoubleJeopardy();
        // Summary: Checks if the grid is double jeopardy
        // Preconditions: A random row and column is set to double Jeopardy
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void dailyDouble();
        // Summary: Runs the daily double
        // Preconditions: The row and column must be daily double
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void finalJeopardy();
        // Summary: Runs the final Jeopardy
        // Preconditions: All questions must be chosen
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void checkWager(Contestant& player, int id);
        // Summary: Checks that the player's enter a wager amount within bounds
        // Preconditions: A player must have selected a daily double tile
        // Postconditions: ---
        //************************************************************************
        //************************************************************************
        void checkContestantsAnswers(Contestant& player, int id);
        // Summary: Checks the contestants answers to see if they are correct,
        // then adds points to the scoreboard
        // Preconditions: Player's must have entered their answers
        // Postconditions: If they get the question right, points are added
        //************************************************************************
};
#endif // JEOPARDY_H_INCLUDED
