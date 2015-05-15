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
    wager = 0;
    id = 0;
    contestant_answer = "";
    row = 1;
    col = 0;
}
Contestant::Contestant(int id)
{
    this->id = id;
    wager = 0;
    contestant_answer = "";
    row = 1;
    col = 0;
}
void Contestant::setWager(int wager)
{
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
    this->id = id;
}
void Contestant::setContestantAnswer(string contestant_answer)
{
    this->contestant_answer = contestant_answer;
}
