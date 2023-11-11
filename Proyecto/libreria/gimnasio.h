#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <string>

using namespace std;
struct Clases {
    string Nombre_clase;
    string Hora_inicio;
    int cupoActual;
    int cupoMax;
};

struct Musculacion {
    string nombre;
    int cupoMax = 30;
};

struct Cliente {
    string nombre;
    string apellido;
    string dni;
    string email;
    int numero_telefono;
    Clases turnos;
};

struct Gimnasio {
    Cliente* listaDeClientes;
    Clases ClasesSemanales[6];
};



#endif // GIMNASIO_H
