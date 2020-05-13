/*******************************************************************
CSCI 480						Assignment 7  							Spring 2020

Progammer:	Ryan Rickgauer
Section:		2
TA:			Jingwan Li
Date Due:   4/24/2020

Purpose:		The purpose of this assignment is to maintain a File
            Allocation Table
********************************************************************/

// defines
#define HOWOFTEN 5
#define BLOCKSIZE 512
#define MAXENTRIES 12

// includes
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;
const char* fileName = "data7.txt";

struct Entry{
	int startPos;
	string fileName;
	int size;
	Entry(int x, string y, int z)
	{
		startPos = x;
		fileName = y;
		size = z;
	}
};

// function prototypes
bool newFile(string, int);
bool renameFile(string, string);
bool modFile(string, int);
bool delFile(string);
bool copyFile(string, string);

// function prototypes for helper functions
void checkFATState();
Entry * findFileWithName(string name);
int findEmptySpotInFAT(int initalPos);
void printFAT();
void printdir();

// global variables
vector<Entry*> dir;
short FAT[4096];

/******************************************************************
Function:   Main

Use:        Main program entry point

Parameters: none

Returns:    0 on success
            -1 on Missing file
******************************************************************/

int main(int argc, char ** argv)
{
	FAT[0] = -1;
	FAT[4095] = -1;
	dir.push_back(new Entry(0, ".", 512));
	dir.push_back(new Entry(-1, "..", 0));


	// open file
	ifstream inFile;
	inFile.open(fileName);

	// exit on open failure
	if (!inFile) {
		cerr << "unable to open input file";
		exit(-1);
	}

	cout << "Beginning of the FAT simulation\n";

	// read line
	char inputLine[256];

	// basic variables for multi-use
	int count = 0;
	bool endCon = false;
	string nameHolder1;
	string nameHolder2;
	int sizeHolder;


	// main event loop
	while (inFile && !endCon)
	{
		// print every HOWOFTEN
		if (count % HOWOFTEN == 0)
		{
			printdir();
			printFAT();
		}

		// clear previous input
		memset(inputLine, '\0', 256);

		// read some stuff
		inFile.getline(inputLine, 256);


		// decide what to do
		switch(inputLine[0])
		{
			case 'C':
				cout << "Transaction:  Copy a file\n";

				strtok(inputLine, " \n\r");
				nameHolder1 = (string) (strtok(nullptr, " \n\r"));
				nameHolder2 = (string) (strtok(nullptr, " \n\r"));


				if (copyFile(nameHolder1, nameHolder2))
					cout << "Successfully copied an existing file, "
						 << nameHolder1
						 << ", to a new file, "
						 << nameHolder2
						 << endl;

				break;
			case 'D':
				cout << "Transaction:  Delete a file\n";

				strtok(inputLine, " \n\r");
				nameHolder1 = (string) (strtok(nullptr, " \n\r"));

				if (delFile(nameHolder1))
					cout << "Successfully deleted a file, "
						 << nameHolder1
						 << endl;

				break;
			case 'N':
				cout << "Transaction:  Add a new file\n";

				strtok(inputLine, " \n\r");
				nameHolder1 = (string) (strtok(nullptr, " \n\r"));
				sizeHolder = atoi(strtok(nullptr, " \n\r"));

				if (newFile(nameHolder1, sizeHolder))
					cout << "Successfuly added a new file, "
					 << nameHolder1
					 << ", of size "
					 << sizeHolder
					 << endl;

				break;
			case 'M':
				cout << "Transaction:  Modify a file\n";

				strtok(inputLine, " \n\r");
				nameHolder1 = (string) (strtok(nullptr, " \n\r"));
				sizeHolder = atoi(strtok(nullptr, " \n\r"));

				if (modFile(nameHolder1, sizeHolder))
					cout << "Successfully modified a file, "
						 << nameHolder1
						 << endl;

				break;
			case 'R':
				cout << "Transaction:  Rename a file\n";

				strtok(inputLine, " \n\r");
				nameHolder1 = (string) (strtok(nullptr, " \n\r"));
				nameHolder2 = (string) (strtok(nullptr, " \n\r"));

				if (renameFile(nameHolder1, nameHolder2))
					cout << "Successfully changed the file name "
						 << nameHolder1
						 << " to "
						 << nameHolder2
						 << endl;

				break;
			case '?':
				endCon = true;
				break;
			default:
				break;
		}

		count++;
	}

	// final print
	cout << "\nEnd of the FAT simulation\n";
	printdir();
	printFAT();

	// done
	return 0;
}


