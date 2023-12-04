#include<iostream>
#include<fstream>
#include "funciones.h"
using namespace std;


int main() {

    ifstream archivobinario;
  archivobinario.open("asistencia.dat", ios::binary);
 leerAsistencias("asistencias.dat");

   //ABRO ARCHIVO CLASES
   ifstream archivo_clase;
   archivo_clase.open("iriClasesGYM.csv");
   //int cantidadClases;
   int N=0;
   Clases*clase=new Clases[N];
   leerClases(archivo_clase,clase,N);

   //ABRIR ARCHIVO CLIENTE
   ifstream archivo_cliente;
  archivo_cliente.open("iriClientesGYM.csv");
   int cantclientes=0;
  Cliente*cliente=new Cliente[cantclientes];
   leercliente(archivo_cliente,cliente,cantclientes);
  cout<<"ver que onda";
  /*for(int i=0;i<cantclientes;i++){
      cout<<"\nFiltrar clase";
       Cliente aux=cliente[i];
      int N=*(aux.cantClases);
       cout<<"Estoy filtrando";
     //filtrar_clase(&aux,N);
   }*/

    return 0;
}

