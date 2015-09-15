/*
 * additions for later:
 * 
 * Need to fix ace as a one OR 11
 * Need to fix soft 17s logic
 * Need to implement double down
 * Need to implement split hand
 * 
 * decks - make an array and a method to populate the array with the number of cards of each type left.  You will need to modify the dealer to pull
 * at random from the remaining cards, and periodically reset(or give the player an option to "shuffle")
 */


import java.util.Random;
public class BlackJack {
	
	static int gamesPlayed = 0;
	private int roundTotal;
	private int pot;
	private int playerCash;
	private int dealerTotal;
	private char[] playerHand;
	private char[] dealerHand;
	private Random deal;
	private int round;
	private int currentBet;
	
	public BlackJack(){
		gamesPlayed++;
		pot = 0;
		dealerTotal = 0;
		roundTotal = 0;
		playerHand = new char[15];
		dealerHand = new char[15];
		deal = new Random();
		playerCash = 1000;
		round = 1;
		currentBet = 0;
	}
	
	public String getPlayerHand(){
		String hand = "";
		for(int i = 0; i< playerHand.length; i++){
			switch(dealerHand[i]-48){
			case 1: hand += "A"; break;
			case 11: hand += "J"; break;
			case 12: hand += "Q"; break;
			case 13: hand += "K"; break;
			default: break;
			
			}
		}
		return hand;
	}
	
	public String getDealerHand(){
		String hand = "";
		for(int i = 0; i< dealerHand.length; i++){
			
			switch(dealerHand[i]-48){
			case 1: hand += "A"; break;
			case 11: hand += "J"; break;
			case 12: hand += "Q"; break;
			case 13: hand += "K"; break;
			default: break;
			
			}
		}
		return hand;
	}
	public int getDealerTotal(){
		int hand = 0;
		for(int i = 0; i< dealerHand.length; i++){
			if(dealerHand[i]!=0){
				hand += ((int)dealerHand[i]-48);
			}
		}
		return hand;
	}
	public int getPlayerTotal(){
		int hand = 0;
		for(int i = 0; i< playerHand.length; i++){
			if(playerHand[i]!=0){
				hand += ((int)playerHand[i]-48);
			}
		}
		return hand;
	}
	
	public void newRound(){		//reset hands, pot, bets, increment round
		for(int i =0; i<dealerHand.length; i++){
			dealerHand[i]=0;
		}
		for(int i =0; i<playerHand.length; i++){
			playerHand[i]=0;
		}
		pot = 0;
		round++;
		currentBet = 0;
		
	}
	public void hitPlayer(){	//hit and update hand total
		int a = (deal.nextInt(12) +1);
		boolean notDone = true;
		for(int i =0; i<playerHand.length; i++){
			if(playerHand[i]==48){
				playerHand[i]= (char)(a+49);
				notDone = false;
			}
		}
	}
	public void hitDealer(){	//hit and update hand total
		int a = (deal.nextInt(12) +1);
		boolean notDone = true;
		for(int i =0; i<dealerHand.length; i++){
			if(dealerHand[i]==48){
				dealerHand[i]= (char)(a+49);
				notDone = false;
			}
		}
	}
	public void deal(){
		int a = (deal.nextInt(12) +1);
		int b = (deal.nextInt(12) +1);
		int c = (deal.nextInt(12) +1);
		int d = (deal.nextInt(12) +1);
		dealerHand[0] = (char)(a+49);
		dealerHand[1] = (char)(b+49);
		playerHand[0] = (char)(c+49);
		playerHand[1] = (char)(d+49);
	}
	
	public boolean doublesCheck(){		//boolean is split/doubledown possible?
		if(playerHand[0]==playerHand[1]){
			return true;
		}
		return false;
	}
	
	public boolean bJCheckPlayer(){
		return(getPlayerTotal()==21);
	}
	public boolean bJCheckDealer(){
		return(getDealerTotal()==21);
	}
	public int getPot(){
		return pot;
	}
	public int getCash(){
		return playerCash;
	}
	public int getBet(){
		return currentBet;
	}
	public void setBet(int a){
		currentBet = a;
	}
	public int getRound(){
		return round;
	}
	public void ante(){
		playerCash -= 10;
		pot += 10;
	}
	public void win(){
		if(bJCheckPlayer()){
			playerCash += (2*pot);
		}
		else{
			playerCash += (pot);
		}
	}
	private boolean aceCheckPlayer(){
		boolean yup = false;
		for(int i = 0; i<playerHand.length; i++){
			if(playerHand[i]=='1'){
				yup = true;
			}
		}
		return yup;
	}
	private boolean aceCheckDealer(){
		boolean yup = false;
		for(int i = 0; i<dealerHand.length; i++){
			if(dealerHand[i]=='1'){
				yup = true;
			}
		}
		return yup;
	}
	

}
