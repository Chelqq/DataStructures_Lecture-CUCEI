#ifndef BTREE_H
#define BTREE_H

#include "bnode.h"

#include <exception>
#include <string>

template <class T>
class BTree{
private:
	
	BNode<T>* root;
	
	void copyAll(const BTree<T>&);
	void copyAll(BNode<T>*&, BNode<T>*);
	
	void insertData(BNode<T>*&, const T&);
	
	BNode<T>*& findData(BNode<T>*&, const T&);
	
	BNode<T>*& getLowest(BNode<T>*&);
	BNode<T>*& getHighest(BNode<T>*&);
	
	void parsePreOrder(BNode<T>*&);
	void parseInOrder(BNode<T>*&);
	void parsePostOrder(BNode<T>*&);
	
	void deleteAll(BNode<T>*&);
	
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
	
	BTree();
	BTree(const BTree&);
	
	~BTree();
	
	BNode<T>*& getRoot();
	
	bool isEmpty() const;
	
	void insertData(const T&);
	
	void deleteData(BNode<T>*&);
	
	T retrieve(BNode<T>*&) const;
	
	BNode<T>*& findData(const T&);
	
	BNode<T>*& getLowest();
	BNode<T>*& getHighest();
	
	bool isLeaf(BNode<T>*&) const;
	
	int getHeight();
	int getHeight(BNode<T>*&);
	
	void parsePreOrder();
	void parseInOrder();
	void parsePostOrder();
	
	void deleteAll();
	
	BTree& operator = (const BTree&);
	
};

template <class T>
void BTree<T>::copyAll(const BTree<T>& t) {
	copyAll(root, t.root);
}

template <class T>
void BTree<T>::copyAll(BNode<T>*& nR, BNode<T>* cR) {
	
	if(cR == nullptr) {
		return;
	}
	
	if((nR = new BNode<T>(cR -> getData())) == nullptr) {
		throw Exception("Memoria Insuficiente, copyAll");
	}
	
	copyAll(nR -> getLeft() ,cR -> getLeft());
	copyAll(nR -> getRight() ,cR -> getRight());
}

template <class T>
BTree<T>::BTree ( ) : root(nullptr) { }

template <class T>
BTree<T>::BTree (const BTree& t) : root(nullptr){
	copyAll(t);
}

template <class T>
BTree<T>::~BTree ( ) {
	deleteAll();
}

template <class T>
BNode<T>*& BTree<T>::getRoot(){
	return root;
}

template <class T>
bool BTree<T>::isEmpty ( ) const {
	return root == nullptr;
}

template <class T>
void BTree<T>::insertData (const T& e) {
	insertData(root, e);
}

template <class T>
void BTree<T>::insertData (BNode<T>*& r, const T& e) {
	
	if(r == nullptr){
		try{
			if((r = new BNode<T>(e)) == nullptr){
				throw Exception("Memoria no disponible, InsertData.");
			}
		}catch(typename BNode<T>::Exception ex) {
			throw Exception(ex.what());
		}
	}
	else{
		if(e < r -> getData()){
			insertData(r -> getLeft(), e);
		}
		else{
			insertData(r -> getRight(), e);
		}
	}
}

template <class T>
void BTree<T>::deleteData (BNode<T>*& e) {
	
	if(root == nullptr or e == nullptr) {
		throw Exception("Insuficiencia de datos, deleteData");
	}
	
	if(isLeaf(e)) {
		delete e;
		e = nullptr;
	}
	else {
		if(e -> getLeft() != nullptr) {
			e -> setData((getHighest(e -> getLeft())) -> getData());
			deleteData((getHighest(e -> getLeft())));
		}
		else {
			e -> setData((getLowest(e -> getRight())) -> getData());
			deleteData((getLowest(e -> getRight())));
		}
	}
}

template <class T>
T BTree<T>::retrieve (BNode<T>*& r) const {
	
	if(r == nullptr){
		throw Exception("Elemento inexistente, retrieve.");
	}
	
	return r -> getData();
}

template <class T>
BNode<T>*& BTree<T>::findData (const T& e) {
	return findData(root, e);
}

template <class T>
BNode<T>*& BTree<T>::findData (BNode<T>*& r, const T& e) {
	
	if(r == nullptr or r -> getData() == e){
		return r;
	}
	
	if(e < r -> getData()){
		return findData(r -> getLeft(), e);
	}
	
	return findData(r -> getRight(), e);
}

template <class T>
BNode<T>*& BTree<T>::getLowest ( ) {
	return getLowest(root);
}

template <class T>
BNode<T>*& BTree<T>::getLowest (BNode<T>*& r) {
	
	if(r == nullptr or r -> getLeft() == nullptr){
		return r;
	}
	
	return getLowest(r -> getLeft());
}

template <class T>
BNode<T>*& BTree<T>::getHighest ( ) {
	return getHighest(root);
}

template <class T>
BNode<T>*& BTree<T>::getHighest (BNode<T>*& r) {
	
	if(r == nullptr or r -> getRight() == nullptr){
		return r;
	}
	
	return getHighest(r -> getRight());
}

template <class T>
bool BTree<T>::isLeaf (BNode<T>*& r) const {
	return r != nullptr and r -> getLeft() == r -> getRight();
}

template <class T>
int BTree<T>::getHeight ( ) {
	return getHeight(root);
}

template <class T>
int BTree<T>::getHeight (BNode<T>*& r) {
	
	if(r == nullptr){
		return 0;
	}
	
	int lH(getHeight(r -> getLeft()));
	int rH(getHeight(r -> getRight()));
	
	return (lH > rH ? lH : rH) + 1;
}

template <class T>
void BTree<T>::parsePreOrder ( ) {
	parsePreOrder(root);
}

template <class T>
void BTree<T>::parsePreOrder (BNode<T>*& r) {
	
	if(r == nullptr){
		return;
	}
	
	std::cout << r -> getData() << ", ";
	
	parsePreOrder(r -> getLeft());
	parsePreOrder(r -> getRight());
}

template <class T>
void BTree<T>::parseInOrder ( ) {
	parseInOrder(root);
}

template <class T>
void BTree<T>::parseInOrder (BNode<T>*& r) {
	
	if(r == nullptr){
		return;
	}
	
	parsePreOrder(r -> getLeft());
	std::cout << r -> getData() << ", ";
	parsePreOrder(r -> getRight());
}

template <class T>
void BTree<T>::parsePostOrder ( ) {
	parsePostOrder(root);
}
template <class T>
void BTree<T>::parsePostOrder (BNode<T>*& r) {
	
	if(r == nullptr){
		return;
	}
	
	parsePreOrder(r -> getLeft());
	parsePreOrder(r -> getRight());
	
	std::cout << r -> getData() << ", ";
}

template <class T>
void BTree<T>::deleteAll ( ) {
	
	deleteAll(root);
	root = nullptr;
}

template <class T>
void BTree<T>::deleteAll (BNode<T>*& r) {
	
	if(r == nullptr){
		return;
	}
	
	deleteAll(r -> getLeft());
	deleteAll(r -> getRight());
	
	delete r;
}

template <class T>
BTree<T>& BTree<T>::operator = (const BTree& t) {
	
	deleteAll();
	copyAll(t);
	
	return *this;
}

#endif


