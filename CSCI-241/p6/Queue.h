/*********************************************************************
 PROGRAM:       CSCI 241 Assignment 6
 PROGRAMMER:    Ryan Rickgauer
 LOGON ID:      z-1729300
 DUE DATE:      4.10.2018
 
 FUNCTION:      This program tests the functionality of the Queue
                template class.
 *********************************************************************/
#ifndef QUE_H
#define QUE_H
#include <iostream>
#include <stdexcept>

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream& streamObj, const Queue<T>& rhs);

template <class T>
class Queue
{
    friend std::ostream& operator<< <>(std::ostream& streamObj, const Queue<T>& rhs);
    
private:
    T* qArray;          // Pointer to the first element of a dynamically allocated array
    size_t qSize;       // Number of data items currently stored in the array
    size_t qCapacity;   // Maximum number of elements that may be stored in the array
    int qFront;         // Subscript of the front item in the queue
    int qBack;          // Subscript of the back item in the queue
  
public:
    Queue();
    ~Queue();
    Queue(const Queue<T>& other);
    Queue& operator=(const Queue& other);
    void clear();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void push(const T& val);
    void pop();
    void reserve(const size_t newCapacity);
};


/**************************************************************
 
    FUNCTION:   Queue<T>::Queue()
 
    ARGUMENTS:  None
 
    RETURNS:    N/A.
 
    NOTES:      Default Constructor.
                Sets the queue size and queue capacity to 0.
                Sets queue array to null ptr.
                Sets the queue front subscript to 0.
                Sets the que back subscript to the capacity - 1.
 
 **************************************************************/
template <class T>
Queue<T>::Queue()
{
    qSize = 0;              // Set size to 0
    qCapacity = 0;          // Set capacity to 0
    qArray = nullptr;       // Set array pointer to nullptr
    qFront = 0;             // set front subscript to 0
    qBack = qCapacity - 1;  // set back subcript to capacity - 1
}

/**************************************************************
 
    FUNCTION:   Queue<T>::~Queue()
 
    ARGUMENTS:  None
 
    RETURNS:    N/A.
 
    NOTES:      Deconstructor.
                Deletes the dynamic memory for the queue array.
 
 **************************************************************/
template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}


/**************************************************************
 
    FUNCTION:   Queue<T>::Queue(const Queue<T>& other)
 
    ARGUMENTS:  other - a reference to a Que template
 
    RETURNS:    N/A.
 
    NOTES:      Copy constructor.
                Initializes a new Queue object to the same
                capacity, size, front and back subscripts, and
                array values as the existing Queue object other.
 
 **************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
    qCapacity = other.qCapacity;    // Set capacity to other's capacity
    qSize = other.qSize;            // Set size to other's size
    
    // If the capacity is greater than 0, create a new array with the same capacity as other
    // Otherwise, set the array pointer to nullptr
    if (qCapacity > 0)
        qArray = new T[qCapacity];
    else
        qArray = nullptr;
    
    // Copies each value from other into the this object
    for (size_t count = 0; count < qCapacity; count++)
        qArray[count] = other.qArray[count];
    
    qFront = other.qFront;          // Set front to other's front
    qBack = other.qBack;            // Set back to other's back
}



/**************************************************************
 
    FUNCTION:   Queue<T>& Queue<T>::operator=(const Queue<T>& other)
 
    ARGUMENTS:  other - a reference to a Que template
 
    RETURNS:    a refrence to a Queue object pointed to by this
 
    NOTES:      Copy Assignment Operator.
                Allows one Queue to be assigned to another.
 
 **************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    // Check if this and other have the same address
    // If they do, then just return this
    if (this != &other)
    {
        delete[] qArray;                // Delete the que array for the object pointed to by this
        qCapacity = other.qCapacity;    // Set the queue capacity for the object pointed to by this to the queue capacity of other
        qSize = other.qSize;            // Set the queue size for the object pointed to by this to the queue size of other
        
        // If the vector capacity is 0, set the vector array pointer for the object pointed to by this to nullptr.
        // Otherwise, use the queue array pointer to allocate an array of <T>
        if (qCapacity > 0)
            qArray = new T[qCapacity];
        else
            qArray = nullptr;
        
        // Copy the contents of the queue array of other into the queue array of the object pointed to by this
        for (size_t count = 0; count < qCapacity; count++)
            qArray[count] = other.qArray[count];
        
        qFront = other.qFront;          // Set the front subscript of this to the front subscript of other
        qBack = other.qBack;            // Set the back subscript of this to the back subscript of other
    }
    
    return *this;
}


/**************************************************************
 
    FUNCTION:   std::ostream& operator<<(std::ostream& streamObject, const Queue<T>& rhs)
 
    ARGUMENTS:  streamObject - a reference to an output stream
                rhs - a reference to a Queue object
 
    RETURNS:    a standard output stream object
 
    NOTES:      The output operator is overloaded so that a
                Queue can be printed on the standard output.
 
 **************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& streamObject, const Queue<T>& rhs)
{
    size_t current;     // counter variable
    size_t i = 0;       // counter variable

    // Loops through the queue array and inserts each element into the output stream
    for (current = rhs.qFront; i < rhs.qSize; i++)
    {
        // print queue element at subscript 1
        streamObject << rhs.qArray[current] << " ";
        
        // increment by 1, wrapping around to front of queue array if neccessary
        current = ((current + 1) % rhs.qCapacity);
    }
    
    return streamObject;
}



/**************************************************************
 
    FUNCTION:   void Queue<T>::clear()
 
    ARGUMENTS:  None
 
    RETURNS:    None
 
    NOTES:      Sets the queue back to the empty state.
 
 **************************************************************/
