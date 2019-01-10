/***********************************************************
 CSCI 340 - Program 8 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  November 17, 2018
 
 Purpose:   This program sorts items in several input files,
 using the heapsort technique.
 ************************************************************/

#include "prog8.h"

int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings
    
    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";
    
    // first heap
    
    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    cout << "\n\nfirst heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    // second heap
    
    cout << "\n\nsecond heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    
    cout << "\n\nsecond heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    // third heap
    
    cout << "\n\nthird heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    
    cout << "\n\nthird heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}

/***************************************************************
 Function: get_list
 
 Parameters: 1 reference to a vector<T>, pointer to char
 
 Returns: void
 
 Notes: Opens an input file for reading, then reads the items
 from the file and inserts them in a vector.
 ***************************************************************/
template < class T >
void get_list ( vector < T >& v, const char* path)
{
    
    ifstream inFile;    // file variable
    inFile.open(path);  // opens the file
    v.clear();          // clears all previous items in the vector
    T temp;             // holds the next value in the file
    
    // inserts all file items into the vector
    while (inFile >> temp)
        v.push_back(temp);
    
    inFile.close();     // close file

}

/***************************************************************
 Function: construct_heap
 
 Parameters: 1 reference to a vector<T>, 1 predicate class
 
 Returns: void
 
 Notes: It constructs a heap structure from the items of vector
 v and uses the predicate pred to compare the items when building
 the heap. Calls the make_heap & sort_heap functions from STL.
 ***************************************************************/
template < class T, class P >
void construct_heap(vector < T >& v, P pred)
{
    make_heap(v.begin(), v.end(), pred);
    sort_heap(v.begin(), v.end(), pred);
}

/***************************************************************
 Function: print_list
 
 Parameters: 4 references to unsigned consts
 
 Returns: void
 
 Notes: The constructor of the print_list class, where s is the
 heap size, w is the minimum number of chars written in printout,
 l is the maximum number of items printed in a single line, and c
 is used as a counter with th default value 0 that can be used
 to insert the newline characters in printout.
 ***************************************************************/
template < class T >
print_list<T>::print_list( const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c)
{
    sz = s;
    wid = w;
    len = l;
    cnt = c;
}

/***************************************************************
 Function: operator()
 
 Parameters: 1 reference to a T const
 
 Returns: void
 
 Notes: () operator overloader to print x on the stdout.
 ***************************************************************/
template < class T >
void print_list<T>::operator()(const T &x)
{
   
    cout.width(wid);
    cout.precision(2);
    cout << fixed << showpoint;
    cout << x << " ";
    
    cnt++;  // adds one to cnt
    
    // once cnt reaches no of allowed items per line, insert line break
    if (cnt % len == 0 && cnt > 0)
        cout << endl;
}
