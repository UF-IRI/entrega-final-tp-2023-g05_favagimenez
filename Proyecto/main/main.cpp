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
   Clases*lista_clases=new Clases[N];
   leerClases(archivo_clase,lista_clases,N);

   //ABRIR ARCHIVO CLIENTE
   ifstream archivo_cliente;
  archivo_cliente.open("iriClientesGYM.csv");
   int cantclientes=0;
  Cliente*lista_clientes=new Cliente[cantclientes];
   leercliente(archivo_cliente,lista_clientes,cantclientes);
  cout<<"ver que onda"<<endl;
   /*
  for(int i=0;i<cantclientes;i++){
      cout<<"Filtrar clase"<<endl;
       Cliente aux=cliente[i];
      int N1=*(aux.cantClases);
       cout<<"Estoy filtrando"<<endl;
     filtrar_clase(&aux,N1);
   }
*/
    return 0;
}

