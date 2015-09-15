/**
*	@file : Main.cpp
*	@author :  Stephen Longofono
*	@date : 2014.01.28
*	Purpose: Implementation of Main Class
*/
#include <iostream>
#include "Dice.h"
#include "Pokemon.h"
#include "Colosseum.h"


int main()
{
	std::cout<<"\nWelcome to the Pokemon Colosseum\n================================\n\n\n";
	bool playAgain = true;
	Colosseum game;
	Pokemon p1;//declared here so we don't create a new object each time
	Pokemon p2;
	
	do{
		std::cout<<"\nPlayer 1, build your Pokemon!\n";
		game.userBuild(p1); 
		std::cout<<"\n\nPlayer 2, build your Pokemon!\n";
		game.userBuild(p2);
		game.play(p1, p2);	

		std::cout<<"Do you want to play again?: (y/n)";
		char choice;
		std::cin>>choice;
		playAgain = (choice=='y'||choice=='Y');

	} while(playAgain);  //end do while
	
	std::cout<<"\n\n";

}// end main


