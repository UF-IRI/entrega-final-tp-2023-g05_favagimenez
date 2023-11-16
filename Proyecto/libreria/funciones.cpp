#include "funciones.h"
#include <iostream>

using namespace std;

void registrarCliente(Cliente*& listaClientes, int *tamactual,  Cliente nuevoCliente) {
    *tamactual=*tamactual+1;
    Cliente* aux = new Cliente[*tamactual];
    int i=0;
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
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
        /*getline(ss, nuevoCliente.fechaNac, coma);*/
        ss>>nuevoCliente.estado;
        registrarCliente(listaClientes, cantidadClientes, nuevoCliente);
        cantidadClientes++;
    }
    infile.close();
    return listaClientes;
}
tm* obtenerFechaHora(string cadena)
{
    tm* ltm = new tm;
    int i = 0;
    int j = 0;
    string dia, mes, anio, hora, minuto = " ";
    while (i<cadena.length()) {
        char aux = cadena[i];
        if (aux !='/'&&aux != ' '&&aux!=':') {
            if (j==0)
                dia += aux;
            else if (j==1)
                mes += aux;
            else if (j==2)
                anio += aux;
            else if (j==3)
                hora += aux;
            else if (j==4)
                minuto += aux;
        }
        else {
            j++;
        }
        i++;
    }
    ltm->tm_year = stoi(anio) - 1900;
    ltm->tm_mday =stoi(dia);
    ltm->tm_mon =stoi(mes) - 1;
    ltm->tm_hour =stoi(hora);
    ltm->tm_min = stoi(minuto);
    return ltm;
}
bool existeSuperposicion(Clases* clase, int numClases, string& claseAReservar, float horarReserva)
{
    for(int i=0;i<numClases;i++)
    {
        if(clase[i].nombre==claseAReservar)
        {
            float difHorario=clase[i].horario-horarReserva;
            if(difHorario<0)
            {
                difHorario=-difHorario;
            }
            if(difHorario<1)
            {
                return true;
            }

        }
    }
    return false;
}
/*
 * /*sAsistencia*leerArchivoBinario(string nombreArchivo, int* cantAsistencias){
    ifstream archibinrd(nombreArchivo, ios::binary);

    if (!archibinrd.is_open()) {
       cout << "Error al abrir el archivo para lectura." <<endl;
        return nullptr;
    }
     sAsistencia* asistencias = new sAsistencia[*cantAsistencias];

    for (int i = 0; i < *cantAsistencias; ++i) {
        archibinrd.read((char*)asistencias[i].idCliente, sizeof(unsigned int));
        archibinrd.read((char*)asistencias[i].cantInscriptos, sizeof(unsigned int));

        asistencias[i].CursosInscriptos = new Inscripcion[asistencias[i].cantInscriptos];

        archibinrd.read((char*)asistencias[i].CursosInscriptos,
                        sizeof(Inscripcion) * asistencias[i].cantInscriptos);
    }

    archibinrd.close();

    return asistencias;
}

*/

