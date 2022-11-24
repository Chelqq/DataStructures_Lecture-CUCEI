#include <iostream>
#include <windows.h>
#include <random>
#include <chrono>
#include <functional>

#include "list.h"

using namespace std;

double timeSortingBubble(List<int>&);
double timeSortingSelect(List<int>&);
double timeSortingInsert(List<int>&);
double timeSortingShell(List<int>&);
double timeSortingMerge(List<int>&);
double timeSortingQuickSort(List<int>&);

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){

      LARGE_INTEGER freq;
      QueryPerformanceFrequency(&freq);

      return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main()
{
      List<int> myList;
      int randNum;

      default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
      uniform_int_distribution<int> distribution(0,1000000);
      auto dice = bind(distribution, generator);

      while(!myList.isFull()){

            randNum = dice();

            myList.insertData(myList.getLastPos(), randNum);
      }

      cout <<"Ordenando por metodo Bubble..." << endl;
      cout << "Segundos empleados: " << timeSortingBubble(myList) << endl << endl;


      cout <<"Ordenando por metodo Insert..." << endl;
      cout << "Segundos empleados: " << timeSortingInsert(myList) << endl << endl;


      cout <<"Ordenando por metodo Select..." << endl;
      cout << "Segundos empleados: " << timeSortingSelect(myList) << endl << endl;


      cout <<"Ordenando por metodo Shell..." << endl;
      cout << "Segundos empleados: " << timeSortingShell(myList) << endl << endl;


      cout <<"Ordenando por metodo Merge..." << endl;
      cout << "Segundos empleados: " << timeSortingMerge(myList) << endl << endl;


      cout <<"Ordenando por metodo QuickSort..." << endl;
      cout << "Segundos empleados: " << timeSortingQuickSort(myList) << endl << endl;

}

double timeSortingBubble(List<int>& myList){

      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataBubble();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}

double timeSortingInsert(List<int>& myList){

      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataInsert();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}

double timeSortingSelect(List<int>& myList){


      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataSelect();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}

double timeSortingShell(List<int>& myList){

      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataShell();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}

double timeSortingMerge(List<int>& myList){

      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataMerge();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}
double timeSortingQuickSort(List<int>& myList){

      LARGE_INTEGER t_ini, t_fin;
      double secs;

      QueryPerformanceCounter(&t_ini);
      myList.sortDataQuickSort();
      QueryPerformanceCounter(&t_fin);

      return secs = performancecounter_diff(&t_fin, &t_ini);
}
