/*	Name: Stephen Longofono - 2776831
*	File name: DoubleLinkedList.cpp
*	Date: 02-11-2015
*	Description: Implementation of the DoubleLinkedList class
*/

#include "Node.h"
#include <iostream>

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
	m_size = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	if(isEmpty()){
		m_front = nullptr;
		m_back = nullptr;
	}
	else{
		Node<T>* n = m_front;
		while(m_front!=m_back){ //while nodes exist
			n = m_front->getNext();
			delete (m_front);
			m_front = n;
		}
		delete (m_front);
		m_front = nullptr;
		m_back = nullptr;
	}
}

template<class T>
bool DoubleLinkedList<T>::isEmpty() const{
	return(m_size==0);
}

template<class T>
int DoubleLinkedList<T>::size() const{
	return m_size;
}

template<class T>
void DoubleLinkedList<T>::pushFront(T value){
	if(isEmpty()){
		Node<T>* n = new Node<T>();
		n->setValue(value);
		m_front = n;
		m_back = n;
		m_size++;
	}
	else{
		Node<T>* n = new Node<T>();
		n->setValue(value);
		n->setNext(m_front);	//sets the new node's next to point at the old front node
		m_front->setPrev(n);	//old front node looks back to new node
		m_front= n;		//sets the m_front pointer to look at the new node
		m_size++;
	}
}

template<class T>
void DoubleLinkedList<T>::pushBack(T value){
	if(isEmpty()){
		Node<T>* n = new Node<T>();
		n->setValue(value);
		m_front = n;
		m_back = n;
		m_size++;
	}	
	else{
		Node<T>* n = new Node<T>();
		n->setValue(value);	
		n->setPrev(m_back);	//sets the new node's m_previous to point to the old rear node
		m_back->setNext(n);	//old node now points to new node instead of null
		m_back = n;		//sets the m_back pointer to look at the new node
		m_size++;	
	}
}

template<class T>
void DoubleLinkedList<T>::printList() const{
	
	if(isEmpty()){
		std::cout<<"List is empty.\n";
	}
	else{
		Node<T>* temp = m_front;		//temporary node to step through list
		while(temp!=m_back){			//until temp points to the last node
			std::cout<<temp->getValue()<<",";	
			temp = temp->getNext();
		}	
		std::cout<<temp->getValue();	//print the value of the last node
	}
}

template<class T>
Node<T>* DoubleLinkedList<T>::find(T value) const{
	if(isEmpty()){
		return nullptr;
	}
	else{
		Node<T>* n = m_front;
		while(n!=m_back){
			if(n->getValue()==value){
				return n;
			}
			n = n->getNext();
		}
		if(n->getValue()==value){
			return n;
		}
	}
	return nullptr;
}

template<class T>
bool DoubleLinkedList<T>::remove(T value)throw(std::runtime_error){
	if(isEmpty()){
		m_front = nullptr;
		m_back = nullptr;
	}
	else{
		Node<T>* n = find(value);
		if(n == nullptr){
			throw(std::runtime_error(" could not be removed from list\n"));
			return false;
		}
		else if(m_front==m_back){
			delete (m_front);
			m_front = nullptr;
			m_back = nullptr;
			m_size--;
			return true;
		}
		else if(n == m_front){
			m_front = m_front->getNext();
			m_front->setPrev(nullptr);
			delete(n);
			m_size--;
			return true;
		}
		else if(n == m_back){
			m_back = m_back->getPrev();
			m_back->setNext(nullptr);
			delete(n);
			m_size--;
			return true;
		}//working before here
		else{	
			(n->getNext())->setPrev(n->getPrev());
			(n->getPrev())->setNext(n->getNext());
			delete(n);
			m_size--;
			return true;
		}
	}
	return false;
}

template<class T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue)throw(std::runtime_error){
	if(isEmpty()){
		Node<T>* n = new Node<T>();
		n->setValue(newValue);
		m_front = n;
		m_back = n;
		m_size++;
	}
	else{
		Node<T>* n = find(listValue);
		if(n==nullptr){		//if not found 
			throw(std::runtime_error(" could not be inserted\n"));
		}
		else{
			if(m_front==m_back){			//if only one item in list, use pushFront
				pushFront(newValue);
			}
			else if(n == m_front){		//if the found node is in front
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				m_front->setPrev(temp);
				temp->setNext(m_front);
				m_front = temp;
				m_size++;
			}
			else if(n==m_back){		//if the found node is in back
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				temp->setPrev(m_back->getPrev());	//temp looks back to the 2nd to last
				temp->setNext(m_back);			//temp looks ahead to m_back
				m_back->setPrev(temp);			//back looks back to temp
				(temp->getPrev())->setNext(temp);	//set the node before temp to look 										ahead to temp
				m_size++;
			}
			else{
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				temp->setNext(n);		//temp looks ahead to n
				temp->setPrev(n->getPrev());	//temp looks back to the node before n
				(n->getPrev())->setNext(temp);	//set the node before n to look ahead to temp
				n->setPrev(temp);		//set n to look back to temp
				
				m_size++;
			}
		}
	}
}

template<class T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue)throw(std::runtime_error){
	if(isEmpty()){
		Node<T>* n = new Node<T>();
		n->setValue(newValue);
		m_front = n;
		m_back = n;
		m_size++;
	}
	else{
		Node<T>* n = find(listValue);
		if(n==nullptr){		//if not found 
			throw(std::runtime_error(" could not be inserted\n"));
		}
		else{
			if(m_front==m_back){			//if only one item in list, use pushBack
				pushBack(newValue);
			}
			else if(n == m_front){		//if the found node is in front
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				temp->setNext(m_front->getNext());	//temp looks ahead to the 2nd node
				temp->setPrev(m_front);		//temp looks back to m_front
				(temp->getNext())->setPrev(temp);//2nd node looks back to temp
				m_front->setNext(temp); //m_front looks ahead to temp
				m_size++;
				
			}
			else if(n==m_back){		//if the found node is in back
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				m_back->setNext(temp);
				temp->setPrev(m_back);
				m_back = temp;
				m_size++;
			}
			else{
				Node<T>* temp = new Node<T>();
				temp->setValue(newValue);
				temp->setPrev(n);	//temp looks back to n
				temp->setNext(n->getNext());//temp looks ahead to the node behing n
				(temp->getNext())->setPrev(temp);//node behind n looks back to temp
				n->setNext(temp);//n looks ahead to temp
				m_size++;
			}
		}
	}
}
