/*
 * Stephen Longofono s580l129@ku.edu
 * EECS168 Lab03
 * Multiples.java
 * 9-15-2014
 * 
 * Write a program that displays a number of multiples of a given number from the user.  Ex 4, 3 multiples -> 4,8,12
 * Display an error message using a for loop if the user enters a number less than or equal to zero in the multiples prompt
 */
import java.util.Scanner;
import java.lang.Math;

public class Multiples {

	public static void main(String[]args){
		
		int terms = 0;
		int base = 0;
		Scanner input = new Scanner(System.in);
		
		System.out.println("what number do you want to see multiples of?");
		base = input.nextInt();
		System.out.println("How many multiples do you want to print?  Enter a whole number greater than zero.");
		terms = input.nextInt();
		
		if(terms <= 0){
			System.out.println("Invalid input.  please enter a whole number greater than zero.");
			terms = input.nextInt();
		}
		
		System.out.println("Here are the first " + terms + " multiples of " + base + ".");
		
		for(int i = 1; i <= terms; i++){
		
			
			System.out.println(base*i);
			
		}
	}
}
