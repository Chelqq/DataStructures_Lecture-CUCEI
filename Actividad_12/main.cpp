#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "btree.h"

using namespace std;

int main ( ) {
	
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(0,100000);
	auto dice = bind(distribution, generator);
	
	char op;
	int value, x,y;
	BTree <int> myTree;
	
	do{
		system("cls");
		
		cout << "Ingresa un cualquier numero entero a utilizar: "; cin >> x;
		
		cout << endl << endl;
		
		for (int i(0); i < x; i++){
			
			//value = dice();
			cout << "Ingresa valor en " << i << " : ";
			cin >> y;
			
			myTree.insertData(y);
		}
		
		cout << endl << endl;
		
		cout << "Recorrido en PreOrder: " << endl;
		myTree.parsePreOrder();
		cout << endl << endl;
		
		cout << "Recorrido en InOrder: " << endl;
		myTree.parseInOrder();
		cout << endl << endl;
		
		cout << "Recorrido en PostOrder: " << endl;
		myTree.parsePostOrder();
		cout << endl << endl;
		
		cout << "Altura del subarbol izquierdo: " << myTree.getHeight(myTree.getRoot() -> getLeft());
		cout << endl << endl;
		
		cout << "Altura del subarbol derecho: " << myTree.getHeight(myTree.getRoot() -> getRight());
		
		cout << endl << endl << "Presiona 0 para salir. Presiona cualquier tecla para intentar nuevamente: "; cin >> op;
		
		if(op != '0'){
			myTree.deleteAll();
		}
		
	}while(op != '0');
}

