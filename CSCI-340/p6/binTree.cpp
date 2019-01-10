#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#include "binTree.h"

#define SEED       1 // seed for RNGs

#define N1       100 // size of 1st vector container
#define LOW1    -999 // low val for rand integer
#define HIGH1    999 // high val for rand integer


#define N2        50 // size of 2nd vector container
#define LOW2  -99999 // low val for rand float
#define HIGH2  99999 // high val for rand float
#define PREC       2 // no of digits after dec pt

#define LSIZE     12 // no of vals printed on line
#define ITEM_W     7 // no of spaces for each item

// prints single val
template < class T > void print ( const T& );

// prints data vals in tree
template < class T > void print_vals ( binTree < T >&, const string& );

// class to generate rand ints
class RND1 {
private:
    int low, high;
public:
    RND1 ( const int& l = 0, const int& h = 1 ) : low ( l ), high ( h ) { }
    int operator ( ) ( ) const {
        return rand ( ) % ( high - low + 1 ) + low;
    }
};

// class to generate rand floats
class RND2 {
private:
    int low, high, prec;
public:
    RND2 ( const int& l = 0, const int& h = 1, const int& p = 0 ) :
    low ( l ), high ( h ), prec ( p ) { }
    float operator ( ) ( ) const {
        return ( static_cast < float >
                ( rand ( ) % ( high - low + 1 ) + low ) ) / pow ( 10, prec );
    }
};

// prints out val passed as argument
template < class T >
void print ( const T& x ) {
    static unsigned cnt = 0;
    cout << setw ( ITEM_W ) << x << ' '; cnt++;
    if ( cnt % LSIZE == 0 ) cout << endl;
}

// prints out height of bin tree and data val in each node in inorder
template < class T >
void print_vals ( binTree < T >& tree, const string& name )
{
    cout << name << ": "; // print name of tree
    
    // print height of tree
    cout << "height of tree = " << tree.height ( ) << endl << endl;
    
    // print data values of tree in inorder
    cout << "Data values in '" << name << "' inorder:\n\n";
    tree.inorder ( print ); cout << endl;
}

// driver program: to test several member functions
// of bin tree class

int main ( )
{
    srand ( SEED ); // set seed for RNGs
    
    // create 1st vector and fill it with rand ints
    vector < int > A ( N1 );
    generate ( A.begin ( ), A.end ( ), RND1 ( LOW1, HIGH1 ) );
    
    // create bin tree with int vals in vector A,
    // and print all vals of tree
    
    binTree < int > first;
    for (unsigned i = 0; i < A.size ( ); i++)
        first.insert ( A [ i ] );
    print_vals ( first, "first" ); cout << endl;
    
    // create 2nd vector and fill it with rand floats
    vector < float > B ( N2 );
    generate ( B.begin ( ), B.end ( ), RND2 ( LOW2, HIGH2, PREC ) );
    
    // create bin tree with float-pt vals in vector B,
    // and print all vals of tree
    
    binTree < float > second;
    for ( unsigned i = 0; i < B.size ( ); i++ )
        second.insert ( B [ i ] );
    print_vals ( second, "second" ); cout << endl;
    
    return 0;
}
