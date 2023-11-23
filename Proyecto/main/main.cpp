#include<iostream>
#include<fstream>
#include "funciones.h"
using namespace std;

int main() {
    cout<<"Hola munda1";
    string rutaArchivoClases = "../Proyecto/iriClasesGYM.csv";
    string rutaArchivoClientes = "../Proyecto/iriClientesGYM.csv";
   string rutaArchivoAsistencias = "../Proyecto/asistencias.dat";
   leerAsistencias(rutaArchivoAsistencias);
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