template <class T>
void Queue<T>::clear()
{
    qSize = 0;              // Set the queue size to 0
    qFront = 0;             // Set the queue front subscript to 0
    qBack = qCapacity - 1;  // Set the queue back subscript to the queue capacity - 1
}


/**************************************************************
 
    FUNCTION:   size_t Queue<T>::size() const
 
    ARGUMENTS:  None
 
    RETURNS:    a size_t
 
    NOTES:      Returns the queue size.
 
 **************************************************************/
template <class T>
size_t Queue<T>::size() const
{
    return qSize;
}


/**************************************************************
 
    FUNCTION:   size_t Queue<T>::capacity() const
 
    ARGUMENTS:  None
 
    RETURNS:    a size_t
 
    NOTES:      Returns the queue capacity.
 
 **************************************************************/
template <class T>
size_t Queue<T>::capacity() const
{
    return qCapacity;
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
    // If the queue size is 0, return true
    // Otherwise, return false
    if (qSize == 0)
        return true;
    else
        return false;
}

/**************************************************************
 
    FUNCTION:   const T& Queue<T>::front() const
 
    ARGUMENTS:  None
 
    RETURNS:    a reference to a constant item of the template
                parameter type
 
    NOTES:      Returns the front element of the queue array.
 
 **************************************************************/
template <class T>
const T& Queue<T>::front() const
{
    // If the queue is empty, throw an underflow_error exception.
    // Otherwise, return the front element of the queue array.
    if (empty())
        throw std::underflow_error("que underflow on call to front()");
    
    return qArray[qFront];
}


/**************************************************************
 
    FUNCTION:   const T& Queue<T>::back() const
 
    ARGUMENTS:  None
 
    RETURNS:    a reference to a constant item of the template
                parameter type
 
    NOTES:      Returns the back element of the queue array.
 
 **************************************************************/
template <class T>
const T& Queue<T>::back() const
{
    // If the queue is empty, throw an underflow_error exception.
    // Otherwise, return the back element of the queue array.
    if (empty())
        throw std::underflow_error("que underflow on call to back()");
    
    return qArray[qBack];
}


/**************************************************************
 
    FUNCTION:   void Queue<T>::push(const T& val)
 
    ARGUMENTS:  val - the value to insert into the queue
 
    RETURNS:    None
 
    NOTES:      Inserts an element into the queue
 
 **************************************************************/
template <class T>
void Queue<T>::push(const T& val)
{
    // If the queue is full call reserve() to increase the array capacity to make room for the item to insert.
    if (qSize == qCapacity)
    {
        // If the queue capacity is currently 0, pass a new capacity of 1 to the reserve() method.
        // Otherwise, pass a new capacity of twice the current queue capacity to the reserve() method.
        if (qCapacity == 0)
            reserve(1);
        else
            reserve(qCapacity * 2);
    }
    
    qBack = (qBack + 1) % qCapacity;    // Increment the queue back subscript
    qArray[qBack] = val;                // Set the back element in the array to the value passed in
    qSize++;                            // Incremenet the queue size by 1
}

/**************************************************************
 
    FUNCTION:  void Queue<T>::pop()
 
    ARGUMENTS: None
 
    RETURNS:   None
 
    NOTES:     Removes the front item in the queue array.
 
 **************************************************************/
template <class T>
void Queue<T>::pop()
{
    // If the queue is empty, throw an underflow_error exception.
    if (empty())
        throw std::underflow_error("que underflow on call to pop()");
    
    qFront = (qFront + 1) % qCapacity;  // Increment the queue front subscript to remove the front item in the queue array
    qSize--;                            // Decrement the queue size by 1
}


/**************************************************************
 
    FUNCTION:  void Queue<T>::reserve(const size_t newCapacity)
 
    ARGUMENTS: newCapacity - the new capacity to allocate for the queue array
 
    RETURNS:   None
 
    NOTES:     Changes the array capaicty to the value passed in.
 
 **************************************************************/
template <class T>
void Queue<T>::reserve(const size_t newCapacity)
{
    // If the new capacity is less than the queue size or is equal to the current queue capacity, return.
    if (newCapacity < qSize || newCapacity == qCapacity)
        return;
    else
    {
        T* tempArray = new T[newCapacity];          // Create a temporary array to hold the values of the old array
        size_t current = qFront;                    // Counter variable
        
        // Copy items from queue array into the temporary array
        for (size_t count = 0; count < qSize; count++)
        {
            tempArray[count] = qArray[current];     // Set current element in temporary array to the corresponding element in queue array
            current = (current + 1) % qCapacity;    // Increment current counter variable
        }
        
        qCapacity = newCapacity;                    // Set queue capacity to the new capacity
        qFront = 0;                                 // Set queue front subscript to 0
        qBack = qSize - 1;                          // Set queue back subscript to the queue size - 1
        delete[] qArray;                            // Dealocate memory of the queue array
        qArray = tempArray;                         // Copy over the temporary array into the updated queue array
    }
}
#endif
