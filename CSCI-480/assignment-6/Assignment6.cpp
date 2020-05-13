/********************************************************************
CSCI 480						Assignment 6  							Spring 2020

Progammer:	Ryan Rickgauer
Section:		2
TA:			Jingwan Li
Date Due:   4/13/2020

Purpose:		The purpose of this assignment is to simulate memory
            management.
*********************************************************************/

#define HOWOFTEN 5
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <climits>
#include <cstdlib>

using namespace std;
const char* fileName = "data6.txt";
struct Blook;
void print();
void mergeAvail();
void load(string, int, string);
void alloc(string, int, string);
void dealloc(string, string);
void term(string, bool firstRun = true);
void blookDelete(Blook *, Blook **);
char fit = 'F';



struct Blook {
	Blook(int, int);
	int address;
	int size;
	string ownpid;
	string blookpid;
	Blook * prev;
	Blook * next;
};

/*
Consturctor: Blook

Use: consturctor for Blook

Parameters: x: address
			y: size
*/

Blook::Blook(int x, int y)
{
	address = x;
	size = y;
}

//Available blocks of memory
Blook * Avail = nullptr;

//InUse blocks of memory
Blook * InUse = nullptr;

/*
Function: Main

Use: Main program entry point

Parameters:none

Returns: 0 on success
        -1 on Missing file or incorrect useage
*/

int main(int argc, char ** argv)
{
	string algo;
	//exit if incorrect aruments are givin
	if (argc != 2)
	{
		cerr << "incorrect useage. ./Assign6 [B, F]\n";
		exit(-1);
	}

	//exit if incorrect arguments are given
	switch (argv[1][0])
	{
		case 'F':
			fit = 'F';
			algo = "First-Fit";
			break;
		case 'B':
			fit = 'B';
			algo = "Best-Fit";
			break;
		default:
			cerr << "incorrect useage. ./Assign6 [B, F]\n";
			exit(-1);
			break;
	}

	//make a new pointer for iteration
	Blook * blookIter;

	//Start Making a linked-list of memory
	//Make new block, emplace it at Avail
	//1MB
	Avail = new Blook(3*1024*1024, 1024*1024);

	//Make new block, emplace it at Avail->next
	//2MB
	Avail->next = new Blook(Avail->size + Avail->address, 2*1024*1024);
	Avail->prev = nullptr;

	blookIter = Avail->next;
	blookIter->prev = Avail;

	//Make new block, emplace it at blookIter->next
	//2MB
	blookIter->next = new Blook(blookIter->size + blookIter->address, 2*1024*1024);
	blookIter->next->prev = blookIter;
	blookIter = blookIter->next;

	//Make new block, emplace it at blookIter->next
	//4MB
	blookIter->next = new Blook(blookIter->size + blookIter->address, 4*1024*1024);
	blookIter->next->prev = blookIter;
	blookIter = blookIter->next;

	//Make new block, emplace it at blookIter->next
	//4MB
	blookIter->next = new Blook(blookIter->size + blookIter->address, 4*1024*1024);
	blookIter->next->prev = blookIter;
	blookIter->next->next = nullptr;

	/*
	 * Above code makes a linked list of
	 * nullptr < 1MB > < 2MB > < 2MB > < 4MB > < 4MB > nullptr;
	 */

	//open file
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile) {
		cerr << "unable to open input file";
		exit(-1);
	}

	//read line
	char inputLine[256];

	//holders for strtok()
	string ownHold = "";
	string idHold = "";
	int sizeHold = 0;
	int count = 0;

	cout << "Simulation of Memory Management using the " << algo << " algorithm\n\n"
		 << "Beginning of the run\n\n";

	print();

	//main event loop
	while (inFile && inFile.peek() != '?')
	{
		if ((count % HOWOFTEN) == 0)
			print();

		//clear previous input
		memset(inputLine, '\0', 256);

		//read some stuff
		inFile.getline(inputLine, 256);

		//decide what to do
		switch(inputLine[0])
		{
			case 'L':
				strtok(inputLine, " \n\r");
				ownHold = (string) strtok(nullptr, " \n\r");
				sizeHold = atoi(strtok(nullptr, " \n\r"));
				idHold = (string) strtok(nullptr, " \n\r");
				load(ownHold, sizeHold, idHold);
				break;
			case 'A':
				strtok(inputLine, " \n\r");
				ownHold = (string) strtok(nullptr, " \n\r");
				sizeHold = atoi(strtok(nullptr, " \n\r"));
				idHold = (string) strtok(nullptr, " \n\r");
				alloc(ownHold, sizeHold, idHold);
				break;
			case 'D':
				strtok(inputLine, " \n\r");
				ownHold = (string) strtok(nullptr, " \n\r");
				idHold = (string) strtok(nullptr, " \n\r");
				dealloc(ownHold, idHold);
				break;
			case 'T':
				strtok(inputLine, " \n\r");
				ownHold = (string) strtok(nullptr, " \n\r");
				term(ownHold);
				break;
			default:
				break;
		}
	}

	//done
	cout << "\n\n\nEnd of the run\n\n";
	print();

	return 0;
}

