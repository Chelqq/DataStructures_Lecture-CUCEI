#ifndef QUEUENODE_H
#define QUEUENODE_H

template <class T>
class QueueNode{
private:
	
	T* dataPtr;
	QueueNode* prev;
	QueueNode* next;
	
public:
	
	class ExceptionQueueNode : public std::exception{
	private:
		std::string msg;
		
	public:
		explicit ExceptionQueueNode(const char* message) : msg(message){}
		
		explicit ExceptionQueueNode(const std::string& message) : msg(message) {}
		
		virtual ~ExceptionQueueNode() throw() {}
		
		virtual const char* what() const throw() {
			return msg.c_str();
		}
		
	};
	
	QueueNode();
	QueueNode(const T&);
	
	~QueueNode();
	
	T* getDataPtr() const;
	T getData() const;
	QueueNode* getPrev() const;
	QueueNode* getNext() const;
	
	void setDataPtr(T*);
	void setData(const T&);
	void setPrev(QueueNode*);
	void setNext(QueueNode*);
	
};

///Implementacion del nodo

template <class T>
QueueNode<T>::QueueNode ( ) : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

template <class T>
QueueNode<T>::QueueNode (const T& e) : dataPtr(new T(e)), prev(nullptr), next(nullptr) { 
	
	if(dataPtr == nullptr){
		throw ExceptionQueueNode("Memoria insuficiente. creando nodo.");
	}
}

template <class T>
QueueNode<T>::~QueueNode (){
	delete dataPtr;
}
	
template <class T>
T* QueueNode<T>::getDataPtr ( ) const {
	return dataPtr;
}
	
template <class T>		
T QueueNode<T>::getData ( ) const {
	
	if(dataPtr == nullptr){
		throw ExceptionQueueNode("Dato inexistente, getData.");
	}
	
	return *dataPtr;
}
	
template <class T>
QueueNode<T>* QueueNode<T>::getPrev ( ) const {
	return prev;
}
	
template <class T>
QueueNode<T>* QueueNode<T>::getNext ( ) const {
	return next;
}
	
template <class T>
void QueueNode<T>::setDataPtr (T* e) {
	dataPtr = e;
}
	
template <class T>
void QueueNode<T>::setData (const T& e) {
	
	if(dataPtr == nullptr){
		if((dataPtr = new T(e)) == nullptr){
			throw ExceptionQueueNode ("Memoria no disponible, setData.");
		}
	}
	else{
		*dataPtr = e;
	}
}

template <class T>
void QueueNode<T>::setPrev (QueueNode* p) {
	prev = p;
}
	
template <class T>
void QueueNode<T>::setNext (QueueNode* p) {
	next = p;
}

#endif
