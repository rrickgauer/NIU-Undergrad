#include "Entry.h"
#ifndef H_HASH_TABLE
#define H_HASH_TABLE

// class for hash table

class HT {
public:
    HT ( const unsigned& = SZ_TBL ); // constructor
    ~HT ( );                         // destructor

    void insert ( const Entry& );    // inserts item in hash table
    void search ( const string& );   // searches for item

    void hTable_print ( ); // prints hash table entries
    void pTable_print ( ); // prints hash table entries in sorted order

private:
    unsigned hsize,             // size of hash table
             psize;             // actual size of ptr table

    vector < Entry >  hTable;   // hash table
    vector < Entry* > pTable;   // ptr table

    int hash ( const string& ); // hash function
};

#endif
