/*
 * SummationOfFives.java
 * Longofono-2776831-S580l129@ku.edu
 * EECS 168 - Lab04
 * 9-22-2014
 * 
 * Write a java program using a while loop to compute the sum of multiples of 5 that are greater than 1 
 * (5, 10, 15, 20, ...). You will get an end value, n, from the user and display the resulting sum of 
 * multiples of 5 up to and including n.
 */

import java.util.Scanner;

public class SummationOfFives {

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);
		int index = 0;
		int sum = 0;
		int count = 0;
		System.out.print("Please input a positive integer as the end value: ");
		index = input.nextInt();
		
		while(count <= index){
			sum = sum + count;
			count= count + 5;
		}
		
		System.out.println("The summation is: " + sum);
		
	}
	
}
