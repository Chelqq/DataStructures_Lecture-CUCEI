#ifndef NODE_H
#define NODE_H

#include "song.h"

template <class T>
class Node{
private:
	
	T data;
	Node* next;
	
public:
	
	Node();
	Node(const T&);
	
	T getData() const;
	Node* getNext() const;
	
	void setData(const T&);
	void setNext(Node*);
};

///Implementacion del nodo

template <class T>
Node<T>::Node ( ) : next(nullptr) { }

template <class T>
Node<T>::Node (const T& e) : data(e), next(nullptr) { }

template <class T>
T Node<T>::getData ( ) const {
	return data;
}

template <class T>
Node<T>* Node<T>::getNext ( ) const {
	return next;
}

template <class T>
void Node<T>::setData (const T& e) {
	data = e;
}
template <class T>
void Node<T>::setNext (Node* p) {
	next = p;
}
#endif
