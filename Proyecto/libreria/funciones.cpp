#include "funciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void registrarCliente(Cliente*& listaClientes, int& N) {
    N=N+1;
    Cliente* aux= new Cliente[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=listaClientes[i];
    }

    delete[] listaClientes;
    listaClientes=aux;
}
void agregar_clases(Clases*& clase, int& N){

    N=N+1;
    Clases* aux= new Clases[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=clase[i];
    }

    delete[] clase;
    clase=aux;
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

void leerClases(ifstream& archi, Clases* &clase, int &tamC){
    if(!archi.is_open())
    {
        cout<<"No se pudo abrir el archivo";
    }


    stringstream ss;
    string encabezado;
    string auxiliarlinea;
    char delimiter=',';
    string auxIdClase;
    string auxNombreClase;
    string auxHorario;


    getline(archi,encabezado);


    while(!archi.eof() && getline(archi,auxiliarlinea))
    {

        agregar_clases(clase,tamC);
        ss.clear();
        ss<<auxiliarlinea;
        getline(ss,auxIdClase,delimiter);
        clase[tamC-1].idClase=stoi(auxIdClase);
        getline(ss,auxNombreClase,delimiter);
        clase[tamC-1].nombre=auxNombreClase;
        getline(ss,auxHorario,delimiter);
        clase[tamC-1].horario=stof(auxHorario);
        cout<<auxIdClase<<delimiter<<auxNombreClase<<delimiter<<auxHorario<<endl;
    }

   /* string linea;
    stringstream s;


    cout<<"Estoy en leer clase";
    if(archi.is_open()){

        getline(archi, linea);
        if(archi.eof()){
            cout<<"Llegue a fin del archivo";
        }
        while(!archi.eof()){
            cout<<"Estoy en el while";
            getline(s,linea,archi);
            cout<<linea;
            s<<linea;
            agregar_clases(clase,tamC);
            s.clear();
            getline(s, linea, ',');
            clase[tamC-1].idClase = stoi(linea);
            getline(s,linea, ',');
            clase[tamC-1].nombre=linea[1];
            getline(s, linea, ',');
            clase[tamC-1].horario=stof(linea);
            getline(s, linea);

            cout<<linea<<endl;

        }
    }*/

}

void leercliente(ifstream& archi, Cliente* &cliente, int &tamC) {
    string linea;
    stringstream s;

    archi.open("../iriClientesGYM.csv");

    if(archi.is_open()){

        getline(archi, linea);

        while(archi){

            s<<linea;
            registrarCliente(cliente,tamC);

            getline(s, linea, ',');
            cliente[tamC-1].idCliente = stoi(linea);
            getline(s,linea, ',');
            cliente[tamC-1].nombre=linea[1];
            getline(s, linea, ',');
            cliente[tamC-1].apellido=linea[2];
            getline(s, linea);
            cliente[tamC-1].email=linea[3];
             getline(s, linea);
            cliente[tamC-1].telefono=linea[4];
              getline(s, linea);
            cliente[tamC-1].fechaNac=linea[5];
              getline(s, linea);
            cliente[tamC-1].estado=stoi(linea);
               getline(s, linea);
            cout<<linea<<endl;

        }
    }
}
/*
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
}*/
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
        else
            return false;

    }
}

/*void filtrar_clase(Cliente* cliente, int*tamactual)
{
    for(int i=0;i<*tamactual;i++)
    {
        int id_clase=cliente[i].clases->idClase;
    }
}*/

