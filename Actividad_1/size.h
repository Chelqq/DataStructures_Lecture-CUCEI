#ifndef SIZE_H
#define SIZE_H

#include <iostream>
#include <string>

class Size{
private:
	short int conSigno;
	unsigned short int sinSigno;
	char caracter;
	unsigned char caracterSinSig;
	long int largoSigno;
	unsigned long int largoSinSig;
	float realSimple;
	double realSimpleDobl;
	
	
public:
	short int getConSigno();
	unsigned short int getSinSigno();
	char getCaracter();
	unsigned char getCaracterSinSig();
	long int getLargoSigno();
	unsigned long int getLargoSinSig();
	float getRealSimple();
	double getRealSimpleDobl();
	
};

#endif
