/**
*	@file : Node.h
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class is a template of a Node for a binary search tree.  It includes a copy constructor to facilitate deep copies of the tree, and appropriate pointers for subtrees.
*/


#ifndef NODE
#define NODE
template<typename T>

class Node{

	public:

/* Constructor
* @pre - none.  ###NOTE### this method does not initialize the m_value member.
* @ post - creates a new node and sets m_left and m_right to null
* @ return - void
*/
		Node();

/* Copy Constructor - this method is called by BinarySearchtree<T>::clone to create a deep copy of the binary search tree
* @pre -  the Node
* @ post - instantiates a Node and sets its value equal to the node passed.  If the node passed has a non-null m_left, calls itself recursively with that node as an argument.  Ditto for right.
* @ return - void
*/
		Node(const Node<T>& other);

/* Getter that returns the value of the node
* @pre -  the node exists and has been assigned a value
* @ post - fetches the m_value member
* @ return - the m_value member
*/
		T getValue() const;

/* Getter for this node's left subtree pointer
* @pre -  the node exists
* @ post - fetches the m_left member
* @ return -the m_left member
*/
		Node<T>* getLeft() const;

/* Getter for this node's right subtree pointer
* @pre -  the node exists
* @ post - fetches the m_right member
* @ return -the m_right member
*/
		Node<T>* getRight() const;

/* Setter for this node's value
* @pre -  the node exists
* @ post - sets m_value to the value passed
* @ return -void
*/
		void setValue(T value);

/* Setter for this node's left node pointer
* @pre -  the node exists
* @ post - sets m_left to point to the value passed
* @ return -void
*/
		void setLeft(Node<T>* left);

/* Setter for this node's right node pointer
* @pre -  the node exists
* @ post - sets m_right to point to the value passed
* @ return -void
*/
		void setRight(Node<T>* right);

	private:

		Node<T>* m_left;
		Node<T>* m_right;
		T m_value;

};

#include "Node.hpp"
#endif

