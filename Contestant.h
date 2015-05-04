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
        int wager,
            id,
            col,
            row;
        string contestant_answer;

    public:
        Contestant();
        Contestant(int id);
        int getWager()const {return wager;}
        int getId()const {return id;}
        int getRow()const {return row;}
        int getCol()const {return col;}
        void setRow(int row);
        void setCol(int col);
        void setWager(int wager);
        void setId(int id);
        string getContestantAnswer() const {return contestant_answer;}
        void setContestantAnswer(string contestant_answer);
};

#endif // CONTESTANT_H_INCLUDED
