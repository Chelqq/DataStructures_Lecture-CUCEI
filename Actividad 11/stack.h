#ifndef STACK_H
#define STACK_H

#include "stacknode.h"

#include <iostream>
#include <exception>

template <class T>
class Stack{
private:
	
	StackNode<T>* anchor;
	
	void copyAll(const Stack<T>&);
	
	void deleteAll();
	
public:
	
	class ExceptionStack : public std::exception{
	private:
		std::string msg;
		
	public:
		explicit ExceptionStack(const char* message) : msg(message){}
		
		explicit ExceptionStack(const std::string& message) : msg(message) {}
		
		virtual ~ExceptionStack() throw() {}
		
		virtual const char* what() const throw() {
			return msg.c_str();
		}
		
	};
	
	Stack();
	Stack(const Stack<T>&);
	
	~Stack();
	
	bool isEmpty() const;
	
	void push(const T&);
	
	T pop();
	
	T getTop() const;
	
	Stack<T>& operator = (const Stack<T>&);	
};


///Implementacion de la pila

template <class T>
void Stack<T>::copyAll(const Stack<T>& s){
	
	StackNode<T>* aux(s.anchor);
	StackNode<T>* last(nullptr);
	StackNode<T>* newNode;
	
	while(aux != nullptr){
		
		if((newNode = new StackNode<T>(aux -> getData())) == nullptr){
			throw ExceptionStack("Memoria no disponible, copyAll");
		}
		
		if(last == nullptr){
			anchor = newNode;
		}
		else{
			last -> setNext(newNode);
		}
		
		last = newNode;
		
		aux = aux -> getNext();
	}
}

template <class T>
void Stack<T>::deleteAll(){
	
	StackNode<T>* aux;
	
	while(anchor != nullptr){
		
		aux = anchor;
		anchor = anchor -> getNext();
		
		delete aux;
	}
}

template <class T>
Stack<T>::Stack() : anchor(nullptr) { }

template <class T>
Stack<T>::Stack(const Stack<T>& s) : anchor(nullptr) { 
	copyAll(s);
}

template <class T>
Stack<T>::~Stack(){ 
	deleteAll();
}

template <class T>
bool Stack<T>::isEmpty() const {
	return anchor == nullptr;
}

template <class T>
void Stack<T>::push(const T& e){
	
	StackNode<T>* aux(new StackNode<T>(e));
	
	if(aux == nullptr){
		throw ExceptionStack("Memoria no disponible, push");
	}
	
	aux -> setNext(anchor);
	anchor = aux;
}

template <class T>
T Stack<T>::pop(){
	
	if(anchor == nullptr){
		throw ExceptionStack("insuficiencia de datos, pop");
	}
	
	T result(anchor -> getData());
	
	StackNode<T>* aux(anchor);
	
	anchor = anchor -> getNext();
	
	delete aux;
	
	return result;
}

template <class T>
T Stack<T>::getTop() const{
	
	if(anchor == nullptr){
		throw ExceptionStack("Insuficiencia de datos, getTop");
	}
	
	return anchor -> getData();
}

template <class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& s){
	
	deleteAll();
	copyAll(s);
	
	return *this;
}

#endif
