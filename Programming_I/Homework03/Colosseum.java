
public class Colosseum {
	
	public static void main(String[]args){
		int roundCount = 1;									//counter for rounds (game while loop)
		boolean someOneDied = false;						//alternate match ender
		Pokemon playr1 = new Pokemon();						//new Pokemon object to default values
		Pokemon playr2 = new Pokemon();
		Dice d2 = new Dice(2);								//new Dice object with 2 as initial numSides
		System.out.println("Player 1, build your Pokemon!");
		playr1.userBuild();
		System.out.println("Player 2, build your Pokemon!");
		playr2.userBuild();
		
		System.out.println("");
		System.out.println("Player 1 will roll a D2, to decides who goes first.");
		
		int initiative = d2.roll();
		
		if(initiative == 1){
			System.out.println("Player 1 rolls a 1 and will go first");
			System.out.println("");
			System.out.println("");
		}
		else{
			System.out.println("Player 1 rolls a 2 and will go second");
			System.out.println("");
			System.out.println("");
		}
		
		
		while((roundCount < 11)&&(!someOneDied)){								//game while loop
			
			System.out.println("Round " + roundCount + "!");
			if(initiative == 1){
				someOneDied = playr1.attack(playr2);							//calls attack method, which returns true if killshot
				if(someOneDied){
					roundCount = 10;											//break while loop
				}
				else{
					playr2.attack(playr1);
					if(someOneDied){
						roundCount = 10;											//break while loop
					}
				}
			}
			else{																//same code, reversed for initiative
				someOneDied = playr2.attack(playr1);
				if(someOneDied){
					roundCount = 10;
				}
				else{
					playr1.attack(playr2);
					if(someOneDied){
						roundCount = 10;											//break while loop
					}
				}
			}
			roundCount++;
			System.out.println("");
			System.out.println("");
			
		}
		
		if(playr1.getHp() <= 0){
			System.out.println(playr1.getName() + " has been defeated!");
		}
		else if(playr2.getHp() <=0){
			System.out.println(playr2.getName() + " has been defeated!");
		}
		else{
			System.out.println("Both fighters are still standing!  It's a draw!");
		}
		
	}
	
}
