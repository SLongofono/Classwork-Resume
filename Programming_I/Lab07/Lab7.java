 /* File Name: Lab7.java
 *  Author: Stephen Longofono s580l129@ku.edu
 *  Assignment:   EECS-168 Lab 07
 *  Description: 
    Ask the user how many numbers he/she wants to store. Assume doubles.
        You must prompt the user over and over until they give a value greater than zero. Use a while or do while to do this. Test this before moving on.
    Create an array of doubles that can hold the number specified by the user
    Now that you have an array, we need to get values. Create a loop that will ask the user to input values for the array.
    Once the array is full, use a method you will define printArray to print the array
    Now ask the user for a new array size
        This size must be larger than the original array
        Wait until the user provides a valid size
    Now use a method, which you must define, called double[] arrayResize(double[] oldArray, int newSize) to create a new array
        arrayResize does not print anything nor interact with the user in anyway
    After array is resized, ask the use to provide values for all the new indices
    Use printArray to print the new array
    End the program
    
    public static void printArray(double[] arr)

    Accepts an array of double as input
    Prints the contents in the following format. Let's say we have the array with values 4.4, 2.5, 10.0 then your method must print:

    [4.4, 2.5, 10.0]

    If the array is empty print:

    []

    Separate all elements with commas, but do not place a comma after the last element

    public static double[] arrayResize(double[] oldArray, int newSize)

    Accepts an array of doubles
    It creates a new array according to newSize
    The values from oldArray are copied over into the same indices they held in oldArray and places 0.0 in the remaining indices.
    It returns an array (reference) to the caller

 *  Date: 10-20-2014
*/


import java.util.Scanner;

public class Lab7 {

	public static void main (String []args){
		
		Scanner input = new Scanner(System.in);
		double [] arrayIn;											//placeholder until proper size is collected
		int size = 0;
		int newSize = 0;
		
		while(size <= 0){
			System.out.print("Input an array size: ");
			size = input.nextInt();
		}
		arrayIn = new double [size];
		
		System.out.println("Now please enter " + size + " numbers:");
		
		for(int i = 0; i<arrayIn.length; i++){
			System.out.print("Input a number into your array: ");
			arrayIn[i] = input.nextDouble();
		}
		
		printArray(arrayIn);
		System.out.println("");
		System.out.println("");
		
		while(newSize <= size){
			System.out.print("Enter a new size: ");
			newSize = input.nextInt();
		}
		
		double [] arrayOut = arrayResize(arrayIn, newSize);
		
		System.out.println("You need to add " + (newSize-size) + " values.");
		
		for(int i = arrayIn.length; i<arrayOut.length; i++){
			System.out.print("Input a number into your array: ");
			arrayOut[i] = input.nextDouble();
		}
		
		printArray(arrayOut);
		
	}
	
	public static void printArray(double[] myArray){					//prints out array formatted [#val, #val, #val]
		
		System.out.println("Here are all the numbers in your array: ");
		System.out.print("[");
		for(int i = 0; i<myArray.length; i++){
			
			if(i == (myArray.length - 1)){
				System.out.print(myArray[i]);
			}
			else{
				System.out.print(myArray[i] + ", ");
			}
			
		}
		System.out.print("]");
		
	}
	
	public static double[] arrayResize(double[] oldArray, int newSize){//create a new array with specified index, transfer old index values to new array
		
		double [] temp = new double [newSize];
		
		for(int i=0; i<oldArray.length; i++){
			temp[i] = oldArray[i];
		}
		
		return temp;
		
	}
	
}
