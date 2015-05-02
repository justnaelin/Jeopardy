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
#include <string>
#include <fstream>
using namespace std;

int Jeopardy::scoreboard[3] = {0, 0, 0};

Jeopardy::Jeopardy()
{
    // Initialize top row of Jeopardy grid to numbers 1-5
    // to represent categories
    for(int i = 0; i < 1; i++)
        for(int j = 0; j < 5; j++)
                board[i][j].setGridValue(to_string(j+1));

    // Initialize Jeopardy grid to point values
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
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

}
void Jeopardy::displayBoard()
{
    // TODO: Replace with actual category names
    cout << "1 - Category #1\n"
         << "2 - Category #2\n"
         << "3 - Category #3\n"
         << "4 - Category #4\n"
         << "5 - Category #5\n";
    for(int i = 1; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
             cout << board[i][j].getGridValue() << '\t';
        cout << endl;
    }
}
void Jeopardy::displayGameOver()
{
    cout << "GAME OVER\n";
    displayBoard();
}
bool Jeopardy::isGameOver()
{
    for(int i = 1; i < 6; i++)
        for(int j = 0; j < 6; j++)
            // If all questions have been chosen, the game is over
            // Otherwise, game is still going on
            if(board[i][j].isQuestionChosen() == false)
                return false;
    return true;
}
void Jeopardy::whoWon()
{
    int highest_score = 0;
    if(isGameOver())
    {
        // Compare player's individual scores
        for(int i = 1; i < 3; i++)
            if(Jeopardy::scoreboard[i] > Jeopardy::scoreboard[highest_score])
                highest_score = i;
    }
}
bool Jeopardy::checkEndGame()
{
    if(isGameOver())
        exit(0);
}
void Jeopardy::runGame(Contestant player)
{
    int grid_points;
    int row,
        col;
    string contestant_answer;
    //initGrid();
    do
    {
        displayBoard();
        cout << "Select a row and column: \n";
        cin >> row >> col;
        player.setRow(row);
        player.setCol(col);
        grid_points = stoi(board[player.getRow()][player.getCol()].getGridValue());
        board[player.getRow()][player.getCol()].setGridValue("X");
        board[player.getRow()][player.getCol()].displayQuestion();
        cout << "Enter your answer: \n";
        cin >> contestant_answer;
        player.setContestantAnswer(contestant_answer);
        if(board[player.getRow()][player.getCol()].checkAnswer(player))
            addToScoreboard(player, grid_points);

    } while(board[player.row][player.col].checkAnswer(player));
}
void Jeopardy::displayWinner(int id)
{
    assert(id < 3);
    cout << "Player " << (id + 1) << endl;
}
void Jeopardy::addToScoreboard(Contestant player)
{
    assert(player.getId() >= 0 || player.getId() < 3);
    Jeopardy::scoreboard[player.getId()] += player.getScore();
}
void Jeopardy::initGrid()
{
    // Initialize questions & answers
    ifstream question_file, answer_file;
    string x, y;

    while(!question_file.eof())
    {
        for(int i = 1; i < 6; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(j == 0)
                {
                    question_file.open("Category1.txt");
                    answer_file.open("Category1Answers.txt");

                    question_file >> x;
                    answer_file >> y;
                    board[j][i].setQuestion(x);
                    board[j][i].setAnswer(y);
                }
                if(j == 1)
                {
                    question_file.open("Category2.txt");
                    answer_file.open("Category2Answers.txt");

                    question_file >> x;
                    answer_file >> y;
                    board[j][i].setQuestion(x);
                    board[j][i].setAnswer(y);
                }
                if(j == 2)
                {
                    question_file.open("Category3.txt");
                    answer_file.open("Category3Answers.txt");

                    question_file >> x;
                    answer_file >> y;
                    board[j][i].setQuestion(x);
                    board[j][i].setAnswer(y);
                }
                if(j == 3)
                {
                    question_file.open("Category4.txt");
                    answer_file.open("Category4Answers.txt");

                    question_file >> x;
                    answer_file >> y;
                    board[j][i].setQuestion(x);
                    board[j][i].setAnswer(y);
                }
                if(j == 4)
                {
                    question_file.open("Category5.txt");
                    answer_file.open("Category5Answers.txt");

                    question_file >> x;
                    answer_file >> y;
                    board[j][i].setQuestion(x);
                    board[j][i].setAnswer(y);
                }
            }
        }
    }
}
void Jeopardy::WhoIsPlaying()
{
    do
    {

        runGame(player1);
        runGame(player2);
        runGame(player3);



    }while(!isGameOver());




}
