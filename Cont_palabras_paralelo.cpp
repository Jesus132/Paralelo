#include <iostream>
#include <fstream>
#include <vector>
#include<omp.h>	

using namespace std;
//Declaramos las funciones que 
int Numero_lineas();
int Cont_Palabras();

vector<string> palabras;//vector para guardar el texto linea por linea
int cont=0;//Contador de lineas del archivo

int main() {
  cout<<"palabras: "<<Numero_lineas()<<endl;
  return 0;
}

int Numero_lineas(){
  ifstream txt;
  txt.open("libro.txt");
  string aux;
    while(getline(txt,aux)){//getline para obtener linea a linea del archivo
    cont=cont+1;
    palabras.push_back(aux);//vector que guarda linea a linea
  }
  return(Cont_Palabras());

}

int Cont_Palabras(){
  int cant_palb=0;
  #pragma omp parallel reduction(+:cant_palb)//obtenemos la cantidad de hilos
  {
  int reparto=int (cont/omp_get_num_threads());//Repartimos en cada hilo
  int Limite=reparto*(omp_get_thread_num()+1);
  if(omp_get_thread_num()==(omp_get_num_threads()-1)){
    Limite=cont;

  }
  bool sp=true;//variable para saber si hay espacios o no
  for(int i=(reparto*omp_get_thread_num()); i<Limite; i++){//Recorremos el vector de las lineas
    sp=true;
    for(int j=0; j<palabras[i].size();j++){//para recorrer la linea de texto dentro de la posicion del vector 
      if(palabras[i][j]==' '){//se verifica si hay espacios para contrar las palabras
        sp=true;
        }else{
          if(sp){
            cant_palb++;//se va sumanda palabra a palabra
          }
          sp=false;
        }
    }
  }

  }

  return cant_palb;
}