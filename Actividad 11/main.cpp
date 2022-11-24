#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"

using namespace std;

int prioridadInfija(char);
int prioridadPila(char);
bool isOperator(char);

int main () {

	Queue <char> myCola;
	Stack <char> myPila;

	string myString;
	char op;


	do{
		system("cls");
		cout << "Enter an infix expression without spaces: ";
		fflush(stdin); getline(cin, myString);                                ///a/b^(c+d)-e*f/g^h - ((((((a+b)*c)-d)^e)/f)+g)*h


		for(int i(0); i < myString.length(); i++){

			if ((myString[i] >= 'a' && myString[i] <= 'z') || (myString[i] >= 49 && myString[i] <= 57)){
				myCola.enqueue(myString[i]);
			}

			if(isOperator(myString[i])){

				if (myPila.isEmpty()){
					myPila.push(myString[i]);
				}else{

					if(prioridadInfija(myString[i]) < prioridadPila(myPila.getTop())){

						while(!myPila.isEmpty()){
							myCola.enqueue(myPila.pop());
						}

						myPila.push(myString[i]);
					}
					if (prioridadInfija(myString[i]) == prioridadPila(myPila.getTop())){

						myCola.enqueue(myPila.pop());
						myPila.push(myString[i]);
					}

					if(prioridadInfija(myString[i]) > prioridadPila(myPila.getTop())){

						myPila.push(myString[i]);
					}
				}
			}

			if(myString[i] == '('){
				myPila.push(myString[i]);
			}

			if(myString[i] == ')'){
				while(myPila.getTop() != '('){

					myCola.enqueue(myPila.pop());
				}
				myPila.pop();
			}

		}

		if(!myPila.isEmpty()){
			while(!myPila.isEmpty()){
				myCola.enqueue(myPila.pop());
			}
		}

		cout << endl << endl;

		try{
			if(!myCola.isEmpty()){
				while(!myCola.isEmpty()){
					cout << myCola.dequeue();
				}
			}
		}catch(typename QueueNode<char>::ExceptionQueueNode ex){
			cout << endl << ex.what() << endl;
		}

		cout << "\n\n\tPress 1 to try again.\n\tPress 0 to exit.\n\t: "; cin >> op;
	}while(op != '0');
}


int prioridadInfija(char a){

	if( a=='^'){
		return 3;
	}
	if( a=='*'){
		return 2;
	}
	if( a=='/'){
		return 2;
	}
	if( a=='+'){
		return 1;
	}
	if( a=='-'){
		return 1;
	}
	if(a=='('){
		return 4;
	}

	return 0;
}

int prioridadPila(char a){

	if( a=='^'){
		return 3;
	}
	if( a=='*'){
		return 2;
		}
	if( a=='/'){
		return 2;
	}
	if( a=='+'){
		return 1;
	}
	if( a=='-'){
		return 1;
	}
	if( a=='('){
		return 0;
	}

	return 0;
}

bool isOperator(char a){
	return a == '+' || a == '-' || a == '*' || a == '/' || a == '^';
}
