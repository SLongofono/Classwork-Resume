/**
*	@file : FarmAnimal.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: Implementation of the FarmAnimal Class
*/
#include "FarmAnimal.h"
#include <string>

FarmAnimal::FarmAnimal(){
	m_name = "unset";
	m_sound = "unset";
}

std::string FarmAnimal::getName() const{
	return (m_name);
}

std::string FarmAnimal::getSound() const{
	return (m_sound);
}

void FarmAnimal::setName(std::string name){
	m_name = name;
}

void FarmAnimal::setSound(std::string sound){
	m_sound = sound;
}

