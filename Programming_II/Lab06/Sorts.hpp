/**
*	@file : Sorts.hpp
*	@author :  Stephen Longofono
*	@date : 03-28-2015
*	Purpose: Implementation of the Sorts.h template class
*/


template<typename T>//works
void Sorts<T>::bubbleSort(T arr[], int size){
	bool sorted = true;

	for(int i = 0; i < (size-1); i++){
		for(int j = 0; j < (size-1); j++){
			
			if(arr[j] > arr[j+1]){		//Note: in c++, arr[] is an implicit
				swap(arr, j, (j+1));//pass by reference.  Thus we can omit the
				sorted = false;		//ampersand when passing it to methods.
			}

		}
		if(sorted){
			i = size;
		}
	}

	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>//works
void Sorts<T>::selectionSort(T arr[], int size){

	
	
	for(int i = 0; i< size; i++){
		int lowValue = arr[i];
		int lowIndex = i;

		for(int j = i; j< size; j++){

			if(arr[j]<lowValue){
				lowValue = arr[j];
				lowIndex = j;
			}
		}
		swap(arr, i, lowIndex);
	}

	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>//broken
void Sorts<T>::insertionSort(T arr[], int size){
	int targetIndex;
	for(int wall= 1 ; wall<size; wall++){ //we shift a "wall" through that separates the sorted from the unsorted
		/*Starting at the index of the wall, compare that index with the one before it.  If the one before
		* is greater, swap them, decrement the target location ( as long as its greater than 0) and check again.
		* When this check returns false, we have everything in the right place and we start over.  This is 
		* based on the premise that the left side of the wall is always sorted (we start with only 1 index).
		*/		

		targetIndex = wall;			
		while((arr[targetIndex]<arr[targetIndex-1])&&(targetIndex>0)){
			swap(arr, targetIndex, (targetIndex-1));			
			targetIndex--;
		}
	}

	
	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>
void Sorts<T>::bogoSort(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));
	
	
	while(!(isSorted(arr, size))){
		shuffle(arr, size, generator);
	}
	
	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>
void Sorts<T>::swap(T arr[], int a, int b){
	T temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	for(int i = 0; i<size-1; i++){
		
		if(arr[i]>arr[i+1]){
			return false;
		}

	}
	return true;
}

template<typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator){

	std::uniform_int_distribution<int> distribution(0, size-1);
	int random = distribution(generator);
	for(int i = 0; i<size; i++){
			
			swap(arr, i, random);
			random = distribution(generator);
	
	}

}
