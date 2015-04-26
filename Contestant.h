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
        string contestant_answer;
    public:
        Contestant();
        int getScore()const {return score;}
        int getWager()const {return wager;}
        void setScore(int score);
        void setWager(int wager);
        void addScore(int score);
        void deductScore();
        string getContestantAnswer()const {return contestant_answer;}
};

#endif // CONTESTANT_H_INCLUDED
