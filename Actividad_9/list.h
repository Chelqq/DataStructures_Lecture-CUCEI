#ifndef LIST_H
#define LIST_H

#include <exception>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>

#include "node.h"

template <class T>
class List{
private:
	
	Node<T>* anchor;
	
	void copyAll(const List<T>&);
	
	bool isValidPos(Node<T>*) const;
	
public:
	
	typedef Node<T>* Position;
	
	class Exception : public std::exception{
	private:
		std::string msg;
		
	public:
		explicit Exception(const char* message) : msg(message){}
		
		explicit Exception(const std::string& message) : msg(message) {}
		
		virtual ~Exception() throw() {}
		
		virtual const char* what() const throw() {
			return msg.c_str();
		}
		
	};
	
	
	List();
	List(const List<T>&);
	
	~List();
	
	bool isEmpty() const;
	
	void insertData(Node<T>*, const T&);
	
	void deleteData(Node<T>*);
	
	Node<T>* getFirstPos() const;
	Node<T>* getLastPos() const;
	Node<T>* getPrevPos(Node<T>*) const;
	Node<T>* getNextPos(Node<T>*) const;
	
	Node<T>* findData(const T&) const;
	
	T retrieve(Node<T>*) const;
	
	std::string toString() const;
	
	void deleteAll();
	
	List<T>& operator = (const List<T>&);
	
	void writeToDisk(const std::string&);
	void readFromDisk(const std::string&);
	
};

///Implementacion de la lista

template <class T>
void List<T>::copyAll (const List<T>& l) {
	
	Node<T>* aux(l.anchor);
	Node<T>* last(nullptr);
	Node<T>* newNode;
	
	while(aux != nullptr){
		
		newNode = new Node<T>(aux->getData());
		
		if(last == nullptr){
			anchor = newNode;
		}
		else{
			last->setNext(newNode);
		}
		
		last = newNode;
		
		aux = aux->getNext();
	}
}

template <class T>
bool List<T>::isValidPos (Node<T>* p) const {
	
	Node<T>* aux(anchor);
	
	while(aux != nullptr){
		
		if(aux == p){
			return true;
		}
		
		aux = aux -> getNext();
	}
	
	return false;
}

template <class T>
List<T>::List ( ) : anchor(nullptr) { }

template <class T>
List<T>::List (const List<T>& l) : anchor(nullptr) {
	copyAll(l);
}

template <class T>
List<T>::~List ( ) {
	deleteAll();
}

template <class T>
bool List<T>::isEmpty ( ) const {
	return anchor == nullptr;
}

template <class T>
void List<T>::insertData (Node<T>* p, const T& e) {
	
	if(p != nullptr and !isValidPos(p)){
		throw Exception("Posicion invalida, InsertData");
	}
	
	Node<T>* aux(new Node<T>(e));
	
	if(aux == nullptr){
		throw Exception("Memoria no disponible, InsertData");
	}
	
	if(p == nullptr){ //Insertamos al principio de la lista
		aux->setNext(anchor);
		anchor = aux;;
	}
	else{ // Insert en cualquier otro lugar de la lista
		aux->setNext(p->getNext());
		p->setNext(aux);
	}
	
}

template <class T>
void List<T>::deleteData (Node<T>* p) {
	
	if(!isValidPos(p)){
		throw Exception("Posicion invalida, DeleteData.");
	}
	
	if(p == anchor){
		anchor = anchor -> getNext();
	}
	else{
		getPrevPos(p) -> setNext(p -> getNext());
	}
	
	delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos ( ) const {
	return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos ( ) const {
	
	if(isEmpty()){
		return nullptr;
	}
	
	Node<T>* aux(anchor);
	
	while(aux->getNext() != nullptr){
		aux = aux->getNext();
	}
	
	return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos (Node<T>* p) const {
	
	if(p == anchor){
		return nullptr;
	}
	
	Node<T>* aux(anchor);
	
	while(aux != nullptr and aux ->getNext() != p){
		aux = aux->getNext();
	}
	
	return aux;
}

template <class T>
Node<T>* List<T>::getNextPos (Node<T>* p) const {
	
	if(!isValidPos(p)){
		return nullptr;
	}
	
	return p->getNext();
}

template <class T>
Node<T>* List<T>::findData (const T& e) const {
	
	Node<T>* aux(anchor);
	
	while(aux != nullptr and aux-> getData() != e){
		aux = aux -> getNext();
	}
	
	return aux;
}

template <class T>
T List<T>::retrieve (Node<T>* p) const {
	
	if(!isValidPos(p)){
		throw Exception("Posicion Invalida, retrieve.");
	}
	
	return p->getData();
}

template <class T>
std::string List<T>::toString ( ) const {
	
	Node<T>* aux(anchor);
	std::string result;
	
	while(aux != nullptr){
		result += aux->getData().toString();
		
		aux = aux->getNext();
	}
	
	return result;
}

template <class T>
void List<T>::deleteAll ( ) {
	
	Node<T>* aux;
	
	while(anchor != nullptr){
		
		aux = anchor;
		
		anchor = anchor->getNext();
		
		delete aux;
	}
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l) {
	
	deleteAll();
	
	copyAll(l);
	
	return *this;
}

template <class T>
void List<T>::writeToDisk(const std::string& fileName){
	
	std::ofstream myFile;
	
	myFile.open(fileName, myFile.trunc/*ios_base::trunc*/);
	
	if(!myFile.is_open()){
		
		std::string message;
		message = "No se pudo abrir el archivo ";
		message += fileName;
		message += " para escritura, writeToDisk.";
		
		throw Exception(message);
	}
	
	Node<T>* aux;
	
	while(anchor != nullptr){
		aux = anchor;
		myFile << aux -> getData().getSong();
		anchor = anchor -> getNext();
	}
	
	myFile.close();
}

template <class T>
void List<T>::readFromDisk(const std::string& fileName){
	
	std::ifstream myFile;
	
	T myData;
	
	myFile.open(fileName);
	
	try{
		if(!myFile.is_open()){
			std::string message;
			message = "No se pudo abrir el archivo ";
			message += fileName;
			message += " para lectura, readFromDisk.";
		}
		
	} catch(Exception ex) {
		myFile.close();
		
		std::string message;
		message +=fileName;
		message += " : ";
		message += ex.what();
		message += ", readFromDisk";
		
		throw Exception (message);
	}
	
	deleteAll();
	
	
	try{
		while(myFile >> myData){ // myFile >> myData returna un falso o verdadero
			insertData(getLastPos(), myData);
		}
	} catch(Exception ex) {
		myFile.close();
		
		std::string message("Error durante la lectura del archivo.");
		
		message +=fileName;
		message += " : ";
		message += ex.what();
		message += ", readFromDisk";
		
		throw Exception (message);
	}
	
	myFile.close();
}
#endif
