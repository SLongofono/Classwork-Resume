/**
*	@file : Cow.h
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This class is a child of the FarmAnimal class.  It has the narrower traits of producing milk and
*		bears appropriate methods for setting and getting the milk.  It inherits the public and
*		protected members of the FarmAnimal class
*/

#ifndef COW
#define COW
#include <string>
#include "FarmAnimal.h"

class Cow: public FarmAnimal{

	protected:
		
		double m_milkProduced;

	public:

	/*This constructor sets the animal's name to "Cow" and sound to "Moo" using the inherited setter methods
	*@pre - non
	*@post - calls this.setName("Cow"), this.setSound("Moo")
	*@return - none
	*/
		Cow();


	/*This method is a getter for the amount of milk this cow has produced
	*@pre - a Cow object exists and m_milkProduced has been initialized
	*@post - retrieves the m_milkProduced member variable
	*@return - the value of m_milkProduced
	*/
		double getMilkProduced() const;

	
	/*This method is a setter for the amount of milk this cow has produced
	*@pre - a Cow object exists
	*@post - takes in a double, and if >=0, sets m_milkProduced to that value.  Otherwise, sets it to 0;
	*@return - void
	*/
		void setMilkProduced(double gallons);
};

#endif
