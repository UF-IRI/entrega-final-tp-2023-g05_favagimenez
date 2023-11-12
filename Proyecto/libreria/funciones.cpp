#include "funciones.h"
#include <iostream>

using namespace std;

void registrarCliente(Cliente*& listaClientes, int& N,  Cliente& nuevoCliente) {
    Cliente* aux = new Cliente[N+1];

    for (int i = 0; i < N; i++) {
        aux[i] = listaClientes[i];
    }
    aux[N++] = nuevoCliente;
    delete[] listaClientes;
    listaClientes = aux;
}

Cliente* guardarCliente(string& archivo, int& cantidadClientes) {
    Cliente* listaClientes = nullptr;
    cantidadClientes = 0;
    ifstream infile(archivo);
    if (!infile.is_open()) {
        cout << "Error al leer archivo";
        return;
    }
    string line;
    char coma = ',';
    getline(infile, line);
    while (getline(infile, line)) {
        stringstream ss(line);
        Cliente nuevoCliente;
        getline(ss, nuevoCliente.nombre, coma);
        getline(ss, nuevoCliente.apellido, coma);
        getline(ss, nuevoCliente.dni, coma);
        getline(ss, nuevoCliente.email, coma);
        getline(ss, nuevoCliente.numero_telefono);
        registrarCliente(listaClientes, cantidadClientes, nuevoCliente);
    }
    infile.close();
    return listaClientes;
}
tm* obtenerFechaHora(string cadena)
{
    tm* ltm = new tm;
    int i = 0;
    int j = 0;
    string dia, mes, anio, hora, minuto = "";
    while (i < cadena.length()) {
        char aux = cadena[i];
        if (aux != '/' && aux != ' ' && aux != ':') {
            if (j == 0)
                dia += aux;
            else if (j == 1)
                mes += aux;
            else if (j == 2)
                anio += aux;
            else if (j == 3)
                hora += aux;
            else if (j == 4)
                minuto += aux;
        }
        else {
            j++;
        }
        i++;
    }
    ltm->tm_year = stoi(anio) - 1900;
    ltm->tm_mday =stoi(dia);
    ltm->tm_mon =stoi(mes) - 1;
    ltm->tm_hour =stoi(hora);
    ltm->tm_min = stoi(minuto);
    return ltm;
}

/*
    Cliente nuevoCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nuevoCliente.nombre;
    cout << "Ingrese el apellido: ";
    cin >> nuevoCliente.apellido;
    cout << "Ingrese el dni: ";
    cin >> nuevoCliente.dni;
    cout << "Ingrese el email del cliente: ";
    cin >> nuevoCliente.email;
    cout << "Ingrese el numero de telefono del cliente: ";
    cin >> nuevoCliente.numero_telefono;

    //gym.listaDeClientes

    // Hay que agregar el nuevo cliente a la lista de clientes pero tengo dudas asi que fijate si te sale jeje

    cout << "Cliente registrado" << endl;
}
 *
 * bool existeSuperposicion(Cliente* cliente, string& claseAReservar){
    // Recorre las clases ya reservadas por el cliente
    for (int i = 0; i < Cliente.turnos; ++i) {
        // Comprueba si la clase a reservar tiene superposición con alguna clase ya reservada
        if (Cliente.turnos[i].Nombre_clase == claseAReservar) {
            cout << "El cliente ya tiene una clase de " << Cliente.turnos[i].Nombre_clase << " reservada." << endl;
            return true;  // Hay superposición
        }
    }
    Cliente.turnos.Nombre_clase;

    // No hay superposición
    return false;
}
*/
