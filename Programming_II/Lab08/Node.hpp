/**
*	@file : Node.hpp
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class implements the Node.h template class.
*/

template<typename T>
Node<T>::Node(){

	m_left = nullptr;
	m_right = nullptr;

}

template<typename T>
Node<T>::Node(const Node<T>& other){

	m_value = other.m_value;  //copy the value of the current node in other to this

	if(other.m_left != nullptr){  //if other has a left subtree, call the copy c on it
		m_left = new Node(*(other.m_left));
	}
	if(other.m_right != nullptr){//ditto with right subtree
		m_right = new Node(*(other.m_right));
	}
	//profit
}

template<typename T>
T Node<T>::getValue()const{

	return m_value;

}

template<typename T>
Node<T>* Node<T>::getRight() const{
	return m_right;
}

template<typename T>
Node<T>* Node<T>::getLeft() const{
	return m_left;
}


template<typename T>
void Node<T>::setValue(T value){
	m_value = value;
}

template<typename T>
void Node<T>::setLeft(Node<T>* left){
	m_left = left;
}

template<typename T>
void Node<T>::setRight(Node<T>* right){
	m_right = right;
}
