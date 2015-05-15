//************************************************************************
// Filename: Grid.cpp
// Description: implements all the methods describe in the Grid header
// file
// Author: Miriam Flores & Naelin Aquino & Bianca Hernandez
// Last modified:05-14-15
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
    this-> question = question;
}
void Grid::setAnswer(string answer)
{
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
    if(contestant_answer == answer)
        return true;
    return false;
}
void Grid::setIsDouble(bool is_double)
{
    this->is_double = is_double;
}
