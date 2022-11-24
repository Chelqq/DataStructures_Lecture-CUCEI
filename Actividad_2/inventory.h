#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <iostream>

#include "date.h"

class Inventory{

    private:

        struct Product{
            char code[14];
            char name[30];
            Date dateProduct;
            float weight;
            float mostrePrice;
            float retailPrice;
            int stock;
        };

        Product productos[500];

        int registeredProducts=0;

        int getLength(const char*);

    public:

        int validateCode(const char*);
        void registerNewProduct(const char*, const char*,const float& , const float&,const float& , const int&,Date&);

        void addStock(const int&,const int&);
        bool decreaseStock(const int& ,const int&);

        int getstock(const int&);
        void showInformation(const char*);
    };

#endif // INVENTORY_H_INCLUDED
