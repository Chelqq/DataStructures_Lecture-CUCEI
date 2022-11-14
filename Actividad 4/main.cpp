#include<iostream>

#include "stack.h"
#include "queue.h"


using namespace std;

int prioridadInfija(char);
int prioridadPila(char);

int main () {
	
	Queue<char> myCola;
	Stack<char> myPila;
	
	char myChar[100], aux;
	int op;
	
	
	do{
		system("cls");
		cout << "Enter an infix expression without spaces: "; cin >> myChar;        ///a/b^(c+d)-e*f/g^h
		
		int i(0);
		
		while( myChar[i] != '\0'){
			
			if ((myChar[i] >= 'a' and myChar[i] <= 'z') or (myChar[i] >= 49 and myChar[i] <= 57)){
				
				myCola.enqueue(myChar[i]);
			}
			
			if(myChar[i] == '+' or myChar[i] == '-' or myChar[i] == '*' or myChar[i] == '/' or myChar[i] == '^'){
				
				if (myPila.isEmpty()){
					
					myPila.push(myChar[i]);
					
					
				}else{
					
					if(!myPila.isEmpty()){
						
						if((prioridadInfija(myChar[i]) < prioridadPila(myPila.getTop())) or (prioridadInfija(myChar[i]) == prioridadPila(myPila.getTop()))){
							
							aux = myPila.getTop();
							myCola.enqueue(aux);
							myPila.pop();
							myPila.push(myChar[i]);
							
						}else{
							myPila.push(myChar[i]);
						}
					}
				}
			}
			
			if(myChar[i] == '('){
				myPila.push(myChar[i]);
			}
			
			if(myChar[i] == ')'){
				while(myPila.getTop() != '('){
					
					aux = myPila.pop();
					myCola.enqueue(aux);
				}
				myPila.pop();
			}
			
			i++;
		}
		
		cout << endl << endl;
		
		while(!myCola.isEmpty()){
			cout << myCola.dequeue();
		}
		
		while(!myPila.isEmpty()){
			cout << myPila.getTop();
			myPila.pop();
			
		}
		
		cout << "\n\n\tPress 1 to try again.\n\tPress 0 to exit.\n\n\t: "; cin >> op;
	}while(op != 0);
}


int prioridadInfija(char a){
	
	if( a=='^'){
		return 4;
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
		return 5;
	}
	
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
	
}			
