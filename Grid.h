#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

//************************************************************************
// Class name: Grid
// Description:
// Authors: Naelin Aquino, Miriam Flores, Bianca Hernandez
// Last modified:
//************************************************************************

class Grid
{
    private:
        string question,
               answer,
               grid_value;

    public:
        Grid();
        bool isQuestionChosen();
        void setQuestion(string question);
        void setAnswer(string answer);
        string getQuestion()const {return question;}
        string getAnswer()const {return answer;}
        void setGridValue(string grid_value);
        void displayQuestion();
        void displayAnswer();
        bool checkAnswer();
};

#endif // GRID_H_INCLUDED
