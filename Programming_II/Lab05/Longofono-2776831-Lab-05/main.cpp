/**
*	@file : main.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This is the farm program.  In all its glory.  It prompts the user to add animals to the pen until they indicate they are done.  Once the user is doen, all the animals are released (and deleted) and the member variables milk and eggs are tallied and displayed.
*/

#include <iostream>
#include <string>
#include "FarmAnimal.h"
#include "StackInterface.h"
#include "Stack.h"
#include "Node.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"

void goodByeMessage(const FarmAnimal& animal){
	std::cout<<"Upon release the "<<animal.getName()<<" said "<<animal.getSound()<<"\n";
}

int main(){
	double totalMilk = 0;
	int totalEggs = 0;
	bool notDone = true;
	int menuChoice = 0;
	int iChoice = 0;
	double dChoice = 0.0;
	AnimalPen pen1;

	std::cout<<"\n\n\n====================Farm Program====================\n";
	
	while(notDone){
		
		std::cout<<"\nSelect and animal to add to the pen:\n"
			<<"1.) Cow (produces milk)\n"
			<<"2.) Chicken (cannot lay eggs)\n"
			<<"3.) Cyber Chicken (seems dangerous, but lays eggs)\n"
			<<"---------------------------------------------------\n"
			<<"choice: ";
		std::cin>>menuChoice;

		switch(menuChoice){
			
			case 1: 
				{
				Cow* temp2 = new Cow();
				std::cout<<"How many gallons of milk did this cow produce?: ";
				std::cin>>dChoice;
				temp2->setMilkProduced(dChoice);
				pen1.push(static_cast<FarmAnimal*>(temp2)); break;
				}
			case 2: {Chicken* temp = new Chicken();
				std::cout<<"Add an eggless chicken to the pen?  OK.  You're the boss.\n";
				pen1.push(static_cast<FarmAnimal*>(temp));break;
				}
			case 3: {CyberChicken* temp3 = new CyberChicken();
				std::cout<<"How many eggs did this cyber chicken produce?: ";
				std::cin>>iChoice;
				temp3->setCyberEggs(iChoice);
				pen1.push(static_cast<FarmAnimal*>(temp3));break;
				}
		}//end switch

		std::cout<<"Done adding animals? (y/n): ";
		char temp4;
		std::cin>>temp4;

		if(temp4=='y'){
			notDone = false;
		}
		std::cout<<"\n";

	}// end while

	std::cout<<"\nReleasing all animals!\n-------------------------\n";

	while(!pen1.isPenEmpty()){
		FarmAnimal* temp5 = pen1.peek();
		if(temp5->getName()=="Cow"){	//static_cast below because we now know what type of animal we are dealing with
			totalMilk += static_cast<Cow*>(temp5)->getMilkProduced();
			std::cout<<"This cow produced "<<static_cast<Cow*>(temp5)->getMilkProduced()<<" gallons of milk.\n";
			goodByeMessage(*(temp5));
			pen1.pop();
		}
		else if(temp5->getName()=="Chicken"){
			std::cout<<"Chicken unable to lay eggs.  Peraps cybornetic implants will help?\n";
			goodByeMessage(*(temp5));
			pen1.pop();
		}
		else{
			totalEggs += static_cast<CyberChicken*>(temp5)->getCyberEggs();
			std::cout<<"This Cyber Chicken laid "<<static_cast<CyberChicken*>(temp5)->getCyberEggs()<<" cyber eggs.  Humanity is in trouble.\n";
			goodByeMessage(*(temp5));
			pen1.pop();			
			
		}
		delete temp5;
		
	}
	std::cout<<"Your farm produced "<<totalMilk<<" gallons of milk and "<<totalEggs<<" eggs.\n\n\n\n";
	



return 0;
}// end main
