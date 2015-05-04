#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

//************************************************************************
// Class name: Grid
// Description:
// Authors: Naelin Aquino & Miriam Flores
// Last modified:
//************************************************************************

#include <string>
#include "Contestant.h"
using namespace std;

class Grid
{
    private:
        string question,
               answer,
               grid_value;
    public:
        //************************************************************************
        Grid();
        // Summary: initializes the question, answer and grid
        // to empty strings
        // Preconditons: ---
        // Posconditions: question, answer, and grid_value
        // are empty strings
        //************************************************************************
        //************************************************************************
        bool isQuestionChosen();
        // Summary: checks whether the question has been
        // assigned. return false if the question is has not
        // been use and true if it has been assigned to another
        // grid.
        // Preconditions: ----
        // Posconditions: return false if the question is has not
        // been use and true if it has been assigned to another
        // grid.
        //************************************************************************
        //************************************************************************
        void setQuestion(string question);
        // Summary:it sets a question into the member variable
        // question
        // Preconditions: The sring being passed in cannot be
        // an empty string
        // Postconditions: the member variable question gets a
        // string value
        //************************************************************************
        //************************************************************************
        void setAnswer(string answer);
        //Summary:it sets a answers into the member variable
        // answers
        // Preconditions:The sring being passed in cannot be
        // an empty string
        // Posrconditions:the member variable answersgets a
        // string value
        //************************************************************************
        //************************************************************************
        string getQuestion()const {return question;}
        // Summary: returns the value stored in the member
        // variable question
        // Preconditions: ---
        // Posrconditions: ---
        //************************************************************************
        //************************************************************************
        string getAnswer()const {return answer;}
        //Summary: returns the value stored in the member
        // variable answers
        // Preconditions: ---
        // Posconditions: ---
        //************************************************************************
        //************************************************************************
        void setGridValue(string grid_value);
        //Summary: it sets a given value into the member variable
        // grid_value
        // Preconditions: grid_value cannot be an empty string
        // Posconditions: the class  member variable grid_value
        // is set to the value of grid_value
        //************************************************************************
        //************************************************************************
        void displayQuestion();
        //Summary: it displays the value stored in the member
        // varible questions
        // Precondituons: the member variable has been initialized
        // Postconditions: a question is display
        //************************************************************************
        //************************************************************************
        void displayAnswer();
        // Summary:it displays the value stored in the member
        // varible answers
        // Preconditions:the member variable has been initialized
        // Posconditions: the answer is display
        //************************************************************************
        //************************************************************************
        bool checkAnswer(string contestant_answer);
        // Summary: Compares the value of
        // the member variable answer with the constentast input
        // Preconditions: both the answers and the constestants
        // input cannot be empty strings and there is a and object
        // of type constestant being passed in
        // Posconditions:returns true if the memember variable
        // and the contenstants' input are the same, otherwise
        // return false
        //************************************************************************
        //************************************************************************
        string getGridValue() const {return grid_value;}
        // Summary: returns the value in the grid_value member
        // variable
        // Postconditions: it has been initialized
        // Preconditions: returns grid_value
        //************************************************************************
};
#endif // GRID_H_INCLUDED
