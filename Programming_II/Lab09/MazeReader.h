/**
*	@file : MazeReader.h
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: This class is in charge of reading in the maze and populating member variables appropriately.  At each stage of
*			the process, an exception may be thrown if the provided file does not match the stipulations detailed
*			below.  This method also includes getters that allow main to instatiate to MazeWalker class with the 
*			maze information.
*/

#ifndef MREAD
#define MREAD
#include <fstream>
#include <iostream>
#include <exception>
#include "MazeCreationException.h"
#include <string>
#include <cstdlib>

class MazeReader{

	public:
/**	This creates an object to manage the reading in of the maze file (and appropriate error
*		 handling)
*	@pre - 
*	@post - A MazeReader is created. A 2D char array is allocated with the maze information.
*	@throws - MazeCreationExecption if any of the following is true:
*                 -The file could not be opened
*                 -The rows or cols are zero or less 
*                 -The start position listed is outside the ranges described by the rows and columns
*                 -You do NOT have to check each character for validity, only the rows, cols, and
*			 starting position.
*	@return - void
*/
	MazeReader(std::string file) throw (MazeCreationException);

/**
*	@pre - a maze exists
*	@post - The maze and its members are deallocated.
*	@return - void
*/
	~MazeReader();

/**
*	@pre - the file was formatting and can be read
*	@post - The maze is deallocated.
*	@return - Returns pointer to the maze
*/
	char** getMaze() const;

/**
*	@pre - the file was formatted and can be read
*	@post - The maze is deallocated.
*	@return - the number of columns listed in the file
*/
	int getCols() const;

/**
*	@pre - the file was formatted and can be read
*	@post - The maze is deallocated.
*	@return - the number of rows listed in the file
*/
	int getRows() const;

/**
*	@pre - the file was formatted and can be read
*	@post - The maze is deallocated.
*	@return - the starting column
*/
	int getStartCol() const;

/**
*	@pre - the file was formatted and can be read
*	@post - The maze is deallocated.
*	@return - the starting row
*/
	int getStartRow() const;

	protected:
/**
*	@pre - the file is properly formatted
*	@post - the characters representing the maze are stored
*	@return - void
*/
	void readMaze()	throw (MazeCreationException);
	

	std::ifstream m_file;
	int m_rows;
	int m_cols;
	int m_startRow;
	int m_startCol;
	char** m_maze;

};

	

#endif
