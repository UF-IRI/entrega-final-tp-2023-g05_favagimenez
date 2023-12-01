#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>

#define MAXCLASES 200
using namespace std;
struct Clases {
    int idClase;
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

void registrarCliente(Cliente*& listaClientes, int &N);
void agregar_clases(Clases*& clase, int& N);
Clases*read_archivo_clases(string a1, int*contador);
void leercliente(string archivo, int* cantidadClientes);
time_t obtenerFechaHora();
void leerAsistencias(string archibinrd);
void reseteararchivo(string rutaarchi, time_t fechadereset);
void resetearbinario(string rutaarchi, tm* fechadereset);
Clases* leerClase(string archivo, int* cantidadClases);
void leerClases(ifstream& archi, Clases* &clase, int &tamC);
bool existeSuperposicion(Cliente* cliente, Clases*clase);
//void reservarClase(Clases*& listaClases, string& nombreClase, int horario, int& cantidadClases);
Inscripcion*reservarClase(Cliente*cliente, Clases*clase);
void regenerarArchivo();

#endif //FUNCIONES_H
