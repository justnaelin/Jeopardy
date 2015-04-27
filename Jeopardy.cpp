//************************************************************************
// Filename: .cpp
// Description:
// Author: Naelin Aquino
// Last modified:
//************************************************************************

#include "Jeopardy.h"
#include "Grid.h"
#include <cassert>
#include <iostream>
using namespace std;

Jeopardy::Jeopardy()
{
    // Initialize top row of Jeopardy grid to numbers 1-5
    // to represent categories
    for(i = 0; i < 1; i++)
        for(int j = 0; j < 5; j++)
            board[i][j].setGridValue(to_string(j + 1));
    // Initialize Jeopardy grid to point values
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; i < 5; i++)
        {
            if(i == 1)
                board[i][j].setGridValue("200");
            if(i == 2)
                board[i][j].setGridValue("400");
            if(i == 3)
                board[i][j].setGridValue("600");
            if(i == 4)
                board[i][j].setGridValue("800");
            if(i == 5)
                board[i][j].setGridValue("1000");
        }
    }
    // TODO: Initialize questions & answers

    // Initialize row and column
    row = 1;
    col = 0;
}
void Jeopardy::displayBoard()
{
    // TODO: Replace with actual category names
    cout << "1 - Category #1\n"
         << "2 - Category #2\n"
         << "3 - Category #3\n"
         << "4 - Category #4\n"
         << "5 - Category #5\n";
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
            board[i][j].getGridValue();
        cout << endl;
    }
}
void Jeopardy::displayGameOver()
{
    cout << "GAME OVER\n";
    int id = whoWon();
    displayWinner(id);
    displayBoard();
}
bool Jeopardy::isGameOver()
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            // If all questions have been chosen, the game is over
            // Otherwise, game is still going on
            if(board[i][j].isQuestionChosen() == false)
                return false;
    return true;
}
int Jeopardy::whoWon()
{
    if(isGameOver)
    {
        // Compare player's individual scores
        int highest_score = 0;
        for(int i = 1; i < 3; i++)
            if(Jeopardy::scoreboard[i] > Jeopardy::scoreboard[highest_score])
                highest_score = i;
    }
    return highest_score;
}
void Jeopardy::checkEndGame()
{
    if(isGameOver())
        exit(0);
}
void Jeopardy::runGame()
{
    do
    {
        displayBoard();
        cout << "Select a row and column: \n";
        cin >> row >> column;
        board[row][column].setGridValue("X");
        board[row][column].displayQuestion();
    } while(true);
}
void Jeopardy::displayWinner(int id)
{
    assert(id < 3);
    cout << "Player " << (id + 1) << endl;
}

void static Jeopardy::addToScoreboard(Contestant player)
{
    assert(player.getId() >= 0 || player.getId() < 3);
    Jeopardy::scoreboard[player.getId()] += player.getScore();
}
