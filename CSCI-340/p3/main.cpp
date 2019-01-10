/***********************************************************
 CSCI 340 - Program 3 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  September 24, 2018
 
 Purpose:   This program finds and prints all prime numbers,
 which are less than or equal to a given value of n, using
 the algorithm known as the Sieve of Eratosthenes.
 ************************************************************/
#include "prog3.h"

int main(int argc, const char * argv[]) {

    // Prompt the user for an upper limit & store it in number
    int number;
    cout << "upper limit for the set of primes: ";
    cin >> number;
    
    set<int> s1;        // Creates an empty set of integers
    sieve(s1, number);  // Calls the subroutine sieve() to execute the Sieve of Eratosthenes algorithm
    print_primes(s1);   // Print the prime numbers on stdout
    
}

/***************************************************************
 Function: print_primes
 
 Parameters: 1 reference to a set of integers const
 
 Returns: void
 
 Notes: Prints the elements in the integer set s (NO_ITEMS = 16
 primes per line and ITEM_W = 4 spaces allocated for each prime)
 ***************************************************************/
void print_primes(const set<int> &s)
{
    int count = 0;
    
    for (set<int>::iterator i = s.begin(); i != s.end(); i++, count++)
    {
        // After 16 integers, print a line break
        if (count % NO_ITEMS == 0 && count != 0)
            cout << endl;
            
        cout << setw(ITEM_W) << *i;
    }
}

/***************************************************************
 Function: sieve
 
 Parameters: 1 reference to a set of integers const, 1 int
 
 Returns: void
 
 Notes: Applies the Sieve of Eratosthenes algorithm to remove all
 nonprime numbers from the integer set s.
 ***************************************************************/
void sieve(set<int> &s, int n)
{
    // Fill set with consecutive integers 2-n
    for (int count = 2; count <= n; count++)
        s.insert(count);
    
    // Use the Sieve of Eratosthenes algorithm to remove all non-prime numbers
    for (int count = 2; count < n; count++)
    {
        for (int m = 2; m < n; m++)
            s.erase(count * m);
    }
}
