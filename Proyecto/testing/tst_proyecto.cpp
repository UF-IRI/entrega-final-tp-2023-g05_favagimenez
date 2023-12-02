#include <catch2/catch.hpp>
#include "funciones.h"


TEST_CASE("Prueba de registrarCliente", "[registrarCliente]") {
    // Inicializa una lista de clientes vacía
    Cliente* listaClientes = nullptr;
    int N = 0;

    // Llama a la función registrarCliente
    registrarCliente(listaClientes, N);

    REQUIRE(N == 1);
}


TEST_CASE("Prueba de agregar_clases", "[agregar_clase]"){
     // Inicializa una lista de clientes vacía
    Clases*listaclases=nullptr;
    int N=0;
// Llama a la función registrarCliente
    agregar_clases(listaclases,N);
    REQUIRE(N==1);
}


TEST_CASE("existeSuperposicion retorna true si hay superposición", "[existeSuperposicion]") {
Cliente cliente;
cliente.idCliente = 1;
cliente.nombre = "Nombre";
cliente.apellido = "Apellido";
cliente.email = "correo@ejemplo.com";
cliente.telefono = "123456789";
cliente.fechaNac = "01/01/2000";
cliente.estado = 1;

// Creamos clases de prueba
Clases clases[2] = {
    {1, "Clase1", 10.5, 20, 30},
    {2, "Clase2", 15.5, 25, 35}
};
cliente.clases = clases;
cliente.cantClases = new int(2);

// Creamos una clase de prueba con un horario que se superpone con la primera clase del cliente.
Clases clasePrueba = {3, "ClasePrueba", 10.5, 22, 32};

// Verificamos que la función devuelve true en este caso.
REQUIRE(existeSuperposicion(&cliente, &clasePrueba) == true);

// Liberamos la memoria asignada dinámicamente.
delete cliente.cantClases;
}

TEST_CASE("existeSuperposicion retorna false si no hay superposición", "[existeSuperposicion]") {
// Creamos un cliente con dos clases, ninguna de las cuales tiene el mismo horario que la clase de prueba.
Cliente cliente;
cliente.idCliente = 2;
cliente.nombre = "Nombre2";
cliente.apellido = "Apellido2";
cliente.email = "correo2@ejemplo.com";
cliente.telefono = "987654321";
cliente.fechaNac = "02/02/2002";
cliente.estado = 1;

// Creamos clases de prueba
Clases clases[2] = {
    {3, "Clase3", 12.5, 22, 32},
    {4, "Clase4", 17.5, 27, 37}
};
cliente.clases = clases;
cliente.cantClases = new int(2);

// Creamos una clase de prueba con un horario que no se superpone con ninguna de las clases del cliente.
Clases clasePrueba = {5, "ClasePrueba2", 8.5, 24, 34};

// Verificamos que la función devuelve false en este caso.
REQUIRE(existeSuperposicion(&cliente, &clasePrueba) == false);

// Liberamos la memoria asignada dinámicamente.
delete cliente.cantClases;
}
