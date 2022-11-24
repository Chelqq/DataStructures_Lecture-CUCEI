#ifndef QUEUE_H
#define QUEUE_H

#include "queuenode.h"

#include <iostream>
#include <exception>

template <class T>
class Queue{
private:
	
	QueueNode<T>* header;
	
	void copyAll(const Queue<T>&);
	
	void deleteAll();
	
public:
	
	class ExceptionQueue : public std::exception{
	private:
		std::string msg;
		
	public:
		explicit ExceptionQueue(const char* message) : msg(message){}
		
		explicit ExceptionQueue(const std::string& message) : msg(message) {}
		
		virtual ~ExceptionQueue() throw() {}
		
		virtual const char* what() const throw() {
			return msg.c_str();
		}
		
	};
	
	Queue();
	Queue(const Queue<T>&);
	
	~Queue();
	
	bool isEmpty();
	
	void enqueue(const T&);
	
	T dequeue();
	
	T getFront() const;
	
	Queue<T>& operator = (const Queue<T>&);
	
};

template <class T>
void Queue<T>::copyAll (const Queue<T>& l) {
	
	QueueNode<T>* aux(l.header -> getNext());
	QueueNode<T>* newNode;
	
	while(aux != l.header){
		
		try{
			if((newNode = new QueueNode<T>(aux -> getData())) == nullptr){
				throw ExceptionQueue("Memoria no disponible, copyAll.");
			}
		}catch (typename QueueNode<T>::ExceptionQueueNode ex){
			throw ExceptionQueue (ex.what());
		}
		
		newNode -> setPrev(header -> getPrev());
		newNode -> setNext(header);
		
		header -> getPrev() -> setNext(newNode);
		header -> setPrev(newNode);
		
		aux = aux -> getNext();
	}
}

template <class T>
void Queue<T>::deleteAll ( ) {
	
	QueueNode<T>* aux;
	
	while(header -> getNext() != header){
		
		aux = header -> getNext();
		header -> setNext(aux -> getNext());
		
		delete aux;
	}
	
	header -> setPrev(header);
}

template <class T>
Queue<T>::Queue ( ) : header(new QueueNode<T>){
	
	if(header == nullptr){
		throw ExceptionQueue("Memoria no disponible, inicializando queue.");
	}
	
	header -> setPrev(header);
	header -> setNext(header);
}

template <class T>
Queue<T>::Queue (const Queue<T>& q) : Queue() {
	copyAll(q);
}

template <class T>
Queue<T>::~Queue ( ) {
	
	deleteAll();
	delete header;
}

template <class T>
bool Queue<T>::isEmpty ( ) {
	return header -> getNext() == header;
}

template <class T>
void Queue<T>::enqueue (const T& e) {
	
	QueueNode<T>* aux;
	
	try{
		if((aux = new QueueNode<T>(e)) == nullptr){
			throw ExceptionQueue("Memoria no disponible, enqueue.");
		}
	}catch (typename QueueNode<T>::ExceptionQueueNode ex){
		throw ExceptionQueue(ex.what());
	}
	
	aux -> setPrev(header -> getPrev());
	aux -> setNext(header);
	
	header -> getPrev() -> setNext(aux);
	header -> setPrev(aux);
}

template <class T>
T Queue<T>::dequeue ( ) {
	
	if(isEmpty()){
		throw ExceptionQueue("insuficiencia de datos, dequeue.");
	}
	
	T result(header -> getNext() -> getData());
	
	QueueNode<T>* aux(header -> getNext());
	
	aux -> getPrev() -> setNext(aux -> getNext());
	aux -> getNext() -> setPrev(aux -> getPrev());
	
	delete aux;
	
	return result;
}

template <class T>
T Queue<T>::getFront ( ) const {
	
	if(isEmpty()){
		throw ExceptionQueue("insuficiencia de datos, getFront.");
	}
	
	return header -> getNext() -> getData();
}

template <class T>
Queue<T>& Queue<T>::operator = (const Queue<T>& q) {
	
	deleteAll();
	copyAll(q);
	
	return *this;
}


#endif
