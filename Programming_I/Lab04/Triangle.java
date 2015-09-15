/*
 * Triangle.java
 * Longofono-2776831-S580l129@ku.edu
 * EECS 168 - Lab04
 * 9-22-2014
 * 
 * Write a program that will print a triangle of asterisks of size n, called Pyramid.java. 
 * In this program you should use nested for-loops (a for loop within another for-loop) 
 * and only print out one asterisk out at a time.
 * 
 */
import java.util.Scanner;

public class Triangle {

	public static void main(String[]args){
		
		int base = 0;
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter the number of asterisks for the base of the triangle: ");
		base = input.nextInt();
		
		for(int i=0; i<base; i++){
			
			for(int j=0; j<=i; j++){
				
				System.out.print("*");
				
			}
			
			System.out.println("");
			
		}
		
	}
	
}
