#include "funciones.h"
/*#include <iostream>
#include <string>

using namespace std;

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
            cliente->clases[cliente->cantClases]=clase;
            cliente->cantClases++;
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
        if(cliente->clases[i].horario==clase->horario){
            return true;
        }

    }
    return false;
}*/

