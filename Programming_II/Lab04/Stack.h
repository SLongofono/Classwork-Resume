/**
*	@file : Stack.h
*	@author :  Stephen Longofono -2776831
*	@date : 02-25-2015
*	Purpose: This is a stack class that inherits from StackInterface
*/
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include <iostream>
template<typename T>
class Stack: public StackInterface<T>{
	
	public:

		Stack();

		~Stack();

	/*This method checks if the stack is empty using the m_size member 
	*@pre - a stack exists with accurate value in m_size
	*@post - checks if m_size is less than or equal to zero
	*@return - returns true if size is <=0, false otherwise
	*/
		virtual bool isEmpty() const;


	/*This method is a getter for the number of Nodes in a Stack
	*@pre - as stack exists
	*@post - gets m_size
	*@return - returns the value of m_size
	*/
		virtual int size() const;
	

	/*This method retrieves the last value pushed onto the stack and deletes the Node
	*@pre - A non-empty stack exists.  If empty, throws an exception.
	*@post - retrieves m_value of the top node in that stack, removes the node, and returns the value
	*@return - returns m_value from the last Node pushed onto the stack.  If the stack is empty, throws an exception
	*/
		virtual T pop() throw(PreconditionViolationException);

	
	/*This method retrieves the last value pushed onto the stack but leaves it intact (getter).
	*@pre - a non-empty stack exists.  If empty, throws an exception.
	*@post - gets the value of the top node in the stack
	*@return - the value of the top node.
	*/

		virtual T peek() const throw(PreconditionViolationException);

	/*This method pushes a new value onto the top of the stack 
	*@pre - a stack exists
	*@post - creates a new node and sets its value to newEntry.  If it is the first node, sets it as top. 
	*@return - void
	*/
		virtual void push(const T& newEntry);

	/*This method prints the values of each node in the stack
	*@pre - a stack exists with accurate m_size.
	*@post - If non-empty, traverses the stack and prints m_value from each node.  If empty, it says so.
	*@return - void.
	*/
		virtual void print()const;


	/*The methods below define comparison between stacks of any type.  They all operate the same way so I'll only write one explanantion.
	*@pre - all assume that both stacks exist and have accurate values for m_size (which is int regardless of type)
	*@post - compares the size by comparing the results of each stacks' size() method
	*@return - boolean indicating the relationships below
	*/

		virtual bool operator>(const StackInterface<T>& rhs)const;
		virtual bool operator>=(const StackInterface<T>&rhs)const;
		virtual bool operator<(const StackInterface<T>& rhs)const;
		virtual bool operator<=(const StackInterface<T>& rhs)const;
		virtual bool operator==(const StackInterface<T>& rhs)const;
		virtual bool operator!=(const StackInterface<T>& rhs)const;
		
	

	private:
		int m_size;
		Node<T>* m_top;


	/*This method is a helper to get the last Node in a stack
	*@pre - a stack exists with accurate m_size and m_top
	*@post - steps through the stack looking for a node pointing to nullptr
	*@return - returns a pointer to the last node in a stack, or nullptr if the stack is empty
	*/
		Node<T>* getBack()const;
		

};
#include "Stack.hpp"
#endif
