/* File Name: Lab6.java
 * Author: Stephen Longofono s580l129@ku.edu
 * Assignment:   EECS-168 Lab06
 * Description:  Play with arrays:
 * 					
    Ask the user how many numbers he/she wants to store. Assume integers.
    You must prompt the user over and over until they give a value greater than zero. Use a while or do while to do this. 
    Test this before moving on.  Create an array of integer that can hold the number specified by the user
    Now that you have an array, we need to get values. Create a loop that will ask the user to input values for the array.
    Display the values back to the user after you obtain all of them. Test this before moving on.
    Create a new variable to store the sum of all the numbers in the array. You will calculate the sum like we used to, 
    but we'll need to access the values in the array. Test this before moving on.
    Create a variable called max and a variable called min. Set them both to the 0th element of the user array. Now, in a loop compare min and max to every element in the array.
        if you find a value bigger than max, store that value in max
        if you find a value less than min, store that value in min
    Finally display the sum, max, min, and average (recall the average of a bunch of numbers is the (sum / how many numbers there were))

 * Date: 10-6-2014
 *
 * 
 */

import java.util.Scanner;
public class Lab6 {

	public static void main (String [] args){
		
	
		Scanner input = new Scanner(System.in);
		int size = 0;
		while(size <= 0){																			// verifies valid input 
			System.out.print("Input an array size: ");
			size = input.nextInt();
		}
		
		int [] myArray = new int[size];
		System.out.println(size);
		System.out.println("Now, please enter " + size + " numbers");								//prompts the user for each of "size" number of indexes
		for (int i = 0; i < myArray.length; i++){
			System.out.println("Enter the number for index " + i + ".");
			myArray[i] = input.nextInt();
		}
		System.out.println("Here are all the numbers in your array:");								//prints all the entered values
		for(int i = 0; i < myArray.length; i++){
			System.out.println(myArray[i]);
		}
		System.out.println("The sum of all the values is: " + sum(myArray));						//calls the individual methods for each function and prints the results
		System.out.println("The average of all the values is: " + mean(myArray, size));
		System.out.println("The largest value is: " + largest(myArray));
		System.out.println("The smallest value is: " + smallest(myArray));
	}
	public static double mean(int[] myArray, int size){												//average calls the sum method and divides the result by size, returns arithmetic mean
		double result = ((sum(myArray))/(size));
		return result;
	}
	public static int sum(int[] myArray){															//simple sum program runs through each index and adds to a running total "sum"
		int sum = 0;
		for(int i = 0; i < myArray.length; i++){
			sum = sum + myArray[i];
		}
		return sum;
	}
	public static int largest(int[] myArray){														//compares each index of the array to "largest".  If an index is greater than largest, largest is assigned to that index's value
		int largest = 0;
		for(int i = 0; i < myArray.length; i++){
			if(largest < myArray[i]){
				largest = myArray[i];
			}
		}
		return largest;
	}
	public static int smallest(int[] myArray){														//opposite of the largest function, adapted with >= so that it always returns a value in the array rather than its initialization.
		int smallest = myArray[0];
		for(int i = 0; i < myArray.length; i++){
			if(smallest >= myArray[i]){
				smallest = myArray[i];
			}
		}
		return smallest;
	}
}
