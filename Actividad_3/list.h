#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "song.h"


template <class T, int ARRAYSIZE = 5000>
class List {
private:
	T data[ARRAYSIZE];
	int last;

	bool isValidPos(const int&);

	void copyAll(const List&);
	
	void swapData(T&, T&);
public:

	class ListException : public std::exception{
	private:
		std::string msg;

	public:
		explicit ListException(const char* message) : msg(message){}

		explicit ListException(const std::string& message) : msg(message) {}

		virtual ~ListException() throw() {}

		virtual const char* what() const throw() {
			return msg.c_str();
		}

	};

	List();
	List(const List&);
	
	bool isEmpty();
	bool isFull();

	void insertData(const int&,const T&);//primera la pos y luego el elemento

	void deleteData(const int&);

	int getFirstPos() const;
	int getLastPos() const;
	int getPrevPos(const int&) const;
	int getNextPos(const int&) const;

	int findDataLineal(const T&);
	int findDataBinaria(const T&);
	
	void sortDataBubble();
	/*void sortDataInsert();
	void sortDataSelect();     // entregable 6
	void sortDataShell();*/

	T retrieve(const int&);

	void sortData();

	std::string toString() const;

	void deleteAll();
	
	void writeToDisk(const std::string&);
	void readFromDisk(const std::string&);
	
	List& operator = (const List&);
	
	bool operator == (const List&) const;
	bool operator != (const List&) const;
	bool operator < (const List&) const;
	bool operator > (const List&) const;
	bool operator <= (const List&) const;
	bool operator >= (const List&) const;
	
};

//implementacion


template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() : last(-1) {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List& s) : last(s.last) { }


template <class T, int ARRAYSIZE>
void List <T,ARRAYSIZE> :: copyAll(const List& s) {
	
	int i(0);
	
	while (i <= s.last) {
		this -> data[i] = s.data[i];
		i++;
	}
	
	this-> last = s.last;
}


template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::swapData(T& a, T& b){                  // swapData
	
	T aux(a);
	a = b;
	b = aux;
	
}

template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidPos(const int& p){
	return p >= 0 and p<= last;
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty ( ) {
	return last == -1;

}

template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull ( ) {
	return last == ARRAYSIZE - 1;

}

template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertData (const int& p, const T& e) {

	if(isFull()){
		throw ListException("Desbordamiento de datos, insertData");
	}

	if(p != -1 and !isValidPos(p)){
		throw ListException("Posicion invalida, insertData");
	}

	int i(last);

	while(i > p){
		data[i+1] = data[i];
		
		i--;
	}

	data[p+1] = e;

	last++;
}

template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteData(const int& p){
	
	if(!isValidPos(p)){
		throw ListException("Posicion invalida, deleteData");
	}

	int i(p);

	while(i < last){
		
		data[i]= data[i+1];
		i++;
	}

	last--;
}

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos() const{
	if (isEmpty()){
		return -1;
	}

	return 0;
}

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos ( ) const{
	return last;

}

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevPos (const int& p) const{
	if(p== 0 or isValidPos(p)){
		return -1;
	}

	return p-1;


}

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) const{
	if(p == 0 or !isValidPos(p)){
		//problema
	}

	return 0+1;
}


template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataLineal(const T& e){        // findDataLineal
	int i(0);
	
	while(i <= last){
		if( data[i] == e){
			return i;
		}
		
		i++;
	}
	
	return -1;
}

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataBinaria(const T& e){        // findDataBinaria
	int i(0), j(last), m;
	
	while(i <= j){
		m = (i+j)/2;
		
		if (data[m] == e){
			return m;
		}
		
		if (e < data[m]){
			j = m-1;
		}else{
			i = m+1;
		}
		
		return -1;
	}
}

template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataBubble ( ) {
	
	int i(last) , j;
	
	bool flag;
	
	do{
		flag = false;
		j = 0;
		
		while(j < i){
			if(data[j] > data[j+1]){
				swapData(data[j], data[j + 1]);
				
				flag = true;
			}
			j++;
		}
		i--;
	}while(flag);
}


template <class T,int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int& p) {
	
	if(!isValidPos(p)){
		throw ListException("Posicion invalida, retrieve");
	}

	return data[p];
}


template <class T,int ARRAYSIZE>
std::string List<T, ARRAYSIZE>::toString ( ) const{

	std::string result;
	int i(0);

	while(i <= last){
		
		result += data[i].toString();
		
		i++;
	}
	
	return result;
	
}


template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll ( ) {
	last = -1;
}


template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::writeToDisk(const std::string& fileName){
	
	std::ofstream myFile;
	
	myFile.open(fileName, myFile.trunc/*ios_base::trunc*/);
	
	if(!myFile.is_open()){
		
		std::string message;
		message = "No se pudo abrir el archivo ";
		message += fileName;
		message += " para escritura, writeToDisk.";
		
		throw ListException(message);
	}
	
	int i(0);
	
	while(i <= last){
		myFile << data[i++];
	}
	
	myFile.close();
}

template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::readFromDisk(const std::string& fileName){
	
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
		
	} catch(ListException ex) {
		myFile.close();
		
		std::string message;
		message +=fileName;
		message += " : ";
		message += ex.what();
		message += ", readFromDisk";
		
		throw ListException (message);
	}
	
	int i(0);
	
	while(i <= last){
		myFile >> data[i];
		i++;
	}
	
	deleteAll();
	
	
	try{
		while(myFile >> myData){ // myFile >> myData returna un falso o verdadero
			insertData(getLastPos(), myData);
		}
	} catch(ListException ex) {
		myFile.close();
		
		std::string message("Error durante la lectura del archivo.");
		
		message +=fileName;
		message += " : ";
		message += ex.what();
		message += ", readFromDisk";
		
		throw ListException (message);
	}
	
	myFile.close();
}


template <class T,int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator = (const List& l) {
	
	copyAll(l);
	
	return *this;
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator == (const List& l) const {
	
	int i(0);
	while(i <= last){
		return data[i] == l.data[i];
	}
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator != (const List& ) const {
	
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator < (const List& ) const {
	
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator > (const List& l) const {

}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator <= (const List& ) const {
	
}


template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::operator >= (const List& ) const {
	
}

#endif
