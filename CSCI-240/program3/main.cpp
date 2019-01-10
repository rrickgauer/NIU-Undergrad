/***************************************************************
 CSCI 240         Program 4     Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 9/29/17
 
 Purpose: This program counts specific types of values from three small groups of random numbers.
 ***************************************************************/

#include <iostream>
#include <iomanip>

#include <cstdlib> //Random number generator
#include <ctime> //ctime random number

using namespace std;

const int MIN_GROUP_SIZE = 2;
const int MAX_GROUP_SIZE = 20;
const int MAX_NUMBER_SIZE = 100;


int main(int argc, const char * argv[]) {
    
    
    cout << "**EXTRA CREDIT ATTEMPTED**" << endl << endl;
    srand(15); //Calls the random number generator function
    
    int number, count, randomNumbers1, even1, odd1, zero1, evenTotal, oddTotal, zeroTotal, numberTotal;
   
    numberTotal = 0;

    
//For loop portion
    
    even1 = 0;
    odd1 = 0;
    zero1 = 0;
    
    number = MIN_GROUP_SIZE + (rand() % (MAX_GROUP_SIZE - MIN_GROUP_SIZE + 1)); //Generates a random number between 2-20
    cout << "This program will generate " << number << " numbers using a for loop." << endl; //Displays how many numbers will be displayed
    
    
    //For rloop that outputs a random number of random numbers between 2-20
    for (count = 0; count < number; count++)
    {
        cout << "   ";
        randomNumbers1 = rand() % MAX_NUMBER_SIZE; //Generates a random number between 0-99
        cout << randomNumbers1 << "    "; //Displays random number
        
        
        //Determines if random number is even, odd, or a zero and adds one to its respective category
        if (randomNumbers1 == 0)
            zero1++;
        else if ((randomNumbers1 % 2) == 0)
            even1++;
        else if ((randomNumbers1 % 2) != 0)
            odd1++;
        
        numberTotal++;
    }
    
    //Displays how many even, odd, or zeros were displayed in the for loop
    cout << endl << endl << "There were " << even1 << " even numbers, " << odd1 << " odd numbers, and " << zero1 << " zeros in the group of numbers" << endl;
    
    //Records how many evens, odds, and zeros were generated
    evenTotal = even1;
    oddTotal = odd1;
    zeroTotal = zero1;
    
    cout << endl << endl << endl;

    
//While Loop Portion
    
    
    //Resets the value of even1, odd1, and zero 1 back to zero
    even1 = 0;
    odd1 = 0;
    zero1 = 0;
    
    number = MIN_GROUP_SIZE + (rand() % (MAX_GROUP_SIZE - MIN_GROUP_SIZE + 1)); //Generates a random number between 2-20
    cout << "This program will generate " << number << " numbers using a while loop." << endl; //Displays how many numbers will be displayed in a while loop
    
    count = 0; //Resets the count value back to one
    
    //While loop that outputs a random number of random numbers between 2-20
    while (count < number)
    {
        cout << "    ";
        randomNumbers1 = rand() % MAX_NUMBER_SIZE; //Generates a random number between 0-99
        cout << randomNumbers1 << "    "; //Displays random number
        
        
        //Determines if random number is even, odd, or a zero and adds one to its respective category
        if (randomNumbers1 == 0)
            zero1++;
        else if ((randomNumbers1 % 2) == 0)
            even1++;
        else if ((randomNumbers1 % 2) != 0)
            odd1++;

        count++;
        numberTotal++;
    }
    
    //Displays how many even, odd, or zeros were displayed in the while loop
    cout << endl << endl << "There were " << even1 << " even numbers, " << odd1 << " odd numbers, and " << zero1 << " zeros in the group of numbers" << endl;

    //Records how many evens, odds, and zeros were generated
    evenTotal = evenTotal + even1;
    oddTotal = oddTotal + odd1;
    zeroTotal = zeroTotal + zero1;
    
    
    
    cout << endl << endl << endl;
    
    
//Do While Loop Portion
    
    
    //Resets the value of even1, odd1, and zero 1 back to zero
    even1 = 0;
    odd1 = 0;
    zero1 = 0;
    
    number = MIN_GROUP_SIZE + (rand() % (MAX_GROUP_SIZE - MIN_GROUP_SIZE + 1)); //Generates a random number between 2-20
    
    //Displays how many numbers will be displayed in a do while loop
    cout << "This program will generate " << number << " numbers using a do while loop." << endl;
    
    count = 0; //Resets the count value back to one

    
    //Do while loop that outputs a random number of random numbers between 2-20
    do
    {
        cout << "    ";
        randomNumbers1 = rand() % MAX_NUMBER_SIZE; //Generates a random number between 0-99
        cout << randomNumbers1 << "    "; //Displays random number
        
        
        //Determines if random number is even, odd, or a zero and adds one to its respective category
        if (randomNumbers1 == 0)
            zero1++;
        else if ((randomNumbers1 % 2) == 0)
            even1++;
        else if ((randomNumbers1 % 2) != 0)
            odd1++;
        
        count++;
        numberTotal++;

        
    } while (count < number);
    
    //Displays how many even, odd, or zeros were displayed in the while loop
    cout << endl << endl << "There were " << even1 << " even numbers, " << odd1 << " odd numbers, and " << zero1 << " zeros in the group of numbers" << endl;
    
    //Records how many evens, odds, and zeros were generated
    evenTotal = evenTotal + even1;
    oddTotal = oddTotal + odd1;
    zeroTotal = zeroTotal + zero1;
    
    cout << endl << endl << endl;
    
    
    
//Extra credit portion
    
    cout << "Overall, there were " << numberTotal << " numbers." << endl; //Displays how many numbers were generated total
    
    //Displays how many evens there were and outputs that number of stars
    cout << "   " << evenTotal << " were even" << setw(3);
    for (count = 0; count < evenTotal; count++)
        cout << "*";
    cout << endl;
    
    //Displays how many odds there were and outputs that number of stars
    cout << "   " << oddTotal << " were odd" << setw(4);
    for (count = 0; count < oddTotal; count++)
        cout << "*";
    cout << endl;
    
    //Displays how many zeros there were and outputs that number of stars
    cout << "   " << zeroTotal << " were zero" << setw(4);
    for (count = 0; count < zeroTotal; count++)
        cout << "*";
    cout << endl;
}
