/* -----------------------------------------------------------------------------
 *
 * File Name: Lab10.java
 * Author: Stephen Longofono s580l129@ku.edu
 * Assignment:   EECS-168 Lab 10
 * Description:  Tester class for bubble sort
 * Date: 11-17-2014
 *
 ---------------------------------------------------------------------------- */

import java.util.Random;
import java.util.Scanner;

public class Lab10 {
	
	public static void main(String[] args){
		Random dice = new Random();
		Scanner input = new Scanner(System.in);
		BubbleSort sorter = new BubbleSort();		//create a new BubbleSort object to use in main
		int size = 0;
		long startTime = 0;
		long stopTime = 0;
		int ascending = 0;
		long timeElapsed = 0;
		double seconds = 0;
		
		do{
		System.out.println("How many random numbers do you want to make?");
		size = input.nextInt();
		}while(size <=0);
		
		System.out.print("Would you like to sort the array in ascending or descending order? (0 for ascending, 1 for descending): ");
		ascending = input.nextInt();
		
		int [] arrayIn = new int[size];				//populate an array of the specified size with the random library, here
		for(int i = 0; i<arrayIn.length; i++){		//it returns a random integer on [0,255]
			arrayIn[i] = dice.nextInt(256);
		}
		
		System.out.println("\nUnsorted Array:");	//helpful interaction
		printArray(arrayIn);
		
		startTime = System.nanoTime();				//log system time in seconds e^-9
		System.out.println("Starting sort at " + startTime + " nanoseconds.");
		
		if(ascending==0){
			sorter.ascending(arrayIn);
		}
		else{
			sorter.descending(arrayIn);
		}
		
		stopTime = System.nanoTime();				//log system time in seconds e^-9
		System.out.println("Stopping sort at " + stopTime + " nanoseconds.");
		
		timeElapsed = (stopTime - startTime);	//relative time in nanoseconds
		seconds = (timeElapsed / 1000000000.0);	//adjusted for seconds
		
		System.out.println("Sorted Array: ");
		printArray(arrayIn);
		
		System.out.println("This sort took a total of " + timeElapsed + " nanoseconds, or " + seconds + " seconds.");
		
	}
	
	public static void printArray(int[] a){
		for(int i = 0; i<a.length; i++){
			System.out.print(a[i] +" ");
		}
		System.out.println("");
	}
}
