Lab01: main.o Dice.o Pokemon.o Colosseum.o
	g++ -std=c++11 -Wall main.o Dice.o Colosseum.o Pokemon.o -o Lab01

main.o: main.cpp Dice.h Pokemon.h Colosseum.h
	g++ -std=c++11 -Wall -c main.cpp

Dice.o: Dice.cpp Dice.h
	g++ -std=c++11 -Wall -c Dice.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -std=c++11 -Wall -c Pokemon.cpp

Colosseum.o: Colosseum.cpp Colosseum.h Dice.h Pokemon.h
	g++ -std=c++11 -Wall -c Colosseum.cpp
clean: 
	rm *.o Lab01
	clean done

