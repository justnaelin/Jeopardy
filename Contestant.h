#ifndef CONTESTANT_H_INCLUDED
#define CONTESTANT_H_INCLUDED

//************************************************************************
// Class name: Contestant
// Description: This class is in charge of holding each contestant's
// attributes
// Authors: Naelin Aquino, Miriam Flores, Bianca Hernandez
// Last modified: 05-15-15
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
    // Constructors
        //***********************************************************************************************************
        Contestant();
        // Summary: The constructor that initializes the contestant
        // Preconditions: ---
        // Postconditions: contestant is initialized
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        Contestant(int id);
        // Description: overloaded constructor
        // PreCondition:
        // PostCondition: sets values to themselves
        //
        //***********************************************************************************************************
    // Accessor Methods
        //***********************************************************************************************************
        int getWager()const {return wager;}
        // Summary: it returns the variable wager
        // Preconditions: wager is greater than 0 && less than score
        // Postconditions: wager is returned
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        int getId()const {return id;}
        // Summary: returns the variable id
        // Preconditions: id > 0 && id < 4
        // Postconditions: id is return with it's value
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        int getRow()const {return row;}
        // Summary: returns the value of the variable row
        // Preconditions: row > 0 && row < 6
        // Postconditions: the value of row is returned
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        int getCol()const {return col;}
        // Summary: returns the value of the variable col
        // Preconditions: col >= 0 && col < 5
        // Postconditions: the value of col is returned
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        string getContestantAnswer() const {return contestant_answer;}
        // Summary: returns the value contestant_answer
        // Postconditions: contestant answer != " "
        // Preconditions: the contestant value is returned
        //
        //***********************************************************************************************************
    // Mutator Methods
        //***********************************************************************************************************
        void setRow(int row);
        // Summary: sets the integer value into the variable row
        // PreCondition: row > 0 && row < 6
        // PostCondition: an integer value is assigned in the variable row
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        void setCol(int col);
        // Summary: sets the integer value into the variable col
        // PreCondition: col >=0 && col < 5
        // PostCondition: an integer value is assigned in the variable col
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        void setWager(int wager);
        // Summary: it sets and integer value into the variable wager
        // PostCondition: wager >= 0 && wager < contestant score
        // PreCondition: an integer value is assigned to the variable wager
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        void setId(int id);
        // Summary: it sets the integer value between 1-3 into the variable id
        // Postconditions: id > 0 && id < 4
        // Preconditions: the integer value is assigned to the variable id
        //
        //***********************************************************************************************************
        //***********************************************************************************************************
        void setContestantAnswer(string contestant_answer);
        // Summary: is sets a string to the variable contestant_answer
        // Postconditions: contestant_answer != " "
        // Preconditions: the string input is assigned to the variable contestant_answer
        //
        //***********************************************************************************************************
};

#endif // CONTESTANT_H_INCLUDED
