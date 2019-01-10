/***************************************************************
 CSCI 240         Program 7           Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 11/3/17
 
 Purpose: This program will will process two sets of random
 numeric information and will be stored in arrays that will be
 displayed, sorted, and displayed (again).
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number
using namespace std;

const double SMALLEST_DOUBLE = 0.0; //lower bound
const double LARGEST_DOUBLE = 100.0; //upper bound
const int MIN = 2;
const int MAX = 50;
const int DISPLAY_MAX = 10;

//function prototypes
double randDouble();
int buildArray(double []);
void printArray(double [], int, string);
void sortArray(double [], int);


void countValues(double [], int); //extra credit 2 function prototype


int main(int argc, const char * argv[]) {
    
    srand(7);
    
    cout << "EXTRA CREDIT 2 ATTEPMPTED!!" << endl << endl;
    
    double array1[50];
    int size, size1, size2;
    string title;
    
    
//First Array
    size = buildArray(array1);
    size1 = size;  //extra credit2
    title = "first array.";
    
    //displays original array1
    printArray(array1, size, title);
    
    //displays sorted array1
    sortArray(array1, size);
    
    
    cout << endl << endl << endl << endl;
    
//Second Array
    double array2[50];
    size = buildArray(array2);
    size2 = size; //extra credit 2
    title = "second array.";
    
    printArray(array2, size, title); //displays original array1
    sortArray(array2, size); //displays sorted array1


 
    cout << endl << endl << endl << endl;
    

    
//extra credit 2
    
    cout << "Extra credit 2 Output" << endl << endl;
    
    //Displays array 1 range of values
    cout << "Array 1" << endl;
    countValues(array1, size1);
    
    //Displays array 2 range of values
    cout << "Array 2" << endl;
    countValues(array2, size2);
    
    //This next portion creates a third array that will include all values from array1 and array2
    int totalSize = size1 + size2;
    double mergedArray[totalSize];
    
    int count, place;
 
    for (count = 0; count < size1; count++)
        mergedArray[count] = array1[count];
    
    place = 0;
    for (count = size1; count < totalSize; count++)
    {
        mergedArray[count] = array2[place];
        place++;
    }
    
    //displays merged array
    cout << "Merged Array" << endl;
    countValues(mergedArray, totalSize);
    
    cout << endl << endl << endl;
    
    
}


/***************************************************************
 Function: double randDouble()
 
 Use: This function will generate a random double value that is
 within a specific range.
 
 Arguments: none
 
 Returns: a double value of a number between 0 and 100
 ***************************************************************/
double randDouble()
{
    //generates a double between 0-100
    double num = SMALLEST_DOUBLE + (rand() / (RAND_MAX / (LARGEST_DOUBLE - SMALLEST_DOUBLE)));
    return num;
}

/***************************************************************
 Function: int buildArray(double array[])
 
 Use: This function will fill an array of doubles with a random
 number of random values.
 
 Arguments: an array of doubles
 
 Returns: the number of values that were placed in the array
 ***************************************************************/
int buildArray(double array[])
{
    int arraySize, count;
    arraySize = MIN + (rand() % (MAX - MIN + 1)); //generates a random number between 2-50
    
    //assigns a random number between 1-100 to the random sized array
    for (count = 0; count < arraySize; count++)
        array[count] = randDouble();
    
    return arraySize;
}

/***************************************************************
 Function: void printArray(double array[], int size, string title)
 
 Use: This function will display the numeric information in an
 array of doubles
 
 Arguments: This function takes three arguments: the first
 argument is an array of doubles that holds the numbers to be
 displayed, the second argument is an integer that holds the
 number of values to be displayed, and the third argument is a
 string that holds a title that should be displayed before
 displaying the numeric information.
 
 Returns: nothing
 ***************************************************************/
void printArray(double array[], int size, string title)
{
    int count;
    
    //Displays unsorted values in the array
    cout << "There are " << size << " values in the " << title << endl << endl;
    
    cout << "Unsorted Random Numbers" << endl;
    for (count = 0; count < 60; count++)
        cout << "-";
    
    //for loop puts a line break after every 10 values displayed
    for (count = 0; count < size; count++)
    {
        if (count % DISPLAY_MAX == 0)
            cout << endl;
        
        cout << fixed << setprecision(1) << setw(6) << array[count];
    }
    
   cout << endl << endl;
}

