 #include "../libreria/funciones.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
   string rutaArchivoClases = "../Proyecto/iriClasesGYM.csv";
    string rutaArchivoClientes = "../Proyecto/iriClientesGYM.csv";
    string rutaArchivoAsistencias = "../Proyecto/asistencias_1697673600000.dat";
  //  leerAsistencias(archibinrd);
   /*int cantAsistencias;
    sAsistencia* asistencias = leerArchivoBinario("asistencias_1697673600000.dat", &cantAsistencias);
    // "../gngng/
    int cantidadClientes=0;

    Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", &cantidadClientes);
    delete[] listaClientes;
        int cantidadClases=0;
  //  Clases* listaClases = cargarClases("iriClasesGYM", cantidadClases);
    //delete[] listaClases;*/

   /*
    sAsistencia asistencia;
    ifstream archivoDAT(rutaArchivoAsistencias, ios::binary);
    if (archivoDAT.is_open()) {
        std::string linea;
        while (std::getline(archivoDAT, linea)) {
            cout << "ID del cliente: " << asistencia.idCliente << endl;
            cout << "Cantidad de cursos a los que se inscribió: "
                 << asistencia.cantInscriptos << endl;
            for (int i = 0; i < asistencia.cantInscriptos; i++) {
                cout << "ID clase: " << asistencia.CursosInscriptos[i].idClase<< endl;
                cout << "Fecha de inscripcion: "<< asistencia.CursosInscriptos[i].fechaInscripcion << endl;
            }
        }
        archivoDAT.close();
    } else {
        cout << "No se pudo abrir el archivo DAT" << std::endl;
    }

    std::ifstream archivoCSV(rutaArchivosClases);
    if (archivoCSV.is_open()) {
        std::string linea;
        while (std::getline(archivoCSV, linea)) {
            // Procesar cada línea del archivo CSV
            std::cout << "CSV: " << linea << std::endl;
        }
        archivoCSV.close();
    } else {
        cout << "No se pudo abrir el archivo CSV" << std::endl;
    }*/
    cout << "Hola mundo!"<<endl;
    return 0;
}
