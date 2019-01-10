/***********************************************************
 CSCI 340 - Program 7 - Fall 2018
 
 Name:      Ryan Rickgauer
 Z-ID:      z1729300
 Section:   3
 Date Due:  November 8, 2018
 
 Purpose:   This program implements a binary search tree
 ************************************************************/
#ifndef binTree_h
#define binTree_h


#include "Node.h"

using namespace std;

template<class T>
class binTree {

public:
    binTree();                                  // default constructor
    unsigned height() const;                    // returns height of tree
    virtual void insert(const T&);              // inserts node in tree
    void inorder(void(*)(T&));            // inorder traversal of tree
    
protected:
    Node <T>* root;                             // root of tree

private:
    unsigned height(Node<T>*) const;            // private version of height()
    void insert(Node<T>*&, const T&);           // private version of insert()
    void inorder(Node<T>*, void (*)(T&)); // private version of inorder()
    typedef enum { left_side, right_side } SIDE;
    SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }
};

/***************************************************************
 Function: binTree<T>::insert
 
 Parameters: 1 reference to a const T
 
 Returns: void
 
 Notes: private version of insert function
 ***************************************************************/
template<class T>
void binTree<T>::insert(const T& x)
{
    insert(root, x);
}

/***************************************************************
 Function: binTree<T>::insert
 
 Parameters: 1 reference pointer to a Node<T>, 1 reference to
 a const T
 
 Returns: void
 
 Notes: inserts a node with the data value x in a binary tree
 ***************************************************************/
template<class T>
void binTree<T>::insert(Node<T>*& n, const T& x)
{
    // if tree is empty, set the root to x
    if (n == nullptr)
    {
        n = new Node<T>(x);
        return;
    }
    
    // randomly select left or right to insert x
    if (rnd() == left_side)
        insert(n->left, x);
    else
        insert(n->right, x);
    
}

/***************************************************************
 Function: binTree<T>::height
 
 Parameters: 1 pointer to a Node<T>
 
 Returns: unsigned int
 
 Notes: returns the height of the tree
 ***************************************************************/
template<class T>
unsigned binTree<T>::height(Node<T>* n) const
{
    // check if tree is empty
    if (n == nullptr)
        return 0;

    // if tree is empty
    else
    {
        // compute the depth of each subtree
        int lDepth = height(n->left);
        int rDepth = height(n->right);
        
        // return the height of the larger side
        if (lDepth > rDepth)
            return(lDepth + 1);
        else
            return(rDepth + 1);
    }
}

/***************************************************************
 Function: binTree<T>::height
 
 Parameters: 1 pointer to a Node<T>
 
 Returns: unsigned int
 
 Notes: private version of height()
 ***************************************************************/
template<class T>
unsigned binTree<T>::height() const
{
    return height(root);
}

/***************************************************************
 Function: binTree<T>::inorder
 
 Parameters: 1 pointer to a Node<T>, a pointer to a function
 
 Returns: nothing
 
 Notes: executes an inorder binary tree traversal
 ***************************************************************/
template<class T>
void binTree<T>::inorder(Node<T>* n, void (*f)(T& x))
{
    // check if null
    if (n == nullptr)
        return;
    
    inorder(n->left, f);
    f(n->data);
    inorder(n->right, f);
}

/***************************************************************
 Function: binTree<T>::inorder
 
 Parameters: 1 pointer to a Node<T>, a pointer to a function
 
 Returns: nothing
 
 Notes: private version of inorder()
 ***************************************************************/
template <class T>
void binTree<T>::inorder(void (*p)(T &x))
{
    inorder(root, p);
}

/***************************************************************
 Function: binTree<T>::binTree
 
 Parameters: none
 
 Returns: nothing
 
 Notes: default constructor, sets the root to nullptr
 ***************************************************************/
template<class T>
binTree<T>::binTree()
{
    root = nullptr;
}

#endif /* binTree_h */
