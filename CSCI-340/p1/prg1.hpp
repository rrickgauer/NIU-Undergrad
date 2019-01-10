/*********************************************************
* Name:         Ryan Rickgauer
* Z-ID:         z-1729300
* Program #:    1
* Due Date:     9/6/2018
 ********************************************************/
#ifndef prg1_hpp
#define prg1_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int LOW = 1;          // Lowest number possible in RNG range
const int HIGH = 10000;     // Highest number possible in RNG range
const int VEC_SIZE = 250;   // Number of elements in the vector
const int SEED = 1;         // Seed value for RNG
const int NO_ITEMS = 12;    // Number of items to print per line
const int ITEM_W = 5;       // Number of spaces for setw()

void genRndNums(vector<int> &newVector);
void printVec(const vector<int> &v);

#endif /* prg1_hpp */
