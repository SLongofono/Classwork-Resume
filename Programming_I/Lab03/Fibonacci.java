/*
 * Just for fun and practice - I'm in 168
 * Stephen Longofono s580l129@ku.edu
 * EECS 168 Lab 03
 * Fibonacci.java
 * 09-15-2014
 * 
 * Create a program to displays the Fibonacci sequence up to a given number of terms.
 * 
 */


import java.lang.Math;
import java.util.Scanner;

public class Fibonacci {

	public static void main(String[]args){
		Scanner input = new Scanner(System.in);
		System.out.println("How many terms of the fibonacci sequence do you want to print?");
		int numberTerms = input.nextInt();
		int aN = 1;
		int aN_1 = 1;
		
		System.out.println("here is your Fibonacci Sequence:");
		
		if(numberTerms == 1){
			System.out.println("0");
			numberTerms = 0;
			}
		else if(numberTerms == 2){
			System.out.println("0");
			System.out.println("1");
			numberTerms = 0;
		}
		else{
			System.out.println("0");
			System.out.println("1");
			System.out.println("1");
		}
		for(int i = 3; i < numberTerms; i++){
			
			aN = aN + aN_1;
			aN_1 = aN -aN_1;
			System.out.println(aN);
			
		}
		
	}
}
	

