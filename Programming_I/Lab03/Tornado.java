/*
 * Stephen Longofono s580l129@ku.edu
 * EECS168 Lab 03
 * Tornado.java
 * 9-15-2014
 * Report on the category of a tornado given a double value from the user
 * values outside the range should not be assigned a category
 *     40 - 72 MPH - F-0 
    > 72 - 112 MPH - F-1 
    > 112 - 157 MPH - F-2 
    > 157 - 205 MPH - F-3 
    > 205 - 260 MPH - F-4 
    > 260 - 318 MPH - F-5 
 * 
 */
import java.util.Scanner;

public class Tornado {

	public static void main(String [] args){
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the wind speed:");
		double windSpeed = input.nextDouble();
		if(windSpeed <=40.0){
			System.out.println(windSpeed);
			System.out.println("There is no tornado.  Calm Yourself.");
		}
		else if(windSpeed>40&&windSpeed<=72){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-0 tornado.");
		}
		else if(windSpeed>72&&windSpeed<=112){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-1 tornado.");
		}
		else if(windSpeed>112&&windSpeed<=157){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-2 tornado.");
		}
		else if(windSpeed>157&&windSpeed<=205){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-3 tornado.");
		}
		else if(windSpeed>205&&windSpeed<=260){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-4 tornado.");
		}
		else if(windSpeed>260&&windSpeed<=318){
			System.out.println(windSpeed);
			System.out.println("The tornado is a f-5 tornado.");
		}
		else if(windSpeed>318){
			System.out.println(windSpeed);
			System.out.println("Panic!  Panic!  Panic!");
		}
	}
	
}
