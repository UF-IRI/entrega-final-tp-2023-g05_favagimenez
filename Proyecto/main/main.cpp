#include<iostream>
#include<fstream>
#include "funciones.h"
using namespace std;


int main() {

    ifstream archivobinario;
  archivobinario.open("asistencia.dat", ios::binary);
//  leerAsistencias("asistencias.dat");

   //ABRO ARCHIVO CLASES
   ifstream archivo_clase;
   archivo_clase.open("../iriClasesGYM.csv");
   //int cantidadClases;
   int N=0;
   cout<<"hola";
   Clases*clase=new Clases[N];
   leerClases(archivo_clase,clase,N);

   //ABRIR ARCHIVO CLIENTE
   //ifstream archivo_cliente;
  // archivo_cliente.open("iriClientesGYM.csv", ios::out);
  // Cliente*cliente;
  // int cantclientes=0;
  // cliente=guardarCliente("iriClientesGYM.csv", &cantclientes);
   //int cantidadClientes;
   //Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", &cantidadClientes);

//
    /*int cantAsistencias;
    sAsistencia* asistencias = leerArchivoBinario("asistencias_1697673600000.dat", &cantAsistencias);
    // "../gngng/
    int cantidadClientes=0;
    @@ -36,12 +71,41 @@ int main() {
  //  Clases* listaClases = cargarClases("iriClasesGYM", cantidadClases);
    //delete[] listaClases;*/

    cout << "Hola mundo!"<<endl;
    return 0;
}

