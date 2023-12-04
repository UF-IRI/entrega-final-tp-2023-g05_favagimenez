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

}

void leercliente(ifstream& archi, Cliente* &cliente, int &tamC) {
    if(!archi.is_open())
    {
        cout<<"No se pudo abrir el archivo";
    }


    stringstream ss;
    string encabezado;
    string auxiliarlinea;
    char coma=',';
    string auxIdCliente;
    string auxNombre;
    string auxApellido;
    string auxEmail;
    string auxTelefono;
    string auxFechaNac;
    string auxEstado;


    getline(archi,encabezado);


    while(!archi.eof() && getline(archi,auxiliarlinea))
    {

        registrarCliente(cliente,tamC);
        ss.clear();
        ss<<auxiliarlinea;
        getline(ss,auxIdCliente,coma);
        cliente[tamC-1].idCliente=stoi(auxIdCliente);
        getline(ss,auxNombre,coma);
        cliente[tamC-1].nombre=auxNombre;
        getline(ss,auxApellido,coma);
        cliente[tamC-1].apellido=auxApellido;
        getline(ss,auxEmail,coma);
        cliente[tamC-1].email=auxEmail;
        getline(ss,auxTelefono,coma);
        cliente[tamC-1].telefono=auxTelefono;
        getline(ss,auxFechaNac,coma);
        cliente[tamC-1].fechaNac=auxFechaNac;
        getline(ss,auxEstado,coma);
        cliente[tamC-1].estado=stoi(auxEstado);

        cout<<auxIdCliente<<coma<<auxNombre<<coma<<auxApellido<<coma<<auxEmail<<coma<<auxTelefono<<coma<<auxFechaNac<<coma<<auxEstado<<endl;
    }
}

Inscripcion*reservarClase(Cliente*cliente, Clases*clase){
    int N=*(cliente->cantClases);
    if(!existeSuperposicion(cliente, clase) && !esta_clase(cliente->clases,clase->idClase,N)){ //aca no recorremos en esta funcion porque al llamar la funcion existe superposicion, esa funcion recorre la lista de clases del cliente, llamo a la funcion booleana esta clases, si no esta la clase
        if(clase->cupo<clase->cupoMax){
            cout<<"Se pudo reservar";
             cliente->cantClases++;
            int N=*(cliente->cantClases);
            agregar_clases(cliente->clases,N); //llamo el resize y agrando el tamano +1
            cliente->clases[N-1]=*clase; //en el ultimo espacio agrego la clase
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

void filtrar_clase(Cliente* cliente, int &tamactual)
{
    Clases*arrayaux=new Clases[0];
    int N=0;

    for(int i=0;i<tamactual;i++)
    {
        Clases claseaux=cliente->clases[i];
        if(!esta_clase(arrayaux,claseaux.idClase,N)){ //si la clase no esta lo inserto
            agregar_clases(arrayaux,N);
            arrayaux[N]=claseaux;
        }

    }  //actualizo las clases del cliente con el arreglo filtrado
    cliente->clases=arrayaux;
    cliente->cantClases=&N;
}
bool esta_clase(Clases*clases, int id, int tam){
    bool toR=false;
    int i=0;
    while(i<tam&&!toR){
        if(clases[i].idClase==id){
            toR=true;

        }
        else
            i++;
    }
    return toR;
}
