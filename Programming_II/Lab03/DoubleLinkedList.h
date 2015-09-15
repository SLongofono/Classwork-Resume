/*	Name: Stephen Longofono - 2776831
*	File name: DoubleLinked.h
*	Date: 02-11-2015
*	Description: This class is a double-linked list of nodes.  It is critical that the private members 
*	remain accurate or most of the methods will break down.  The nodes can all hold different types of values
*	but are committed at runtime to that type.  To change a node's type, you must remove it and insert a new
*	node of the desired type.
*/

#ifndef DOUBLE_H
#define DOUBLE_H
#include "Node.h"

template<class T>

class DoubleLinkedList{

	public:

/*
* This is the constructor
* @pre - none
* @post - Creates a DoubleLinkedList object.  Initializes the front and back pointers to 0.  Initializes the size
*	to 0.  Does not creat nodes or commit types. 
* @return - none
*/ 
		DoubleLinkedList();


/*
* This is the Deconstructor
* @pre - A DoubleLinkedList exists with accurate member variables
* @post - steps through the list and deletes each Node, then sets pointers to nullptr.  Housekeeping.
* @return - none
*/ 
		~DoubleLinkedList();
		
		
/*
* This is a getter of sorts to check if there are nodes in the list
* @pre - A DoubleLinkedList exists with accurate values for m_size
* @post - retrieves the value of m_size and compares it to zero
* @return - true if the size is zero (empty list), false otherwise
*/ 		
		bool isEmpty() const;

/*
* This is a getter for the number of nodes in the list
* @pre - A DoubleLinkedList exists with accurate values for m_size
* @post - retrieves the value of m_size
* @return - the value of the int m_size
*/ 
		int size() const;


/*
* This is a getter for that finds the value passed.  This is a dumb search, that is, it returns the first node
* that matches the parameter and then stops looking.
* @pre - A DoubleLinkedList exists with accurate values.  Assumes the list/node type can be compared with '=='
* @post - Traverses the list and compares the parameter passed with the m_value.
* @return - if the list is empty or does not contain the value, returns nullptr.  Otherwise, returns a pointer
*	 to the first Node from the front with a matching value.
*/ 
		Node<T>* find(T value)const;


/*
* This method finds the first node with a m_value that matches the value passed and removes it from the list.
* @pre - A DoubleLinkedList exists with accurate values.
* @post - Calls the find method and uses the pointer returned to remove the node from the list.
* @return - if the list is empty or does not contain the value, a runtime exception is thrown.  If the list is empty,
*	 returns false.  Otherwise, returns true.
*/ 
		bool remove(T value) throw(std::runtime_error);


/*
* This adds a node to the front of the list and sets its value
* @pre - A DoubleLinkedList exists with accurate members
* @post - creates a node object, sets its value to the parameter passed, and places it at the front of the list
*	 This is achieved by setting the m_front node's previous pointer to the new node, and the new node's
*	 m_next pointer to the old front node.  If the list is empty, creates a node, sets its value, and sets
*	 m_front/m_back to point to the new node.
* @return - void
*/ 
		void pushFront(T value);


/*
* This method inserts a new node before the first node in the list with a m_value that matches listvalue.
* @pre - A DoubleLinkedList exists with accurate members.  Assumes a node with listValue exists.  Note that
* 	this method is set to throw a runtime exception if find() returns nullptr.
* @post - Traverses the list with the find method to locate the first node from the front whose m_value equals
*	 listValue.  Then, it creates a new node and places it in front of the found node.  Pointers shuffle
*	 appropriately.
* @return - void, or runtime error if listValue was not found/does not exits.
*/ 
		void insertAhead(T listValue, T newValue) throw(std::runtime_error);


/*
* This method inserts a new node after the first node in the list with a m_value that matches listvalue.
* @pre - A DoubleLinkedList exists with accurate members.  Assumes a node with listValue exists.  Note that
* 	this method is set to throw a runtime exception if find() returns nullptr.
* @post - Traverses the list with the find method to locate the first node from the front whose m_value equals
*	 listValue.  Then, it creates a new node and places it behind the found node.  Pointers shuffle
*	 appropriately.
* @return - void, or runtime error if listValue was not found/does not exits.
*/ 
		void insertBehind(T listValue, T newValue) throw(std::runtime_error);


/*
* This adds a node to the back of the list and sets its value
* @pre - A DoubleLinkedList exists with accurate members
* @post - creates a node object, sets its value to the parameter passed, and places it at the rear of the list
*	 This is achieved by setting the new node's previous pointer to the old rear node, and the old node's
*	 m_next pointer to the new node.  If the list is empty, creates a node, sets its value, and sets
*	 m_front/m_back to point to the new node.
* @return - void
*/ 
		void pushBack(T value);

/*
* This is a getter of sorts that traverses the list and prints all the m_values in its nodes
* @pre - A DoubleLinkedList exists with accurate member values.  Assumes the type is printable via cout<<
* @post - Starts at m_front and prints the value, then steps through the list until m_next of the current
*	 node is nullptr.  If the list is empty, it says so.
* @return - the values of each node followed by a space, then a newline
*/ 
		void printList() const;



	private:
		Node<T>* m_front;	//leading node
		Node<T>* m_back;	//rear node
		int m_size;		//number of nodes in the list (may be zero)

};
#include "DoubleLinkedList.hpp"
#endif
