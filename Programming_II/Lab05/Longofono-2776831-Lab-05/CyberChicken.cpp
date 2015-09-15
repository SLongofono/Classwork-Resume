/**
*	@file : CyberChicken.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: Implementation of CyberChicken class
*/
#include "Chicken.h"
#include "CyberChicken.h"


CyberChicken::CyberChicken(): Chicken(){
	setName("Cyber Chicken");
	setSound("Resistance is futile.");
}

int CyberChicken::getCyberEggs() const{
	return (getEggs());	//calls the inherited getter
}

void CyberChicken::setCyberEggs(int eggs){
	setEggs(eggs);	//calls the inherited setter
}
