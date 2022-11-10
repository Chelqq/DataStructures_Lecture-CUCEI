#include "inventory.h"

#include <iostream>

using namespace std;

int Inventory::getLength(const char *c)
{
    int length=0;
    for(int i(0) ; c[i]!='\0' ; i++)
        length++;

    return length;
}

int Inventory::validateCode(const char *c)
{
    int i,j;

    if(getLength(c)!=13)
        return -2;

    for(i=0; i<registeredProducts;i++)
    {
        for(j=0; j<13 ; j++)
            if(c[j] != productos[i].code[j])
                break;

        if(j==13)
            return i;
    }

    return -1;
}

void Inventory::registerNewProduct(const char* c, const char* n,const float &w, const float &mp,const float &rp, const int &s, Date&d)
{
    for(int i=0; i<getLength(c);i++)
       productos[registeredProducts].code[i] = c[i];

    for(int i=0; i<getLength(n);i++)
       productos[registeredProducts].name[i] = n[i];

    productos[registeredProducts].weight = w;
    productos[registeredProducts].mostrePrice = mp;
    productos[registeredProducts].retailPrice = rp;
    productos[registeredProducts].stock = s;
    productos[registeredProducts].dateProduct.setYear(d.getYear());
    productos[registeredProducts].dateProduct.setMonth(d.getMonth());
    productos[registeredProducts].dateProduct.setDay(d.getDay());

    registeredProducts++;
}

void Inventory::addStock(const int&s ,const int &i)
{
    productos[i].stock+=s;
}

bool Inventory::decreaseStock(const int&d ,const int &i)
{
    if(productos[i].stock<d)
        return false;

    productos[i].stock-=d;
    return true;
}


int Inventory::getstock(const int&i)
{
    return productos[i].stock;
}

void Inventory::showInformation(const char*c)
{
    int i=validateCode(c);

    cout << "Nombre del producto: " << productos[i].name << endl;
    cout << "Peso del producto: " << productos[i].weight << endl;
    cout << "Precio de mayoreo: " << productos[i].mostrePrice << endl;
    cout << "Precio al menudeo: " << productos[i].retailPrice << endl;
    cout << "Existencia(s): " << productos[i].stock << endl;
    cout << "Fecha de entrada: " << productos[i].dateProduct.getDay() << "/" <<
    productos[i].dateProduct.getMonth() << "/" << productos[i].dateProduct.getYear();

}



