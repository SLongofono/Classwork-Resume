/**
*	@file : NumberFileGenerator.hpp
*	@author :  Stephen Longofono
*	@date : 04-04-2015
*	Purpose: Implementation of the NumberFileGenerator class
*/

#include "NumberFileGenerator.h"


void NumberFileGenerator::ascending(std::string fileName, int amount){
	
	std::ofstream outFile(fileName);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++){
		outFile<<i<<"\n";  //write to file
	}
	outFile.close();

}


void NumberFileGenerator::descending(std::string fileName, int amount){

	std::ofstream outFile(fileName);
	outFile<<amount<<"\n";
	for(int i = amount; i>0; i--){
		outFile<<i<<"\n";  //write to file
	}
	outFile.close();

}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max){
	std::default_random_engine generator(time(nullptr)); //seeds a random engine with time
	std::uniform_int_distribution<int> distr(min, max-1); //uniform distribution of expected values, adjust per spec to not include max
	std::ofstream outFile(fileName);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++){
		outFile<<distr(generator)<<"\n";
	}
	outFile.close();
	
} 

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value){

	std::ofstream outFile(fileName);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++){
		outFile<<value<<"\n";
	}
	outFile.close();

}

