 #include "funciones.h"
//#include <string>

/*../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClasesGYM.csv"
../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClientesGYM.csv"
../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/"asistencias_1697673600000.dat"  */                                                                                                                                                                                                                                                                  using namespace std;
using namespace std;

//#include "funciones.h"

//using namespace std;

int main(int argc, char *argv[]) {
    std::string rutaArchivoClases = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClasesGYM.csv";
    std::string rutaArchivoClientes = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClientesGYM.csv";
    std::string rutaArchivoAsistencias = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/asistencias_1697673600000.dat";
    string archibinrd = "asistencias_1697673600000.dat";

    leerAsistencias(archibinrd);
   int cantAsistencias;
    sAsistencia* asistencias = leerArchivoBinario("asistencias_1697673600000.dat", &cantAsistencias);
    // "../gngng/
    int cantidadClientes=0;

    Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", &cantidadClientes);
    delete[] listaClientes;
        int cantidadClases=0;
  //  Clases* listaClases = cargarClases("iriClasesGYM", cantidadClases);
    //delete[] listaClases;
    return 0;
}
