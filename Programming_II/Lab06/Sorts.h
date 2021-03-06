/**
*	@file : Sorts.h
*	@author :  Stephen Longofono
*	@date : 03-28-2015
*	Purpose: This class offers a template for various sorting algorithms, including bubble, selection, insertion, and
*		bogo.  ****NOTE****  All types used with this class must have the binary operators defined, as this is how
*		sorting is accomplished.
*/


#ifndef SORTS
#define SORTS
#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

template<typename T>
class Sorts{

	public:
/* This method sorts by swapping adjacent indices so that they are in the proper order.
*@pre - an array exists with an accurate size value
*@post - compares each value in the array with the next and switches them so that the lower value is in
*	the lower index.  This runs through two nested for loops with n^2 time.
*@return - void.  The array is sorted.
*/
		static void bubbleSort(T arr[], int size);


/* This method sorts by swapping each index with a random index in the array. Note: this has potential
*  to run indefinitely, as an index may switch with itself.
*@pre - an array exists with an accurate size value
*@post - Uses the random number generator to swap every index with a random index within the array.
*@return - void.  The array is sorted. If the array has size zero, it does nothing.
*/
		static void bogoSort(T arr[], int size);


/* This method sorts by separating the array into two sections, beginning with only the first index
* in one section(the sorted one).  It then grabs the first index of the next section, and shifts
* it to the right position by comparing with the values in the sorted side from highest to lowest
*  to run indefinitely, as an index may switch with itself.
*@pre - an array exists with an accurate size value
*@post - compares the first value in the second section to the values in the first section from 
*	highest to lowest.  Stops when the wall reaches the second to last. n^2 time.
*@return - void.  The array is sorted.  If the array has size zero, it does nothing.
*/
		static void insertionSort(T arr[], int size);


/* This method sorts by keeping track of the lowest value and index, using this information to
* "select" the proper value for each index, one at a time from the bottom up.
*@pre - an array exists with an accurate size value
*@post - Assumes the first index is the lowest, and iterates over the array, comparing 
*	with every element until it finds a lower one.  At the end, it swaps the selected index
*	with the index noted as the lowest in the iteration.  Repeat until done.  n^2 time.
*@return - void.  The array is sorted.  If the array has size zero, it does nothing.
*/
		static void selectionSort(T arr[], int size);


/* This method determines if an array is sorted in an iterative fashion.
*@pre - an array exists with an accurate size value
*@post - compares each index to the next, and compares the values
*@return - False if any index is greater than the next index.  True otherwise.
*/
		static bool isSorted(T arr[], int size);
	
	private:

/* This method does most of the work for the bogoSort() method.
*@pre - an array exists with an accurate size value
*@post - iterates over the array, swapping each index with a random index within the range of size.
*@return - void.
*/
		static void shuffle(T arr[], int size, std::default_random_engine& generator);


/* This method is a helper that swaps the values at the given indices
*@pre - an array exists.  Both a and b are valid indices in the array.
*@post - Swaps the value of a with the value of b.
*@return - void.
*/
		static void swap(T arr[], int a, int b);
		

};

#include "Sorts.hpp"
#endif
