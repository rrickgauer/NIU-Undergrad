/***********************************************************
CSCI 340 - Program 9 - Fall 2018

Name:      Ryan Rickgauer
Z-ID:      z1729300
Section:   3
Date Due:  November 25, 2018

Purpose:   This program creates, searches, prints, and sors
an item inventory using a hash table.
************************************************************/
#include "hTable.h"

/**************************************************************
Function: HT

Parameters: none

Returns: none

Notes: constructor
***************************************************************/
HT::HT(const unsigned &size)
{
	hsize = size;				// set hTable size to size
	psize = 0;					// set pTable size to 0
	hTable.resize(size);		// resize hTable to size
	pTable.resize(size);		// resize pTable to size
}

/**************************************************************
Function: ~HT

Parameters: none

Returns: none

Notes: destructor
***************************************************************/
HT::~HT()
{
	hTable.clear();
	pTable.clear();
}

/**************************************************************
Function: insert

Parameters: a reference to an Entry

Returns: none

Notes: used to insert a the record for an item into the hash table
***************************************************************/
void HT::insert(const Entry& item)
{
	int i = hash(item.key);

	unsigned int count;
	for(count = 0; count < hsize; count++)
	{

		int position = (i + count) % hsize;

		// key already exists
		if (hTable[position].key == item.key)
		{
			cout << " not inserted - duplicate key!!!" << endl;
			break;
		}

		// item is inserted into table
		if (hTable[position].key == FREE)
		{
			cout << " entry = " << position << endl;
			hTable[position] = item;
			pTable[psize] = &hTable[position];
			psize++;
			break;
		}
	}

	// table is full
	if (count == hsize)
	{
		cout << " not inserted - table full!!!" << endl;
	}
}

/**************************************************************
Function: search

Parameters: a reference to a string

Returns: none

Notes: used to search the hash table for a record with a given
key.
***************************************************************/
void HT::search(const string& key)
{
	int i = hash(key);
	unsigned int count;
	for (count = 0; count < hsize; count++)
	{
		int position = (count + i) % hsize;

		// located the item
		if (hTable[position].key == key)
		{
			cout << " ==> ";
			cout << "number: " << hTable[position].num << " - ";
			cout << "item: " << hTable[position].desc << endl;
			break;
		}
	}

	// item was not found
	if (count == hsize)
		cout  << " not in table!!" << endl;
}

/**************************************************************
Function: hTable_print

Parameters: none

Returns: none

Notes: prints the subscript and the contents of all the active
records in the hash table.
***************************************************************/
void HT::hTable_print()
{
	for (unsigned count = 0; count < hsize; count++)
	{
		if (hTable[count].key != FREE)
		{
			// print entry number
			cout << setw(4) << count << ":";

			// print key
			cout << "  " << hTable[count].key << "  -";

			// print number
			cout << setw(6) << hTable[count].num << "  -  ";

			// print description
			cout << hTable[count].desc << endl;

		}
	}

	cout << endl;
}

/**************************************************************
Function: insert

Parameters: a reference to an Entry

Returns: none

Notes: used to print the contents of all the active records in
the hash table in asceding order with the key of the records
***************************************************************/
void HT::pTable_print()
{
	// sort table
	unsigned int i, j;
	Entry* temp;

	for (i = 0; i < psize; i++)
	{
		temp = pTable[i];

		for (j = i; (j > 0) && (pTable[j-1]->key > temp->key); j--)
			pTable[j] = pTable[j-1];

		pTable[j] = temp;
	}

	// print table
	for (unsigned count = 0; count < psize; count++)
	{
		cout << "   ";

		// print key
		cout << pTable[count]->key << "  -";

		// print number
		cout << setw(6) << pTable[count]->num << "  -  ";

		// print description
		cout << pTable[count]->desc << endl;
	}

	cout << endl;
}
