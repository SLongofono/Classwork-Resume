Lab09: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o
	g++ -g -Wall -std=c++11 main.o MazeReader.o MazeCreationException.o Position.o MazeWalker.o -o Lab09

main.o: main.cpp MazeReader.h MazeCreationException.h MazeWalker.h
	g++ -g -Wall -std=c++11 -c main.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -Wall -std=c++11 -c MazeCreationException.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -Wall -std=c++11 -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp Position.h MazeReader.h
	g++ -g -Wall -std=c++11 -c MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -g -Wall -std=c++11 -c Position.cpp
