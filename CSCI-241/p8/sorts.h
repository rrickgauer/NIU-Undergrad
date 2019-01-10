/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 8
 PROGRAMMER: Ryan Rickgauer
 LOGON ID:   z1729300
 DUE DATE:   4/26/2017
 
 FUNCTION:   This program builds and sorts lists using the quick
             sort algorithm.
 *********************************************************************/

#ifndef sorts_h
#define sorts_h
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

template <class T> void buildList(vector<T>& set, const char* fileName);
template <class T> void printList(const vector<T>& set, int itemWidth, int numPerLine);
template <class T> bool lessThan(const T& item1, const T& item2);
template <class T> bool greaterThan(const T& item1, const T& item2);

/**************************************************************
 
 FUNCTION: void buildList(vector<T>& set, const char* fileName)
 
 ARGUMENTS: set - a reference to a vector object
            fileName - a C string containing the full pathname
            of the input file
 
 RETURNS:   N/A.
 
 NOTES:     Read items from an input file and put them into a vector.
 
 **************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
    T item;             // Temporary varibale to hold a vector item
    ifstream inFile;    // File stream variable
    
    // Open file for input using fileName as the name of the file to open
    inFile.open(fileName);
    
    // Check if file opens successfully
    if (!inFile)
    {
        cout << "Unable to open input file" << fileName << endl;
        exit(1);
    }
    
    // Read items from input file
    inFile >> item;
    while (inFile)
    {
        set.push_back(item);
        inFile >> item;
    }
    
    // Close the file
    inFile.close();
}


/**************************************************************
 
 FUNCTION:  void printList(const vector<T>& set, int itemWidth, int numPerLine)
 
 ARGUMENTS: set - a reference to a constant vector object that will contain the items to print.
            itemWidth - an integer specifying the width an individual item should occupy when printed
            numPerLine - an integer specifying the maximum number of items that should be printed in a single line of output.
 
 RETURNS:   N/A.
 
 NOTES:     Prints a list of items stored in a vector.
 
 **************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    int i = 0;  // Counter
    
    // While i is less than the size of set
    while (i < (int)set.size())
    {
        cout << setw(itemWidth) << set[i] << ' ';
        i++;
        
        // Print a line break
        if (i % numPerLine == 0)
            cout << endl;
    }
    
    cout << endl;
}


/**************************************************************
 
 FUNCTION:  bool lessThan(const T& item1, const T& item2)
 
 ARGUMENTS: item1 - reference to a const T
            item2 - reference to a const T
 
 RETURNS:   bool
 
 NOTES:     Returns true if item1 is less than item2. False if not.
 
 **************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
    // True if item 1 is less than item 2
    // Otherwise, return false
    return (item1 < item2);
}

/**************************************************************
 
 FUNCTION:  bool greaterThan(const T& item1, const T& item2)
 
 ARGUMENTS: item1 - reference to a const T
            item2 - reference to a const T
 
 RETURNS:   bool
 
 NOTES:     Returns true if item1 is greater than item2. False if not.
 
 **************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
    // True if item 1 is greater than item 2
    // Otherwise, return false
    return (item1 > item2);
}

#endif /* sorts_h */
