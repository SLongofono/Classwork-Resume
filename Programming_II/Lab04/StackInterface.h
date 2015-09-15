/**
*	@file : StackInterface.h
*	@author :  Stephen Longofono
*	@date : 02-25-2015
*	Purpose: Interface for the Stack Class
*/

#ifndef STACK_I
#define STACK_I
#include "Node.h"
#include "PreconditionViolationException.h"

template<typename T>
class StackInterface{

public:
	virtual bool isEmpty() const =0;
	
	virtual void push(const T& newEntry) = 0;

	virtual T pop() throw(PreconditionViolationException) = 0;

	virtual T peek() const throw(PreconditionViolationException) = 0;

	virtual int size() const = 0;

	virtual void print() const = 0;

	virtual ~StackInterface()
		{
	
		}
	
	virtual bool operator<(const StackInterface<T>& rhs) const = 0;
	
	virtual bool operator<=(const StackInterface<T>& rhs) const = 0;

	virtual bool operator>(const StackInterface<T>& rhs) const = 0;

	virtual bool operator>=(const StackInterface<T>& rhs) const = 0;

	virtual bool operator==(const StackInterface<T>& rhs) const = 0;

	virtual bool operator!=(const StackInterface<T>& rhs) const = 0;


};


#endif
