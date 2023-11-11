#include "funciones.h"
#include <iostream>

using namespace std;

void registrarCliente(Gimnasio& gym) {
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

/*bool existeSuperposicion(Cliente* cliente, string& claseAReservar){
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
