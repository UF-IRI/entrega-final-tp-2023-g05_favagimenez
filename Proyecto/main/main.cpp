#include <iostream>
#include <string>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#define MAXCLASES 200
using namespace std;

struct Clases {
    unsigned idClase;
    string nombre;
    float horario;
    int cupo;
    int cupoMax;
};


struct Cliente {
    unsigned int idCliente;
    string nombre;
    string apellido;
    string email;
    string telefono;
    string fechaNac;
    int estado;
    Clases*clases[MAXCLASES];
    int cantClases;
};

struct Inscripcion {
    unsigned int idClase;
    unsigned int idCliente;
    time_t fechaInscripcion;
};
typedef struct {

    unsigned int idCliente, cantInscriptos;

    Inscripcion* CursosInscriptos;

} sAsistencia;


void registrarCliente(Cliente*& listaClientes, int* tamactual, Cliente nuevoCliente);
void agregar_clases(Clases*&lista_clases, Clases clase, int*tamactual);
Clases*read_archivo_clases(string a1, int*contador);
Cliente* guardarCliente(string& archivo, int* cantidadClientes);
void obtenerFechaHora();
void leerAsistencias(string& archibinrd);
void reseteararchivo(string rutaarchi);
Clases* leerClase(string& archivo, int* cantidadClases);
bool existeSuperposicion(Cliente* cliente, Clases*clase);
//void reservarClase(Clases*& listaClases, string& nombreClase, int horario, int& cantidadClases);
Inscripcion*reservarClase(Cliente*cliente, Clases*clase);


int main() {
    string rutaArchivoClases = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClasesGYM.csv";
    string rutaArchivoClientes = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/iriClientesGYM.csv";
    string rutaArchivoAsistencias = "../OneDrive/Documentos/GitHub/entrega-final-tp-2023-g05_favagimenez/Proyecto/asistencias_1697673600000.dat";
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

    cout << "Hola mundo!"<<endl;
    return 0;
}

void registrarCliente(Cliente*& listaClientes, int *tamactual, Cliente nuevoCliente) {
    *tamactual=*tamactual+1;
    Cliente* aux = new Cliente[*tamactual];
    int i=0;
    while (i<*tamactual-1&&*tamactual-1!=0) {
        aux[i] = listaClientes[i];
        i++;
    }
    aux[i] = nuevoCliente;
    delete[] listaClientes;
    listaClientes = aux;
}
void agregar_clases(Clases*&lista_clases, Clases clase, int*tamactual){
    *tamactual=*tamactual+1;
    int i=0;
    Clases*aux=new Clases[*tamactual];
    while(i<*tamactual-1&&*tamactual-1!=0){
        aux[i]=lista_clases[i];
        i++;
    }
    aux[i]=clase;
    delete[]lista_clases;
    lista_clases=aux;

}
void leerAsistencias(string& archibinrd) {
    ifstream f(archibinrd, ios::binary);

    if (f.is_open()) {
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
    f.close();
}
Clases* leerClase(string& archivo, int* cantidadClases) {

    Clases* listaClases;
    ifstream infile("iriClasesGYM.csv");
    if (!infile.is_open()) {
        cout << "Error al leer archivo de clientes";
        return nullptr;
    }
    string line;
    char coma = ',';
    getline(infile, line);
    while (getline(infile, line)) {
        stringstream ss;
        Clases nuevaClase;
        ss>>nuevaClase.idClase;
        getline(ss, nuevaClase.nombre, coma);
        ss>>nuevaClase.horario;
        agregar_clases(listaClases, nuevaClase, cantidadClases);
        cantidadClases++;
    }
    infile.close();
    return listaClases;
}
Cliente* guardarCliente(string& archivo, int* cantidadClientes) {
    Cliente* listaClientes = nullptr;
    cantidadClientes = 0;
    ifstream infile("iriClientesGYM.csv");
    if (!infile.is_open()) {
        cout << "Error al leer archivo";
        return nullptr;
    }
    string line;
    char coma = ',';
    getline(infile, line);
    while (getline(infile, line)) {
        stringstream ss;
        Cliente nuevoCliente;
        ss>>nuevoCliente.idCliente;
        getline(ss, nuevoCliente.nombre, coma);
        getline(ss, nuevoCliente.apellido, coma);
        getline(ss, nuevoCliente.email, coma);
        getline(ss, nuevoCliente.telefono);
        ss>>nuevoCliente.estado;
        registrarCliente(listaClientes, cantidadClientes, nuevoCliente);
        cantidadClientes++;
    }
    infile.close();
    return listaClientes;
}

Inscripcion*reservarClase(Cliente*cliente, Clases*clase){
    if(!existeSuperposicion(cliente, clase)){
        if(clase->cupo<clase->cupoMax){
            cout<<"Se pudo reservar";
            cliente->cantClases++;
            cliente->clases[cliente->cantClases]=clase;
            clase->cupo++;
            Inscripcion*nuevainscripcion;
            nuevainscripcion->fechaInscripcion=obtenerFechaHora();
            nuevainscripcion->idClase=clase->idClase;
            nuevainscripcion->idCliente=cliente->idCliente;
            return nuevainscripcion;
        }
    }
    return nullptr;
}
void obtenerFechaHora()
{
    static tm ultimaFechaReset = {};  //static mantiene a la variable y la inicializa solo la primera vez que se llama a la funcion
    time_t auxiliar_fecha = time(0);
    tm* hoy = localtime(&auxiliar_fecha);
    tm fecha_hoy;
    fecha_hoy.tm_mday = hoy->tm_mday;
    fecha_hoy.tm_mon = hoy->tm_mon;
    fecha_hoy.tm_year = hoy->tm_year;
    if (hoy->tm_mday != ultimaFechaReset.tm_mday || hoy->tm_mon != ultimaFechaReset.tm_mon || hoy->tm_year != ultimaFechaReset.tm_year) {
        // Resetear el archivo
        reseteararchivo("iriClientes.csv");

        // Actualizar la fecha del último reseteo
        ultimaFechaReset = *hoy;
    }
}
void reseteararchivo(string rutaarchi){
    ofstream ofs;
    ofs.open("iriClientes.csv", ofstream::out | ofstream::trunc);
    ofs.close();
}
void regenerarArchivo(){

}
bool existeSuperposicion(Cliente* cliente, Clases*clase){
    for(int i=0;i<cliente->cantClases;i++){
        if(cliente->clases[i]->horario==clase->horario){
            return true;
        }

    }
    return false;
}
