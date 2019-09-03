#include <bits/stdc++.h>
#include <pthread.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{ 
  pthread_t thread1, thread2;
  int a=0;
  string line, cadena="Hola que haces";
  ifstream lib("libro.txt");
  cout<<lib.gcount();
  //cout<<gcount(lib);
  while(lib >> line){
    //cout<<line;
    a++;
  }
  cout<<"Cantidad: "<<a;
}
