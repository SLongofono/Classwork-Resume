/**
*	@file : CyberChicken.h
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This class is a child of the FarmAnimal class.  It has the narrower traits of eggs and
*		bears appropriate methods for setting and getting the eggs.  It inherits the public and
*		protected members of the FarmAnimal class and the Chicken class.
*	########NOTE - The setCyberEggs() method does not filter input
*/

#ifndef CCHIX
#define CCHIX
#include <string>
#include "FarmAnimal.h"
#include "Chicken.h"

class CyberChicken: public Chicken{

	public:
		
	/*This constructor sets the animal's name to "Cyber Chicken" and sound to "Resistance is futile" using
	* inherited setter methods from the FarmAnimal class
	*@pre - none
	*@post - calls this.setName("Cyber Chicken"), this.setSound("Resistance is futile")
	*@return - none
	*/
		CyberChicken();

	/*This method is a getter for the amount of eggs this cyberchicken has
	*@pre - a CyberChicken object exists and m_eggs has been initialized
	*@post - retrieves the m_eggs member variable inherited from the chicken class
	*@return - the value of m_eggs
	*/
		int getCyberEggs() const;


	/*This method is a setter for the amount of eggs this cyberchicken has
	*@pre - a CyberChicken object exists
	*@post - takes in a double, and if >=0, sets m_milkProduced to that value.  Otherwise, sets it to 0;
	*@return - void
	*/
		void setCyberEggs(int eggs);

};

#endif
