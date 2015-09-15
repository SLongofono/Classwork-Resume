/**
*	@file : AnimalPen.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: Implementation of te AnimalPen class
*/

#include "Stack.h"
#include "AnimalPen.h"
#include "FarmAnimal.h"

AnimalPen::AnimalPen(){}	//do nothing, the stack will be created automatically

AnimalPen::~AnimalPen(){
	while(!isEmpty()){
		FarmAnimal* temp = peek();
		delete temp;
		temp = nullptr;	
		pop();
	}
	m_top = nullptr;
}

bool AnimalPen::isPenEmpty(){
	return(isEmpty());
}


FarmAnimal* AnimalPen::peekAtNextAnimal(){
	return(peek());
}

void AnimalPen::releaseAnimal(){
	FarmAnimal* temp = peek();
	delete temp;
	temp = nullptr;
	pop();
}

void AnimalPen::addAnimal(FarmAnimal* a){
	push(a);
}


