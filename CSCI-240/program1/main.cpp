/***************************************************************
 CSCI 240         Program 1     Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 9/8/17
 
 Purpose: This program calculates and displays a course average for
 the CSCI 240 course.
 ***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double programAverage, testAverage;
    
    cout << "Enter the program average: ";
    cin >> programAverage;
    
    cout << "Enter the test average: ";
    cin >> testAverage;
    
    double courseAverage = ((programAverage * 0.3) + (testAverage * 0.7));
    
    //Display Calculations
    
    cout << "\n**************************\n";
    cout << "Grade Calculator\n";
    cout << "\n";
    
    
    cout << "Program Average   " << programAverage << endl;
    cout << "Test Average      " << testAverage << endl;
    cout << "\n";
    cout << "Course Average    " << courseAverage << endl;
    cout << "**************************\n";
    
    
    return 0;
}
