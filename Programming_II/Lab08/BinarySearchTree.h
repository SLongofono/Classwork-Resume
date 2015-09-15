/**
*	@file : BinarySearchTree.h
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class is a template for a binary search tree.  It's methods allow for recursive calls from an upstream driver class, without having to see the private members.
*
*	Idea: have key nodes every 10ish levels with a recursive method that gives a straight shot to it 
*		from root (a recursive method with array length as its base case, array filled with left/right
*		indicators from the root node.  The key nodes have their own class, and a findLeaf method, 
*		which goes left and counts each node it touches  The main root will be a key node, and use the
*		findleaf method to determine when to place keys.
*
*
*/

#ifndef BTREE
#define BTREE
#include "BSTI.h"
#include <iostream>


template<typename T>
class BinarySearchTree: public BSTI<T>{

	public:

/* Constructor
* @pre -  none
* @ post - instantiates a binary search tree and binds the type
* @ return - void
*/
		BinarySearchTree();//done


/* Copy Constructor - This method is used to create a deep copy of a Binary search tree.  It calls the copy constructor of the Node<T> class with the m_root Node of other
* @pre -  other is a valid binary search tree
* @ post - calls the copy constructor of the Node class with other.m_root
* @ return - void
*/
		BinarySearchTree(const BinarySearchTree<T>& other);//done

/* Deconstructor
* @pre -  a valid binary search tree exists
* @ post - calls the deleteTree method, which recursively deletes all the Nodes within the binary search tree passed
* @ return - void
*/
		~BinarySearchTree();

/* This method is in place to allow a deep copy to be made from main.  The interface class will not allow recursive calls (not instantiated), so it includes this method.
* @pre -  none
* @ post - calls the copy constructor of the binary search tree class
* @ return - void
*/
		BSTI<T>* clone();
		
/* This method checks to see if a tree has any nodes in it.
* @pre -  a properly instantiated binary search tree exists.
* @ post - checks to see if the m_root member is nullptr
* @ return - true if m_root = nullptr, false otherwise
*/
		bool isEmpty() const;//done

/* This method is in place to add values from main.
* @pre -  a valid binary search tree exists
* @ post - checks to see if m_root is nullptr.  If not, it calls the recursive add method, passing in m_root as the Node<T>* argument
* @ return - false if m_root = nullptr or if the other add method returns false.  True otherwise.
*/
		bool add(T value);//done

/* This method is in place to print values from main.
* @pre -  a valid binary search tree exists
* @ post - calls the recursive printTree method with the Order value passed in
* @ return - void
*/
		void printTree(Order order) const;

/* This method is redundant
* @pre -  a valid binary search tree exists
* @ post - calls the recursive printTree method with Order set to IN_ORDER
* @ return - void
*/
		void sortedPrint() const;

/* This method is in place to search for values from main
* @pre -  a valid binary search tree exists
* @ post - calls the recursive search method with m_root as an argument
* @ return - The value searched for, or throws an exception
*/
		T search(T value)const throw (ValueNotFoundException);
		


	private:

/* This method recursively checks the entire tree for the value passed.
* @pre -  a valid binary search tree exists.
* @ post - if the node passed is nullptr, creates a new node with the value passed. If the value passed is greater than or equal to the value 
*	 of the node passed, calls itself with the node argument's right node. Otherwise, calls itself with the node argument's left node
* @ return - true if the value was successfully added.  The way I wrote it, there will be no false returns.
*/
		bool add(T value, Node<T>* subTree);//done

/* This method is called by the deconstructor to systematically delete all of the nodes in a binary search tree.  
* @pre -  a valid binary search tree exists
* @ post - follows a post_order style visit of the entire tree through recursive calls.  If the node passed has null values for its left and right pointers, the node is deleted and it returns
* @ return - void
*/
		void deleteTree(Node<T>* subTree);//done

/* This method is used to recursively search a binary search tree for the value passed.
* @pre -  a valid binary search tree exists
* @ post - checks the value passed agains the value of the node passed.  If the value in the node is less than the value passed, a recursive call is made on the node's right subtree.
*	 If the value in the node is greater than the value passed, a recursive call is made on the node's left subtree.  The specifications require an exception to be thrown if the
*	 value isn't found, so there are some crazy nested try/catch blocks in place.
* @ return - The value searched if the tree contains a node with the value, otherwise throws an exception
*/
		T search(T value, Node<T>* subtree) const throw(ValueNotFoundException);

/* This method prints the values at every node in the tree, following the ordering convention passed in.
* @pre -  a valid binary search tree exists
* @ post - The method either prints the current node's value, makes a recursive call on the node's left subtree, or makes a recursive call on the node's right subtree.  The order 
*	 dictates the order.  Pre - the value is printed before the recursive call.  In - the value is printed between calls on the left and right subtrees.  Post - the value is printed
*	 after the calls to the left and right subtrees.
* @ return - void
*/
		void printTree(Node<T>* subtree, Order order) const;

//this is here to anchor the recursive methods to an overall root.  it is used as the initial Node argument in all of the recursive methods.
		Node<T>* m_root;

};

#include "BinarySearchTree.hpp"
#endif
