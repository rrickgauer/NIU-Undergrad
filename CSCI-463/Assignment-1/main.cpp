/****************************************************************
 
 Name: Ryan Rickgauer
 
 z-ID: z1729300
 
 Assignment: 1
 
 Due Date: 9/24/2019
 
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

class Binary {
    
private:
    string v1;          // v1
    string v2;          // v2
    string sum;         // sum
    string diff;        // difference
    string v1Parity;    // v1 parity
    string v2Parity;    // v2 parity
    string sumParity;   // sum parity
    string diffParity;  // difference parity
    bool addSO;         // was signed overflow from addition detected
    bool addUO;         // was unsigned overflow from addition
    bool addZero;       // is sum zero
    bool diffSO;        // was signed overflow from subtraction detected
    bool diffUO;        // was unsigned overflow from subtraction detected
    bool diffZero;      // is difference zero
    
    
public:
    Binary(string newV1, string newV2);
    void calculateSum();
    void calculateDifference();
    char add(char bit1, char bit2, char& carry);
    bool isZero(string s);
    string parity(string s);
    string onesCompliment(string s);
    void print();
    
};

// constructor
Binary::Binary(string newV1, string newV2)
{
    
    v1 = newV1; // set v1 to the newV1
    v2 = newV2; // set v2 to the new v2
    
    // calculate sum and overflows
    calculateSum();
    
    // determine if sum is zero
    if (isZero(sum))
        addZero = true;
    else
        addZero = false;
    
    // calculate difference and overflows
    calculateDifference();
    
    // determine if difference is zero
    if (isZero(diff))
        diffZero = true;
    else
        diffZero = false;
    
    // determine paritys for v1, v2, sum, and difference
    v1Parity = parity(v1);
    v2Parity = parity(v2);
    sumParity = parity(sum);
    diffParity = parity(diff);
}

// calculates the sum bewteen v1 and v2
// determines if signed overflow occured
// deteremines if unsigned overlfow occured
void Binary::calculateSum()
{
    char tempSum[v1.length()];
    char carry = '0';
    char carryIn = '0';
    
    // calculate the sum
    for (int count = (int)v1.length() - 1; count >= 0; count--) {
        
        carryIn = carry;
        
        char bit1 = v1[count];
        char bit2 = v2[count];
        char bitSum = add(bit1, bit2, carry);
        
        tempSum[count] = bitSum;
    }
    
    sum = tempSum;  // set the sum
    
    
    // check for signed overflow
    if (carryIn != carry)
        addSO = true;
    else
        addSO = false;
    
    // check for unsigned overflow
    if (carry != '0')
        addUO = true;
    else
        addUO = false;
}

// calculates the difference bewteen v1 and v2
// determines if signed overflow occured
// deteremines if unsigned overlfow occured
void Binary::calculateDifference()
{
    char tempDifference[v1.length()];
    string v2Compliment = onesCompliment(v2);   // get ones compliment of v2
    
    char carry = '1';   // start carry at 1 to get 2s compliment
    char carryIn = carry;
    
    for (int count = (int)v1.length() - 1; count >= 0; count--) {
        
        carryIn = carry;
        
        char bit1 = v1[count];
        char bit2 = v2Compliment[count];
        
        char bitSum = add(bit1, bit2, carry);
        
        tempDifference[count] = bitSum;
        
    }
    
    diff = tempDifference;  // set the difference
    
    // determine if signed overflow occured
    if (carryIn != carry)
        diffSO = true;
    else
        diffSO = false;
    
    // determine if unsigned overflow occured
    if (carry == '0')
        diffUO = true;
    else
        diffUO = false;
    


}


// returns the sum of 2 bits and the carry in
char Binary::add(char bit1, char bit2, char &carry)
{
    int numOnes = 0;
    
    // calculate how many ones there are
    if (bit1 == '1')
        numOnes++;
    if (bit2 == '1')
        numOnes++;
    if (carry == '1')
        numOnes++;
    
    char result;
    
    // decide what the result and carryout is
    switch (numOnes) {
        case 0:
            result = '0';
            carry = '0';
            break;
        case 1:
            result = '1';
            carry = '0';
            break;
        case 2:
            result = '0';
            carry = '1';
            break;
        default:
            result = '1';
            carry = '1';
            break;
    }
    return result;
}

// determines if a number is zero
bool Binary::isZero(string s)
{
    for (char bit : s)
        if (bit != '0')
            return false;
    
    return true;
}

// returns the parity of a binary number
string Binary::parity(string s)
{
    // count up how many one bits
    int numOnes = 0;
    for (char bit : s)
        if (bit == '1')
            numOnes++;
    
    // return if even or odd number of one bits
    if (numOnes % 2 == 0)
        return "even";
    else
        return "odd";
}

// returns the 1s compliment of a binary number
string Binary::onesCompliment(string s)
{
    string result = "";
    
    for (int count = (int)s.length() - 1; count >= 0; count--) {
        
        if (s[count] == '0')
            result = '1' + result;
        else
            result = '0' + result;
    }
    
    return result;
}

// prints the data
void Binary::print()
{
    // v1 line
    cout << setw(5) << left << "v1   " << setw(10) << left << v1Parity << setw(5) << left << v1 << endl;
    
    // v2 line
    cout << setw(5) << left << "v2   " << setw(10) << left << v2Parity << setw(5) << left << v2 << endl;
    
    // sum line
    cout << left << setw(5) <<  "sum"  << setw(5) << left << sumParity;
    if (addSO == true)
        cout << "S";
    else
        cout << " ";
    if (addUO == true)
        cout << "U";
    else
        cout << " ";
    if (addZero == true)
        cout << "Z ";
    else
        cout << "  ";
    cout << " " << sum << endl;
    
    
    
    
    
    // differnce line
    cout  << left << setw(5) << "diff" << left << setw(5) << diffParity;
    if (diffSO == true)
        cout << "S";
    else
        cout << " ";
    if (diffUO == true)
        cout << "U";
    else
        cout << " ";
    if (diffZero == true)
        cout << "Z ";
    else
        cout << "  ";
    cout << " " << diff << endl;
    

}


int main(int argc, const char * argv[]) {
    
    
    Binary b1 = Binary("0111", "0001");
    b1.print();
    cout << endl;
    
    Binary b2 = Binary("101101001010111011001101110101011110111011101011100111101111111", "100010000010101100010011011101010101101110110010111001001011011");
    b2.print();
    cout << endl;
    
    Binary b3 = Binary("0010001000001010110001001101110101010110111011001011100100101101", "0100010000010101100010011011101010101101110110010111001001011010");
    b3.print();
    cout << endl;
    
    Binary b4 = Binary("10000", "10000");
    b4.print();
    cout << endl;
    
    Binary b5 = Binary("00", "11");
    b5.print();
    cout << endl;

}


