/*
 * File Name: 	SumOfDigits.java
 * Author: 		Stephen Longofono s580l129@ku.edu	
 * Assignment:  EECS-168 Lab 05
 * Description: Write a Program that takes in an Integer value form the user and finds the sum of the digits.
				Method to define: addDigits(int x)

    			this takes in an integer as argument
    			returns the sum of the digits
    			this method must be called from the main method
       		
 * Date: 		9-29-2014
 */

import java.util.Scanner;
import java.lang.Math;

public class SumOfDigits {

	public static void main(String[]args){
		Scanner input = new Scanner(System.in);
		boolean again = false;
		int choice = 0;
		do{																						//run it once no matter what
		
			System.out.println("Please enter a number:");
		
			System.out.println("The sum of the digits is: " + addDigits(input.nextInt()));
			
			System.out.println("");
			
			System.out.println("Would you like to try again? (y=1/n=0):");
			
			choice = input.nextInt();
			
			System.out.println("");
			
		
		}while(choice == 1);																	//conditional on user input
		
		System.out.print("Thank you!");
	}
	
	public static int addDigits(int x){
		
		int sum = 0;
		int parsedDigit = 0;
		
		while(!(x % 10 == 0)){
			
			parsedDigit = x % 10;									// gets digit in the ones place
			sum = sum + parsedDigit;								//adds the parsed digit to the running total
			x = ((x - parsedDigit)/10) ;							//removes the parsed digit from the given number
																	//and shifts the decimal place (tens to ones)
		}
		
		return sum;
		
	}
	
}
