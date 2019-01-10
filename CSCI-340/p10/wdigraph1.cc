#include "wdigraph.h"

// default class constructor

wdigraph :: wdigraph ( int n ) : size ( n )
{
    // allocate dynamic memory

    label = vector < char > ( size );
    adj_matrix = vector < vector < int > > ( size );
    for ( int i = 0; i < size; i++ )
        adj_matrix [ i ] = vector < int > ( size );

    // assign labels to each node

    label [ 0 ] = 'A';
    for ( int i = 1; i < size; i++ )
        label [ i ] = label [ i - 1 ] + 1;

    // determine weights for links between nodes randomly
    // and build adjacency matrix

    srand ( 1 );
    for ( int i = 0; i < size; i++ ) {
        adj_matrix [ i ] [ i ] = 0;
        bool flag = false;
        for ( int j = 0; j < size; j++ ) {
            if ( j == i ) continue;
            double r = ( double ) rand ( ) / RAND_MAX;
            adj_matrix [ i ] [ j ] =
                ( r <= LINK_PROB ) ? rand ( ) % MAX_WEIGHT + 1 : 0;
            if ( adj_matrix [ i ] [ j ] > 0 ) flag = true;
        }

        // if node is not connected to any other node, then
        // connect this node to random node

        if ( size > 1 && !flag ) {
            int k; while ( ( k = rand ( ) % size ) == i ) ;
            adj_matrix [ i ] [ k ] = rand ( ) % MAX_WEIGHT + 1;
        }
    }
}
