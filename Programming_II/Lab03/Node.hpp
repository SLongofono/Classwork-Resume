/*	Name: Stephen Longofono - 2776831
*	File name: Node.hpp
*	Date: 02-11-2015
*	Description: Implementation of the node template class
*/


template<class T>
Node<T>::Node(){
	
	m_next = nullptr;
	m_previous = nullptr;
	m_value = T();	//this is called at runtime, it is some default value for the type in question

}

template<class T>
Node<T>* Node<T>::getNext() const{
	return m_next;
}

template<class T>
Node<T>* Node<T>::getPrev() const{
	return m_previous;
}

template<class T>
void Node<T>::setNext(Node<T>* n){
	m_next = n;
}

template<class T>
void Node<T>::setPrev(Node<T>* n){
	m_previous =n;
}

template<class T>
T Node<T>::getValue() const{
	return m_value;
}

template<class T>
void Node<T>::setValue(T value){
	m_value = value;
}
