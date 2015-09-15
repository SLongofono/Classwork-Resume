/*
 * 	File Name: GameDriver.java
	Author: Stephen Longofono
	KUID: 2776831
	Email Address: s580l129@ku.edu 
	Homework Assignment Number: 4 
	Description:  This is the "front-end" driver for the Hangman game on a desktop/laptop.  The back-end allows for different implementations, but the setup here is as follows:
	
					Take in a secret word or phrase and advance the console/output 100 lines
					
					Create a HangMan instance (increments the gamesPlayer counter, a static value)
					
					Begin main game phase:
						
						Begin turn phase:
							
							Display the output array, with chars disguised as question marks, guessed letters shown as is
							
							Display total guesses so far
							
							Display "lives" as O's, which become X's as wrong guesses are entered
							
							Display feedback after each guess
						
						End Turn Phase, repeats until winning/losing condition is met (instance methods)
						
					Display you win/you lose feedback
					
					Prompt to play again
						
						If yes, get a new secret word and create a new instance with this word.  Start main game phase.
						
						If no, retrieve games played and break the while loop wrapping main
					-end-
					
	
	Last Changed: 12-05-14 
	
 */
import java.util.Scanner;

public class GameDriver {

	public static void main(String [] args){
		
		Scanner input = new Scanner(System.in);
		String secret = "";
		String playAgain = "no";
		String lineIn = "";
		boolean notDonePlaying = true;
		
		System.out.println("Enter the secret word:");
		secret = input.nextLine();
		
		while(notDonePlaying){								//main game phase loop
			
			for(int i = 0; i<100; i++){
				System.out.println("");
			}
		
			HangMan game = new HangMan(secret);				//instance creation point
		
			System.out.println("Welcome to the Hangman Game!\n----------------------------");
		
			while(!game.isGameOver()){						//Turn phase loop
				System.out.println("Guess this: " + game.getDisguisedWord());				//display the question marks and guessed letters
				System.out.println("Guesses so far: " + game.getGuessCount());				//getter, number of guesses counter
				System.out.println("Misses: " + game.getMissedMarker());					// getter, lives left
				System.out.print("Enter your guess character: ");
				lineIn = input.next();
				while(lineIn == null){														//probably redundant, here in case return doesn't count as a character
					System.out.println("You must enter a character: ");
					lineIn = input.next();
				}
				if(game.guessCharacter(lineIn.charAt(0))){
					System.out.println(lineIn.charAt(0) + " is in the secret word!");
					System.out.println("");
					
				}
				else{
					System.out.println(lineIn.charAt(0) + " is not in the secret word.  Death draws closer.");
					System.out.println("");
				}
			}
			//feedback and prompts/resetting
			System.out.println("Game over!");
			if(game.isFound()){
				System.out.println("Congratulations! You guessed the secret word: " + secret + " in " + game.getGuessCount() + " guesses!");
				System.out.println("Do you want to play again? (yes/no): ");
				playAgain = input.next().toLowerCase();
				if(playAgain.equals("yes")){
					input.nextLine();				//very important because of scanner black magic
					System.out.println("Enter a secret word: ");
					secret = input.nextLine();
				}
				else{
					notDonePlaying = false;			//break main game loop
				}
			}
			else{
				System.out.println("You have died. Next time, guess as if your life depended on it.");
				System.out.println("Do you want to play again? (yes/no): ");
				playAgain = input.next().toLowerCase();
				if(playAgain.equals("yes")){
					input.nextLine();				//very important because of scanner black magic
					System.out.println("Enter a secret word: ");
					secret = input.nextLine();
				}
				else{
					notDonePlaying = false;			//break main game loop
				}
				
			}
		}
		System.out.println("Thanks for playing " + HangMan.gamesPlayed + " game(s) of Hang Man!");
	}	//main
	
}	//class
