/**
*	@file : ValueNotFoundException.cpp
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class implements the ValueNotFoundException class.  It has no other purpose.
*/
#include "ValueNotFoundException.h"

ValueNotFoundException::ValueNotFoundException(const char* message): std::runtime_error(message){}
