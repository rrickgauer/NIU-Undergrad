/*********************************************************
 * Name:         Ryan Rickgauer
 * Z-ID:         z-1729300
 * Program #:    1
 * Due Date:     9/6/2018
 ********************************************************/

#include "prg1.hpp"
using namespace std;

/***************************************************************
 genRndNums
 
 Use: Generates and stores random numbers into a vector
 
 Parameters: newVector
 
 Returns: nothing
 ***************************************************************/
void genRndNums(vector<int> &newVector)
{
    srand(1);    //initializes random number generator
    
    // generates a random number betweeen 1 - 10,000
    // inserts the generated random number into the vector
    for (int count = 0; count < VEC_SIZE; count++)
        newVector.push_back(rand() % (HIGH - LOW + 1) + LOW);
    
    // sorts the vector into ascending order
    sort(newVector.begin(), newVector.end());
    
}

/***************************************************************
 printVec
 
 Use: Displays the contents of vector v on stdout
 
 Parameters: v
 
 Returns: nothing
***************************************************************/
void printVec(const vector<int> &v)
{
    // Prints out the vector 12 items per line
    // Uses the setw() to set atleast 5 spaces in between elements
    for (int count = 0; count < VEC_SIZE; count++)
    {
        if (count % NO_ITEMS == 0 && count != 0)
            cout << endl;
        
        cout << setw(ITEM_W) << v[count];
    }
}
