/*ConvertTemperature.java
 * Stephen Longofono s580l129@ku.edu
 * EECS_168 Lab02
 * 9/8/2014 
 */
import java.util.Scanner;
public class ConvertTemperature {

	public static void main(String[] args){
	//C = (F-32) * (5/9)
		Scanner uI = new Scanner(System.in); //User input
		System.out.println("Enter the temperature in Farenheit"); //Friendly prompt
		double tempF = uI.nextDouble(); 
		double tempC = (tempF - 32.0)*(5.0/9.0);
		System.out.println(tempF + " degrees Farenheit = " + tempC + " degrees Celsius.");
		
		
	}
	
}
