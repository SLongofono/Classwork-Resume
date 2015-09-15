
/* File Name: MyCircle.java
 * Author: Stephen Longofono 2776831
 * Assignment:   EECS-168 lab08
 * Description:  Create a new class constructor for circles, with methods for area, circumference, and diameter
 * Date: 10-27-2014
 */
public class MyCircle {
	
	private final double PI = 3.141592;
	public double radius;
	
	public double diameter(){
		
		return (radius*2);
		
	}
	
	public double circumference(){
		
		return (radius*2*PI);
		
	}
	
	public double area(){
		
		return (radius*radius*PI);
		
	}

}
