/**
*	@file : main.cpp
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: The main class instantiates the MazeReader and MazeWalker classes, and does basic filtering of user input.
*			The primary job of this class is to create and manage the maze classes.
*/

#include "MazeReader.h"
#include "MazeCreationException.h"
#include <iostream>
#include <string>
#include "MazeWalker.h"


int main(int argc, char** argv){

	bool dfsChoice;
	if(argc<3){
		std::cout<<"Invalid number of arguments\nEnter: [executable] [filename.ext] [-bfs or -dfs]\n";
		return -1;
	}	
	std::string choice(argv[2]);
	if(choice=="-bfs"){
		dfsChoice = false;
	}
	else if(choice == "-dfs"){
		dfsChoice = true;
	}
	else{
		std::cout<<"Invalid search choice.  Enter -dfs or -bfs\n";
		return -1;
	}


	std::string myFile(argv[1]);
	MazeReader* myMazeReader = new MazeReader(myFile);
	std::cout<<"Success!\n";

	char** theMaze = myMazeReader->getMaze();
	MazeWalker* workHorse = new MazeWalker
		(theMaze, myMazeReader->getStartRow(), myMazeReader->getStartCol(), myMazeReader->getRows(), myMazeReader->getCols(), dfsChoice);
	workHorse->walkMaze();
	delete workHorse;
	delete myMazeReader;
	theMaze = nullptr;
	workHorse = nullptr;
	myMazeReader = nullptr;
	
return 0;
}
