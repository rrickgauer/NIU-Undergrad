/*********************************************************************
 PROGRAM:       CSCI 241 Assignment 6
 PROGRAMMER:    Ryan Rickgauer
 LOGON ID:      z-1729300
 DUE DATE:      4.10.2018
 
 FUNCTION:      This program tests the functionality of the Queue
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
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing push()\n\n";
    
    for (int i = 5; i < 40; i += 5)
        q1.push(i);
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing pop()\n\n";
    
    for (int i = 0; i < 3; ++i)
        q1.pop();
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing wrap-around on push()\n\n";
    
    for (int i = 3; i <= 12; i += 3)
        q1.push(i);
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing wrap-around on pop()\n\n";
    
    for (int i = 0; i < 6; ++i)
        q1.pop();
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing queue resize on push()\n\n";
    
    for (int i = 10; i < 140; i += 10)
        q1.push(i);
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing copy constructor()\n\n";
    
    Queue<int> q2 = q1;
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "q2: " << q2 << endl;
    cout << "q2 size: " << q2.size() << endl;
    cout << "q2 capacity: " << q2.capacity() << endl;
    cout << "q2 is " << ((q2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing front() and back()\n\n";
    
    cout << "Front item of q1: " << q1.front() << endl;
    cout << "Front item of q2: " << q2.front() << endl << endl;
    
    cout << "Back item of q1: " << q1.back() << endl;
    cout << "Back item of q2: " << q2.back() << endl << endl;
    
    cout << "q1: " << q1 << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "q2: " << q2 << endl;
    cout << "q2 size: " << q2.size() << endl;
    cout << "q2 capacity: " << q2.capacity() << endl;
    cout << "q2 is " << ((q2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing pop() to empty\n\n";
    
    while (!q1.empty())
    {
        cout << q1.front() << ' ';
        q1.pop();
    }
    
    cout << endl;
    cout << "q1 size: " << q1.size() << endl;
    cout << "q1 capacity: " << q1.capacity() << endl;
    cout << "q1 is " << ((q1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing assignment operator\n\n";
    
    Queue<int> q3;
    
    q3 = q2;
    
    cout << "q2 (size " << q2.size() << "): " << q2 << endl;
    cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;
    
    cout << "Testing clear()\n\n";
    
    q2.clear();
    
    cout << "q2 (size " << q2.size() << "): " << q2 << endl;
    cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;
    
    cout << "Testing assignment to self and swap\n\n";
    
    q3 = q3;
    q2 = q3;
    q3.clear();
    
    cout << "q2 (size " << q2.size() << "): " << q2 << endl;
    cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;
    
    cout << "Testing chained assignment\n\n";
    
    Queue<int> q4;
    
    q4 = q3 = q2;
    
    cout << "q2 (size " << q2.size() << "): " << q2 << endl;
    cout << "q3 (size " << q3.size() << "): " << q3 << endl;
    cout << "q4 (size " << q4.size() << "): " << q4 << endl << endl;
    
    cout << "Testing other data type\n\n";
    
    Queue<char> q5;
    
    for (char c = 'a'; c < 'k'; c++)
        q5.push(c);
    
    cout << "q5 (size " << q5.size() << "): " << q5 << endl << endl;
    
    cout << "Testing const correctness\n\n";
    
    const Queue<char>& r5 = q5;
    
    cout << "q5 (size " << r5.size() << "): " << r5 << endl;
    cout << "q5 is " << ((r5.empty()) ? "empty\n" : "not empty\n");
    cout << "Front item of q5: " << r5.front() << endl;
    cout << "Back item of q5: " << r5.back() << endl << endl;
    
    cout << "Testing exception handling\n\n";
    
    cout << "Testing front() with empty queue\n\n";
    
    try
    {
        cout << q1.front() << endl;
    }
    catch (underflow_error e)
    {
        cout << "Caught "<< e.what() << endl << endl;
    }
    
    cout << "Testing back() with empty queue\n\n";
    
    try
    {
        cout << q1.back() << endl;
    }
    catch (underflow_error e)
    {
        cout << "Caught "<< e.what() << endl << endl;
    }
    
    cout << "Testing pop() with empty queue\n\n";
    
    try
    {
        q1.pop();
    }
    catch (underflow_error e)
    {
        cout << "Caught "<< e.what() << endl;
    }
    
    return 0;
}
