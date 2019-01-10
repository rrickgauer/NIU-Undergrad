/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 7
 PROGRAMMER: Ryan Rickgauer
 LOGON ID:   z-1729300
 DUE DATE:   4/19/2018
 
 FUNCTION:   This program tests the functionality of the Queue
 template class.
 *********************************************************************/

#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cout;
using std::endl;
using std::underflow_error;

int main()
{
    cout << "Testing default constructor\n\n";
    
    Queue<int> q1;
    
    cout << "q1 (size " << q1.size() << "): " << q1 << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing push()\n\n";
    
    q1.push(17);
    
    cout << "q1 (size " << q1.size() << "): " << q1 << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    q1.push(2);
    q1.push(6);
    q1.push(4);
    
    cout << "q1 (size " << q1.size() << "): " << q1 << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing copy constructor\n\n";
    Queue<int> q2(q1);
    
    cout << "q1 (size " << q1.size() << "): " << q1 << endl;
    cout << "q2 (size " << q2.size() << "): " << q2 << endl << endl;
    
    cout << "Testing clear()\n\n";
    q1.clear();
    
    cout << "q1 (size " << q1.size() << "): " << q1 << endl;
    cout << "q2 (size " << q2.size() << "): " << q2 << endl << endl;
    
    Queue<int> q3;
    
    q3.push(36);
    q3.push(41);
    q3.push(75);
    q3.push(28);
    
    cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;
    
    cout << "Testing assignment operator\n\n";
    
    Queue<int> q4;
    
    q4 = q3;
    
    cout << "q3 (size " << q3.size() << "): " << q3 << endl;
    cout << "q4 (size " << q4.size() << "): " << q4 << endl << endl;
    
    
    q3.clear();
    
    cout << "q3 (size " << q3.size() << "): " << q3 << endl;
    cout << "q4 (size " << q4.size() << "): " << q4 << endl << endl;
    
    cout << "Testing assignment to self\n\n";
    
    q4 = q4;
    q3 = q4;
    q4.clear();
    
    cout << "q3 (size " << q3.size() << "): " << q3 << endl;
    cout << "q4 (size " << q4.size() << "): " << q4 << endl << endl;
    
    cout << "Testing chained assignment\n\n";
    
    Queue<int> q5;
    
    q5 = q4 = q3;
    
    cout << "q3 (size " << q3.size() << "): " << q3 << endl;
    cout << "q4 (size " << q4.size() << "): " << q4 << endl;
    cout << "q5 (size " << q5.size() << "): " << q5 << endl << endl;
    
    cout << "Testing front(), push(), pop()\n\n";
    
    Queue<char> q6, q7;
    
    for(char c = 'a'; c < 'k'; c++)
        q6.push(c);
    
    cout << "q6 (size " << q6.size() << "): " << q6 << endl << endl;
    
    for(int i = 0; i < 10; i++)
    {
        int val;
        
        val = q6.front();
        q7.push(val);
        q6.pop();
    }
    
    cout << "q6 (size " << q6.size() << "): " << q6 << endl;
    cout << "q7 (size " << q7.size() << "): " << q7 << endl << endl;
    
    cout << "Testing back()\n\n";
    
    int val1, val2;
    
    q6 = q7;
    
    val1 = q6.back();
    val2 = q7.back();
    val1 = q6.back();     // Make sure that back() doesn't remove a value.
    
    cout << ((val1 == val2) ? "back() works\n\n" : "back() failure\n\n");
    
    cout << "Testing front()\n\n";
    
    val1 = q6.front();
    val2 = q7.front();
    val1 = q6.front();    // Make sure that front() doesn't remove a value.
    
    cout << ((val1 == val2) ? "front() works\n\n" : "front() failure\n\n");
    
    cout << "Testing const correctness\n\n";
    
    q7.clear();
    const Queue<char>& r6 = q6;
    
    cout << "q6 (size " << r6.size() << "): " << r6 << endl;
    cout << "q6 is " << ((r6.empty()) ? "empty\n" : "not empty\n");
    cout << "Front item of q6: " << r6.front() << endl;
    cout << "Back item of q6: " << r6.back() << endl << endl;
    
    q7 = r6;
    Queue<char> q8(r6);
    
    cout << "q7 (size " << q7.size() << "): " << q7 << endl;
    cout << "q8 (size " << q8.size() << "): " << q8 << endl << endl;
    
    cout << "Testing exception handling\n\n";
    
    try
    {
        cout << q1.front() << endl;
    }
    catch (underflow_error e)
    {
        cout << "Exception: "<< e.what() << endl << endl;
    }
    
    try
    {
        cout << q1.back() << endl;
    }
    catch (underflow_error e)
    {
        cout << "Exception: "<< e.what() << endl << endl;
    }
    
    try
    {
        q1.pop();
    }
    catch (underflow_error e)
    {
        cout << "Exception: "<< e.what() << endl;
    }
    
    return 0;
}
