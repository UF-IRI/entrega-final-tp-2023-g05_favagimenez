#include "funciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
void agregar_clases(Clases*&lista_clases, Clases* clase, int*tamactual){
    *tamactual=*tamactual+1;
    int i=0;
    Clases*aux=new Clases[*tamactual];
    while(i<*tamactual-1&&*tamactual-1!=0){
        aux[i]=lista_clases[i];
        i++;
    }
    aux[i]=*clase;
    delete[]lista_clases;
    lista_clases=aux;
}
void leerAsistencias(string archibinrd) {
   ifstream f(archibinrd, ios::out | ios::binary);

    cout<<archibinrd;
    if (f.is_open()) {

        sAsistencia asistencia;
        while (f.read((char*)&asistencia, sizeof(sAsistencia))) {
            cout << "ID del cliente: " << asistencia.idCliente << endl;
            cout << "Cantidad de cursos a los que se inscribio: "<< asistencia.cantInscriptos << endl;
            for (int i = 0; i < asistencia.cantInscriptos; i++) {
                Inscripcion inscripcion;
                f.read((char*)&inscripcion, sizeof(Inscripcion));
                cout << "ID clase: " << inscripcion.idClase<< endl;
                cout << "Fecha de inscripcion: "<< inscripcion.fechaInscripcion << endl;
            }
        }
    }
    else
        cout<<"Error al leer archivo";
    f.close();
}
/*Clases* leerClase(string archivo, int* cantidadClases) {
    Clases* listaClases = nullptr;
    *cantidadClases = 0;

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
        agregar_clases(listaClases, &nuevaClase, cantidadClases);
    }
    infile.close();
    return listaClases;
}*/
void leerClases(ifstream &archi, Clases* &clase, int &tamC){
    string linea;
    stringstream s;
    Clases*clasess=new Clases[tamC];
    if(archi.is_open()){

        getline(archi, linea);

        while(archi.good()){

            s<<linea;

            agregar_clases(clase,clasess,&tamC);

            getline(s, linea, ',');
            clase[tamC-1].idClase = stoi(linea);
            getline(s,linea, ',');
            clase[tamC-1].nombre=linea[1];
            getline(s, linea, ',');
            clase[tamC-1].horario=stof(linea);
            getline(s, linea);

        }
    }
    delete[]clasess;
}

Cliente* guardarCliente(string archivo, int* cantidadClientes) {
    Cliente* listaCliente=new Cliente[0];
    *cantidadClientes=0;
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
        registrarCliente(listaCliente, cantidadClientes, nuevoCliente);
    }
    infile.close();
    return listaCliente;
}
Inscripcion*reservarClase(Cliente*cliente, Clases*clase){
    if(!existeSuperposicion(cliente, clase)){ //aca no recorremos en esta funcion porque al llamar la funcion existe superposicion, esa funcion recorre la lista de clases del cliente
        if(clase->cupo<clase->cupoMax){
            cout<<"Se pudo reservar";
             cliente->cantClases++;
            agregar_clases(cliente->clases,clase, cliente->cantClases);
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
time_t obtenerFechaHora()
{

time_t auxiliar_fecha = time(0);
//
return auxiliar_fecha;
}
void reseteararchivo(string rutaarchi, tm* fechadereset){
    time_t auxiliar_fecha = time(0);
    tm* hoy = localtime(&auxiliar_fecha);
   if(hoy->tm_mday!=fechadereset->tm_mday)
    {
        ofstream ofs;
        ofs.open("iriClientes.csv", ofstream::out | ofstream::trunc);
        fechadereset=hoy;
        ofs.close();
    }
}
void resetearbinario(string rutaarchi, tm* fechadereset){
    time_t auxiliar_fecha = time(0);
    tm* hoy = localtime(&auxiliar_fecha);
    if(hoy->tm_mday!=fechadereset->tm_mday)
    {
        ofstream ofs;
        ofs.open("asistencia.dat", ofstream::out | ofstream::trunc);
        fechadereset=hoy;
        ofs.close();
    }
}
bool existeSuperposicion(Cliente* cliente, Clases*clase){

    for(int i=0;i<*cliente->cantClases;i++){
        if(cliente[i].clases->horario==clase->horario){
            return true;
        }

    }
    return false;
}
/*void filtrar_clase(Cliente* cliente, int*tamactual)
{
    for(int i=0;i<*tamactual;i++)
    {
        int id_clase=cliente[i].clases->idClase;
    }
}*/

