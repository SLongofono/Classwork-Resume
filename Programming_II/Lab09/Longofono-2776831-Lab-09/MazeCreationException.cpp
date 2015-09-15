/**
*	@file : MazeCreationException.cpp
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: Implementation of MazeCreationException.h.  Note it must pass its message at instantiation.
*/
#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message): std::runtime_error(message){};
