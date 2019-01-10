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

#ifndef prog3_h
#define prog3_h

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

// Symbolic constants
const int NO_ITEMS = 16;
const int ITEM_W = 4;

void print_primes(const set<int> &s);
void sieve(set<int> &s, int n);

#endif /* prog3_h */
