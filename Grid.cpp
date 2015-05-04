//****************************************************
//File Name:Grid.cpp
//
//Summary: The following file implements the methods for thr grid class
//Modification:
//Author: Miriam Flores
//compiler: CB 13.12
//****************************************************
//

#include "Grid.h"
#include "Contestant.h"
#include <iostream>
#include <cassert>

using namespace std;

 Grid::Grid()
 {
    question = "";
    answer = "";
    grid_value = "";
 }
bool Grid::isQuestionChosen()
{
    assert(grid_value == "X");
    return true;

}
void Grid::setQuestion(string question)
{
    assert(question != "");
    this-> question = question;
}
void Grid::setAnswer(string answer)
{
    assert(answer != "");
    this->answer = answer;

}
void Grid::setGridValue(string grid_value)
{
    assert(grid_value != "");
    this-> grid_value = grid_value;
}
void Grid::displayQuestion()
{
    cout << question << "?\n";
}
void Grid::displayAnswer()
{
    cout << answer << endl;
}
bool Grid::checkAnswer(string contestant_answer)
{
    assert(contestant_answer != ""); // not sure if the getContestant method will work
    if(contestant_answer == answer) // I need to see in which class the getContestantAnswer() is
        return true;
    else
        return false;
};
