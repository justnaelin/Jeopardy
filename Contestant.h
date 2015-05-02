#ifndef CONTESTANT_H_INCLUDED
#define CONTESTANT_H_INCLUDED

//************************************************************************
// Class name: Contestant
// Description:
// Authors: Naelin Aquino, Miriam Flores, Bianca Hernandez
// Last modified:
//************************************************************************

#include <string>
using namespace std;

class Contestant
{
    private:
        int score,
            wager,
            id,
            col,
            row;
        string contestant_answer;

    public:
        Contestant();
        Contestant(int id);
        int getScore()const {return score;}
        int getWager()const {return wager;}
        int getId()const {return id;}
        int getRow()const {return row;}
        int getCol()const {return col;}

        void setRow(int row);
        void setCol(int col);
        void setScore(int score);
        void setWager(int wager);
        void setId(int id);
        void addScore(Contestant player,int score);
        void deductScore();
        string getContestantAnswer() const {return contestant_answer;}
        string setContestantAnswer(string contestant_answer);
};

#endif // CONTESTANT_H_INCLUDED
