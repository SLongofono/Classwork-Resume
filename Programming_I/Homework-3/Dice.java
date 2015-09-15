import java.util.Random;
public class Dice {
	
	private int numSides;	//private member only for use within the class
	private Random rando = new Random();
	
	public Dice(int sides){	//public method "setter"
		numSides = sides;
	}
	
	public int roll(){		//public method 
		return ((rando.nextInt(numSides)) + 1);		//add one for 1 output on [1, numSides]
	}
}
