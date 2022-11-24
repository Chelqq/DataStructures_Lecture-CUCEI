#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <functional>


#include "list.h"
#include "song.h"

using namespace std;

void addSong();
void deleteSong();
void findSong();

int randNum;
string myStr;
List <Song> myLista;
Song mySong;

default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(1,3000);
auto dice = bind(distribution, generator);

int main () {
	
	char op;
	
	do{
		
		if (myLista.isEmpty()){
			
			cout << "\nNo hay canciones en el sistema." << endl;
		}
		
		if (!myLista.isEmpty()){
			
			cout<< "\n\tTitulo  -  Artista  -  Ranking"<< endl << endl;
			cout << myLista.toString();
		}
		
		cout << "\n\t1- Agregar una lista de canciones." << endl;
		cout << "\t2- Agregar cancion." << endl;
		cout << "\t3- Eliminar cancion." << endl;
		cout << "\t4- Buscar cancion." << endl;
		cout << "\t5- Guardar lista actual." << endl;
		cout << "\t0- Salir" << endl;
		cout << "\nElige una opcion: "; cin >> op;
		
		switch(op){
		case '1':
			{	
			system("cls");
				string savedSongs;
				
				cout << "\nIngresa el nombre del archivo donde se encuentran las canciones: ";
				fflush(stdin); getline(cin, savedSongs);
				
				myLista.readFromDisk(savedSongs);
			}
			break;
			
		case '2':
			system("cls");
			addSong();
			
			break;
			
		case '3':
			system("cls");
			deleteSong();
			
			break;
			
		case '4':
			system("cls");
			findSong();
			
			break;
			
		case '5':
			{	
				system("cls");
				string savedSongs;
				cout << "\nIngresa el nombre que va a tener el archivo (extension .txt): "; fflush(stdin); getline(cin, savedSongs);
				
				myLista.writeToDisk(savedSongs);
			}
			break;
			
		default:
			cout << "\nOpcion invalida, intentelo de nuevo." << endl;
			break;
		}
		
	}while(op != '0');
	
}


void addSong() {

	randNum = dice();
	char op;
	
	do{
		std::string s = "";
		s = std::to_string(dice());
		
		cout<< "\n\nNombre de la cancion: ";
		fflush(stdin);getline(cin, myStr);
		mySong.setSongName(myStr);
		
		cout<< "Artista: ";
		fflush(stdin);getline(cin, myStr);
		mySong.setAuthor(myStr);
		
		
		mySong.setRanking(s);
		
		myLista.insertData(myLista.getLastPos(), mySong);
		
		cout << "\nDeseas agregar otra cancion? (1=Si, 0= No)"; cin >> op;
		
	}while(op != '0');
	
}

void deleteSong(){
	
	int pos;
	string myStr;
	
	cout << "\nIngresa nombre de la cancion a eliminar: ";
	fflush(stdin); getline(cin , myStr);
	mySong.setSongName(myStr);
	
	pos = myLista.findDataLineal(mySong);
	
	myLista.deleteData(pos);
	
	cout << "\nSe ha eliminado correctamente." << endl;
	
}

void findSong(){
	
	char op;
	
	cout << "\n\n\tMetodo de busqueda:\n\n\t1- Lineal.\n\t2- Binaria.\n\t >>:"; cin >> op;
	
	switch(op){
	case '1':
		{
			string myStr;
			int pos;
			
			cout << "\nCancion a buscar: ";
			fflush(stdin); getline(cin , myStr);
			mySong.setSongName(myStr);
			mySong.setAuthor(myStr);
			
			pos = myLista.findDataLineal(mySong);
			
			if(pos == -1){
				cout << "\nLa cancion " << myStr << " no se encuentra en la lista." << endl;
			}else{
				cout << "\n\n\tCancion encontrada: " << myLista.retrieve(pos).toString() << endl;
			}
			
		}
		break;
		
	case '2':
		{
			myLista.sortDataBubble();
			
			string myStr;
			int pos;
			
			cout << "\nCancion a buscar: ";
			fflush(stdin); getline(cin , myStr);
			mySong.setSongName(myStr);
			mySong.setAuthor(myStr);
			
			pos = myLista.findDataBinaria(mySong);
			
			if(pos == -1){
				cout << "\nLa cancion " << myStr << " no se encuentra en la lista." << endl;
			}else{
				cout << "\n\n\tCancion encontrada: " << myLista.retrieve(pos).toString() << endl;
			}
		}
		break;
		
	default:
		cout << "\nOpcion invalida, intentelo de nuevo." << endl;
		break;
	}

}
