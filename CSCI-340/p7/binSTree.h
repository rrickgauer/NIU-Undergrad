/***********************************************************
 CSCI 340 - Program 7 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  November 8, 2018
 
 Purpose:   This program implements a binary search tree
 ************************************************************/
#ifndef binSTree_h
#define binSTree_h

// CHANGE TO LINKED PATH IN LINUX
#include "binTree.h"

template < class T >
class binSTree : public binTree <T>
{
public:
    void insert ( const T& x );
    bool search ( const T& x ) const;
    bool remove ( const T& x );
    unsigned size() const;
    
private:
    void insert ( Node < T >*&, const T& );
    bool search ( Node < T >*, const T& ) const;    // private version of search
    void remove ( Node < T >*&, const T& );         // private version of remove
    bool leaf   ( Node < T >* node ) const;         // checks if node is leaf
    unsigned size(Node<T>* node) const;
};


/***************************************************************
 Function: insert
 
 Parameters: a reference to a Node<T> pointer, reference to a
 const T
 
 Returns: void
 
 Notes: inserts a node with the data value x in the tree.
 ***************************************************************/
template <class T>
void binSTree<T>::insert(Node<T> *& root, const T &x)
{
    // insert new node
    if (root == nullptr)
    {
        root = new Node<T>(x);
        return;
    }
    
    // x is already placed in the BST
    else if (root->data == x)
        return;
    
    // insert x into left subtree
    if (x < root->data)
        insert(root->left, x);
    
    // insert x into right subtree
    else
        insert(root->right, x);
}

/***************************************************************
 Function: insert
 
 Parameters: reference to a const T
 
 Returns: void
 
 Notes: public versions of insert function
 ***************************************************************/
template <class T>
void binSTree<T>::insert(const T &x)
{
    insert(this->root, x);
}

/***************************************************************
 Function: search
 
 Parameters: pointer to a Node<T>, reference to a const T
 
 Returns: bool
 
 Notes: x is the data value of a leaf to be searched for. If the
 search is successful, the search ( ) function returns true;
 otherwise, it returns false.
 ***************************************************************/
template <class T>
bool binSTree<T>::search(Node<T>* root, const T& x) const
{
    // empty tree
    if (root == nullptr)
        return false;
    
    // check left subtree
    else if (x < root->data)
        return search(root->left, x);
    
    // check right subtree
    else if (x > root->data)
        return search(root->right, x);
    
    // check if located node is a leaf
    else
        return leaf(root);
}

/***************************************************************
 Function: search
 
 Parameters: reference to a const T
 
 Returns: bool
 
 Notes: public version of search function. calls the private version
 ***************************************************************/
template <class T>
bool binSTree<T>::search(const T& x) const
{
    return search(this->root, x);
}

/***************************************************************
 Function: leaf
 
 Parameters: pointer to Node<T>
 
 Returns: bool
 
 Notes: checks if a node is a leaf, meaning has no children
 ***************************************************************/
template <class T>
bool binSTree<T>::leaf(Node<T> *node) const
{
    // node must have no children to be a leaf
    if (node->left == nullptr && node->right == nullptr)
        return true;
    else
        return false;
}

/***************************************************************
 Function: remove
 
 Parameters: a reference to a Node<T> pointer, reference to a
 const T
 
 Returns: void
 
 Notes: removes a leaf from the BST
 ***************************************************************/
template <class T>
void binSTree<T>::remove(Node<T> *& node, const T &x)
{
    // return if tree is empty
    if (node == nullptr)
        return;
    
    // x is located on left subtree
    else if (x < node->data)
        remove(node->left, x);
    
    // x is located on right subtree
    else if (x > node->data)
        remove(node->right, x);
    
    // remove located node
    else
    {
        delete node;
        node = nullptr;
        return;
    }
}

/***************************************************************
 Function: remove
 
 Parameters: reference to a const T
 
 Returns: bool
 
 Notes: first calls the search function to determine the result
 of the search for a leaf with the data value x, and if the
 search is successful, then it calls the private version of the
 remove function to remove the corresponding leaf from the tree
 and returns true; otherwise, it returns false
 ***************************************************************/
template <class T>
bool binSTree<T>::remove(const T &x)
{
    // remove the element if it is a leaf
    if (search(x))
    {
        remove(this->root, x);
        return true;
    }
    else
        return false;
}

/**************************************************************
 Function: size
 
 Parameters: pointer to a Node<T>
 
 Returns: unsigned
 
 Notes: returns the number of nodes in the BST
 ***************************************************************/
template <class T>
unsigned binSTree<T>::size(Node<T> *node) const
{
  
    // return 0 if tree is empty
    if (node == nullptr)
        return 0;
    
    unsigned left = size(node->left);   // size of left subtree
    unsigned right = size(node->right); // size of right subtree
    return left + right + 1;            // return sum of left and rightsubtrees plus root
}

/**************************************************************
 Function: size
 
 Parameters: none
 
 Returns: unsigned
 
 Notes: public version of size, simply calls the private size
 function, passing the root of the BST to start
 ***************************************************************/
template <class T>
unsigned binSTree<T>::size() const
{
    return size(this->root);
}

#endif /* binSTree_h */
