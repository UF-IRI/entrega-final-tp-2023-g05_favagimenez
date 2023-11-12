#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "gimnasio.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


void registrarCliente(Cliente*& listaClientes, int& N, const Cliente& nuevoCliente);
Cliente* guardarCliente(string& archivo, int& cantidadClientes);
tm* obtenerFechaHora(string cadena);
/*void registrarCliente(Gimnasio& gym);
bool existeSuperposicion(Clases* clase, string& claseAReservar);
void reservarClase(Gimnasio& gym);
*/
#endif // FUNCIONES_H
