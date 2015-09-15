/**
*	@file : Cow.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: Implementation of the Cow class
*/
#include "FarmAnimal.h"
#include "Cow.h"


Cow::Cow(): FarmAnimal(){
	setName("Cow");
	setSound("Moo.");
}

double Cow::getMilkProduced() const{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons){
	if(gallons>=0){
		m_milkProduced = gallons;
	}
	else{
		m_milkProduced = 0;
	}
}
