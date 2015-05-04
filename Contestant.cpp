//************************************************************************
// Filename: Contestant.cpp
// Description:
// Author: Naelin Aquino, Miriam Flores, & Bianca Hernandez
// Last modified:
//************************************************************************

#include "Contestant.h"
#include "Grid.h"
#include <iostream>
#include <cassert>

Contestant::Contestant()
{
    score = 0;
    wager = 0;
    id = 0;
    contestant_answer = "";
    row = 1;
    col = 0;
}
Contestant::Contestant(int id)
{
    this->id = id;
    score = 0;
    wager = 0;
    contestant_answer = "";
    row = 1;
    col = 0;
}
void Contestant::setWager(int wager)
{
    assert(wager <= score || wager >= 0);
    this->wager = wager;
}
void Contestant::setCol(int col)
{
    this->col = col;
}
void Contestant::setRow(int row)
{
    this->row = row;
}
void Contestant::setId(int id)
{
    assert(id >= 0 || id < 3);
    this->id = id;
}
void Contestant::setContestantAnswer(string contestant_answer)
{
    assert(contestant_answer != "");
    this->contestant_answer = contestant_answer;
}
