#include<iostream>
#include "size.h"

using namespace std;


void menu();

int main () {
	
	menu();
	
	return 0;
}

void menu(){
	
	Size bit;
	char op;
	
	do{
		cout << "\n\n\n\t\tB i e n v e n i d o \n\n\n";
		cout << "\na)Tamaño y rangos de los Tipos de Dato Primitivos." <<endl;
		cout << "b)Ejemplo de uso de Tipo de dato Estructurado." <<endl;
		cout << "c)Salir." <<endl;
		cout << "Selecciona una opcion: "; cin >> op;
		
		switch(op){
			
		case 'a':
			
			bit.getConSigno();
			
			break;
		case 'b':
			break;
		}
	}while(op!='c');

}