/*
Function: load

Use: Loads a process into memory

Parameters: own: the process ID of a block of memory
			size: size of memory requested
			block: block ID of the block of memory

Returns: Nothing
*/

void load(string own, int size, string block)
{
	Blook * iter = Avail;
	Blook * nextSpot = nullptr;
	int prevSize = INT_MAX;
	bool stop = false;
	cout << "Transaction: request to load process "
		 << own
		 << ", block ID "
		 << block
		 << " using "
		 << size
		 << " bytes\n";
	if (fit == 'F')
	{
		//look for a block of the needed size using First-Fit
		while (iter != nullptr && stop != true)
		{
			if (iter->size >= size)
				stop = true;
			else
				iter = iter->next;
		}
	}
	else
	{
		//look for a block of the needed size using Best-Fit
		while (iter != nullptr)
		{
			if (iter->size >= size)
			{
				if (prevSize > iter->size)
				{
					prevSize = iter->size;
					nextSpot = iter;
				}
				iter = iter->next;
			}
			else
				iter = iter->next;
		}

		//obtain the best-fit
		if (nextSpot != nullptr)
		{
			stop = true;
			iter = nextSpot;
			nextSpot = nullptr;
		}
	}

	//if we didn't find a block print an error
	if (stop != true)
	{
		cerr << "Unable to comply as no block of adequate size is available\n";
	}
	else
	{
		cout << "Found a block of size " << iter->size << "\n";

		//make a new block
		nextSpot = new Blook(iter->address, size);

		//update sizes/address
		iter->address += size;
		iter->size -= size;

		if (iter->size <= 0)
		{
			blookDelete(iter, &Avail);
		}

		iter = InUse;

		//get the last element in InUse
		if (iter != nullptr)
			while (iter->next != nullptr)
				iter = iter->next;

		//set defaults for block of memory
		nextSpot->ownpid = own;
		nextSpot->blookpid = block;
		nextSpot->next = nullptr;
		nextSpot->prev = nullptr;

		//decide where to put the block of memory
		if (InUse == nullptr)
			InUse = nextSpot;
		else
		{
			iter->next = nextSpot;
			nextSpot->prev = iter;
		}

		cout << "Success in allocating a block\n";
	}
}

/*
Function: alloc

Use: allocates memory for a Process

Parameters: own: the process ID of a block of memory
			size: size of memory requested
			block: block ID of the block of memory

Returns: Nothing
*/

