/**
*	@file : NumberFileGenerator.h
*	@author :  Stephen Longofono
*	@date : 04-04-2015
*	Purpose: This class is used to generate text files for use with other classes.  Each of the methods creates
*		a file of integers, the first line being the number of subsequent lines to expect. 
*	###NOTE###  No filtering is done here, use the driver to ensure proper filename and to filter input
*/

#ifndef NUMGEN
#define NUMGEN
#include <string>
#include <fstream>
#include <random>
#include <ctime> //for seeding random generator

class NumberFileGenerator{

	public:

/* This method creates and populates a text file with the amount of numbers specified, in ascending order.
*@pre - A valid filename is passed, amount is greater than zero.
*@post - opens the text file, writes the amount value to the first line, and then writes numbers in order starting from 0.
*@return - void
*/
		static void ascending(std::string fileName, int amount);


/* This method creates and populates a text file with the amount of numbers specified, in descending order.
*@pre - A valid filename is passed, amount is greater than zero.
*@post - opens the text file, writes the amount value to the first line, and then writes numbers in order starting from 0.
*@return - void
*/
		static void descending(std::string fileName, int amount);


/* This method creates and populates a text file with the amount of numbers specified, in no particular order.
* Here, each value will be within the min and max parameters
*@pre - A valid filename is passed, amount is greater than zero, min<=max.
*@post - opens the text file, writes the amount value to the first line, and then writes a random value that falls
*       within the range specified.
*@return - void
*/
		static void random(std::string fileName, int amount, int min, int max); 

/* This method creates and populates a text file with the amount of numbers specified, all of a single value.
*@pre - A valid filename is passed, amount is greater than zero.
*@post - opens the text file, writes the amount value to the first line, and then writes the value 'amount' times.
*@return - void
*/
		static void singleValue(std::string fileName, int amount, int value); 
};
#endif
