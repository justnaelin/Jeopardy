//************************************************************************
// Filename: Grid.cpp
// Description:
// Author: Miriam Flores & Naelin Aquino
// Last modified:
//************************************************************************

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
    is_double = false;
}
bool Grid::isQuestionChosen()
{
    if(grid_value == "X")
        return true;
    return false;
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
    assert(contestant_answer != "");
    if(contestant_answer == answer)
        return true;
    return false;
}
void Grid::setIsDouble(bool is_double)
{
    this->is_double = is_double;
}
