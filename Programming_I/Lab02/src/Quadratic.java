/* Quadratic.java
 * Stephen Longofono s580l129@ku.edu
 * EECS_168 Lab02
 * 9/8/2014
 * I'm not in the honors course, but I wanted to give it a shot.
 */
import java.util.Scanner;
import java.lang.Math;

public class Quadratic {
	
	public static void main(String[] args){
		
	Scanner uI = new Scanner(System.in);
	System.out.println("Enter the coefficients A, B, and C of your quadratic equation.  Follow each with return.");
	double a = uI.nextDouble();
	double b = uI.nextDouble();
	double c = uI.nextDouble();
	double posRoot;
	double negRoot;
	System.out.println("Input a: "+ a);
	System.out.println("Input b: "+ b);
	System.out.println("Input c: "+ c);
	//test for real sol'ns
	
	if(((b*b)-4*a*c)<0){
		System.out.println("There are no real roots to this quadratic equation.");
	}
	else{
		posRoot = ((b*(-1.0)) + Math.sqrt((b*b)-(4*a*c)))/(2*a);
		negRoot = ((b*(-1.0)) - Math.sqrt((b*b)-(4*a*c)))/(2*a);
		System.out.println("root 1: " + posRoot);
		System.out.println("root 2: " + negRoot);
	}
	}
}