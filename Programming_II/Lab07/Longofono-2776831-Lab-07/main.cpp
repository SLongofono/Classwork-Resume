/**
*	@file : Main.cpp
*	@author :  Stephen Longofono
*	@date : 04-04-2015
*	Purpose: This class acts as the top level for interaction with the user.  It will check its arguments to make sure
*	there are at least 5 (minimum for correct function) and then calls the appropriate run command.
*/

#include <iostream>
#include "SortDriver.h"
#include <string>
#include "NumberFileDriver.h"

int main(int argc, char** argv){



	if(argc<5){
		std::cout<<"Invalid number of arguments\n";
		NumberFileDriver::printHelpMenu();
	}
	
	std::string mode = (argv[1]);
	if(mode.compare("-create")==0){

		NumberFileDriver::run(argc, argv);

	}
	else if(mode.compare("-sort")==0){

		SortDriver::run(argc, argv);

	}
	else{

		std::cout<<"Invalid parameters.  Check the order of your options\n";
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();

	}

return 0;

}



