/***************************************************************
 CSCI 240         Program 6     Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 10/20/17
 
 Purpose: This program will have 4 functions that will manipulate
 an integer to calculate the sum of its individual digits, the
 number's reversal, whether the integer is a palindrome, and
 whether or not it is prime.
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number
using namespace std;
const int NUM_VALS = 10;

//function prototypes
int sumDigits(int num);
int reverse(int num);
bool isPalindrome(int num);
bool isPrime(int num);
void numerology();


int main(int argc, const char * argv[]) {
    
    srand(31); //initializes random number generator
    
    int num, loopCnt;
    
    cout << "***EXTRA CREDIT ATTEMPTED***" << endl << endl; //Displays a message saying the extra credit poriton has been attempted
    
    //for loop executes 10 times.
    //Each execution generates a random number and displays the sum of the individual digits in the number,
    //the indidivual digits in the number reversed, whether the number was a palindrome, and whether the number was prime
    for( loopCnt = 1; loopCnt <= NUM_VALS; loopCnt++ )
    {
        num = rand(); //generates a random number
    
        cout << "The number is " << num << endl
        << "----------------------------------------" << endl
        << "Adding the digits result" << setw(16) << sumDigits(num) << endl
        << "Reversing the digits result" << setw(13) << reverse(num) << endl
        << "Is the number a palindrome?" << setw(13) << (isPalindrome(num)? "Yes" : "No") << endl
        << "Is the number prime?" << setw(20) << (isPrime(num)? "Yes" : "No") << endl
        << endl << endl;
    }
    
    //Extra credit portion
    numerology();
}

/***************************************************************
 Function:  int sumDigits(int num)
 
 Use: This function calculates and returns a sum by adding the
 individual digits in an integer number.
 
 Arguments: an integer named "num", which is the integer number
 used to calculate the sum of its inidividual digits
 
 Returns: an integer value of the sum of individual digits in
 the number.
 ***************************************************************/
int sumDigits(int num)
{
    int number = num;
    int total = 0;
    
    //While loop isolates each individual digit in the number and adds them together
    while (number != 0)
    {
        total = total + (number % 10);
        number = (number / 10);
    }
    
    return total;
}

/***************************************************************
 Function:  int reverse(int num)
 
 Use: This function will reverse and return the digits in an
 integer number.
 
 Arguments: an integer named "num", which is the integer number
 used to reverse its inidividual digits.
 
 Returns: an integer value of the individual digits reversed.
 ***************************************************************/
int reverse(int num)
{
    int number = num;
    int reverseNumber = 0;
    
    //while loop isolates each indivudual digit in the number and reverses their original order
    while (number != 0)
    {
        reverseNumber = reverseNumber * 10;
        reverseNumber = reverseNumber + (number % 10);
        number = (number / 10);
    }
    
    return reverseNumber;
}


/***************************************************************
 Function:  bool isPalindrome(int num)
 
 Use: This function tests to see if an integer number is a
 palindrome.
 
 Arguments: an integer named "num", which is the integer number
 used to test if it is a palindrome.
 
 Returns: a boolean value that indicates if the number is or
 is not a palindrome
 ***************************************************************/
bool isPalindrome(int num)
{
    int number = num;
    int reverseNumber = reverse(num);
    bool palindrome;
    
    //if else statement determines if the number is a palindrome by comparing the original number to its reverse
    if (reverseNumber == number)
        palindrome = true;
    else
        palindrome = false;
        
    return palindrome;
}

/***************************************************************
 Function:  bool isPrime(int num)
 
 Use: This function determines if a number is a prime number
 
 Arguments: an integer named "num", which is the number to be
 tested
 
 Returns: a boolean value that indicates if the number is or
 is not prime
 ***************************************************************/
bool isPrime(int num)
{
    bool prime = true;
    int count;
    
    //for loop determines if the number is prime or not
    for (count = 2; count <= (num/2) && prime == true; count++)
    {
        if (num % count == 0)
            prime = false;
        else
            prime = true;
    }
    
    return prime;
}

//EXTRA CREDIT PORTION

/***************************************************************
 Function:  void numerology()
 
 Use: This function will use a person's date of birth to try and
 determine some traits about the person by using some basic
 principles of numerology.
 
 Arguments: none
 
 Returns: nothing
 ***************************************************************/
void numerology()
{
    int day, month, year;
    
    cout << "Enter your birthday in (mm/dd/yyyy) form: ";
    cin >> month; //get the month value from the input buffer
    cin.ignore(); //remove the 1st / from the input buffer
    cin >> day; //get the day value from the input buffer
    cin.ignore();  //remove the 2nd / from the input buffer
    cin >> year; //get the year value from the input buffer
    
    int number;
    number = day + month + year;
    
    int total = 0;
    
    //while loop sums up the inidividual digits from the user's birthday
    while (number != 0)
    {
        total = total + (number % 10);
        number = number / 10;
    }
    
    //if statement that in a case where the life path number = 10, it changes it to 1
    if (total == 10)
        total = 1;
    
    cout << "Your Life Path number is: " << total << endl; //displays user's life path number
    
    //else-if statements determine which life path number the user has, and ouputs some traits based on their life path number
    if (total == 1)
        cout << "This suggests that you are individualistic, independent, and show leadership and drive." << endl;
    else if (total == 2)
        cout << "This suggests that you are sensitive, tactful, diplomatic, and cooperative." << endl;
    else if (total == 3)
        cout << "This suggests that you are creative and a good communicator." << endl;
    else if (total == 4)
        cout << "This suggests that you are a natural planner, fixer, and builder." << endl;
    else if (total == 5)
        cout << "This suggests that you are energetic, adventurous, daring, and freedom-loving." << endl;
    else if (total == 6)
        cout << "This suggests that you are responsible, loving, self-sacrificing, protective, and compassionate." << endl;
    else if (total == 7)
        cout << "This suggests that you have a gift for investigation, analysis, and keen observation." << endl;
    else if (total == 8)
        cout << "This suggests that you have skills to lead, direct, organize and govern." << endl;
    else if (total == 9)
        cout << "This suggests that you are helpful, compassionate, sophisticated and generous." << endl;
}