/***************************************************************
 Function: void sortArray(double array[], int size)
 
 Use: This function will use the selection sort algorithm to
 sort the array in ascending order.
 
 Arguments: This function takes two arguments: the first
 argument is an array of doubles that holds the numbers to be
 sorted, and the second argument is an integer that holds the
 number of values to be sorted.
 
 Returns: nothing
 ***************************************************************/
void sortArray(double array[], int size)
{
    int count, place = 1;
    double temp;
    
    //selection sort algorithm to put array in ascending order
    for (count = 0; count < size; count++)
    {
        for (place = 0; place < size; place++)
        {
            if (array[count] < array[place])
            {
                temp = array[count];
                array[count] = array[place];
                array[place] = temp;
            }
        }
    }
    
    //Displays results
    cout << "Sorted Random Numbers" << endl;
    for (count = 0; count < 60; count++)
        cout << "-";
    
    //for loop puts a line break after every 10 values displayed
    for (count = 0; count < size; count++)
    {
        if (count % DISPLAY_MAX == 0)
            cout << endl;
        
        cout << fixed << setprecision(1) << setw(6) << array[count];
    }
  
    
}

//Extra credit 2
/***************************************************************
 Function: void countValues(double array[], int size)
 
 Use: This function will count and display the number of values
 in an array of double values that fall within specific ranges.
 
 Arguments: This function takes two arguments: the first
 argument is an array of doubles that holds a set of values to
 be processed, and the second argument is an integer that holds
 the number of values in the array to be processeded.
 
 Returns: nothing
 ***************************************************************/
void countValues(double array[], int size)
{
    
    int _10 = 0, _20 = 0, _30 = 0, _40 = 0, _50 = 0, _60 = 0, _70 = 0, _80 = 0, _90 = 0, _100 = 0;

    int count;
    
    
    //for loop tests every  value in the array to see which range of number it falls under
    //then it stores how many of each range of numbers were in the array
    for (count = 0; count < size; count++)
    {
        if (array[count] > 0.0 && array[count] <= 9.9)
            _10++;
        else if (array[count] >= 10.0 && array[count] <= 19.9)
            _20++;
        else if (array[count] >= 20.0 && array[count] <= 29.9)
            _30++;
        else if (array[count] >= 30.0 && array[count] <= 39.9)
            _40++;
        else if (array[count] >= 40.0 && array[count] <= 49.9)
            _50++;
        else if (array[count] >= 50.0 && array[count] <= 59.9)
            _60++;
        else if (array[count] >= 60.0 && array[count] <= 69.9)
            _70++;
        else if (array[count] >= 70.0 && array[count] <= 79.9)
            _80++;
        else if (array[count] >= 80.0 && array[count] <= 89.9)
            _90++;
        else if (array[count] >= 90.0 && array[count] <= 99.9)
            _100++;
    }
    
    
    //Displays results
    cout << "---------------------------" << endl;
    cout << "There were " << size << " total values" << endl << endl;
    
    cout << setw(10) << "0 - 10:" << setw(6) << _10 << endl;
    cout << setw(10) << "10 - 20:" << setw(6) << _20 << endl;
    cout << setw(10) << "20 - 30:" << setw(6) << _30 << endl;
    cout << setw(10) << "30 - 40:" << setw(6) << _40 << endl;
    cout << setw(10) << "40 - 50:" << setw(6) << _50 << endl;
    cout << setw(10) << "50 - 60:" << setw(6) << _60 << endl;
    cout << setw(10) << "60 - 70:" << setw(6) << _70 << endl;
    cout << setw(10) << "70 - 80:" << setw(6) << _80 << endl;
    cout << setw(10) << "80 - 90:" << setw(6) << _90 << endl;
    cout << setw(10) << "90 - 100:" << setw(6) << _100 << endl;
    
    cout << endl << endl << endl;
}
