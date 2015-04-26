//****************************************************
//File Name:Grid.cpp
//
//Summary: The following file implements the methods for thr grid class
//Modification:
//Author: Miriam Flores
//compiler: CB 13.12
//****************************************************
//
#include <cassert>

using namespace std;

 Gird::Grid()
 {
    question = "";
    answers = "";
    grid_value = "";
 }
bool Grid::isQuestionChosen()
{
    assert(grid_value == "X");
    return true

}
void Grid::setQuestion(string question)
{
    assert(question != "");
    this -> question = question;

}
void Grid::setAnswer(string answer)
{
    assert(answers != "");
    this -> question = question;

}
void Grid::setGridValue(string grid_value)
{
    assert(grid_Value != "");
    this -> grid_value = grid_value;
}
void Grid::displayQuestion()
{
    cout << question << "?\n";

}
void Grid::displayAnswer()
{
    cout << answer << endl;

}
bool Grid::checkAnswer()
{
    assert(getContestantAnswer() != "") // not sure if the getContestant method will work
    if(getContestantAnswer() == answers) // I need to see in which class the getContestantAnswer() is
        return true
    return false
};
