Lab02: main.o Node.o LinkedList.o
	g++ -g -std=c++11 Node.o main.o LinkedList.o -o Lab02

main.o: main.cpp Node.h LinkedList.h
	g++ -g -std=c++11 -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -g -std=c++11 -c LinkedList.cpp


Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -c Node.cpp


clean:
	rm *.o main
	clean done
