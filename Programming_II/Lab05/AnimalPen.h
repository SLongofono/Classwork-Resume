/**
*	@file : AnimalPen.h
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This class is a child of the Stack class.  It is a customized class that stores pointers to the
*		FarmAnimal type.  It acts as a wrapper through which main can access a specialized stack of FarmAnimals.
*		I've included in this scenario, PVE is not required because we have hidden away any opportunity to pop/peek
*		an empty stack.  Since we don't know what type fo FarmAnimal the user will choose, we use casting on the way
*		in, and then check the m_sound on the way out to determine the type of animal being returned.
*/
#ifndef PEN
#define PEN
#include "Stack.h"
#include "FarmAnimal.h"

class AnimalPen: public Stack<FarmAnimal*>{

	public:

		AnimalPen();

		~AnimalPen();


	/*This method pushes a pointer to the argument passed onto te AnimalPen stack
	*@pre - a AnimalPen exists with accurate member variable (inherited M-size and m_top)
	*@post - casts the argument as a FarmAnimal* and calls the inherited push(T);
	*@return - void
	*/
		void addAnimal(FarmAnimal* a);


	/*This method removes the last pointer added from the stack and deletes it.  If empty, throws exception
	*(inherited, just use it from main).
	*@pre - a AnimalPen exists with accurate member variable (inherited M-size and m_top)
	*@post - calls the inherited method pop()
	*@return - void
	*/
		void releaseAnimal();


	/*This method checks the inherited m_size to see if te stack is empty.
	*@pre - a AnimalPen exists with accurate member variable (inherited M-size and m_top)
	*@post - calls the inherited method isEmpty()
	*@return - true if m_size <=0, false oterwise
	*/
		bool isPenEmpty();


	/*This method returns the last pointer added to the stack, but doesn't remove it.  If empty, throws
	*a PVE exception (inherited, just use it in main).
	*@pre - a AnimalPen exists with accurate member variable (inherited M-size and m_top)
	*@post - calls the inherited method peek()
	*@return - the last FarmAnimal* added to the stack
	*/
		FarmAnimal* peekAtNextAnimal();
		
		

};

#endif
