import java.util.Scanner;

public class BlackJack_Driver {
	
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		System.out.println("************ Black Jack ************");
		System.out.println("Rules:\nDealer will hit on soft 17\nYou begin with $1000\nThe dealer will lend you up to $5000\nLikewise, the dealer limits your winnings to $5000 per session\nBets pay 1:1, 2:1 for a blackjack\nante is $10\nThe house wins all ties\nYou have the option of quitting whenever it is your turn\nLet's get started!");
		boolean keepPlaying = true;
		
		while(keepPlaying){		//game loop
			boolean notOver = true;
			boolean wannaQuit = false;
			boolean inputBad = false;
			BlackJack game = new BlackJack();
			while(notOver){		//session loop
				System.out.println("Round " + game.getRound());
				
				System.out.println("Place your bet: ");
				while(!inputBad){
					try{
						game.setBet(input.nextInt());
					}
					catch(Exception e){
						System.out.println("I don't understand that.  Please enter a whole number for your bet: ");
					}
				game.deal();
				game.ante();
				System.out.println("Pot: " + game.getPot());
				System.out.println("Your Hand: " + game.getPlayerHand());
				System.out.println("Dealer's Hand: " + game.getDealerHand());
				if((game.bJCheckDealer())||(game.bJCheckPlayer())){//here is where the split and double checks should go later
					if(game.bJCheckDealer()){
						System.out.println("The dealer got a black jack!");
						game.newRound();
					}
					else{
						System.out.println("You got a blackjack!  You win!");
						game.win();
						game.newRound();
					}
				}
				else{
					char choice = 'a';
					String userIn = "";
					while(game.getPlayerTotal()<21){
						
						while(choice == 'a'){
							while(choice!='h'||choice!='s'){
								System.out.println("Enter h to hit or s to stay");
								userIn = input.next();
								choice = userIn.toLowerCase().charAt(0);
							}
							if(choice == 'h'){
								game.hitPlayer();
								System.out.println("Your hand: " + game.getPlayerHand());
								System.out.println("Your current hand total: " + game.getPlayerTotal());
								if(game.getPlayerTotal()<21){
									choice = 'a';
								}	
							}
							else{
								
									while(game.getDealerTotal()<=17){
										System.out.println("Dealer hits.");
										game.hitDealer();
										System.out.println("Dealer's hand: " + game.getDealerHand());
									}
									if((game.getDealerHand().charAt(0)>=10||game.getDealerHand().charAt(1)>=10)&&(game.getDealerTotal()==17)){
										System.out.println("Dealer hits.");
										game.hitDealer();
										System.out.println("Dealer's hand: " + game.getDealerHand());
									}
									if(game.getDealerTotal()==21){
										System.out.println("Dealer wins!");
										game.newRound();
									}
									else if(game.getDealerTotal()>21){
										System.out.println("Dealer busts!");
										game.win();
										game.newRound();
									}
									else{
										if(game.getDealerTotal()>=game.getPlayerTotal()){
											System.out.println("Dealer wins!");
											game.newRound();
										}
										else{
											System.out.println("You win!");
											game.win();
											game.newRound();
										}
									}
								}
							}
						}
							
						}
					
				}
				
				
				
				if((game.getCash()==5000)||(game.getCash()==-5000)||(wannaQuit)){
					notOver = false;	//quit session
					System.out.println("Final total: " + game.getCash() + " in " + game.getRound() + " rounds.");
				}
			}
			
			System.out.println("Do you want to start a new session (yes/no): ");
			String choiceEnd = input.nextLine();
			if(!(choiceEnd.toLowerCase().equals("yes"))){	//quit game
				keepPlaying = false;
			}
		}
		System.out.println("Total games played: " + BlackJack.gamesPlayed);
		System.out.println("Thanks for playing!");
		
	}//main
	
}//class
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
