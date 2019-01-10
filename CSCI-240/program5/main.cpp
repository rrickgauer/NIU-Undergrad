/***************************************************************
 CSCI 240         Program 5     Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 10/13/17
 
 Purpose: This program will simulate a single game of Craps
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number

const int MAX = 6;
const int MIN = 1;
const int SEVEN = 7;

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << endl << "EXTRA CREDIT ATTEMPTED" << endl;
    
    srand(8); //Sets up the random number generator
    
    int die1, die2, sum, point;
    char repeat;
    
    do
    {
        point = 0;
        
        //Generates 2 random numbers between 1-6 and adds them together
        die1 = (rand() % MAX) + MIN;
        die2 = rand() % MAX + MIN;
        sum = die1 + die2;
        
        cout << "\nThe come out roll is " << sum << endl; //Displays the come out roll
        
        if ((sum == SEVEN) || (sum == 11)) //If player's initial roll is 7 or 11 then the player wins the game
            cout << endl << "You won!" << endl;
        else if ((sum == 2) || (sum == 3) || (sum == 12)) //If player's initial roll is 2, 3,or 12 then the player loses the game
            cout << endl << "Craps! You lost!" << endl;
        else //If player's initial roll is anything else then the player continues to roll the dice
        {
            point = sum;
            cout << endl << "The point is " << point << endl << endl; //Displays the point
            
            //Generates 2 random numbers between 1-6 and adds them together
            die1 = rand() % MAX + MIN;
            die2 = rand() % MAX + MIN;
            sum = die1 + die2;
            
            cout << "The roll is " << sum << endl; //Displays the roll
            
            //While loop that continues generating 2 random number and adding them together until the player rolls a 7 or their point
            while (sum != point && sum != SEVEN)
            {
                die1 = rand() % MAX + MIN;
                die2 = rand() % MAX + MIN;
                sum = die1 + die2;
                
                cout << "The roll is " << sum << endl;
            }
            
            //If the player rolled a 7 then program displays a message saying they lost, if they rolled their point then message says they won
            if (sum == SEVEN)
                cout << endl << "Too Bad! You seven'd out and lost!" << endl;
            else
                cout << endl << "Congratulations! You rolled your point and won!" << endl;
        }
        
        cout << "\nWould you like to play again (y for yes)?";
        cin >> repeat;
        
    } while (repeat == 'y' || repeat == 'Y'); //Do-while loop that repeats if user enters y or Y
}
