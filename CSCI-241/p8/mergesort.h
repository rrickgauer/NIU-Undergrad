/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 8
 PROGRAMMER: Ryan Rickgauer
 LOGON ID:   z1729300
 DUE DATE:   4/26/2017
 
 FUNCTION:   This program builds and sorts lists using the quick
             sort algorithm.
 *********************************************************************/

#ifndef mergesort_h
#define mergesort_h
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

template <class T> void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));
template <class T> void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

/**************************************************************
 
 FUNCTION:  void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type
 
 RETURNS:   N/A.
 
 NOTES:     Sorts the items in set using the merge sort algoirthm.
 
 **************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    // Calls the recursive merge sort function
    mergeSort(set, 0, (int)set.size() - 1, compare);
}

/**************************************************************
 
 FUNCTION:  void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object
            low - integer representing the lowest subscript index
            high - integer representing the highest subscript index
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type
 
 RETURNS:   N/A.
 
 NOTES:     Divides a vector into 2 subvectors, sorts them,
            and then merges them.
 
 **************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
    if (low < high)
    {
        // Mid is in the middle of low and high
        int mid = (low + high) / 2;
        
        // Divide and conquer
        mergeSort(set, low, mid, compare);
        mergeSort(set, mid+1, high, compare);
        
        // Combine sorted subarrays
        merge(set, low, mid, high, compare);
    }
}

/**************************************************************
 
 FUNCTION:  void merge(vector<T>& set, int low, int mid, int high, bool(*compare)(const T&, const T&))
 
 ARGUMENTS: set - a reference to a vector object
            low - integer representing the lowest subscript index
            mid - integer representing the middle subscript index
            high - integer representing the highest subscript index
            *compare - a pointer to a comparison function that can
            be used to compare 2 items of the template type
 
 RETURNS:   N/A.
 
 NOTES:     Merges 2 sorted subvectors.
 
 **************************************************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool(*compare)(const T&, const T&))
{
    // Create a temporary vector to hold merged subvectors
    vector<T> temp(high - low + 1);
    
    int i = low;        // Subscript for start of left sorted subvector
    int j = mid + 1;    // Subscript for start of right sorted subvector
    int k = 0;          // Subscript for start of merged vector
    
    // While not at the end of either subvector
    while (i <= mid && j <= high)
    {
        if (compare(set[j], set[i]))
        {
            temp[k] = set[j];   // Copy element j of set into element k of temp
            j++;                // Add one to j
            k++;                // Add one to k
        }
        
        else
        {
            temp[k] = set[i];   // Copy element i of set into element k of temp
            i++;                // Add one to i
            k++;                // Add one to k
        }
    }
    
    // Copy over any remaining elements of left subvector
    while (i <= mid)
    {
        temp[k] = set[i];   // Copy element i of set into element k of temp
        i++;                // Add one to i
        k++;                // Add one to k
    }
    
    // Copy over any remaining elements of the right subvector
    while (j <= high)
    {
        temp[k] = set[j];
        j++;
        k++;
    }

    // Copy merged elements back into orignial vector
    for (i = 0, j = low; j <= high; i++, j++)
        set[j] = temp[i];
}

#endif /* mergesort_h */
