/***************************************************************
 CSCI 240         Program 8           Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 11/10/17
 
 Purpose: This program will implement and use the methods for a
 class called Die.
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number
using namespace std;

//Class 1: Die
class Die{
    
public:
    
    Die(); //constructor method initialization
    void roll();
    int getValue();
    void draw(); //extra credit
    
private:
    
    int numRoll;
    static const int NUM_SIDES;
    
};

const int Die::NUM_SIDES = 6;

int main(int argc, const char * argv[]) {
    
    
    srand(35);
    
    //Creates 2 objects
    Die die1 = Die();
    Die die2 = Die();
    
    int numberOfRolls;
    char even_odd;
    int result1, result2;
    int count, sum, playerWins, houseWins;
    bool even = false;
    bool odd = false;
    
    //Prompts player to enter how many times they want dice rolled
    cout << "How many times should the dice be rolled? ";
    cin >> numberOfRolls;
    
    //Prompts user to enter if they bet the sum to be odd or even
    cout << endl << "Will sum of the rolls be (E)ven or (O)dd? ";
    cin >> even_odd;

    if (even_odd == 'E' || even_odd  == 'e')
        even = true;
    else
        odd = true;
    
    
    playerWins = 0;
    houseWins = 0;
    
    //displays dice rolls
    
    //for loop executes the player's desired amount
    for (count = 0; count < numberOfRolls; count++)
    {
        die1.roll(); //executes roll method to die1
        result1 = die1.getValue(); //assigns number rolled to variable result1
        
        die2.roll(); //executes roll method to die2
        result2 = die2.getValue(); //assigns number rolled to variable result2
        
        //Extra credit poriton
        die1.draw();
        die2.draw();
        
        
        sum = result1 + result2; //Calculates sum of the to dice rolls
        
        //determines if player won if they choose even sum
        if (even)
        {
            if (sum % 2 == 0) //player wins
            {
                cout << "You won!" << endl;
                playerWins++;
            }
            else
            {
                cout << "Dealer won." << endl;
                houseWins++;
            }
      
        }
        
        //determines if player won if they choose odd
        else
        {
            if (sum % 2 == 1)
            {
                cout << "You won!" << endl;
                playerWins++;
            }
            else
            {
                cout << "Dealer won." << endl;
                houseWins++;
            }
        }

        cout << endl << endl;
        
    }
    
    //Displays player and dealer's scores and determines/displays who won the game
    cout << "Your final score is " << playerWins << " points." << endl;
    cout << "Dealer's final score is " << houseWins << " points." << endl;
   
    if (playerWins > houseWins)
        cout << "You won the game!" << endl;
    else if (playerWins < houseWins)
        cout << "The dealer won the game." << endl;
    else
        cout << "The game was a tie." << endl;
    
    cout << endl << endl;

    
    return 0;
}



/*********************************************************
 Constructor:
 The constructor for the Die class takes no arguments.
 It initializes the numeric data member to 0.
 Returns nothing
 *********************************************************/
Die::Die()
{
    numRoll = 0;
}


/*********************************************************
 Access method: void roll();
 This method takes no arguments and returns nothing.
 This method simulates the rolling of the die.
 *********************************************************/
void Die::roll()
{
    numRoll = rand() % NUM_SIDES + 1;
}



/*********************************************************
 Access method: int getValue();
 This method takes no arguments and returns and int.
 This method returns the current side of the die that is
 facing up.
 *********************************************************/
int Die::getValue()
{
    return numRoll;
}

/*********************************************************
 Extra credit method
 
 Print: void draw();
 This method takes no arguments and returns nothing.
 This method prints the side of the die that is currently
 up.
 *********************************************************/
void Die::draw()
{
    if (numRoll == 1)
    {
        cout << " ----- " << endl;
        cout << "|     |" << endl;
        cout << "|  O  |" << endl;
        cout << "|     |" << endl;
        cout << " ----- " << endl;
    }
    else if (numRoll == 2)
    {
        cout << " ----- " << endl;
        cout << "|O    |" << endl;
        cout << "|     |" << endl;
        cout << "|    O|" << endl;
        cout << " ----- " << endl;
    }
    
    else if (numRoll == 3)
    {
        cout << " ----- " << endl;
        cout << "|O    |" << endl;
        cout << "|  O  |" << endl;
        cout << "|    O|" << endl;
        cout << " ----- " << endl;
    }
    
    else if (numRoll == 4)
    {
        cout << " ----- " << endl;
        cout << "|O   O|" << endl;
        cout << "|     |" << endl;
        cout << "|O   O|" << endl;
        cout << " ----- " << endl;
    }
    
    else if (numRoll == 5)
    {
        cout << " ----- " << endl;
        cout << "|O   O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O   O|" << endl;
        cout << " ----- " << endl;
    }
    else if (numRoll == 6)
    {
        cout << " ----- " << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << " ----- " << endl;
    }
    
    cout << endl;
}