/*****************************************************************
Function:   printdir

Use:        prints eveything in the current directory

Parameters: none

Returns:    nothing
******************************************************************/
void printdir()
{
	cout << "\nDirectory Listing\n";
	int sizeCount = 0;
	int clustCount;

	//  iterate thru every element in "dir"
	for (vector<Entry*>::iterator it = dir.begin(); it != dir.end(); it++) {
		sizeCount += (*it)->size;
		cout << "File name: " << setw(23) << left << (*it)->fileName;
		cout << "File Size: " << setw(5) << right << (*it)->size << endl;
		cout << "Cluster(s) in use:  ";

		if ((*it)->startPos != -1)
      {
			clustCount = 1;
			if (FAT[(*it)->startPos] == -1)
				cout << setw(6) << (*it)->startPos << endl;
			else
			{
				cout << setw(6) << (*it)->startPos;
				for(int pos = (*it)->startPos; FAT[pos] != -1; pos = FAT[pos])
				{
					if (clustCount % 12 == 0)
						cout << endl << "                    ";

					cout << setw(6) << FAT[pos];
					clustCount++;

				}
				cout << endl;
			}

		}
		else
			cout << "(none)\n";
	}

	//  final results
	cout << "Files:  " << dir.size();
	cout << "  Total Size:  " << sizeCount;
	cout << " bytes\n";

}

/*****************************************************************
Function:   printFAT

Use:        Prints the FAT up to its 240th block

Parameters: none

Returns:    Nothing
******************************************************************/
void printFAT()
{
	cout << "\nContents of the File Allocation Table";
	int lineno = 0, lineCount = 0;
	while (lineCount < 240)
	{
		// print line Numbers
		if (lineCount % 12 == 0)
		{
			// this 'if' is usedto get the spacing right, so the ouput matches
			if (lineCount == 0)
				cout << "\n#" << setw(3) << setfill('0') << lineno;
			else
				cout << " \n#" << setw(3) << setfill('0') << lineno;

			lineno += 12;
			cout << "-" << setw(3) << setfill('0') << lineno-1 << " ";
		}

		// print each block content
		cout << setw(6) << setfill(' ') << FAT[lineCount];
		lineCount++;
	}
	// finish formatting
	cout << setfill(' ') << " " << endl << endl;
}

/******************************************************************
Function:   newFile

Use:        Creates a new file in the dir and corrispondingly
            fills the FAT as neccessay

Parameters: nameHolder: Name of the new file
			   sizeHolder: size of the new file

Returns:    true if sucessful
            false otherwise
******************************************************************/
bool newFile(string nameHolder, int sizeHolder)
{
	bool rv = true;
	int currentSpot = 0;
	int nextSpot = -1;

	// check if file exsists
	Entry * fileNameHolder = findFileWithName(nameHolder);

	if (fileNameHolder == nullptr)
	{
		if (sizeHolder != 0)
		{
			// find the first spot available
			currentSpot = findEmptySpotInFAT(0);

			// create a new entry in dir
			dir.push_back(new Entry(currentSpot, nameHolder, sizeHolder));
			sizeHolder -= BLOCKSIZE;

			// allocate multiple blocks to satisfy size
			while (sizeHolder > 0)
			{
				// cout << " S: " << sizeHolder;
				nextSpot = findEmptySpotInFAT(currentSpot+1);
				// cout << " *NS* " << nextSpot;
				FAT[currentSpot] = nextSpot;
				currentSpot = nextSpot;

				sizeHolder -= BLOCKSIZE;
			}
			// cout << endl;
			FAT[currentSpot] = -1;
		}
		else
			dir.push_back(new Entry(-1, nameHolder, 0));

	}
	else
	{
		cout << "File already exsists!\n";
		rv = true;
	}
	checkFATState();
	return rv;
}

/******************************************************************
Function:   renameFile

Use:        Renames a file from one name to another

Parameters: name1: Filename to be renamed
            name2: Desired new filename

Returns:    true if sucessful
            false otherwise
******************************************************************/
bool renameFile(string name1, string name2)
{
	Entry * file1 = findFileWithName(name1);
	if (file1 == nullptr)
	{
		cout << "Error!  The old file name, " << name1 << ", was not found.\n";
		return false;
	}

	Entry * file2 = findFileWithName(name2);
	if (file2 != nullptr)
	{
		cout << "File already exsists!\n";
		return false;
	}

	file1->fileName = name2;
	return true;
}

/******************************************************************
Function:   modFile

Use:        Modifies an exsisting file, used to change the filesize

Parameters: name: Name of the file to modify
            size: new size of the file

Returns:    true if sucessful
            false otherwise
******************************************************************/
bool modFile(string name, int size)
{
	Entry * file = findFileWithName(name);
	if (file == nullptr)
	{
		cout << "Error!  The file name, " << name << ", was not found.\n";
		return false;
	}

	// tempname has spaces, and since a file shouldn't have
	// spces, there'll be no rename collisions
	string tempname = (file->fileName) + "     ";

	string oldname = file->fileName;

	// create new file, delete old file, rename file back
	newFile(tempname, size);
	delFile(oldname);
	renameFile(tempname, oldname);
	return true;
}

