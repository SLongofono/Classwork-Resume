/**
*	@file : BSTI.h
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class is an interface for a general binary search tree.  It includes the clone method to facilitate deep copies(copy constructor defined in the implementation class).
*/

#ifndef BST_I
#define BST_I
#include "ValueNotFoundException.h"
#include "Node.h"

enum Order{PRE_ORDER, IN_ORDER, POST_ORDER};

template<typename T>
class BSTI{

	public:

/* Constructor
* @pre -  none
* @ post - virtual
* @ return - void
*/
	virtual ~ BSTI(){};//not pure virtual so we can redefine a deconstructor when necessary

/* This method is in place to enforce a method for a copy constructor.  The clone method should call a recursive copy constructor.
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - a pointer of the binary search tree interface type
*/
	virtual BSTI<T>* clone() = 0;//this IS the deep copy constructor, it will call the copy constructor 

/* This method should check the conditions for which a binary search tree is considered empty (m_root = nullptr)
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - true if empty, false otherwise
*/
	virtual bool isEmpty() const = 0;

/* This method should call a recursive method using the value passed and the child class's m_root member
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - true if the value was added, false otherwise
*/
	virtual bool add(T value) = 0;

/* This method should call a recursive search method using the value passed and the child class's m_root member
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - the value found, otherwise throw an exception
*/
	virtual T search(T value) const throw (ValueNotFoundException) = 0;

/* This method should call a recursive print function using the enum passed and the child class's m_root member
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - void
*/
	virtual void printTree(Order order) const = 0;

/* This method should call a recursive print function using the IN_ORDER enumeration and the child class's m_root member
* @pre -  the caller is a valid child class
* @ post - virtual
* @ return - void
*/
	virtual void sortedPrint() const = 0;
	
};

#endif
