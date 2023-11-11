#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "gimnasio.h"
#include <string>
using namespace std;

void registrarCliente(Gimnasio& gym);
bool existeSuperposicion(Clases* clase, string& claseAReservar);
void reservarClase(Gimnasio& gym);

#endif // FUNCIONES_H
