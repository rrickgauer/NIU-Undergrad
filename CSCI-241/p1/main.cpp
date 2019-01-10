/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Ryan Rickgauer
   LOGON ID:   z-1729300
   DUE DATE:   2/1/2018
 
   FUNCTION:   This program tests functions for manipulating C 
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//Function Prototypes

bool equals(const char* str1, const char* str2); //function 1
bool equalsIgnoreCase(const char* str1, const char* str2); //function2
int indexOf(const char* str, char ch); //function 3
int lastIndexOf(const char* str, char ch); //function 4
bool startsWith(const char* str, const char* prefix); //function 5
bool endsWith(const char* str, const char* suffix); //function 6


int main()
   {
   int index;
   
   // Tests 1a - 1d: Test the equals() function
   //function 1 test
   cout << "Test 1a: ";
   if (equals("catapult", "catapult"))
      cout << "correct\n";
   else
      cout << "incorrect\n";
      
   cout << "Test 1b: ";
   if (!equals("catapult", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1c: ";
   if (!equals("cat", "catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 1d: ";
   if (!equals("catapult", "cat"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;


   // Tests 2a - 2d: Test the equalsIgnoreCase() function
   cout << "Test 2a: ";
   if (equalsIgnoreCase("catapult", "CATAPULT"))
      cout << "correct\n";
   else
      cout << "incorrect\n";
      
   cout << "Test 2b: ";
   if (!equalsIgnoreCase("catapult", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2c: ";
   if (!equalsIgnoreCase("Cat", "Catamaran"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 2d: ";
   if (!equalsIgnoreCase("Catapult", "Cat"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;
 
   
   // Tests 3a - 3d: Test the indexOf() function
   cout << "Test 3a: ";
   index = indexOf("adamant", 'a');
   if (index == 0)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 0\n";

   cout << "Test 3b: ";
   index = indexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 3c: ";
   index = indexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 3d: ";
   index = indexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;
   

   // Tests 4a - 4d: Test the lastIndexOf() function
   cout << "Test 4a: ";
   index = lastIndexOf("adamant", 't');
   if (index == 6)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 6\n";

   cout << "Test 4b: ";
   index = lastIndexOf("adamant", 'm');
   if (index == 3)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 3\n";

   cout << "Test 4c: ";
   index = lastIndexOf("adamant", 'a');
   if (index == 4)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not 4\n";

   cout << "Test 4d: ";
   index = lastIndexOf("adamant", 'x');
   if (index == -1)
      cout << "correct\n";
   else
      cout << "incorrect - index returned was " << index << ", not -1\n";

   cout << endl;
   
   
   
   
   //function 5
   

   // Tests 5a - 5c: Test the startsWith() function
   cout << "Test 5a: ";
   if (startsWith("your house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";
      
   cout << "Test 5b: ";
   if (!startsWith("my house", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 5c: ";
   if (!startsWith("you", "your"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << endl;
   
   
   
   
   
   
   
   
   // function 6

   // Tests 6a - 6c: Test the endsWith() function
   cout << "Test 6a: ";
   if (endsWith("your house", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";
      
   cout << "Test 6b: ";
   if (!endsWith("your mouse", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";

   cout << "Test 6c: ";
   if (!endsWith("use", "house"))
      cout << "correct\n";
   else
      cout << "incorrect\n";
      
   return 0;
   
   }

//function 1
bool equals(const char* str1, const char* str2)
{
	bool equal;
	
	if (strcmp(str1, str2) == 0)
		equal = true;
	else
		equal = false;
		
	return equal;
}

//function2
bool equalsIgnoreCase(const char* str1, const char* str2)
{
	bool equal;
	
	int size1 = strlen(str1); //assigns size of str1 to size1
	int size2 = strlen(str2); //assigns size of str2 to size2
	
	//creates 2 char arrays the same sizes as str1 and str2
	char temp1[size1]; 
	char temp2[size2];
	
	strcpy(temp1, str1);
	strcpy(temp2, str2);
	
	int count;
	
	//assigns all lower case char from str1 to temp1
	for (count = 0; count < size1; count++)
	{
		temp1[count] = tolower(temp1[count]);
	}
	
	//assigns all lower case char from str2 to temp2
	for (count = 0; count < size2; count++)
	{
		temp2[count] = tolower(temp2[count]);
	}
	
	//if the 2 strings are equal regardless of whether their characters are upper or lower case then return true, otherwise return false
	if (strcmp(temp1, temp2) == 0)
		equal = true;
	else
		equal = false;
	
	return equal;
	
	
	
	
	
	
	
	
	
	
}


//function 3
int indexOf(const char* str, char ch)
{
	int index = -1;	
	int size = strlen(str);
	int count;
	
	for (count = 0; count < size; count++)
	{
		if (str[count] == ch && index == -1)
			index = count;
	}
	
	return index;
}


//function 4
int lastIndexOf(const char* str, char ch)
{
	int index = -1;
	int size = strlen(str);
	
	int count;
	
	for (count = 0; count < size; count++)
	{
		if ((str[count] == ch) && (count > index))
			index = count;
	}
	
	return index;
}

//function 5
bool startsWith(const char* str, const char* prefix)
{
	bool starts;
	
	int prefixSize = strlen(prefix);
	
	if (strncmp(str, prefix, prefixSize) == 0)
		starts = true;
	else
		starts = false;
	
	return starts;
}


//function 6
bool endsWith(const char* str, const char* suffix)
{
	bool ends;
	
	int suffixSize = strlen(suffix);
	int size = strlen(str);
	
	int place = size - suffixSize;
	
	int testCount = 0;
	int count;
	
	for (count = 0; count < suffixSize; count++)
	{
		if (suffix[count] == str[place])
			testCount++;
		
		place++;
	}
	
	if (testCount == suffixSize)
		ends = true;
	else
		ends = false;
	
	return ends;
		
}
