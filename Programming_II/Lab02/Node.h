/*	Name: Stephen Longofono - 2776831
*	File name: Node.h
*	Date: 02-04-2015
*	Description: This class is a generic container for use in our linked list.  Each will be 
*	operated on like a stack box in that it will hold a value and a pointer.  The pointer
*	allows multiple nodes to be connected in a structure.  By defining each Node to
*	initialize as zero and nullptr for value and pointer respectively, we have a way to
*	determine where we are in the structure at any given time.
*/

#ifndef NODE_H
#define NODE_H

class Node{

	public:
		
	/*
	* This is the constructor
	* @pre - none
	* @post - creates a Node object
	* @return - none
	*/ 
	Node();

	/* This is a setter for the value of the Node
	* @pre - Assumes a valid integer value
	* @post - This sets the m_value of the Node to the argument valIn 
	* @return - void
	*/
	void setValue(int valIn);


	/* This is a setter for the pointer of the Node.  The name of the argument implies that this
	* method gets called when a Node is added.
	* @pre - Assumes that the the Node pointer argument points to an initialized Node object or null
	* @post - Sets this Node's m_next to point to the Node passed in
	* @return - void
	*/
	void setNext(Node* prev);


	/* This is a getter for the value of this Node's m_next pointer
	* @pre - Assumes that this node is initialized and that m_next points to a valid object or null
	* @post - Gets m_next, the pointer for this node
	* @return - Returns the pointer m_next
	*/
	Node* getNext() const;


	/* This is a getter for the value of this Node
	* @pre - Assumes this is a properly initialized Node (non-empty value)
	* @post - Gets m_value, the value of this Node
	* @return - Returns the int m_value
	*/

	int getValue()	const;

	private:

	int m_value;	//value for this Node
	
	Node* m_next;	//pointer for this Node

};//end class


#endif
