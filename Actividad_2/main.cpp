#include <iostream>
#include <locale.h>
#include <string>

#include "date.h" DeleteP
#include "inventory.h"

using namespace std;

void RegistrationMenu(Inventory&);
void DeleteP(Inventory&);

int main()
{
    setlocale(LC_ALL,"spanish");

    char code[14];
    Inventory InventoryProduct;

    int op;

    do
    {
        system("cls");
        cout << "\n\n\t1) Registrar nuevo producto." << endl;
        cout << "\t2) Remover de existencias." << endl;
        cout << "\t3) Mostrar producto" << endl;
        cout << "\t0) Salir" << endl;
        cout << "Ingresa una opion: "; cin >> op;

        switch(op)
        {
        case 1:
            RegistrationMenu(InventoryProduct);
            cin.get();
            cout << "\nPresiona ENTER tecla para continuar";
            cin.get();
            break;
        case 2:
            DeleteP(InventoryProduct);
            cin.get();
            cout << "\nPresiona ENTER tecla para continuar";
            cin.get();
            break;
        case 3:
            cout << "\nIngresa un codigo 13(digitos): " << endl;
            cin >> code;
            InventoryProduct.showInformation(code);
            cin.get();
            cout << "\nPresiona ENTER tecla para continuar";
            cin.get();
            break;
        case 0:
            cout << "Gracias por utilizar este programa !";
            break;
        default:
            cout << "opion NO valida !";
        }
    }while(op!=0);


    return 0;
}

void RegistrationMenu(Inventory &inventory)
{
    char auxCode[14],auxName[30];
    string aux;
    float auxWeight, auxMostPrice, auxRetailPrice;
    int auxStock;
    Date auxDate;

    cout << "\nIngresa un codigo 13(digitos): " << endl;
    fflush(stdin);
    cin.getline(auxCode,14,'\n');
    if(inventory.validateCode(auxCode)==-1)
    {
        cout << "Ingresa el nombre del producto: " << endl;
        cin.getline(auxName,29,'\n');

        cout << "Ingresa el peso del producto: " << endl;
        cin >> auxWeight;

        cout << "Ingresa el precio de mayoreo: " << endl;
        cin >> auxMostPrice;

        cout << "Ingresa el precio al menudeo: " << endl;
        cin >> auxRetailPrice;

        cout << "Ingresa la existencia del producto: " << endl;
        cin >> auxStock;

        cout << "Ingresa el a?o de 'entrada': " << endl;
        cin >> aux;
        auxDate.setYear(aux);

        cout << "Ingresa el mes de 'entrada': " << endl;
        cin >> aux;
        auxDate.setMonth(aux);

        cout << "Ingresa el dia de 'entrada': " << endl;
        cin >> aux;
        auxDate.setDay(aux);

        inventory.registerNewProduct(auxCode,auxName,auxWeight,auxMostPrice,auxRetailPrice,auxStock,auxDate);

    }
    else if (inventory.validateCode(auxCode)>=0)
    {
        int i = inventory.validateCode(auxCode);
        cout << "?Cuantos articulos nuevos hay? (Existencias) :" <<  endl;
        cin >> auxStock;
        inventory.addStock(auxStock,i);
        cout << "\nLote de productos agregados correctamente! " << endl;
    }
    else
        cout << "\nCodigo INVALIDO" << endl;
}


void DeleteP(Inventory &inventory)
{
    char auxCode[14];
    int amountRemove;
    cout << "\nIngresa un codigo 13(digitos): " << endl;
    cin >> auxCode;
    cout << "?Cuantos elementos deseas remover:" << endl;
    cin >> amountRemove;
    if(inventory.decreaseStock(amountRemove,inventory.validateCode(auxCode)))
        cout << "\nProceso realizado CORRECTAMENTE ! , te quedan : " << inventory.getstock(inventory.validateCode(auxCode)) << " productos en el inventario" << endl;
    else
        cout << "No cuentas con esa cantidad de productos" << endl;
}

