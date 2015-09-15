/**
*	@file : Sorts.h, v2.0
*	@author :  Stephen Longofono
*	@date : 03-28-2015 - Modified 04/01/15
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
#include <functional>
#include <chrono>

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


/* This method sorts an array per the standard mergesort algorithm
*@pre - arr is a valid array with an accurate size.
*@post - recursively splits the array into arrays of size 1, then uses merge to put them back together
*@return - void
*/
		static void mergeSort(T arr[], int size);


/* This method calls quicksort with median flag set to false
*@pre - none
*@post - this method is here by requirement.  It is a second driver that decrements the size by one and then calls
*	 quickSortRec with median as false. 
*@return - void
*/
		static void quickSort(T arr[], int size);


/* This method calls quicksort with median flag set to false
*@pre - none
*@post - this method is here by requirement.  It is a second driver that decrements the size by one and then calls
*	 quickSortRec with median as true. 
*@return - void
*/
		static void quickSortMedian(T arr[], int size);


/* This method does magic, as it is sufficiently advanced beyond my understanding.
*@pre - An array exists, with valid size and type.  The type must allow or have defined comparators '<', '>'.
*@post - 
*@return - 
*/	
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
	
	

/* This method combines two sorted arrays into another sorted array
*@pre - a1 and a2 point to different parts of a single array (or other contiguous pieces of memory).  Size values are accurate.
*	a1 is of lower index than a2 in the array.
*@post - Compares the first value in one array with the other, placing the smallest in a temporary array.  It then compares
*	the next value in the array that had the smaller value, and so on until one array is exhausted.  Then, the rest of the
*	remaining array is appended to the temporary array, and this array is copied back into the original array starting
*	with the a1 pointer.
*@return - void
*/
		static void merge(T* a1, T* a2, int size1, int size2);


/* This method partitions and sets the pivot point for use within the quickSort algorithm.  The value of 
* median triggers a call to setMedianPivot just before setting the pivot to the last index of the array.
*@pre - An array exists, with accurate indices first and last.
*@post - Steps through the array first from the left, and then from the right, comparing each index value to the last index.
*	If it finds a value from the left less than the pivot, and a value from the right greater than the pivot, it
*	swaps them and continues until the left meets the right.  This index is then swapped with the pivot (last index).
*@return - the integer index where the left and right met.
*/	
		static int partition(T arr[], int first, int last, bool median);

/* This method is sorts an array with the quicksort algorithm.  There are two options for calling it which
* are collected at one level upward by the sortDriver.  The value of median is passed to the partition
* method, which if true will prompt the pivot to be set using the setMedianPivot method.
*@pre - The drivers (SortDriver, quickSort, quickSortMedian) have done their job
*@post - if size is 3 or less, it calls selection sort, since the setMedianPivot method requires size 3 or more.  Otherwise,
*	it calls partition, and then calls itself recursively first with the sub-array to the left of the returned index, and 
*	then with the sub-array to the right of the returned index.
*@return - void
*/
		static void quickSortRec(T arr[], int first, int last, bool median);


	private: //TODO move merges, quicks back down




/* This method is here to swap the median of an array to the final position.  This is triggered
* by the median flag from within the partition method.
*@pre - An array exists with accurate last and first values
*@post - selects the first, last, and middle values and places them in a temporary array.  This array is sorted with 
*	selection sort, and then each of the values in the original array is compared to index 1 of the temporary array.
*	When this comparison evaluates to true, the corresponding index is swapped with the value at arr[last]
*@return - void 
*/		
		static void setMedianPivot(T arr[], int first, int last);



/* This method swaps each index in an array with another.
*@pre - an array exists with accurate size
*@post - creates a random number generator, with uniform distribution over the number from 0 to size.  Then, swaps each index
*	of the array with the index at a random value from this distribution, which effectively shuffles the array.
*@return - void
*/
		static void shuffle(T arr[], int size);


/* This method is a helper that swaps the values at the given indices
*@pre - an array exists.  Both a and b are valid indices in the array.
*@post - Swaps the value of a with the value of b.
*@return - void.
*/
		static void swap(T arr[], int a, int b);
		

};

#include "Sorts.hpp"
#endif
