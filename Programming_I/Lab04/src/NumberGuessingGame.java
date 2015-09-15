/*
 * NumberGuessingGame.java
 * Longofono-2776831-S580l129@ku.edu
 * EECS 168 - Lab04
 * 9-22-2014
 * 
 * Create a program, NumberGuessingGame.java that will make the user guess a specific number, 73. 
 * Your program won't end until the user guesses the correct number, but along the way you will help the user.
 * 
 * Use a do while loop to do this
 * 
 */
 

import java.util.Scanner;

public class NumberGuessingGame {

	public static void main(String[]args){
		
		Scanner input = new Scanner(System.in);
		int guess = 0;
		
		System.out.println("Welcome to the number guessing game!");
		
		do{
			System.out.print("Guess a number:");
			guess = input.nextInt();
			if(guess<73){
				System.out.println("Sorry, your guess is too low.");
			}
			else if (guess>73){
				System.out.println("Sorry, your guess is too high.");
			}
		}while(guess != 73);
		
		System.out.println("You Win!");
		
	}
	
}
