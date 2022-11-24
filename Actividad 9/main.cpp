#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <functional>
#include <conio.h>

#include "list.h"
#include "song.h"

using namespace std;

void addSong(List <Song>&);
void deleteSong(List <Song>&);
void findSong(List <Song>&);

void enterToContinue(){
	cout << "\nPresiona ENTER para continuar."; getch();
}

int main () {
	
	char op;
	
	List <Song> myLista;
	string savedSongs;
	
	do{
		system("cls");
		if (myLista.isEmpty()){
			
			cout << "\nNo hay canciones en el sistema." << endl;
		}
		
		if (!myLista.isEmpty()){
			
			cout<< "\n\tTitulo  -  Artista  -  Ranking"<< endl << endl;
			cout << myLista.toString();
		}
		
		cout << "\n\t1- Agregar cancion." << endl;
		cout << "\t2- Buscar cancion." << endl;
		cout << "\t3- Eliminar cancion." << endl;
		cout << "\t4- Agregar una lista de canciones." << endl;
		cout << "\t5- Guardar lista actual." << endl;
		cout << "\t0- Salir" << endl;
		cout << "\nElige una opcion: "; cin >> op;
		
		switch(op){
		case '4':
			
			system("cls");
			
			cout << "\nIngresa el nombre del archivo donde se encuentran las canciones: ";
			fflush(stdin); getline(cin, savedSongs);
			
			myLista.readFromDisk(savedSongs);
			
			break;
			
		case '1':
			addSong(myLista);
			
			break;
			
		case '3':
			system("cls");
			deleteSong(myLista);
			
			break;
			
		case '2':
			system("cls");
			findSong(myLista);
			
			break;
			
		case '5':
			
			system("cls");
			cout << "\nIngresa el nombre que va a tener el archivo (extension .txt): "; fflush(stdin); getline(cin, savedSongs);
			
			myLista.writeToDisk(savedSongs);
			
			break;
			
		default:
			cout << "\nOpcion invalida, intentelo de nuevo." << endl;
			break;
		}
		
	}while(op != '0');
	
}


void addSong(List<Song>& myLista) {
	
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1,3000);
	auto dice = bind(distribution, generator);
	
	string myStr;
	Song mySong;
	char op;
	
	do{
		system("cls");
		std::string s = "";
		s = std::to_string(dice());
		
		cout<< "\n\nNombre de la cancion: ";
		fflush(stdin);getline(cin, myStr);
		mySong.setSongName(myStr);
		
		cout<< "Artista: ";
		fflush(stdin);getline(cin, myStr);
		mySong.setAuthor(myStr);
		
		mySong.setRanking(s);
		
		try{
			myLista.insertData(myLista.getLastPos(), mySong);
		}catch (List<Song>::Exception ex){
			cout << "Algo salio mal." << ex.what();
		}
		
		cout << "\nDeseas agregar otra cancion? (1=Si, 0= No): "; cin >> op;
		
	}while(op != '0');
	
}

void deleteSong(List<Song>& myLista){
	
	char op;
	Song mySong;
	string myStr;
	
	cout << "\nNombre o Autor de la cancion a eliminar: ";
	fflush(stdin); getline(cin , myStr);
	mySong.setSongName(myStr);
	mySong.setAuthor(myStr);
	
	do{
		system("cls");
		cout << "\n\tEliminar:" << myLista.retrieve(myLista.findData(mySong)).toString() << "\n\t1- Eliminar.\n\t0- Cancelar.\n\t>>: ";
		cin >> op;
		
		switch(op){
		case '0':
			break;
			
		case '1':
			
			try{
				myLista.deleteData(myLista.findData(mySong));
				cout << "\nSe ha eliminado correctamente." << endl;
				enterToContinue();
			}catch(List<Song>::Exception ex){
				cout << "\nOcurrio algo malo." << ex.what();
			}
			
			return;
			break;
			
		default:
			cout << "\nOpcion invalida. Intenta nuevamente." << endl;
		}
	}while(op != '0');
}

void findSong(List<Song>& myLista){
	
	Song mySong;
	string myStr;
	Node<Song>* pos;
	
	cout << "\nCancion a buscar: ";
	fflush(stdin); getline(cin , myStr);
	mySong.setSongName(myStr);
	mySong.setAuthor(myStr);
	
	pos = myLista.findData(mySong);
	
	if(pos == nullptr){
		cout << "\nLa cancion " << myStr << " no se encuentra en la lista." << endl;
		enterToContinue();
	}else{
		cout << "\n\n\tCancion encontrada: " << myLista.retrieve(pos).toString() << endl;
		enterToContinue();
	}

}
