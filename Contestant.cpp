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
Contestant::setScore()
{
    this->score = score;
}
Contestant::setWager()
{
    assert(wager <= score || wager >= 0);
    this->wager =wager;
}
void addScore()
{
    //TODO: where is score going to get points from
    score +=
}
void deductScore()
{
    //TODO: where is score going to get points from
    score -=
}
