#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <string>
#include <ctime>

using namespace std;

struct ClasesGym{
    unsigned int idClase;
    string nombre;
    unsigned int horario;
};

struct Inscripcion {
    unsigned int idClase;
    time_t fechaInscripcion;
};
#endif // ARCHIVOS_H
