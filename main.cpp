#include <bits/stdc++.h>
#include <pthread.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{ 
  int a=0;
  string line;//variable que guardara lo que tenga el archivo
  ifstream lib("libro.txt");
  cout<<lib.gcount();
  while(lib >> line){//Vamos guardando pálabra a palabra en la variable hasta que llegue a la ultima
    //cout<<line;
    a++;//Sumamos una a una
  }
  cout<<"Cantidad: "<<a;
}
