#ifndef H_NODE
#define H_NODE

// definition for class of nodes in bin tree

template<class T>
class binTree;    // forward declaration

template <class T>
class Node
{
    friend class binTree<T>;         // binTree is friend

public:
    
    // default constructor
    Node (const T& x = T(), Node<T>* l = 0, Node<T>* r = 0) : data(x), left(l), right(r) {}
    
private:
    T data;                         // data component
    Node<T> *left, *right;          // left and right links
};

#endif

