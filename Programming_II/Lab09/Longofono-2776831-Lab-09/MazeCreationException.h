/**
*	@file : MazeCreationException.h
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: This class is a custom exception that inherits from the runtime_error standard exception. It is used at various
*		points of the reading process to provide specific feedback as to what, if anything, is considered an error.
*/

#ifndef MEX
#define MEX
#include <exception>
#include <stdexcept>
class MazeCreationException: public std::runtime_error{
	public:
	MazeCreationException(const char* message);

};

#endif