/******************************************************************
Function:   delFile

Use:        deletes a file from dir and corrispondingly removes
            it's place in the FAT

Parameters: name: the name of the file to delete

Returns:    true if sucessful
            false otherwise
******************************************************************/
bool delFile(string name)
{
	Entry * file1 = findFileWithName(name);
	if (file1 == nullptr)
	{
		cout << "Error!  The file name, " << name << ", was not found.\n";
		return false;
	}

	int pos = file1->startPos;
	int nextPos;

	// if startPos = -1, then the size = 0
	if (pos != -1)
	{
		// iterate thru this file's FAT data and replace all
		// spots to 0
		while (FAT[pos] != -1)
		{
			nextPos = FAT[pos];
			FAT[pos] = 0;
			pos = nextPos;
		}
		// replace final -1 to 0
		FAT[pos] = 0;
	}

	// Used to erase the specific file entry
	bool stopCondition = false;
	for (vector<Entry*>::iterator it = dir.begin(); it != dir.end() && !stopCondition; it++)
	{
		if ((*it)->fileName == name)
		{
			dir.erase(it);
			stopCondition = true;
		}
	}

	// update FAT state
	checkFATState();

	return true;
}

/******************************************************************
Function:   copyFile

Use:        copies a file with a given filename to another name

Parameters: name1: name of the desired file to copy
            name2: name of the desired copy

Returns:    true if sucessful
            false otherwise
******************************************************************/
bool copyFile(string name1, string name2)
{
	Entry * file1 = findFileWithName(name1);
	if (file1 == nullptr)
	{
		cout << "Error!  The old file name, " << name1 << ", was not found.\n";
		return false;
	}

	Entry * file2 = findFileWithName(name2);
	if (file2 != nullptr)
	{
		cout << "Error!  The new file name, " << name2 << ", already exists.\n";
		return false;
	}

	newFile(name2, file1->size);
	return true;
}

/******************************************************************
Function:   checkFATState

Use:        checks to see if the current dir size isn't sufficient
            or superfluous

Parameters: none

Returns:    Nothing
******************************************************************/
void checkFATState()
{
	// shrink
	if (((float)dir.front()->size / (float)BLOCKSIZE) > ceil((float)dir.size() / (float)MAXENTRIES))
	{
		int prevPos = 0;
		int curPos = 0;
		while (FAT[curPos] != -1)
		{
			prevPos = curPos;
			curPos = FAT[curPos];
		}

		FAT[curPos] = 0;
		FAT[prevPos] = -1;
		dir.front()->size = (int) ((float)BLOCKSIZE * ceil((float)dir.size() / (float)MAXENTRIES));
	}
	// grow
	else if (((float) dir[0]->size / (float) BLOCKSIZE) < ceil( (float) dir.size() / (float) MAXENTRIES))
	{
		int curPos = 0;
		int nextPos;
		while (FAT[curPos] != -1)
		{
			curPos = FAT[curPos];
		}
		nextPos = findEmptySpotInFAT(curPos);
		FAT[curPos] = nextPos;
		FAT[nextPos] = -1;
		dir.front()->size = (int) ((float)BLOCKSIZE * ceil((float)dir.size() / (float)MAXENTRIES));
	}
}
/******************************************************************
Function:   findEmptySpotInFAT

Use:        Finds a '0' in the FAT following initalPos

Parameters: initalPost: the starting position for starting the search

Returns:    The position of the next zero or -1 if the FAT is full.
******************************************************************/
int findEmptySpotInFAT(int initalPos)
{
	int rv = -1;
	for (bool found = false; !found && initalPos < 4096; initalPos++)
	{
		if (FAT[initalPos] == 0)
		{
			found = true;
			rv = initalPos;
		}
	}
	return rv;
}

/******************************************************************
Function:   findFileWithName

Use:        Finds a file in dir with the same name as the 'name'
            parameter

Parameters: name: a name to look for

Returns:    A pointer to the Entry in dir with the specificed name
******************************************************************/
Entry * findFileWithName(string name)
{
	Entry * rv = nullptr;
	bool stopCondition = false;
	for (vector<Entry*>::iterator it = dir.begin(); it != dir.end() && !stopCondition; it++)
	{
		if ((*it)->fileName == name)
		{
			rv = *it;
			stopCondition = true;
		}
	}

	return rv;
}
