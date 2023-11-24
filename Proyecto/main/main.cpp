#include<iostream>
#include<fstream>
#include "funciones.h"
using namespace std;


int main() {
    cout<<"Hola munda1\n";
   // string rutaArchivoClases = "../Proyecto/iriClasesGYM.csv";
  //  string rutaArchivoClientes = "../Proyecto/iriClientesGYM.csv";
  // string rutaArchivoAsistencias = "../Proyecto/asistencias.dat";
    ifstream archivobinario;
  archivobinario.open("asistencia.dat", ios::binary);
  leerAsistencias("asistencias.dat");
  //sAsistencia*asistencia;
  //int cantasistencias;
  //asistencia=leerArchivoBinario("asistencias.dat",&cantasistencias);
   //ABRO ARCHIVO CLASES
   //ifstream archivo_clase;
   //archivo_clase.open("iriClasesGYM.csv", ios::out);
   //int cantidadClases;
   //Clases* listaClases = leerClase("iriClasesGYM.csv", &cantidadClases);

   //ABRIR ARCHIVO CLIENTE
   //ifstream archivo_cliente;
  // archivo_cliente.open("iriClientesGYM.csv", ios::out);
  // Cliente*cliente;
  // int cantclientes=0;
  // cliente=guardarCliente("iriClientesGYM.csv", &cantclientes);
   //int cantidadClientes;
   //Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", &cantidadClientes);


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

