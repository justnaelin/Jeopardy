//************************************************************************
// Filename: .cpp
// Description:
// Author: Naelin Aquino
// Last modified:
//************************************************************************

#include "Contestant.h"
#include "Grid.h"
#include <iostream>
#include <cassert>

Contestant::Contestant()
{
    //default score
    score = 0;
    wager = 0;
    id = 0;
    contestant_answer = "";
}
void Contestant::setScore(int score)
{
    this->score = score;
}
void Contestant::setWager(int wager)
{
    assert(wager <= score || wager >= 0);
    this->wager = wager;
}
void Contestant::setId(int id)
{
    assert(id >= 0 || id < 3);
    this->id = id;
}
void Contestant::addScore(int grid_points)
{
    //TODO: where is score going to get points from
    score += grid_points;
}
void Contestant::deductScore()
{
    //TODO: where is score going to get points from

}
string Contestant::setContestantAnswer(string contestant_asnwer)
{
    assert(contestant_answer != "");
    this->contestant_answer = contestant_answer;

}