void alloc(string own, int size, string block)
{
	Blook * iter = Avail;
	Blook * nextSpot;
	int prevSize = INT_MAX;
	bool stop = false;
	cout << "Transaction: request to allocate "
		 << size
		 << " bytes for process "
		 << own
		 << ", block ID: "
		 << block
		 << endl;

	if (fit == 'F')
	{
		//look for a block of the needed size using First-Fit
		while (iter != nullptr && stop != true)
		{
			if (iter->size >= size)
				stop = true;
			else
				iter = iter->next;
		}
	}
	else
	{
		//look for a block of the needed size using Best-Fit
		while (iter != nullptr)
		{
			if (iter->size >= size)
			{
				if (prevSize > iter->size)
				{
					prevSize = iter->size;
					nextSpot = iter;
				}
				iter = iter->next;
			}
			else
				iter = iter->next;
		}

		//obtain best fit
		if (nextSpot != nullptr)
		{
			stop = true;
			iter = nextSpot;
			nextSpot = nullptr;
		}
	}

	//if we didn't find a block print an error
	if (stop != true)
		cerr << "No space found! We gonna crash...";
	else
	{
		cout << "Found a block of size " << iter->size << "\n";

		//make a new block
		nextSpot = new Blook(iter->address, size);

		//update sizes/address
		iter->address += size;
		iter->size -= size;
		if (iter->size <= 0)
		{
			blookDelete(iter, &Avail);
		}

		iter = InUse;

		//get the last element in InUse
		if (iter != nullptr)
			while (iter->next != nullptr)
				iter = iter->next;

		//set defaults for block of memory
		nextSpot->ownpid = own;
		nextSpot->blookpid = block;
		nextSpot->next = nullptr;
		nextSpot->prev = nullptr;

		//decide where to put the block of memory
		if (InUse == nullptr)
			InUse = nextSpot;
		else
		{
			iter->next = nextSpot;
			nextSpot->prev = iter;
		}

		cout << "Success in allocating a block\n";
	}
}

/*
Function: dealloc

Use: deallocates a block of memory

Parameters: own: the process ID of a block of memory
			block: block ID of the block of memory

Returns: Nothing
*/

void dealloc(string own, string block)
{
	cout << "Transaction: request to deallocate block ID "
		 << block
		 << " for process "
		 << own
		 << "\n";

	Blook * iter = InUse;
	Blook * emplacer;
	bool found = false;

	//try and find the uniue block of memory
	while (iter != nullptr && found != true)
	{
		if (iter->ownpid == own && iter->blookpid == block)
			found = true;
		else
			iter = iter->next;
	}


	if (found == false)
	{
		cerr << "Unable to comply as the indicated block cannot be found.\n";
	}
	else
	{
		Blook * prevHold = nullptr;

		//emplacer is a new block with its contents the same as
		//the requested block to be dealloc'd
		emplacer = new Blook(iter->address, iter->size);

		//take iter off InUse
		blookDelete(iter, &InUse);

		//iter will be where to put emplacer
		iter = Avail;

		//simple exit condition
		found = false;

		//find the spot to put emplacer
		while (iter != nullptr && found != true)
		{
			if (emplacer->address < iter->address)
				found = true;
			else
			{
				prevHold = iter;
				iter = iter->next;
			}
		}


		//end of block
		if (iter == nullptr)
		{
			//get iter back to the end of Avail
			iter = Avail;
			while (iter->next != nullptr)
				iter = iter->next;

			//put address of block as next(end)
			iter->next = emplacer;

			//set prev to second to last block
			emplacer->prev = iter;

			//at the end, there is no next
			emplacer->next = nullptr;
		}
		//beggining of block
		else if (iter == Avail)
		{

			//shift 1st block to be the second.
			emplacer->next = Avail;
			Avail->prev = emplacer;
			emplacer->prev = nullptr;


			//Avail is now emplacer
			Avail = emplacer;
		}
		//middle of block
		else
		{
			prevHold->next = emplacer;
			emplacer->next = iter;
			emplacer->prev = prevHold;
			iter->prev = emplacer;
		}


		//merge memory
		mergeAvail();
		cout << "Success in deallocating a block\n";
	}
}

/*
Function: term

Use: Terminates a process and frees up memory blocks

Parameters: own: the process ID of a block of memory
            firstRun: Indicates if a step in the recursive
			          method is the first one

Returns: Nothing
*/

