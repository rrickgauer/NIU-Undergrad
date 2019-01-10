#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef H_PROG8
#define H_PROG8

// data files

#define D1 "d1.txt"
#define D2 "d2.txt"
#define D3 "d3.txt"

#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers in single line
#define FLT_LN 9    // no of floating-pt nums in single line
#define STR_LN 5    // no of strings in single line

// function and class prototypes

// stores items from input file into vector
template < class T >
void get_list ( vector < T >&, const char* );

// construct heap from items in vector
template < class T, class P >
void construct_heap ( vector < T >&, P );

// class to print heap items

template < class T >
class print_list {
    unsigned sz,  // heap size
    wid, // min num of chars written in printout
    len, // max num of items printed in single line
    cnt; // counter for printout
public:
    print_list ( const unsigned& = 1, const unsigned& = 1,
                const unsigned& = 1, const unsigned& = 0 ); // constructor
    void operator ( ) ( const T& );
};
#endif
