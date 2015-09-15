/**
*	@file : PreconditionViolationException.h
*	@author :  Stephen Longofono -2776831
*	@date : 02-25-2015
*	Purpose: This is a custom exception used here to handle popping or peeking an empty stack.  It makes use of the instantiation block
*		because the parent class requires a message in its constructor.
*		Fun fact: my last name has almost as many o's as the name of this class.
*/
#ifndef LONGNAME
#define LONGNAME
# include <stdexcept>
#include <string>

class PreconditionViolationException: public std::runtime_error{
	public:
	PreconditionViolationException(const char* msg);
};

#endif
