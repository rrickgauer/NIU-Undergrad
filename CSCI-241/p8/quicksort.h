/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 8
 PROGRAMMER: Ryan Rickgauer
 LOGON ID:   z1729300
 DUE DATE:   4/26/2017
 
 FUNCTION:   This program builds and sorts lists using the quick
             sort algorithm.
 *********************************************************************/
#ifndef quicksort_h
#define quicksort_h

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

template<class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

/**************************************************************
 
 FUNCTION:  void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type

 RETURNS:   N/A.
 
 NOTES:     Sorts the items in set using the quick sort algorithm.
 
 **************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    // Call the recursive quick sort function
    quickSort(set, 0, (int)set.size()-1, compare);
    
}

/**************************************************************
 
 FUNCTION:  void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object
            start - integer that represents the start of the vector
            end - integer that represents the start of the vector
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type
 
 RETURNS:   N/A.
 
 NOTES:     Performs the recursive calls to implement the quick
            sort algorithm.
 
 **************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotPoint;
    
    if (start < end)
    {
        pivotPoint = partition(set, start, end, compare);   // Get the pivot point
        quickSort(set, start, pivotPoint - 1, compare);     // Sort the first sublist
        quickSort(set, pivotPoint + 1, end, compare);       // Sort second sublist
    }
    
}


/**************************************************************
 
 FUNCTION:  int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object.
            start - integer that represents the start of the vector.
            end - integer that represents the start of the vector.
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type.
 
 RETURNS:   int
 
 NOTES:     Selects a pivot element and then partitions the vector
            around the pivot.
 
 **************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotIndex;
    T pivotValue, temp;
    
    // Set mid to the middle index of the vector
    int mid = (start + end) / 2;
    
    // Swap elements start and mid of the vector
    temp = set[start];
    set[start] = set[mid];
    set[mid] = temp;
    
    pivotIndex = start;
    pivotValue = set[start];
    
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (compare(set[scan], pivotValue))
        {
            pivotIndex++;
            
            // Swap elements at pivotIndex and scan of the vector
            temp = set[pivotIndex];
            set[pivotIndex] = set[scan];
            set[scan] = temp;
        }
        
    }
    
    // swap elements at start and pivotIndex of the vector
    temp = set[start];
    set[start] = set[pivotIndex];
    set[pivotIndex] = temp;
    
    
    return pivotIndex;
}
#endif /* quicksort_h */
