//************************************************************************
// Filename: Jeopardy.cpp
// Description:
// Author: Naelin Aquino & Miriam Flores
// Last modified:
//************************************************************************

#include "Jeopardy.h"
#include "Grid.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

using namespace std;

int Jeopardy::scoreboard[3] = {0, 0, 0};

Jeopardy::Jeopardy()
{
    // Set daily double to a random tile
    srand(time(NULL));
    int r = rand() % 5 + 1;
    sleep(1);
    int c = rand() % 5 + 1;
    board[5][0].setIsDouble(true);

    // Initialize players with IDs
    player1.setId(0);
    player2.setId(1);
    player3.setId(2);

    // Counter represents the number of questions selected
    counter = 0;

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
    cout << "=========Scoreboard=========\n";
    cout << "P1:" << scoreboard[0] << '\t' << "P2:" << scoreboard[1] << '\t' << "P3:" << scoreboard[2] << endl;
    cout << "============================\n";

    cout << "1 - Songs\n"
         << "2 - Disney\n"
         << "3 - Harry Potter\n"
         << "4 - Musicals\n"
         << "5 - Greek Mythology\n";
    cout << endl;

    for(int i = 0; i < 6; i++)
    {
        cout << i << '\t';
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
            if(!board[i][j].isQuestionChosen())
                return false;
    return true;
}
void Jeopardy::whoWon()
{
    // Compare player's individual scores
    int highest_score = 0;
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
void Jeopardy::runGame(Contestant player, int id)
{

    int grid_point_value;
    char irow, // variables used to check user input
         icol;
    string contestant_answer;
    bool isDailyDouble = false;
    int row, // variables that are used in arrays and conditional staments
        col,
        wager;
    do
    {
        displayBoard();
        do
        {
            cout << "Select a row and column (1-5): \n";
            cin >> irow >> icol;

            //user input validation
            //user cannot enter characters or numbers over 5
            do
            {
                 cout << "Select a row and column (1-5): \n";
                 cin >> irow >> icol;

            }while((!isdigit(irow) || !isdigit(icol) || (irow > 48 && irow <= 53) || (icol > 48 && icol <=53)));

            // type cast the user input in order to use it throughout the rest of the code
            row = irow-'0'; //changes the char to an int
            col = icol-'0'; // changes the char to an int
            col = col - 1; // subtracts one to columns to get the right postion of the tile

        } while(board[row][col].isQuestionChosen());
        cin.ignore();

        // Checks if they selected the Daily Double tile
        if(board[row][col].getIsDouble())
        {
            player1.setRow(row);
            player1.setCol(col);
            dailyDouble();
            isDailyDouble = true;
        }
        // Run game as usual
        else
        {
            player.setRow(row);
            player.setCol(col);
            grid_point_value = stoi(board[player.getRow()][player.getCol()].getGridValue()); // Converts the the string grid-value to an int
            board[player.getRow()][player.getCol()].setGridValue("X");
            board[player.getRow()][player.getCol()].displayQuestion();

            cout << "Enter your answer: \n";
            getline(cin, contestant_answer);
            player.setContestantAnswer(contestant_answer);

            if(board[player.getRow()][player.getCol()].checkAnswer(player.getContestantAnswer()))
            {
                cout << "Correct!\n";
                addToScoreboard(player, grid_point_value);
            }
            else
                cout << "Incorrect!\n";
            counter++;
        }
        if(counter == 25)
            finalJeopardy();
    } while(isDailyDouble == false && board[player.getRow()][player.getCol()].checkAnswer(player.getContestantAnswer()));

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
        if(i == 0) // Category 1
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
            question_file.close();
            answer_file.close();
        }
        if(i == 1) // Category 2
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
            question_file.close();
            answer_file.close();
        }
        if(i == 2) // Category 3
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
            question_file.close();
            answer_file.close();
        }
        if(i == 3) // Category 4
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
            question_file.close();
            answer_file.close();
        }
        if(i == 4) // Category 5
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
            question_file.close();
            answer_file.close();
        }
    }
}
void Jeopardy::startGame()
{
    initGrid();

    do
    {
        runGame(player1, 0);
        runGame(player2, 1);
        runGame(player3, 2);

    } while(!isGameOver());
}
void Jeopardy::dailyDouble()
{
    int row,
        col,
        grid_point_value;
    string contestant_answer;

    checkWager(player1, 0);
    checkWager(player2, 1);
    checkWager(player3, 2);

    grid_point_value = stoi(board[player1.getRow()][player1.getCol()].getGridValue()); // Converts the the string grid-value to an int
    board[player1.getRow()][player1.getCol()].setGridValue("X");
    board[player1.getRow()][player1.getCol()].displayQuestion();

    cout << "Player 1: Enter your answer: \n";
    getline(cin, contestant_answer);
    player1.setContestantAnswer(contestant_answer);
    cout << "Player 2: Enter your answer: \n";
    getline(cin, contestant_answer);
    player2.setContestantAnswer(contestant_answer);
    cout << "Player 3: Enter your answer: \n";
    getline(cin, contestant_answer);
    player3.setContestantAnswer(contestant_answer);

    // Checks all contestants' answers
    checkContestantsAnswers(player1, 0);
    checkContestantsAnswers(player2, 1);
    checkContestantsAnswers(player3, 2);

    displayBoard();

    counter++;
}
void Jeopardy::finalJeopardy()
{
    string answer = "walter e disney", // Answer for Final Jeopardy
           contestant_answer;

    cout << "    FINAL JEOPARDY!!!!    \n";

    // TODO: Revise this to be specific to Final Jeopardy
    checkWager(player1, 0);
    checkWager(player2, 1);
    checkWager(player3, 2);

    // Final Jeopardy question
    cout << "What does Wall-E stand for? \n";

    // Sets players' answers
    cout << "Player 1: Enter your answer: \n";
    getline(cin, contestant_answer);
    player1.setContestantAnswer(contestant_answer);
    cout << "Player 2: Enter your answer: \n";
    getline(cin, contestant_answer);
    player2.setContestantAnswer(contestant_answer);
    cout << "Player 3: Enter your answer: \n";
    getline(cin, contestant_answer);
    player3.setContestantAnswer(contestant_answer);

    // TODO: Revise this to be specific to Final Jeopardy
    checkContestantsAnswers(player1, 0);
    checkContestantsAnswers(player2, 1);
    checkContestantsAnswers(player3, 2);

    // Checks if the game is over
    if(isGameOver())
    {
        whoWon();
        displayGameOver();
        displayBoard();
    }
}
void Jeopardy::checkWager(Contestant& player, int id)
{
    int wager;
    do
    {
        cout << "Player " << id + 1 << " how much would you like to wager? \n";
        cin >> wager;

        if(wager < 100)
            cout << "Wager must be at least 100.\n";

    } while (wager < 100);
    cin.ignore();
    player.setWager(wager);
}
void Jeopardy::checkContestantsAnswers(Contestant& player, int id)
{
    if(board[player.getRow()][player.getCol()].checkAnswer(player.getContestantAnswer()))
    {
        cout << "Player " << id + 1 << ":  Correct!\n";
        addToScoreboard(player, player.getWager());
    }
    else
    {
        cout << "Player " << id + 1 << ": Incorrect!\n";
        addToScoreboard(player, (scoreboard[id] - player.getWager()));
    }
}
