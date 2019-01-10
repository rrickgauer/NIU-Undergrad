/***********************************************************
 CSCI 340 - Program 5 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  October 8, 2018
 
 Purpose:   This program simulates and solves the Josephus
 problem.
 ************************************************************/

#include "prog5.h"
using namespace std;

int main() {

    list<string> names;         // list for names
    args counter;               // input arguments
    init_vals(names, counter);  // fill list with names and get values for args
    print_list(names, 0);       // print initial list of names
    
    cout << endl << endl << endl;
    
    int i = 0;
    unsigned numRemovals = 0;
    
    while ((int)names.size() > 1)
    {
        i = (i + counter.M - 1) % names.size();
        
        auto p = names.begin();
        advance(p, i);
        p = names.erase(p);
        numRemovals++;
        
        if (numRemovals % counter.K == 0)
            print_list(names, numRemovals);
        
    
    }
    
    print_list(names, numRemovals);
}

/***************************************************************
 Function: init_vals
 
 Parameters: 1 reference to a list<string>, 1 reference to args
 
 Returns: void
 
 Notes: This routine reads the input values N, M and K of the
 struct args in when the program prompts for them and prints out
 those values on stdout.
 ***************************************************************/
void init_vals(list<string>& newList, args& newArgs)
{
    // Prompt user to enter 3 values for args
    // Store them in their respective variables
    cout << "Number of people? ";
    cin >> newArgs.N;
    cout << "Index for eliminating? ";
    cin >> newArgs.M;
    cout << "Index for printing? ";
    cin >> newArgs.K;

    // Resize list to hold all names
    // Generate random names into the list
    newList.resize(newArgs.N);
    generate(newList.begin(), newList.end(), SEQ());
  
}

/***************************************************************
 Function: print_list
 
 Parameters: 1 reference to a const list<string>, 1 reference to
 an unsigned
 
 Returns: void
 
 Notes: This routine prints out the contents of the list L at
 the beginning and after removing K names (each time) from the
 list, until only one name remains in the list.
 ***************************************************************/
void print_list(const list<string>& L, const unsigned& cnt)
{
    // Print if cnt is zero
    if (cnt == 0) {
        cout << "\nInitial group of people" << endl;
        cout << "-----------------------";
    }
    
    // print number of removals
    else {
        cout << "\n\nAfter eliminating " << cnt << "th person" << endl;
        cout << "----------------------------";
    }
    
    int lineBreak = 0;  // counter for line break
    
    // prints names in L , 12 per row
    for (auto count = L.begin(); count != L.end(); count++) {
        
        // after 12 names, print on a new line
        if (lineBreak % 12 == 0)
            cout << endl;
        
        cout << *count << " ";
        
        lineBreak++;
    }
}
