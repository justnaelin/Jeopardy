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
        // Constructors

        //***********************************************************************************************************
        Contestant();
        // Description: The constructor that initializes the contestant
        // PreCondition:
        // PostCondition: contestant is initialized
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
        // Description: it returns the variable wager
        // PreCondition: wager is greater than 0 && less than score
        // PostCondition: wager is returned
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        int getId()const {return id;}
        // Description: returns the variable id
        // PreCondition: id > 0 && id < 4
        // PostCondition: id is return with it's value
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        int getRow()const {return row;}
        // Description: returns the value of the variable row
        // PreCondition: row > 0 && row < 6
        // PostCondition: the value of row is returned
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        int getCol()const {return col;}
        // Description: returns the value of the variable col
        // PreCondition: col >= 0 && col < 5
        // PostCondition: the value of col is returned
        //
        //***********************************************************************************************************

        // Mutator Methods
        //***********************************************************************************************************
        void setRow(int row);
        // Description: sets the integer value into the variable row
        // PreCondition: row > 0 && row < 6
        // PostCondition: an integer value is assigned in the variable row
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        void setCol(int col);
        // Description: sets the integer value into the variable col
        // PreCondition: col >=0 && col < 5
        // PostCondition: an integer value is assigned in the variable col
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        void setWager(int wager);
        // Description: it sets and integer value into the variable wager
        // PostCondition: wager >= 0 && wager < contestant score
        // PreCondition: an integer value is assigned to the variable wager
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        void setId(int id);
        // Description: it sets the integer value between 1-3 into the variable id
        // PostCondition: id > 0 && id < 4
        // Precondition: the integer value is assigned to the variable id
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        string getContestantAnswer() const {return contestant_answer;}
        // Description: returns the value contestant_answer
        // PostCondition: contestant answer != " "
        // PreCondition: the contestant value is returned
        //
        //***********************************************************************************************************

        //***********************************************************************************************************
        void setContestantAnswer(string contestant_answer);
        // Description: is sets a string to the variable contestant_answer
        // PostCondition: contestant_answer != " "
        // PreCondition: the string input is assigned to the variable contestant_answer
        //
        //***********************************************************************************************************

};

#endif // CONTESTANT_H_INCLUDED
