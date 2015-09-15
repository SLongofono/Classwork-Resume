/* File Name: MyCircleTest.java
 * Author: Stephen Longofono 2776831
 * Assignment:   EECS-168 lab08
 * Description:  Create a class with a main to interact with the class MyCircle
 * 					
 * Date: 10-27-2014
 */

public class MyCircleTest {
	
	public static void main(String[] args){
		
		MyCircle myCircle = new MyCircle();
		myCircle.radius = 5.5;
		System.out.println("My circle has a radius of " + myCircle.radius);
		double theArea = myCircle.area();
		double theCircum = myCircle.circumference();
		System.out.println("The area is " + theArea);
		System.out.println("The circumference is " + theCircum);
		System.out.println("The diameter is " + myCircle.diameter());
		
	}

}
