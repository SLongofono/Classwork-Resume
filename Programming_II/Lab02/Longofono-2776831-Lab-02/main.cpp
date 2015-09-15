/*	Name: Stephen Longofono - 2776831
*	File name: main.cpp
*	Date: 02-04-2015
*	Description: This class acts as an entry point and driver to test out the LinkedList class.
*			:::NOTE::: This program has no exception handling, it must be given ints as input.
*/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"

/* This is a sample menu written in full by Dr. Gibbons for use in our Lab.  It details the user's
*  choices to demonstrate the LinkedList class
* @pre - none - this is strictly for feedback purposes
* @post - prints out the menu to display the value input and what it will do
* @return - void
*/
void printMenu(){
	std::cout<< "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "Enter your choice: ";
}

int main(){

	LinkedList ll1;	
	int userChoice = 5;
	int innerChoice = 0;
	while(userChoice != 7){

		std::cout<<"\n\n";
		printMenu();
		std::cin>>userChoice;
		std::cout<<"  You chose: "<<userChoice<<"\n";
		while((userChoice > 7)||(userChoice < 1)){
			std::cout<<"Invalid choice.\n";
			printMenu();
			std::cin>>userChoice;
			std::cout<<"  You chose: "<<userChoice<<"\n";
		}

		switch(userChoice){
	
		case 1: std::cout<<"Input a value to add: ";
			std::cin>>innerChoice;
			std::cout<<"  Adding "<<innerChoice<<" to the list\n";
			ll1.addFront(innerChoice);
			break;

		case 2: std::cout<<"Input a value to add: ";
			std::cin>>innerChoice;
			std::cout<<"  Adding "<<innerChoice<<" to the list\n";
			ll1.addBack(innerChoice);break;

		case 3: std::cout<<"Attempting removal from front of list.\n";
			if(ll1.removeFront()){
				std::cout<<"Removal successful.\n";
			}
			else{
				std::cout<<"There are no values to remove.\n";
			} break;

		case 4: std::cout<<"Attempting removal from back of list.\n";
			if(ll1.removeBack()){
				std::cout<<"Removal successful.\n";
			}
			else{
				std::cout<<"There are no values to remove.\n";
			} break;


		case 5: std::cout<<"Printing list:\n";
			ll1.printList();  break;


		case 6: std::cout<<"Enter a value to search for: ";
			std::cin>>innerChoice;
			std::cout<<"  Searching for "<<innerChoice<<"...\n";
			if(ll1.search(innerChoice)){
				std::cout<<innerChoice<<" is in the list.\n";
			}
			else{
				std::cout<<innerChoice<<" is not in the list\n";
			}  break;


		case 7: break;
		}//end switch

	}//end while
	
	std::cout<<"Exiting...\n\n";
	ll1.~LinkedList();
	
	return 0;
}




