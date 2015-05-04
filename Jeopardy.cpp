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
    player1.setId(0);
    player2.setId(1);
    player3.setId(2);
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
    cout << "======Scoreboard======\n";
    cout << "P1: " << scoreboard[0] << '\t' << "P2: " << scoreboard[1] << '\t' << "P3: " << scoreboard[2] << endl;
    cout << "======================\n";

    cout << "1 - Songs\n"
         << "2 - Disney\n"
         << "3 - Harry Potter\n"
         << "4 - Musicals\n"
         << "5 - Greek Mythology\n";
    cout << endl;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
             cout << board[i][j].getGridValue() << '\t';
        cout << endl;
    }
    cout << endl;
}
void Jeopardy::displayGameOver()
{
    cout << "GAME OVER\n";
    displayBoard();
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
void Jeopardy::runGame(Contestant player)
{
    int grid_point_value;
    int row,
        col;
    string contestant_answer;

    do
    {
        displayBoard();
        cout << "Select a row and column: \n";
        cin >> row >> col;
        cin.ignore();

        player.setRow(row);
        player.setCol(col);
        grid_point_value = stoi(board[player.getRow()][player.getCol()].getGridValue());
        board[player.getRow()][player.getCol()].setGridValue("X");
        board[player.getRow()][player.getCol()].displayQuestion();

        cout << "Enter your answer: \n";
        getline(cin, contestant_answer);
        player.setContestantAnswer(contestant_answer);
        if(board[player.getRow()][player.getCol()].checkAnswer(player.getContestantAnswer()))
        {
            addToScoreboard(player, grid_point_value);
        }
        else
            cout << "Wrong\n";


    } while(board[player.getRow()][player.getCol()].checkAnswer(player.getContestantAnswer()));
}
void Jeopardy::addToScoreboard(Contestant player, int grid_point_value)
{
    Jeopardy::scoreboard[player.getId()] += grid_point_value;
}
void Jeopardy::initGrid()
{
    // Initialize questions & answers
    ifstream question_file, answer_file;
    string x, y;

        for(int i = 0; i < 5; i++)
        {
            if(i == 0)
            {
                question_file.open("Category1.txt");
                answer_file.open("Category1Answers.txt");

                for(int j = 1; j < 6; j++)
                {
                    getline(question_file, x);
                    board[j][i].setQuestion(x);
                    getline(answer_file, y);
                    board[j][i].setAnswer(y);
                }
            }
            if(i == 1)
            {
                question_file.open("Category2.txt");
                answer_file.open("Category2Answers.txt");

                for(int j = 1; j < 6; j++)
                {
                    getline(question_file, x);
                    board[j][i].setQuestion(x);
                    getline(answer_file, y);
                    board[j][i].setAnswer(y);
                }
            }
            if(i == 2)
            {
                question_file.open("Category3.txt");
                answer_file.open("Category3Answers.txt");
                for(int j = 1; j< 6;j++)
                {

                    getline(question_file, x);
                    board[j][i].setQuestion(x);
                    getline(answer_file, y);
                    board[j][i].setAnswer(y);
                }
            }
            if(i == 3)
            {
                question_file.open("Category4.txt");
                answer_file.open("Category4Answers.txt");
                for(int j =1; j < 6; j++)
                {
                    getline(question_file, x);
                    board[j][i].setQuestion(x);
                    getline(answer_file, y);
                    board[j][i].setAnswer(y);
                }
            }
            if(i == 4)
            {
                question_file.open("Category5.txt");
                answer_file.open("Category5Answers.txt");
                for(int j = 1; j < 6; j++)
                {
                    getline(question_file, x);
                    board[j][i].setQuestion(x);
                    getline(answer_file, y);
                    board[j][i].setAnswer(y);
                }
            }
            }
        }
void Jeopardy::startGame()
{
    initGrid();

    do
    {
        runGame(player1);
        runGame(player2);
        runGame(player3);

    }while(!isGameOver());
}
