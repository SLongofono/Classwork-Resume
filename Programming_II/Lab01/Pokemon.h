/**
*	@file : Pokemon.cpp
*	@author :  Stephen Longofono
*	@date : 2014.01.28
*	Purpose: Header Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H
#include <string> /*Allows filtering of input for userBuild method*/ 

class Pokemon{
	public:
	/**
	*@pre: none
	*@post: Constructor, to be called twice for each game.a 
	*@return: Pokemon object with zero for numerical members and "" for string members	
	*/
	Pokemon();

	/**
	*@pre: a Pokemon object with a value assigned to hp
	*@post: Retrieves hp for user feedback and the attack method
	*@return: an integer representing the pokemon's remaining hp
	*/
	int getHP() const;


	/**
	*@pre: a Pokemon object with a value assigned to attack
	*@post: Retrieves attack for the attack method
	*@return: an integer representing the pokemon's attack
	*/
	int getAttack() const;


	/**
	*@pre: a Pokemon object with a value assigned to defense
	*@post: Retrieves defense for the attack method
	*@return: an integer representing the pokemon's defense	
	*/
	int getDefense() const;


	/**
	*@pre: a Pokemon object with a non-zero value assigned to hp
	*@post: Retrieves the name for user feedback
	*@return: an integer representing the pokemon's remaining hp	
	*/
	std::string getName() const;

	/**
	*@pre: assumes a Pokemon exists and has its hp initialized to any non-null value
	*@post: Used to decrement a Pokemon's hp by the specified amount.  This will not prevent 
	*negative value.
	*@return: changes the hp, does not otherwise modify
	*/
	void reduceHP(int amount);

	/**
	*@pre: a Pokemon object and a valid string or char array
	*@post: Assigns the argument to m_name
	*@return: void	
	*/
	void setName(std::string nameIn);

	/**
	*@pre: a Pokemon object and an integer>0
	*@post: Assigns the argument to m_hp
	*@return: void
	*/
	void setHP(int life);

	/**
	*@pre: a Pokemon object and an integer in []
	*@post: Assigns the argument to m_name
	*@return: void	
	*/
	void setAttack(int attackLvl);
	
	/**
	*@pre: a Pokemon object with a value assigned to defense
	*@post: Assigns the argument to m_name
	*@return: void	
	*/
	void setDefense(int defenseLvl);
	


	private:

	int m_attackLevel;
	int m_defenseLevel;
	int m_hp;
	std::string m_name;//included std to show I have experienced data hiding

	
};

#endif
