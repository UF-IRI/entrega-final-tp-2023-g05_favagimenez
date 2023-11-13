#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "gimnasio.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Clases {
    unsigned idClase;
    string nombre;
  //  string sala;
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
    char fechaNac;
    int estado;
    Clases turnos;
};

struct Inscripcion {
    unsigned int idClase;
    time_t fechaInscripcion;
};
typedef struct {

    unsigned int idCliente, cantInscriptos;

    Inscripcion* CursosInscriptos;

} sAsistencia;

struct Gimnasio {
    Cliente* listaDeClientes;
    Clases ClasesSemanales[6];
};

void registrarCliente(Cliente*& listaClientes, int* tamactual, Cliente nuevoCliente);
void agregar_clases(Clases*&lista_clases, Clases clase, int*tamactual);
//void agregar_inscripciones(Inscripcion*&lista_inscripciones, Inscripcion inscripciones, int*tamactual);
//void agregar_asistencia(sAsistencia *&lista_asistencia, sAsistencia asistencias,int*tamactual);
void resize(Cliente*& clientes, unsigned int& tamC);
void read_archivo_clientes(ifstream &archi, Cliente*&clientes, unsigned int*tamC);
Clases*read_archivo_clases(string a1, int*contador);
Cliente* guardarCliente(string& archivo, int& cantidadClientes);
tm* obtenerFechaHora(string cadena);

sAsistencia*leerArchivoBinario(string nombreArchivo, int*cantAsistencia);
/*void registrarCliente(Gimnasio& gym);
bool existeSuperposicion(Clases* clase, string& claseAReservar);
void reservarClase(Gimnasio& gym);
*/
#endif // FUNCIONES_H
