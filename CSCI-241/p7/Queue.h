/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 7
 PROGRAMMER: Ryan Rickgauer
 LOGON ID:   z-1729300
 DUE DATE:   4/19/2018
 
 FUNCTION:   This program tests the functionality of the Queue
             template class.
 *********************************************************************/

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
    T data;                                         // Stores an item to be inserted into the queue
    Node<T>* next;                                  // Pointer to the next node in the linked list
    
    Node(const T& = T(), Node<T>* next = nullptr);  // Constructor
};

/**************************************************************
 
 FUNCTION:  Node<T>::Node(const T& newData, Node<T>* newNext)
 
 ARGUMENTS: const T& newData - reference to a to const new data member
            Node<T>* newNext - pointer to the next node
 
 RETURNS:   N/A.
 
 NOTES:     Constructor
 
 **************************************************************/
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
    data = newData;
    next = newNext;
}

// Begin Queue class

// Forward definitions of the Queue template class
template <class T>
class Queue;

// Forward definitions of the operator<< template function
template <class T>
std::ostream& operator<< (std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
    // Friend decleration for the template function
    friend std::ostream& operator<< <>(std::ostream& streamObject, const Queue<T>& rhs);
    
private:
    Node<T>* qFront;    // Pointer to front (first) node in the list
    Node<T>* qBack;     // Pointer to rear (last) node in the list
    size_t qSize;       // Number of items currently stored in queue
    
public:
    Queue();
    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T> other);
    void clear();
    size_t size() const;
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void push(const T& val);
    void pop();
    
    void copyList(const Queue<T>& other);
    
    
};

/**************************************************************
 
 FUNCTION:  Queue<T>::Queue()
 
 ARGUMENTS: None
 
 RETURNS:   N/A.
 
 NOTES:     Default Constructor.
            Set data pointer to nullptr
            Set Queue size to 0
 
***************************************************************/
template <class T>
Queue<T>::Queue()
{
    qFront = qBack = nullptr;
    qSize = 0;
}

/**************************************************************
 
 FUNCTION:   Queue<T>::~Queue()
 
 ARGUMENTS:  None
 
 RETURNS:    N/A.
 
 NOTES:      Deconstructor. Calls the clear method
 
 **************************************************************/
template <class T>
Queue<T>::~Queue()
{
    clear();
}

/**************************************************************
 
 FUNCTION:  Queue<T>::Queue(const Queue<T>& other)
 
 ARGUMENTS: other - a reference to a Que template
 
 RETURNS:   N/A.
 
 NOTES:     Copy constructor.
            Copies this list's data into other
 
 **************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
    qFront = qBack = 0; // Set qFront and qBack to 0
    qSize = 0;          // Set size to 0
    copyList(other);    // Call the copyList() method to copy data
}

/**************************************************************
 
 FUNCTION:  Queue<T>& Queue<T>::operator=(const Queue<T>& other)
 
 ARGUMENTS: other - a reference to a Que template
 
 RETURNS:   a refrence to a Queue object pointed to by this
 
 NOTES:     Copy Assignment Operator.
            Allows one Queue to be assigned to another.
 
 **************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> other)
{
    // Check if this and other have the same address
    // If they do, return *this
    // Otherise, clear this Queue, and copy the contents into other
    if (this != &other)
    {
        clear();
        copyList(other);
    }
    
    return *this;
}

/**************************************************************
 
 FUNCTION:  std::ostream& operator<<(std::ostream& streamObject, const Queue<T>& rhs)
 
 ARGUMENTS: streamObject - a reference to an output stream
            rhs - a reference to a Queue object
 
 RETURNS:   a standard output stream object
 
 NOTES:     The output operator is overloaded so that a
            Queue can be printed on the standard output.
 
 **************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& streamObject, const Queue<T>& rhs)
{
    Node<T>* ptr;   // Initialize a new node to be inserted into Queue
    
    // Loop through list, printing the data for each node
    for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
        streamObject << ptr->data << ' ';
    
    return streamObject;
}


/**************************************************************
 
 FUNCTION:  void Queue<T>::clear()
 
 ARGUMENTS: None
 
 RETURNS:   None
 
 NOTES:     Sets the queue back to the empty state.
 
 **************************************************************/
