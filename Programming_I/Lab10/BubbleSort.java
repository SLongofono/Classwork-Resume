/* -----------------------------------------------------------------------------
 *
 * File Name: BubbleSort.java
 * Author: Stephen Longofono s580l129@ku.edu
 * Assignment:   EECS-168 Lab 10
 * Description:  implement bubble sort
 * Date: 11-17-2014
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;

public class BubbleSort {
	
	public void ascending(int[] arr){
		int temp = 0;
		boolean sorted = true;					//assume it is sorted
		while(sorted){							//run while it is sorted
			for(int i = 0; i<arr.length-1; i++){
				for(int j = 0; j<arr.length-1; j++){
					if(arr[j]>arr[j+1]){
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;	
						sorted = false;		//toggle sorted if the array was not sorted.
											//added to reduce sort time.  50k values in less than 4 seconds.
					}
				}
			}
		}
	}
	
	public void descending(int[] arr){
		int temp = 0;
		boolean sorted = true;
		while(sorted){
			for(int i = 0; i<arr.length-1; i++){
				for(int j = 0; j<arr.length-1; j++){
					if(arr[j]<arr[j+1]){
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
						sorted = false;
					}
				}
			}
		}
	}
	
}
