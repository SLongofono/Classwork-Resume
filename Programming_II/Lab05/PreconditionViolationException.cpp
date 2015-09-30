/**
*	@file : PreconditionViolationException.cpp
*	@author :  Stephen Longofono
*	@date : 02-25-2015
*	Purpose: Implementation of the header file
*/
#include "PreconditionViolationException.h"
#include <stdexcept>

PreconditionViolationException::PreconditionViolationException(const char* msg) : std::runtime_error(msg){
	
}