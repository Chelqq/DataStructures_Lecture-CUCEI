#ifndef STACK_H
#define STACK_H

#include <string>

template <class T, int ARRAYSIZE = 1000>                           ///Definicion
class Stack{
private:
	
	T data[ARRAYSIZE];
	int top;
	
	void copyAll(const Stack&);
	
public:
	Stack();
	Stack(const Stack&);
	
	bool isEmpty();
	bool isFull();
	
	void push(const T&);
	
	T pop();
	
	T getTop() const;
	
	
	Stack& operator = (const Stack&);
	
	bool operator == (const Stack&) const;
	bool operator != (const Stack&) const;
	bool operator < (const Stack&) const;
	bool operator <= (const Stack&) const;
	bool operator > (const Stack&) const;
	bool operator >= (const Stack&) const;
};



template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll (const Stack& s) {           ///Implementacion
	
	int i(0);
	
	while (i<= s.top){
		this->data[i] = s.data[i];
		i++;
	}
	
	this -> top = s.top;
	
	return *this;
}


template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack ( ) : top(-1){ }


template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack (const Stack& s) {
	
	copyAll(s);
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty ( ) {
	
	return top == -1;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull ( ) {
	
	return top == ARRAYSIZE -1;
}


template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push (const T& e) {
	
	data[++top] = e;
}


template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop ( ){
	
	return data[top--];
}


template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop ( ) const {
	
	return data[top];
}


template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack& s) {
	
	copyAll(s);
	
	return *this;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator != (const Stack& s) const {
	return top != s.top;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator == (const Stack& s) const {
	return top == s.top;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator < (const Stack& s) const {
	return top < s.top;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator <= (const Stack& s) const {
	return top <= s.top;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator > (const Stack& s) const {
	return top > s.top;
}


template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::operator >= (const Stack& s) const {
	return top >= s.top; 
}


#endif





