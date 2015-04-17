#ifndef CONTESTANT_H_INCLUDED
#define CONTESTANT_H_INCLUDED

//************************************************************************
// Class name: Contestant
// Description:
// Authors: Naelin Aquino, Miriam Flores, Bianca Hernandez
// Last modified:
//************************************************************************

class Contestant
{
    private:
        int score,
            wager;
    public:
        Contestant();
        int getScore()const {return score;}
        int getWager()const {return wager;}
        void setScore(int score);
        void setWager(int wager);
        void addScore(int score);
        void deductScore();
};

#endif // CONTESTANT_H_INCLUDED