template <class T>
void Queue<T>::clear()
{
    // While the queue is not empty, call pop()
    while (empty() == false)
        pop();
}


/**************************************************************
 
 FUNCTION:  size_t Queue<T>::size() const
 
 ARGUMENTS: None
 
 RETURNS:   size_t
 
 NOTES:     Returns the queue size.
 
 **************************************************************/
template <class T>
size_t Queue<T>::size() const
{
    return qSize;
}


/**************************************************************
 
 FUNCTION:  bool Queue<T>::empty() const
 
 ARGUMENTS: None
 
 RETURNS:   a bool
 
 NOTES:     Returns true if the queue size is 0; otherwise it
            returns false.
 
 **************************************************************/
template <class T>
bool Queue<T>::empty() const
{
    // If Queue's size is 0, return true
    // Otherwise, return false
    if (qSize == 0)
        return true;
    else
        return false;
}

/**************************************************************
 
 FUNCTION:  const T& Queue<T>::front() const
 
 ARGUMENTS: None
 
 RETURNS:   a reference to a constant item of the template
            parameter type
 
 NOTES:     Returns the front element of the queue list.
 
 **************************************************************/
template <class T>
const T& Queue<T>::front() const
{
    // Check if empty, if so throw an underflow exception
    if (empty())
        throw std::underflow_error("Queue underflow on front()");
    
    // Return data in the front node
    return qFront->data;
}

/**************************************************************
 
 FUNCTION:  const T& Queue<T>::back() const
 
 ARGUMENTS: None
 
 RETURNS:   a reference to a constant item of the template
            parameter type
 
 NOTES:     Returns the back element of the queue list.
 
 **************************************************************/
template <class T>
const T& Queue<T>::back() const
{
    // Check if empty, if so throw an underflow exception
    if (empty())
        throw std::underflow_error("Queue underflow on back()");
    
    // Return data in the back node
    return qBack->data;
}


/**************************************************************
 
 FUNCTION:  void Queue<T>::push(const T& val)
 
 ARGUMENTS: val - the value to insert into the queue
 
 RETURNS:   None
 
 NOTES:     Inserts an element into rear of the queue
 
 **************************************************************/
template <class T>
void Queue<T>::push(const T& val)
{
    // Create a new node to store the data
    Node<T>* newNode = new Node<T>(val);
    
    // Check if queue is empty
    // If yes, set the front of the queue to the new node
    // Otherwise, set the back node of the queue to the new node
  
    if (empty())
        qFront = newNode;
    else
        qBack->next = newNode;
    
    qBack = newNode;      // Add 1 to the queue size
    qSize++;
}


/**************************************************************
 
 FUNCTION:  void Queue<T>::pop()
 
 ARGUMENTS: None
 
 RETURNS:   None
 
 NOTES:     Removes the front item in the queue list.
 
 **************************************************************/
template <class T>
void Queue<T>::pop()
{
    // Check if empty, if so throw an underflow exception
    if (empty())
        throw std::underflow_error("Queue underflow on pop()");
    
    // Remove first node in the list
    Node<T>* delNode = qFront;
    qFront = qFront->next;
    
    // If queue is now empty, make sure both pointers are nullptr
    if (qFront == nullptr)
        qBack = nullptr;
    
    delete delNode; // Deallocate the first node in the list
    qSize--;        // Subtract 1 from the queue size
}


/**************************************************************
 
 FUNCTION:  void Queue<T>::copyList(const Queue<T>& other)
 
 ARGUMENTS: const Queue<T>& other - a reference to a Queue to copy
 
 RETURNS:   None
 
 NOTES:     Copies the linked list from other to this object
 
 **************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
    Node<T>* ptr; // Holds a value to be pushed into the list
    
    // Copy other data into this object
    for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
        push(ptr->data);
}
#endif /* Queue_h */
