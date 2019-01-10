/***********************************************************
 CSCI 340 - Program 4 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  October 2, 2018
 
 Purpose:   This program implements an interactive scanner to
 scan and process a stream of words of a plain text.
 ************************************************************/

#ifndef Program4_h
#define Program4_h

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>


using namespace std;

const int NO_ITEMS = 3;
const int ITEM_W = 16;

void clean_entry(const string& original, string& result);
void get_words(map<string, int>& m);
void print_words(const map<string, int> &newMap);

#endif /* Program4_h */
