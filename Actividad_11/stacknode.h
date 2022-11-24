#ifndef STACKNODE_H
#define STACKNODE_H

template <class T>
class StackNode{
private:
	
	T data;
	StackNode* next;
	
public:
	
	StackNode();
	StackNode(const T&);
	
	T getData() const;
	StackNode* getNext() const;
	
	void setData(const T&);
	void setNext(StackNode*);
};

///Implementacion del nodo

template <class T>
StackNode<T>::StackNode() : next(nullptr) { }

template <class T>
StackNode<T>::StackNode(const T& e) : data(e), next(nullptr) { }
	
template <class T>
T StackNode<T>::getData() const {
	return data;
}

template <class T>
StackNode<T>* StackNode<T>::getNext() const {
	return next;
}

template <class T>
void StackNode<T>::setData(const T& e) {
	data = e;
}

template <class T>
void StackNode<T>::setNext(StackNode* p) {
	next = p;
}

#endif
