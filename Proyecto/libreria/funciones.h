#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
    Clases*clases;
    int* cantClases;
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
void agregar_clases(Clases*&lista_clases, Clases *clase, int*tamactual);
Clases*read_archivo_clases(string a1, int*contador);
Cliente* guardarCliente(string archivo, int* cantidadClientes);
time_t obtenerFechaHora();
void leerAsistencias(ifstream &f, string archibinrd);
void reseteararchivo(string rutaarchi, time_t fechadereset);
Clases* leerClase(string& archivo, int* cantidadClases);
bool existeSuperposicion(Cliente* cliente, Clases*clase);
//void reservarClase(Clases*& listaClases, string& nombreClase, int horario, int& cantidadClases);
Inscripcion*reservarClase(Cliente*cliente, Clases*clase);
void regenerarArchivo();
void filtrar_clase(Cliente* cliente, int*tamactual, Clases* lista_clases);
#endif //FUNCIONES_H
