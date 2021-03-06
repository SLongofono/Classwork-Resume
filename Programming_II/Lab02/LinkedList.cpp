/*	Name: Stephen Longofono - 2776831
*	File name: LinkedList.cpp
*	Date: 02-04-2015
*	Description: Implementation of the LinkedList class.
*/

#include "Node.h"
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
	m_front = nullptr;
	m_size = 0;
}

LinkedList::~LinkedList(){
	
	while(removeFront()){};	//removeFront returns true unless the list is empty
	m_front = nullptr;

}

bool LinkedList::isEmpty() const{
	return (0==m_size);
}

int LinkedList::size() const{
	return m_size;
}

void LinkedList::addFront(int value){
	Node* n = new Node; 	//this node should now have m_value of 0 and m_next as nullptr
	n->setValue(value);	//set m_value of the node to the value passed
	n-> setNext(m_front);	//n looks at the old front
	m_front = n;		//set the front of the  list to point to n
	m_size++;		//increment the size of the LinkedList	
	n = nullptr;		//housekeeping
}

void LinkedList::addBack(int value){
	Node* n = new Node;
	n->setValue(value);
	if(isEmpty()){
		m_front = n;
		m_size++;
		n = nullptr;
	}
	else if(m_front == getBack()){
		m_front->setNext(n);
		m_size++;
		n = nullptr;
	}
	else{
		bool notDoneLooking = true;	//for the while loop
		Node* stepper = m_front;	//this pointer will change as we comb through the list
		while(notDoneLooking){
		
			if(nullptr != stepper->getNext()){	//check the current Node's pointer value
				stepper = stepper->getNext();	//if !null, set stepper to look at the next 									Node
			}
			else{					//if stepper points to a Node that points at 										null,we are at the end, add the new 										node to the back
				notDoneLooking = false; 	//break loop
				stepper-> setNext(n);		//the last  node now looks at the new node
				m_size++;			//the new node should already be initialized 										to null
				n = nullptr;
			}
			
		}
	}
}

void LinkedList::printList()const{
	
	if(isEmpty()){
		std::cout<<"List empty.\n";
	}
	else if(m_front == getBack()){//if there is only one Node..
		std::cout<<m_front->getValue();
	}
	else{
		Node* temp = m_front;			//temp pointer
		while(temp->getNext()!= nullptr){		//while temp is not pointing the last Node
			
			std::cout<<temp->getValue()<<" ";	//print the value of the current node
			temp = temp->getNext();		//look at the next node

		}
		std::cout<<temp->getValue()<<"\n";	//since we are at the last entry, just display the value

	}
}

bool LinkedList::removeFront(){
	if(isEmpty()){
		return false;
	}
	else if(m_front == getBack()){//if there is only 1 Node (when front Node is the back Node)
		delete m_front;
		m_front = nullptr;
		m_size--;
		return true;
	}
	else{

		Node* n = m_front->getNext();		//temp pointer points to the second value
		delete m_front;				//delete the object m_fron is looking at (old front 								  node)
		m_front = n;				//m_front now looks at the new front Node
		n = nullptr;				//housekeeping
		m_size--;				
	}
	return true;
}

bool LinkedList::removeBack(){
	if(isEmpty()){
		return false;
	}
	else if(m_front == getBack()){ //if there is only one element in the list, just delete it and be done.  Note that when this is the case, the last and the first item are the same Node.
		delete m_front;
		m_size--;
		m_front = nullptr;
		return true;
				
	}
	else{

		Node* previous = nullptr;	//this will point to the last non-null Node (second to last)
		bool notDoneLooking = true;	//for the while loop
		Node* stepper = m_front;	//this pointer will change as we comb through the list
		while(notDoneLooking){
		
			if(nullptr != stepper->getNext()){	//check the current Node's pointer value
				previous = stepper;		//keeps track of the second to last
				stepper = stepper->getNext();	//if !null, set stepper to look at the next 									  Node
			}
			else{					//if stepper points to a Node that points at 									  null,we are at the end
				notDoneLooking = false; 	//break loop
				previous-> setNext(nullptr);	//new last Node now points to nullptr
				delete stepper;
				stepper = nullptr;		//housekeeping
				m_size--;
			
			}
		
		}//end while
	
	}//end empty wrapper
}

bool LinkedList::search(int value) const{
	if(isEmpty()){
		return false;
	}
	else{
		Node* stepper = m_front;		
		while(stepper->getNext()!=nullptr){	//set up to avoid having to always check each Node
			if(stepper->getValue() == value){ //checks all values except the last one
				return true;
			}
			else{
				stepper = stepper->getNext();
			}
		}
		if(stepper->getValue() == value){  //one last check
			return true;
		}
	}
	return false;
}

//##############################HELPERS#############################

Node* LinkedList::getBack() const{
	if(isEmpty()){
		return nullptr;
	}
	else{
		bool notDone = true;
		Node* stepper = m_front;
		while(notDone){
			
			if(stepper->getNext() != nullptr){//if stepper is pointing at a Node that isn't 						pointing to null, look at the next Node			
				stepper = stepper->getNext();
			}
			else{
				return stepper;
				notDone = false;
			}
			
		}//end while
	}
	return nullptr;
}







