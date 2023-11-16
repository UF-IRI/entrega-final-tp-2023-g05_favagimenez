#ifndef FUNCIONES_H
#define FUNCIONES_H
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
    Clases*clases;
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
void registrarCliente(Cliente*& listaClientes, int *tamactual,  Cliente nuevoCliente) ;
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
#endif //FUNCIONES_H
