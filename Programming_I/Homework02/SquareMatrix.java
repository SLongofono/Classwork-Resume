/* 	File Name: SquareMatrix.java
 * 	Author: Stephen Longofono 
 *  KUID: 2776831
 *  Email Address: s580l129@ku.edu 
 *	Homework Assignment Number: 2.2
 *	Description:
 *
 *  	Write a Program SquareMatrix.java that takes a number n from the user and find its Square Matrix and Transpose of the Square Matrix
 *  	using nested For loops. See the sample output.  Assume valid input for this exercise. 
 *    
 *	Last Changed: 9-26-2014 
 * 
 */

import java.util.Scanner;
import java.lang.Math;

public class SquareMatrix {

	public static void main(String [] args){
		
		Scanner input = new Scanner(System.in);
		int n = 0;
		System.out.println("Enter the Size of the Square Matrix:");
		n = input.nextInt();
		int lastSum = 0;												//running total of current digit, declared here to preserve its value outside of the for loops

		System.out.println("");
		System.out.println("Square Matrix:");
		
		for(int i = 0; i < n; i++){							
					
			for(int j = 0; j < n; j++){
				
				lastSum = lastSum + 1;									//increments in tandem with j, and stores the last used value of j for the next iteration.
				if(lastSum < 10){										//digit alignment for matrices  up to 31 x 31
					System.out.print(lastSum + "   ");
				}
				else if(lastSum < 100 && lastSum > 9){
					System.out.print(lastSum + "  ");
				}
				else{
					System.out.print(lastSum + " " );
				}
								
			}
			
			System.out.println("");
		}
		
		System.out.println("");
		System.out.println("Transposed:");
		
		for(int i = 1; i <= n; i++){
			
			for(int j = i; j <= (n * n); j = j + n){
				
				if(j < 10){											//digit alignment for matrices up to 31 x 31
					System.out.print(j + "   ");
				}
				else if(j < 100 && j > 9){
					System.out.print(j + "  ");
				}
				else{
					System.out.print(j + " " );
				}
								
			}
			
			System.out.println("");
		}
	}
	
}