void term(string own, bool firstRun)
{
	if (firstRun)
		cout << "Transaction: request to terminate process "
			 << own
		 	<< "\n";


	Blook * iter = InUse;
	Blook * emplacer;
	bool found = false;

	//find a block with ownpid == own
	while (iter != nullptr && found != true)
	{

		if (iter->ownpid == own)
			found = true;
		else
			iter = iter->next;
	}

	if (found == false && firstRun == true)
	{
		cerr << "Unable to comply as the indicated block cannot be found.\n";
	}
	else if (found == true)
	{
		//previous holder
		Blook * prevHold = nullptr;

		//emplacer is a new block with its contents the same as
		//the requested block to be dealloc'd
		emplacer = new Blook(iter->address, iter->size);

		emplacer->next = nullptr;
		emplacer->prev = nullptr;

		//take iter off InUse
		blookDelete(iter, &InUse);

		//iter will be where to put emplacer
		iter = Avail;

		//simple exit condition
		found = false;

		//find the spot to put emplacer
		while (iter != nullptr && found != true)
		{
			if (emplacer->address < iter->address)
				found = true;
			else
			{
				prevHold = iter;
				iter = iter->next;
			}
		}


		//end of block
		if (iter == nullptr)
		{
			//get iter back to the end of Avail
			iter = Avail;
			while (iter->next != nullptr)
				iter = iter->next;

			//put address of block as next(end)
			iter->next = emplacer;

			//set prev to second to last block
			emplacer->prev = iter;

			//at the end, there is no next
			emplacer->next = nullptr;
		}
		//beggining of block
		else if (iter == Avail)
		{

			//shift 1st block to be the second.
			emplacer->next = Avail;
			Avail->prev = emplacer;
			emplacer->prev = nullptr;


			//Avail is now emplacer
			Avail = emplacer;
		}
		//middle of block
		else
		{
			prevHold->next = emplacer;
			emplacer->next = iter;
			emplacer->prev = prevHold;
			iter->prev = emplacer;
		}

		//recursive, continue untill no more blocks of memory are found
		if (InUse != nullptr)
			term(own, false);

		//after callstack unravels, 1st call will merge
		if (firstRun)
		{
			mergeAvail();
			cout << "Success in terminating a process\n";
		}
	}
}

/*
Function: print

Use: Prints the contets of Avail and InUse

Parameters: none

Returns: Nothing
*/

void print()
{
	Blook * iter = Avail;
	long int totalSize = 0;
	cout << "List of available blocks\n";
	if (iter == nullptr)
		cout << "(none)\n";

	//print Avail
	while (iter != nullptr)
	{
		cout << "Start Address = "
			 << setw(8)
			 << iter->address
			 << " Size = "
			 << setw(7)
			 << iter->size
			 << "\n";
		totalSize += iter->size;
		iter = iter->next;
	}
	cout << "Total size of the list = " << totalSize << "\n\n";



	iter = InUse;
	totalSize = 0;

	cout << "List of blocks in use\n";
	if (iter == nullptr)
		cout << "(none)\n";

	//print InUse
	while (iter != nullptr)
	{
		cout << "Start Address = "
			 << setw(9)
			 << iter->address
			 << " Size = "
			 << setw(8)
			 << iter->size
			 << " Process ID = "
			 << iter->ownpid
			 << " Block ID = "
			 << iter->blookpid
			 << "\n";
		totalSize += iter->size;
		iter = iter->next;
	}
	cout << "Total size of the list = " << totalSize << "\n\n";
}

/*
Function: mergeAvail

Use: Merges Blocks of memory that are Available

Parameters: none

Returns: Nothing
*/

void mergeAvail()
{
	Blook * iter = Avail;
	Blook * hold;
	bool IterativeFlag = false;
	while (iter->next != nullptr)
	{
		if ((iter->size + iter->next->size) < 4*1024*1024)
		{
			IterativeFlag = true;
			cout << "Merging two blocks at "
				 << iter->address
				 << " and "
				 << iter->next->address
				 << "\n";

			iter->size += iter->next->size;
			hold = iter->next;
			iter->next = iter->next->next;
			delete hold;
		}
		iter = iter->next;
	}
	if (IterativeFlag)
		mergeAvail();
}

/*
Function: blookDelete

Use: Deletes a Block in a given list

Parameters: iter: a pointer to a Block that needs to be deleted
			from: the address of a pointer that is the starting
				  point of the linked list

Returns: Nothing
*/

void blookDelete(Blook * iter, Blook ** from)
{
	//start point
	if (iter->prev == nullptr && iter->next != nullptr)
	{
		*from = iter->next;
		iter->next->prev = nullptr;
	}
	//mid point
	else if (iter->prev != nullptr && iter->next != nullptr)
	{
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
	}
	//start point, 1 element in list
	else if (iter->prev == nullptr && iter->next == nullptr)
	{
		delete *from;
		*from = nullptr;
	}
	else
	{
		iter->prev->next = nullptr;
	}

	if (*from != nullptr)
		delete iter;
}
