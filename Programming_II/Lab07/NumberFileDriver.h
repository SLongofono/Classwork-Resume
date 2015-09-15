/**
*	@file : NumberFileDriver.hpp
*	@author :  Stephen Longofono
*	@date : 04-05-2015
*	Purpose: This class is responsible for obtaining and filtering user input to be used with the NumberFileGenerator class.
*/

#ifndef NUMDRV
#define NUMDRV
#include <string>
#include <iostream>
#include <string>
#include "NumberFileGenerator.h"
#include <cstdlib>
#include <fstream>

class NumberFileDriver{

	public:
		

/* This method takes in arguments from main and reacts appropriately
*@pre - the 2-D array exists with valid arguments
*@post - if the arguments are valid, calls the appropriate methods from the NumberFileGenerator class.  Otherwise,
*	prints the help menu and returns.  Includes a primitive catch for bad numerical parameters, because I don't have time to define the
*	behavior for all possible errors.
*@return - void
*/
		static void run(int argc, char** argv);


/* This method prints a help/options menu for the user when they give bad input.
* This text was provided by Dr. Gibbons for use with our program.
*@pre - none
*@post - prints options menu to stdout
*@return - void
*/
		static void printHelpMenu(); 

	private:


/* This method verifies that the arguments passed correspond to those specified in the help menu (-a,-d,-s,or -r)
*@pre - A string of at least 2 characters exists, as converted from a character array
*@post - checks the first two characters against the values above
*@return - True if argument matches any of the above values, false otherwise.
*/
		static bool isValidOption(std::string option);

};

#endif
