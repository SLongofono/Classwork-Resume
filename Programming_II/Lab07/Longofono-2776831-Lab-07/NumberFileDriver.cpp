/**
*	@file : NumberFileDriver.cpp
*	@author :  Stephen Longofono
*	@date : 04-05-2015
*	Purpose: Implementation of the NumberFileDriver.h class
*/

#include "NumberFileDriver.h"


void NumberFileDriver::run(int argc, char** argv){
	std::string inputAsString(argv[2]);//this converts it to <string> for use with the isValidOption method
	if(isValidOption(inputAsString)){
			if(argv[2][1]=='a'){//now, we use the 2D approach instead
				NumberFileGenerator::ascending(std::string(argv[3]), atoi(argv[4]));
				std::cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
			}
			else if(argv[2][1] =='d'){
				NumberFileGenerator::descending(std::string(argv[3]), atoi(argv[4]));
				std::cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
			}
			else if(argv[2][1] =='s'){
				NumberFileGenerator::singleValue(std::string(argv[3]), atoi(argv[4]), atoi(argv[5]));
				std::cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
			}
			else if(argv[2][1] =='r'){
				NumberFileGenerator::random(std::string(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
				std::cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
			}

	}
	else{
		printHelpMenu();
	}

}

void NumberFileDriver::printHelpMenu(){

	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(std::string option){

		if(option.substr(0,2)=="-a"){//start from index 0, and include 2 characters
			return true;
		}
		if(option.substr(0,2)=="-d"){
			return true;
		}
		if(option.substr(0,2)=="-s"){
			return true;
		}
		if(option.substr(0,2)=="-r"){
			return true;
		}
	
	return false;

}
