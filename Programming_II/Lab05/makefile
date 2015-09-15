Lab05: main.o PreconditionViolationException.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o
	g++ -g -Wall -std=c++11 main.o PreconditionViolationException.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o -o Lab05

main.o: main.cpp StackInterface.h Stack.h PreconditionViolationException.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h AnimalPen.h
	g++ -g -Wall -std=c++11 -c main.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -Wall -std=c++11 -c FarmAnimal.cpp

Cow.o: FarmAnimal.h Cow.h Cow.cpp
	g++ -g -Wall -std=c++11 -c Cow.cpp

Chicken.o: FarmAnimal.h Chicken.h Chicken.cpp
	g++ -g -Wall -std=c++11 -c Chicken.cpp

CyberChicken.o: Chicken.h CyberChicken.h CyberChicken.cpp
	g++ -g -Wall -std=c++11 -c CyberChicken.cpp

AnimalPen.o: StackInterface.h Stack.h AnimalPen.h AnimalPen.cpp
	g++ -g -Wall -std=c++11 -c AnimalPen.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11  -c PreconditionViolationException.cpp

clean:
	rm *.o main
	clean done 
