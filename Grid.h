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

        //******************************************************
        Grid();
        //Summary: initializes the question, answer and  grid
        //to empty strings
        //preconditon: ---
        //poscondition: question, answer and grid_vale
        // are empty strings
        //
        //******************************************************

         //******************************************************
        bool isQuestionChosen();
        //Summary: checks whether the question has been
        //assigned. return false if the question is has not
        //been use and true if it has been assigned to another
        //grid.
        //preconditon: ----
        //poscondition: return false if the question is has not
        //been use and true if it has been assigned to another
        //grid.
        //
        //******************************************************

         //******************************************************
        void setQuestion(string question);
         //Summary: it sets a question into the member variable
         // Question
        //preconditon: The sring being passed in cannot be
        // an empty string
        //poscondition: the member variable question gets a
        // string value
        //
        //******************************************************
         //******************************************************
        void setAnswer(string answer);
         //Summary:it sets a answers into the member variable
         // answers
        //preconditon:The sring being passed in cannot be
        // an empty string
        //poscondition:the member variable answersgets a
        // string value
        //
        //******************************************************

         //******************************************************
        string getQuestion()const {return question;}
         //Summary: returns the value stored in the member
         // variable question
        //preconditon: ---
        //poscondition: ---
        //
        //******************************************************

         //******************************************************
        string getAnswer()const {return answer;}
         //Summary:returns the value stored in the member
         // variable answers
        //preconditon: ---
        //poscondition: ---
        //
        //******************************************************
         //******************************************************
        void setGridValue(string grid_value);
         //Summary: it sets a given value into the member variable
         // grid_value
        //preconditon: grid_value cannot be an empty string
        //poscondition: the class  member variable grid_value
        // is set to the value of grid_value
        //
        //******************************************************
         //******************************************************
        void displayQuestion();
         //Summary: it displays the value stored in the member
         // varible questions
        //preconditon: the member variable has been initialized
        //poscondition: a question is display
        //
        //******************************************************

        //******************************************************
        void displayAnswer();
        //Summary:it displays the value stored in the member
         // varible answers
        //preconditon:the member variable has been initialized
        //poscondition: the answer is display
        //
        //******************************************************
        //******************************************************
        bool checkAnswer();
        //Summary: the following methods compares the value of
        // the member variable answer with the constentast input
        //preconditon: both the answers and the constestants
        // input cannot be empty strings
        //poscondition:returns true if the memember variable
        // and the contenstants' input are the same, otherwise
        //return false
        //******************************************************
        //******************************************************
        string getGridValue() const {return grid_value;}
        //Summary: returns the value in the grid_value member
        // variable
        //Postcondition: it has been initialized
        //Precondition: returns grid_value
        //
        //******************************************************

};

#endif // GRID_H_INCLUDED
