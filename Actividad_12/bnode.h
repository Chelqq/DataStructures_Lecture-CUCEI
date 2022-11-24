#ifndef BNODE_H
#define BNODE_H

#include <exception>
#include <string>

template <class T>
class BNode{
private:
	
	T* dataPtr;
	BNode* left;
	BNode* right;
	
public:
	
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
	
	BNode();
	BNode(const T&);
	
	~BNode();
	
	T*& getDataPtr() ;
	T getData() const;
	BNode*& getLeft();
	BNode*& getRight();
	
	void setDataPtr(T*&);
	void setData(const T&);
	void setLeft(BNode*&);
	void setRight(BNode*&);
	
};

template <class T>
BNode<T>::BNode ( ) : dataPtr(nullptr), left(nullptr), right(nullptr) { }

template <class T>
BNode<T>::BNode (const T& e) : dataPtr(new T(e)), left(nullptr), right(nullptr){
	
	if(dataPtr == nullptr){
		throw Exception("Memoria insuficiente, creando nodo.");
	}
}

template <class T>
BNode<T>::~BNode ( ) {
	delete dataPtr;
}

template <class T>
T*& BNode<T>::getDataPtr ( )  {
	return dataPtr;
}

template <class T>
T BNode<T>::getData ( ) const {
	
	if(dataPtr == nullptr){
		throw Exception("Dato Inexistente, getData.");
	}
	
	return *dataPtr;
}

template <class T>
BNode<T>*& BNode<T>::getLeft ( ) {
	return left;
}

template <class T>
BNode<T>*& BNode<T>::getRight ( ) {
	return right;
}

template <class T>
void BNode<T>::setDataPtr (T*& p) {
	dataPtr = p;
}

template <class T>
void BNode<T>::setData (const T& e) {
	
	if(dataPtr == nullptr){
		if((dataPtr = new T(e)) == nullptr){
			throw Exception("Memoria no disponible, setData.");
		}
	}
	else{
		*dataPtr = e;
	}
}

template <class T>
void BNode<T>::setLeft (BNode*& p) {
	left = p;
}

template <class T>
void BNode<T>::setRight (BNode*& p) {
	right = p;
}

#endif



