#include "wdigraph.h"

#define N2 5    // size of 2nd graph
#define N3 20   // size of 3rd graph
#define M  3    // skip value in printing

void proc_graph ( wdigraph& );

// This driver program can be used to test routines
// defined in class wdigraph.

int main ( )
{
    // create weighted digraph for default size
    wdigraph g1; proc_graph ( g1 );

    // create weighted digraph of size N2
    wdigraph g2 ( N2 ); proc_graph ( g2 );

    // create weighted digraph of size N3
    wdigraph g3 ( N3 ); proc_graph ( g3 );

    return 0;
}

// This routine is to create a weighted digraph
// for given size and it prints adjacency matrix.

void proc_graph ( wdigraph& g )
{
    // print graph
    cout << "\nA Weighted Digraph\n";
    cout << "__________________\n";
    g.print_graph ( );

    // visit nodes by depth-first search
    cout << "Paths by Depth-First Search\n\n";
    for ( int i = 0; i < g.get_size ( ); i += M ) g.depth_first ( i );
}
