#ifndef H_ENTRY
#define H_ENTRY

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SZ_ID    3      // size of key
#define SZ_ITEM 24      // max size for item description 
#define SZ_TBL  31      // default size for hash table
#define FREE   "$$$"    // indicates empty spot in hash table

// entry in hash table

struct Entry {
    string key,   // key
           desc;  // description
    unsigned num; // no of copies

    //constructor
    Entry ( const string& k = FREE, const string& d = "",
        const unsigned& n = 0 ) : key ( k ), desc ( d ),
        num ( n ) { }
};

#endif
