/***********************************************************
 CSCI 340 - Program 10 - Fall 2018

 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  December 6, 2018

 Purpose:   This program implements several graph algorithms
 on weighted digraphs.
 ************************************************************/

#include "wdigraph.h"

/***************************************************************
Function: depth_first()

Parameters: 1 int

Returns: void

Notes: Traverses a digraph in the depth-first order and it prints
the resulting path. The index value u of the starting node is
given as an input argument to this function.
***************************************************************/
void wdigraph::depth_first(int start) const
{
		// set all elements as not visited
   	vector<bool> visit(get_size(), false);

   	// use a stack to keep track of previous elements
   	stack<int> s;
   	s.push(start);

   	while (s.empty() == false)
  		{
        	// get previous element and remove it
        	int top = s.top();
        	s.pop();

			// print element if it has not been visited
        	if (visit[top] == false)
			{
				visit[top] = true;

				if (top != start)
					cout << "->";
				cout << label[top];
			}

        	// place all adjecent vertices in the stack
        	for (int count = get_size(); count >= 0; count--)
    			if (visit[count] == false && adj_matrix[top][count] > 0)
            	s.push(count);
  		}

		cout << endl << endl;
}

/***************************************************************
Function: print_graph()

Parameters: none

Returns: void

Notes: Prints the number of nodes in a graph, and prints an
adjacency matrix representation.
***************************************************************/
void wdigraph::print_graph() const
{
	// print num nodes
	cout << "\nNo of nodes = " << get_size() << endl << endl;
	cout << "Adjacency Matrix" << endl << endl;

	cout << "  |";

	// print column headers
	for (int count = 0; count < get_size(); count++)
		cout << setw(3) << label[count];

	// print line dashes beneath
	cout << endl << "--|";
	for (int count = 0; count < get_size() * 3; count++)
		cout << "-";

	cout << endl;

	// print adj matrix
	for (int count = 0; count < get_size(); count++)
	{
		cout << label[count] << " |";

		for (int count2 = 0; count2 < get_size(); count2++)
		{
			if (adj_matrix[count][count2] == 0)
    			cout << setw(3) << "-";
			else
    			cout << setw(3) << adj_matrix[count][count2];
		}

	cout << endl << "  |" << endl;
	}

	cout << endl;
}
