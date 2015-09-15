/**
*	@file : MazeReader.cpp
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: Implementation of MazeReader.h
*/

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException){
	try{
		m_file.open(file);
	}
	catch(MazeCreationException& e){
		throw MazeCreationException(e.what());
	}
	try{
		readMaze();
	}
	catch(MazeCreationException& e){
		throw MazeCreationException(e.what());  //convoluted way of being more specific for end user
	}
}

MazeReader::~MazeReader(){
	for(int i = 0; i<m_rows; i++){
			delete [] m_maze[i];	
	}
	delete [] m_maze;
	m_maze = nullptr;
	m_file.close();
}

char** MazeReader::getMaze() const{
	return m_maze;
}
int MazeReader::getCols() const{
	return m_cols;
}
int MazeReader::getRows() const{
	return m_rows;
}
int MazeReader::getStartCol() const{
	return m_startCol;
}
int MazeReader::getStartRow() const{
	return m_startRow;
}

void MazeReader::readMaze()throw (MazeCreationException){
	std::string nextLine;

	try{
		std::cout<<"Reading Dimensions...\n";
		m_file>>m_rows;
		m_file>>m_cols;
		m_file>>m_startRow;
		m_file>>m_startCol;		
	}
	catch(std::exception& e){
		throw MazeCreationException("File read error: type mismatch or number format error\n\n");
	}

	if((m_rows < 1)||(m_cols<1)){
		throw MazeCreationException("Invalid maze: check bounds\n\n");
	}
	if((m_startRow<0)||(m_startCol<0)||(m_startRow>m_rows)||(m_startCol>m_cols)){
		throw MazeCreationException("Invalid maze: check start position\n\n");
	}


	try{
		std::cout<<"Reading maze...\n";
		m_maze = new char*[m_rows];
		for(int i = 0; i<m_cols; i++){
			m_maze[i] = new char[m_cols];	//we can't declare 2 deep, we have to one at a time
		}				//this is that ridiculous gotcha for 2D arrays		
		for(int i = 0; i< m_rows; i++){
			m_file>>nextLine;			
			for(int j = 0; j<m_cols; j++){
				m_maze[i][j]= char(nextLine[j]);
			}
		}	
	}
	catch(std::exception& e){
		throw MazeCreationException("Error: Maze not read\n\n");
	}
}
