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

    // Initialize row and column
    row = 1;
    col = 1;
}
void Jeopardy::displayBoard()
{
    // TODO: Replace with actual category names
    cout << "1 - Songs\n"
         << "2 - Disney\n"
         << "3 - Harry Potter\n"
         << "4 - Musicals\n"
         << "5 - Greek Mythology\n";
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
    whoWon();
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
    // Compare player's individual scores
    for(int i = 1; i < 3; i++)
        if(Jeopardy::scoreboard[i] > Jeopardy::scoreboard[highest_score])
            highest_score = i;

    if(highest_score == 0)
        cout << "Player 1 Wins!\n";
    else if(highest_score == 1)
        cout << "Player 2 Wins!\n";
    else if(highest_score == 2)
        cout << "Player 3 Wins!\n";

}
bool Jeopardy::checkEndGame()
{
    if(isGameOver())
        exit(0);
}
/*void Jeopardy::runGame()
{
    int grid_points;
    initGrid();
    do
    {
        displayBoard();
        cout << "Select a row and column: \n";
        cin >> row >> col;
        grid_points = stoi(board[row][col].getGridValue());
        board[row][col].setGridValue("X");
        board[row][col].displayQuestion();
        cout << "Enter your answer: \n";
        cin >> contestant_answer;
        setContestantAnswer(contestant_answer);
        if(checkAnswer())
            addScore(grid_points);


    } while(true);
}*/
/*void Jeopardy::displayWinner(int id)
{
    assert(id < 3);
    cout << "Player " << (id + 1) << endl;
}*/
void Jeopardy::addToScoreboard(Contestant player, int grid_point_value)
{
    Jeopardy::scoreboard[player.getId()] += grid_point_value;
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
