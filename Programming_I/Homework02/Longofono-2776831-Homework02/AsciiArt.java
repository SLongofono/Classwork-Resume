/*	File Name: AsciiArt.java
	Author: Stephen Longofono 
    KUID: 2776831
	Email Address: s580l129@ku.edu 
	Homework Assignment Number: 2.1
	Description:  
	
		Write a simple program called AsciiArt.java that uses nested loops and if statements to create a nXn grid,
	 	a checker board and a diagonal reflected across the y-plane depending on the users input each with the rows labeled 0
	 	through n. You'll obtain n from the user, and n must be larger than 1. If the user gives an invalid size or menu choice,
	 	display the text "Error." and exit.

	Last Changed: 9-26-2014 
 * 
 */
import java.util.Scanner;
import java.lang.Math;

public class AsciiArt {

	public static void main (String[]args){
		
		Scanner input = new Scanner(System.in);
		int choice = 0;
		int dimension = 0;
		int pebcak = 0;		//Throws an error message immediately if input from gathering stage is invalid, and stops the program.
							//Also stops the while loop after the program has run successfully (see note at bottom).
		
		System.out.printf("Choose one of the following patterns by typing the corresponding number:%n" + "1) Stripes%n" + "2) Checker Board%n" + "3) Double Diagonal (aka the X)%n");
		choice = input.nextInt();
		System.out.println("");
		
		if((!(choice == 1||choice == 2|| choice == 3))){
			
			System.out.println("Error.");
			pebcak = 1;
		}
		
		if(pebcak !=1){
		
			if(choice == 3 && pebcak != 1){
				System.out.println("If you want to display the Double Diagonal, choose an odd number size less than 11 for best results.");
			}
			
			System.out.println("Input a size (must be larger than 1):");
			dimension = input.nextInt();
		}
				
		if(!(dimension>1) && pebcak !=1){
			
			System.out.println("Error.");
			pebcak = 1;
		}
		while(pebcak !=1){
			
			if(choice == 1){
			
				for (int i = 0; i < dimension; i++){			//number of rows

					System.out.print(i + "    ");						
										
					for(int j = 0; j < 5; j++){					//number of columns, arbitrarily chosen to be 5
					
						if(j % 2 == 0){							//alternates output as j progresses
							System.out.print("*");
						}
						else{
							System.out.print("   ");
						}
					
					}
					
					System.out.println("");
					
					if(i == (dimension-1)){
					pebcak = 1;									//halts after successful execution.
					}
				
				}
			}
			
			else if(choice == 2){
				
				for(int i = 0; i < dimension; i++){ 			//number of rows
					
					System.out.print(i + "    ");						
										
					for(int j = 0; j < dimension; j++){			//number of columns
						
						if((j + i) % 2 == 0){					//Alternates based on the value of i, with the effect of a staggered output of asterisks, both in the 
							System.out.print("  ");				// column and in the row.
							System.out.print("*");
						}
						else{
							System.out.print("   ");
						}
					
					}
					
					System.out.println("");
					
					if(i == (dimension - 1)){
						pebcak = 1;								//halts after successful execution
					}
				}
				
			}
			
			else{
					final int VERT = ((dimension/2));			//Determines center of given dimensions (horizontally and vertically)
					final int HORI = ((dimension/2));			//Determines center of current vertical, progressed at the end of each row						
					for(int i = 0; i < dimension; i++){			//Number of rows
					
						if(dimension >= 10){					//Fixes alignment for double digit indices...sort of.  Row 10 on is shifted right
							System.out.print(i + "   ");		//and I couldn't figure out how to correct it.
						}	
						else{
							System.out.print(i + "    ");						
						}
						
						for(int j = 0; j < dimension; j++){		//number of columns
							
							/*
							 * Here, each iteration of the j loop compares the absolute value of the difference between j and the horizontal center to the absolute value
							 * of i from the vertical center.  This only prints an asterisk when the values are equal, and the absolute value creates symmetrical
							 * output once a center is established 
							 */
							
							
							if(Math.abs(HORI - j) == Math.abs(VERT-i)){
								System.out.print("*");
							}
							else{
								System.out.print(" ");
							}
						}
						
						System.out.println("");
						
						if(i == (dimension - 1)){
							pebcak = 1;
						}
						
					}
			
			}
		
		}													//end while loop
		
	}
	
}
