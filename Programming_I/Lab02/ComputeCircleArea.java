/*
 * ComputeCircleArea.java
 * Stephen Longofono s580l129@ku.edu
 * EECS_168 Lab02
 * 9/8/2014
 */

import java.util.Scanner;

public class ComputeCircleArea {

	public static void main(String[] args){
		
		Scanner uI = new Scanner(System.in);
		System.out.println("Enter the radius of the circle.");
		final double PI = 3.141592;
		double radius = uI.nextDouble();
		double area = radius*radius*PI;
		
		System.out.println("For the given radius " + radius + ", the area of the circle will be " + area + ".");
		
		
		
	}
	
}
