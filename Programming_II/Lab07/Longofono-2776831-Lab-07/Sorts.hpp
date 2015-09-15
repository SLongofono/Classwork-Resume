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

template<typename T>//works
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
void Sorts<T>::shuffle(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));	//seed a random generator with system time
	std::uniform_int_distribution<int> distribution(0, size-1);//create a uniform distribution over the values of indices
	int random = distribution(generator);	//pick one
	for(int i = 0; i<size; i++){
			
			swap(arr, i, random);//swap each index with another at random
			random = distribution(generator);//at random
	
	}

}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size){
	if(size<=1){
		return;
	}
	int leftSize = (size/2);
	int rightSize = (size-leftSize);
	T* left = arr;
	T* right = (arr+leftSize);
	mergeSort(left, leftSize);
	mergeSort(right, rightSize);
	merge(left, right, leftSize, rightSize);
	assert(Sorts<T>::isSorted(arr, size));

}

template<typename T>
void Sorts<T>::quickSort(T arr[], int size){

	quickSortRec(arr, 0, size-1, false);	

}



template<typename T>
void Sorts<T>::quickSortMedian(T arr[], int size){

	quickSortRec(arr, 0, size-1, true);

}



template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[], int)> sort, T arr[], int size){
// std::function <returnType(param1Type, param2Type)> functionName
//The above prototype is how we use the functional class to abstract a method signature

std::chrono::system_clock::time_point start;//starting time marker
std::chrono::system_clock::time_point end;//ending time marker
std::chrono::duration<double> elapsed;//time elapsed, formatted per chrono class

start = std::chrono::system_clock::now();//grab current time

sort(arr, size);//this is calling the sort function passed in.  This seems like a dangerous idea...

end = std::chrono::system_clock::now();//grab current time

elapsed = (end-start);//difference is time elapsed
return (elapsed.count());//return converted to seconds
		
}




template<typename T>	//a1, a2 are two indices within the same array
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2){
	if(size1+size2 <= 1){
		return;
	}
	T* tempArr = new T[size1+size2]; //dynamically created, because this is a static method.  
	int ix=0;
	int iy=0;
	int currentIndex = 0;
	while(ix<size1 && iy<size2){//until we reach the end of one half

		if(*(a1+ix)>*(a2+iy)){
			tempArr[currentIndex] = *(a2+iy);
			iy++;
		}
		else{
			tempArr[currentIndex] = *(a1 +ix);
			ix++;
		}
		currentIndex++;
	}

	while(ix<size1){//this never executes if the first half finishes first
		tempArr[currentIndex] = *(a1+ix);
		ix++;
		currentIndex++;
	}
	while(iy<size2){//this never executes if the second half finishes first
		tempArr[currentIndex] = *(a2+iy);
		iy++;
		currentIndex++;
	}
	for(int i = 0; i<(size1+size2); i++){

		a1[i] = tempArr[i];//ok because a1 is specifically an array pointer

	}
	delete [] tempArr;

}



template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){

	if(median && ((last+1)<3)){//base case, amended for use with median
		selectionSort(arr, (last+1));
		return;
	}
	if(first<last){
		int pivot = partition(arr, first, last, median);
		quickSortRec(arr, first, (pivot-1), median);
		quickSortRec(arr, (pivot+1), last, median);
		return;
	}

}//recursive==Rec?



template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int  first, int last){
	int mid = (last+1)/2;
	T temp [] = {arr[first], arr[mid], arr[last]};
	selectionSort(temp, 3);
	if(arr[first]==temp[1]){//if middle value is in first index
		swap(arr, mid, last);//place first at the end
	}
	else if(arr[mid]==temp[1]){
		swap(arr, mid, last);//place middle at the end
	}
	//else do nothing, the last is already at the end
	

}//find median, swap with end



template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median){
	int pivotIndex = last;
	int leftIndex=first;
	int rightIndex = (pivotIndex-1);
	if(median){
		setMedianPivot(arr, first, last);
	}	
	bool notDone = true;
	while(notDone){
			while(arr[leftIndex]<arr[pivotIndex]){
				leftIndex++;
			}
			while(arr[rightIndex]>= arr[pivotIndex]){
				rightIndex--;
			}
			if(leftIndex<rightIndex){
				swap(arr, leftIndex, rightIndex);
			}
			else{
				notDone = false;
				swap(arr, leftIndex, pivotIndex);
				
			}
		
	}

	return leftIndex; //now holds the pivot value, in the correct position
	
}
