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



void registrarCliente(Cliente*& listaClientes, int* tamactual, Cliente nuevoCliente);
void agregar_clases(Clases*&lista_clases, Clases clase, int*tamactual);
Clases*read_archivo_clases(string a1, int*contador);
Cliente* guardarCliente(string& archivo, int* cantidadClientes);
tm* obtenerFechaHora(string cadena);
void leerAsistencias(string& archibinrd);
Clases* leerClase(string& archivo, int* cantidadClases);
bool existeSuperposicion(Cliente* clase, int numClases, string& claseAReservar, float horarReserva);

#endif // FUNCIONES_H
