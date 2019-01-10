/***********************************************************
 CSCI 340 - Program 2 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  September 4, 2018
 
 Purpose:   This program implements two search algorithms (a
            linear search & binary search) on randomly generated
            integers stored in vectors.
 ************************************************************/

#ifndef prog2_h
#define prog2_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

// Symbolic constants
const int LOW = 1;
const int HIGH = 1000;
const int ARR_SIZE = 200;
const int TEST_ARR_SIZE = 100;
const int SEED1 = 1;
const int SEED2 = 3;
const int NO_ITEMS = 16;
const int ITEM_W = 4;

// Functions
void Vectors(vector<int> &v1, vector<int> &v2, int s1, int s2);
bool linearSearch(const vector<int> &v, int x);
bool binarySearch(const vector<int> &v, int x);
int search(const vector<int> &v1, const vector<int> &v2, bool(*p)(const vector <int>&, int));
void sortVector(vector<int> &v);
void printVector(const vector<int> &v);
void printStat(int totalSucCnt, int vectorSz);

#endif /* prog2_h */
