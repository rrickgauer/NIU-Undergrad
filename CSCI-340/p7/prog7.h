#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#ifndef H_PROG7
#define H_PROG7

#define SEED 1      // seed for RNG
#define N 100       // num of rand ints

// class to generate rand ints
class RND {
private:
    int seed;
public:
    RND ( const int& s = SEED ) : seed ( s ) { srand ( seed ); }
    int operator ( ) ( ) { return rand ( ) % N + 1; }
};

#define NO_ITEMS 16 // max num of elems printed in line
#define ITEM_W 3    // size of each elem on printout

unsigned sz;        // size of vector

// macro to print size
#define COUT_SZ cout << "size = " << setw ( ITEM_W ) << sz << " :"

// function to print elems on stdout
template < class T > void print ( T& x )
{
    static unsigned cnt = 0;
    const string sp ( 12, ' ' );
    
    cout << setw ( ITEM_W ) << x << ' '; cnt++;
    if ( cnt % NO_ITEMS == 0 || cnt == sz ) cout << endl << sp;
    if ( cnt == sz ) cnt = 0;
}

#endif
