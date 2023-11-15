#include <iostream>
#include"funciones.h"
#include <fstream>
//#include <string>

/*../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClasesGYM.csv"
../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClientesGYM.csv"
../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"asistencias_1697673600000.dat"  */
using namespace std;

//#include "funciones.h"

//using namespace std;
void leerAsistencias2(string archibinrd) {
    ifstream f(archibinrd, ios::binary);
   /* if (f.is_open()) {
        sAsistencia asistencia;
        while (f.read((char*)&asistencia, sizeof(sAsistencia))) {
            cout << "ID del cliente: " << asistencia.idCliente << endl;
            cout << "Cantidad de cursos a los que se inscribió: "
                 << asistencia.cantInscriptos << endl;
            for (int i = 0; i < asistencia.cantInscriptos; i++) {
                cout << "ID clase: " << asistencia.CursosInscriptos[i].idClase<< endl;
                cout << "Fecha de inscripcion: "<< asistencia.CursosInscriptos[i].fechaInscripcion << endl;
            }
        }
    }
    f.close();*/
}

int main() {
    string rutaArchivoClases = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClasesGYM.csv";
    string rutaArchivoClientes = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClientesGYM.csv";
    string rutaArchivoAsistencias = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/asistencias_1697673600000.dat";
    string archibinrd = "asistencias_1697673600000.dat";

    leerAsistencias(rutaArchivoAsistencias);

   /*int cantAsistencias;
    sAsistencia* asistencias = leerArchivoBinario("asistencias_1697673600000.dat", &cantAsistencias);
    // "../gngng/
    int cantidadClientes=0;

    Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", &cantidadClientes);
    delete[] listaClientes;
        int cantidadClases=0;
  //  Clases* listaClases = cargarClases("iriClasesGYM", cantidadClases);
    //delete[] listaClases;
*/
    cout<<"Hola";
    return 0;
}
