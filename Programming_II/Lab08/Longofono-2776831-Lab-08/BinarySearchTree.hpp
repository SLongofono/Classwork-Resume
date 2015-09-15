/**
*	@file : BinarySearchTree.hpp
*	@author :  Stephen Longofono
*	@date : 04-10-2015
*	Purpose: This class implements the BinarySearchTree template class.
*/


template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
	m_root = nullptr;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){

	m_root = new Node<T>(*(other.m_root));
						
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	deleteTree(m_root);
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone(){

	BinarySearchTree<T>* temp = new BinarySearchTree<T>(*(this));
	return temp;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const{

	return(m_root == nullptr);

}

template<typename T>
bool BinarySearchTree<T>::add(T value){//this method calls itself recursively, so we need this
					// wrapper so it can still be accessed from main
	return(add(value, m_root));
	
}

template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree){
	bool tracker = true;
	if(m_root == nullptr){
		Node<T>* n = new Node<T>();
		n->setValue(value);
		m_root = n;
		return true;
	}
	else{
		if(value < (subtree->getValue())){

			if(subtree->getLeft() != nullptr){//call recursively on LST
				tracker = add(value, subtree->getLeft());
			}
			else{
				Node<T>* n = new Node<T>();
				n->setValue(value);
				subtree->setLeft(n);
				return true;
			}
		}
		if(value >= subtree->getValue()){
	
			if(subtree->getRight() != nullptr){//call recursively on RST
				tracker = add(value, subtree->getRight());
			} 
			else{
				Node<T>* n = new Node<T>();
				n->setValue(value);
				subtree->setRight(n);
				return true;
			}
		}
	}
	return tracker;

}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree){
	
	if(subtree->getLeft() != nullptr){//if there is a left subtree
		deleteTree(subtree->getLeft());
	}
	if(subtree->getRight() != nullptr){//ditto for right
		deleteTree(subtree->getRight());
	}
	//at this point, there are no children of the current node, so we can delete and 
	//return to the previous recursive call
	delete (subtree);
	subtree = nullptr;
	return;

}

template<typename T>
void BinarySearchTree<T>::printTree(Order order) const{//We have this method so we can call the other
	if(isEmpty()){				//recursively from main
		std::cout<<"Tree empty\n";
	}
	else{
		printTree(m_root, order);
	}
	std::cout<<"\n";
}

template<typename T>
void BinarySearchTree<T>::sortedPrint() const{
	printTree(IN_ORDER);
}

template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const{
	if(subtree == nullptr){
		return;
	}
	else{
		if(order == PRE_ORDER){
			std::cout<<(subtree->getValue())<<" ";
			printTree(subtree->getLeft(), PRE_ORDER);
			printTree(subtree->getRight(), PRE_ORDER);
		}
		else if(order == POST_ORDER){
			printTree(subtree->getLeft(), POST_ORDER);
			printTree(subtree->getRight(), POST_ORDER);
			std::cout<<(subtree->getValue())<<" ";
		}
		else{
			printTree(subtree->getLeft(), IN_ORDER);
			std::cout<<(subtree->getValue())<<" ";
			printTree(subtree->getRight(), IN_ORDER);
		}
	}
	return;
}

template<typename T>
T BinarySearchTree<T>::search(T value)const throw(ValueNotFoundException){
	T temp;	
	try{
		temp = search(value, m_root);
		return temp;
	}
	catch(std::exception e){
		throw ValueNotFoundException("The value is not in the tree\n");
	}
	return temp;
}

template<typename T>
T BinarySearchTree<T>::search(T value, Node<T>* subtree) const throw(ValueNotFoundException){
	T temp;	
	if(subtree == nullptr){
		throw ValueNotFoundException("The value is not in the tree\n");//first, make sure we aren't at a dead end
	}
	else if((subtree->getValue())==value){//then, check current root value
		return value;
	}
	if(value < (subtree->getValue())){// try to check the left side
		try{
			temp = search(value, subtree->getLeft());//this may throw and exception, which will
						//continue upstream and be caught immdeiately above
		}
		catch(std::exception e){
			throw ValueNotFoundException("The value is not in the tree\n");		
		}
	}
	else{//check the right if necessary
		if(!((subtree->getValue())< value)){//the value is not in the left, so if it is not >= root,
							//then it isn't here
			throw ValueNotFoundException("The value is not in the tree\n");
		}
		try{
			temp = search(value, subtree->getRight());
		}
		catch(std::exception e){//at this point, throw the exception upstream because we have
						//exhausted the tree
			throw ValueNotFoundException("The value is not in the tree\n");
		}
	
	}
	return temp;
}





