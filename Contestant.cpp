//************************************************************************
// Filename: .cpp
// Description:
// Author: Naelin Aquino
// Last modified:
//************************************************************************

#include "Contestant.h"
#include <iostream>
#include <cassert>

Contestant::Contestant()
{
    //default score
    score = 0;
}
void Contestant::setScore(int score)
{
    this->score = score;
}
void Contestant::setWager(int wager)
{
    assert(wager <= score || wager >= 0);
    this->wager =wager;
}
void Contestant::addScore(int score)
{
    //TODO: where is score going to get points from
     this -> score += score;
}
void Contestant::deductScore()
{
    //TODO: where is score going to get points from
}
string Contestant::setContestantAnswer(string contestant_asnwer)
{
    assert(contestant_answer != "");
    this -> contestant_answer = contestant_answer;

}
