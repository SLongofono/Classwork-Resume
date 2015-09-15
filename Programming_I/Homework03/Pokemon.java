import java.util.Scanner;
public class Pokemon {

	private int hp;
	private int attack;
	private int defense;
	private String name;
	private Dice d20 = new Dice(20);
	private Dice d6 = new Dice(6); 
	
	public Pokemon(){
		hp = 0;
		attack = 0;
		defense = 0;
		name = "";
	}
	
	public boolean attack(Pokemon opponent){
		int aBonus = d20.roll();
		int dBonus = d20.roll();
		int tempAttack = attack + aBonus;
		int tempDefense = opponent.getDefense() + dBonus;
		int d1 = d6.roll();
		int d2 = d6.roll();
		int d3 = d6.roll();
		
		System.out.println(name + " is attacking " + opponent.getName() + "!");
		System.out.println(name + " rolls an attack bonus of " + aBonus + "!");
		System.out.println(opponent.getName() + " rolls a defense bonus of " + dBonus + "!");
		
		if(tempAttack > tempDefense){
			System.out.println("The attack hits dealing 3-D6 damage!");
			System.out.println("The rolls are " + d1 + ", " + d2 + ", and " + d3 + " totaling: " +(d1 + d2 + d3)+ " damage!");
			opponent.setHp(opponent.getHp() - (d1+d2+d3)); 
			if(opponent.getHp() >= 0){
				System.out.println(opponent.getName() + " has " + opponent.getHp() + " hit points left");
			}
		}
		else{
			System.out.println("The attack missed!");
		}
		return (opponent.getHp() <= 0);							//the attacked pokemon died.
	}
	
	public void userBuild(){
		Scanner io = new Scanner(System.in);
		int hpIn = 0;
		int atkIn = 0;
		int defIn = 0;
		String nameIn = "";
		System.out.println("=====================");
		do{
			System.out.print("Please name your pokemon: ");		//prompts a name until it gets a character 
			nameIn = io.nextLine();
			System.out.println("");
		}while(nameIn.length() < 1);
		
		System.out.print("How many hit points will it have? (1-50): ");
		System.out.println("");
		
		while(hpIn < 1 || hpIn > 50){
			hpIn = io.nextInt();
			System.out.println("");
			if(hpIn < 1 || hpIn > 50){
				System.out.print("Sorry.  The hit points must be between 1 and 50:");
				System.out.println("");
			}
		}
		
		System.out.println("Split 50 points between attack level and defense level");
		System.out.print("Enter your attack level (1-49): ");
		
		while(atkIn < 1 || atkIn > 49){
			atkIn = io.nextInt();
			System.out.println("");
			if(atkIn < 1 || atkIn > 49){
				System.out.print("Sorry.  The attack level must be between 1 and 49:");
				System.out.println("");
			}
		}
		
		System.out.println("Enter your defense level (1-" + (50-atkIn) + "): ");	//adjusts range for attack selection
			
		while(defIn < 1 || defIn > (50-atkIn)){
			defIn = io.nextInt();
			System.out.println("");
			if(defIn < 1 || defIn > (50-atkIn)){
				System.out.print("Sorry.  The defense level must be between 1 and " + (50-atkIn) + ":");//ditto above
				System.out.println("");
			}
		}
		name = nameIn;
		attack = atkIn;
		defense = defIn;
		hp = hpIn;
		if(nameIn.equals("ChuckNorris")){
			godMode();
		}
		
	}
	
	public void setHp(int input){		//"Setters" to filter proper input, assign if positive
			hp = input;
	}
	
	public void setAttack(int input){
			attack = input;
	}
	
	public void setDefense(int input){
			defense = input;
		}
	
	public void setName(String input){
			name = input;
	}
	
	public int getHp(){			//"Getters" to read private member values
		return hp;
	}
	
	public int getAttack(){
		return attack;
	}
	
	public int getDefense(){
		return defense;
	}
	
	public String getName(){
		return name;
	}
	
	public void godMode(){		//for epic battles and cheaters
		hp = 250;
		attack = 80;
		defense = 80;
		System.out.println("Cheater!");
		System.out.println("");
	}
}
