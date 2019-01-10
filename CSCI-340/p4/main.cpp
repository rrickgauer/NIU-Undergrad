/***********************************************************
 CSCI 340 - Program 4 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  October 2, 2018
 
 Purpose:   This program implements an interactive scanner to
 scan and process a stream of words of a plain text.
 ************************************************************/

#include "Program4.h"

using namespace std;

int main(int argc, const char * argv[])
{
    map<string, int> m1;
    get_words(m1);
    print_words(m1);
}

/***************************************************************
 Function: clean_entry
 
 Parameters: 1 reference to a const string, 1 reference to a
 string
 
 Returns: void
 
 Notes: It cleans a word from its punctuation marks. The first
 argument is the original word in the input stream and the
 second argument contains the same word after cleaning.
 ***************************************************************/
void clean_entry(const string& original, string& result)
{
    // get first index
    int index1 = 0;
    while (isalnum(original[index1]) == false && index1 < original.length())
        index1++;

    // get second index
    int index2 = 0;
    int count = index1;
    while (isalnum(original[count]) && index2 < original.length())
    {
        count++;
        index2++;
    }
    
    // assign the result the substring of the clean string
    result = original.substr(index1, index2);
    
    // set all characters in clean string to lower case
    int resultSize = (int)result.length();
    for (count = 0; count < resultSize; count++)
        result[count] = tolower(result[count]);
}

/***************************************************************
 Function: get_words
 
 Parameters: 1 reference to a map<string, int>
 
 Returns: void
 
 Notes: It gets a word from the input stream and removes its
 punctuation marks. Inserts clean word into map. Updates key
 frequency
 ***************************************************************/
void get_words(map<string, int>& m)
{
    string word;        // original word to be cleaned
    string cleanWord;   // resulting string from clean_entry()
    
    // place all words in standard in into clean_entry
    // then add the clean word to the map and update frequency
    while (cin >> word)
    {
        clean_entry(word, cleanWord);
        m[cleanWord]++;
    }
    
    // remove the blank entry in the map
    m.erase("");
}

/***************************************************************
 Function: print_words
 
 Parameters: 1 reference to a const map<string, int>
 
 Returns: void
 
 Notes: It prints the final list of words and their frequencies.
 It also prints the number of nonempty words and the number of
 distinct words in the input stream.
 ***************************************************************/
void print_words(const map<string, int> &newMap)
{
    int count = 0;      // line break counter
    int numInput = 0;   // word count
    int numOutput = 0;  // number of unique words
    
    // Print all pairs in map
    for (auto i = newMap.begin(); i != newMap.end(); i++)
    {
        cout << setw(ITEM_W) << left << (*i).first  << ": " << (*i).second << "\t";
        count++;
        
        // Check for 3 items printed
        // Once 3 items have been printed on a line, print line break
        if (count % NO_ITEMS == 0)
            cout << endl;
        
        // Update input and output totals
        numInput = numInput + (*i).second;
        numOutput++;
    }
    
    // Print final totals of input stream and output stream
    cout << endl << "no of words in input stream " << numInput << endl;
    cout << "no of words in output stream " << numOutput << endl;
}
