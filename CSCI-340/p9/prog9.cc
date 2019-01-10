#include "prog9.h"
#include "hTable.h"

// Hashing with linear probe and indirect sorting

int main ( )
{
    char c;  // operation code
    Entry e; // holds input data
    HT h;    // hash table

    // print program header message
    cout << "\t*** Hashing with linear probe ***\n\n";

    while ( cin >> c ) {
        switch ( c ) {
            case 'A': // insert record in hash table
                read_rec1 ( e ); prnt_rec1 ( e );
                h.insert ( e ); break;

            case 'S': // search for record in hash table
                read_rec2 ( e );
                cout << "search: key " << e.key;
                h.search ( e.key ); break;

            case 'P': // print all active entries of hash table
                cin.ignore ( SZ_BUF, ':' );
                cout << "\nhTable_print:\n";
                cout << "entry  key    number    description\n";
                h.hTable_print ( ); break;

            default: // illegal command
                cout  << "error: invalid entry\n";
                break;
        }
    }

    // print hash table (in sorted order) 

    cout << "\nsort_print:\n   sorted hash table:\n";
    cout << "   key    number    description\n";
    h.pTable_print ( );

    // print program termination message
    cout << "\n\t*** end of program termination ***\n";
    return 0;
}

// routine to get record from stdin
void read_rec1 ( Entry& e )
{
    char buf1 [ SZ_BUF + 1 ];

    cin.ignore ( SZ_BUF, ':' );
    cin.get ( buf1, SZ_ID + 1, ':' ); cin.ignore ( SZ_BUF, ':' );

    e.key = string ( buf1 ); cin >> e.num; cin.ignore ( SZ_BUF, ':' );
    cin.get ( buf1, SZ_ITEM + 1, ':' ); cin.ignore ( SZ_BUF, ':' );
    e.desc = string ( buf1 );
}

// routine to get record from hash table
void read_rec2 ( Entry& e )
{
    char buf2 [ SZ_BUF + 1 ];

    cin.ignore ( SZ_BUF, ':' );
    cin.get ( buf2, SZ_ID + 1, ':' ); cin.ignore ( SZ_BUF, ':' );
    e.key = string ( buf2 );
}

// routine to print record from stdin on stdout
void prnt_rec1 ( const Entry& e )
{
    cout << "insert: :" << e.key << ':';
    cout.flags ( ios :: right );
    cout << setw ( SZ_ID + 1 ) << e.num << ':';
    cout.flags ( ios :: left );
    cout << setw ( SZ_ITEM ) << e.desc.c_str ( ) << ':';
    cout.flags ( ios :: right);
}
