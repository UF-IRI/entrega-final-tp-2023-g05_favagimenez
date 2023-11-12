#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <string>

using namespace std;
struct Clases {
    string Nombre_clase;
    string sala;
    int horarios[6][6];
    int cupo;
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
