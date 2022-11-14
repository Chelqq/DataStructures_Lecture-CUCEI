#ifndef QUEUE_H
#define QUEUE_H

#include <string>

template <class T, int ARRAYSIZE = 1000>                          ///Definicion
class Queue{
	
private:
	
	T data[ARRAYSIZE];
	
	int frontPos;
	int endPos;
	
	void copyAll(const Queue&);
	
public:
	
	Queue();
	Queue(const Queue&);
	
	bool isEmpty();
	bool isFull();
	
	void enqueue(const T&);
	
	T dequeue();
	
	T getFront() const;
	
	Queue& operator = (const Queue&);
	
};



template <class T, int ARRAYSIZE>                              ///Implementacion
void Queue<T, ARRAYSIZE>::copyAll (const Queue& q) { 
	
	int i(0);
	
	while (i <= q.endPos){
		this->data[i] = q.data[i];
		i++;
	}
	
	this -> endPos = q.endPos;
}


template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue ( ) : frontPos(0), endPos(ARRAYSIZE - 1){ }


template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue (const Queue& q) { 
	
	copyAll(q);
}


template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty ( ) {
	
	return frontPos == endPos + 1 or (frontPos == 0 and endPos == ARRAYSIZE - 1);
}


template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull ( ) {
	
	return frontPos == endPos + 2
		or (frontPos == 0 and endPos == ARRAYSIZE - 2)
		or (frontPos == 1 and endPos == ARRAYSIZE -1);
}


template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue (const T& e) {
	
	data[endPos = ++endPos == ARRAYSIZE ? 0 : endPos] = e;
}


template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue ( ) {
	
	T result(data[frontPos]);
	
	if (++frontPos == ARRAYSIZE){
		frontPos = 0;
	}
	
	return result;
}


template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront ( ) const {
	
	return data[frontPos];
}


template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator = (const Queue& q) {
	
	copyAll(q);
	
	return *this;
}

#endif
