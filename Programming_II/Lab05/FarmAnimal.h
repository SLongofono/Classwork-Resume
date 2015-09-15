/**
*	@file : FarmAnimal.h
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This class is the base class from which all the farm animals derive.  It will contain
*	 only those members that all animals should have, and anything more specific will be left to
*	 define in the child classes.
*/

#ifndef ANIMAL
#define ANIMAL
#include <string>


class FarmAnimal{

	public:

	/*This is the constructor.
	*@pre - none
	*@post - instantiates an animal object, sets m_name and m_sound to the string"unset"
	*@return - none
	*/
		FarmAnimal();

	
	/*This method is a getter for the animal's name
	*@pre - an animal exists
	*@post - retrieves the m_name member variable
	*@return - the value of this.m_name
	*/
		std::string getName() const;
	

	/*This method is a getter for the animal's sound
	*@pre - an animal exists
	*@post - retrieves the m_sound member variable
	*@return - the value of this.m_sound
	*/
		std::string getSound() const;		


	/*This method sets the name for an animal
	*@pre - an animal exists
	*@post - sets m_name to the string argument passed
	*@return - void
	*/
		void setName(std::string name);


	/*This method sets the sound for an animal
	*@pre - an animal exists
	*@post - sets m_sound to the argument passed
	*@return - void
	*/
		void setSound(std::string sound);

	protected:
		std::string m_name;
		std::string m_sound;
};

#endif
