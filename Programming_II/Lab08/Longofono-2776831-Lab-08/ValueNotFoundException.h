/**
*	@file : ValueNotFoundException.h
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class is a custom exception used for the specific case when a recursive search doesn't find a value in the BinarySearchTree class.
*/

#ifndef VEX
#define VEX
#include <stdexcept>
#include <string>

class ValueNotFoundException: public std::runtime_error{

	public:
//Calls the parent class with a custom message for use with the exception's e.what() method.  Makes use of the instantiation block of the constructor.
	ValueNotFoundException(const char* message);

};


#endif
