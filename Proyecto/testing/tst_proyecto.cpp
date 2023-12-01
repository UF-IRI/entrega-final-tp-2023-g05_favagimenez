#include <catch2/catch.hpp>
#include "funciones.h"

/*
TEST_CASE("Prueba de registrarCliente", "[registrarCliente]")
{
    // Configurar datos de prueba
    Cliente* listaClientes = nullptr;
    int tamactual = 0;

    // Llamar a la función registrarCliente con un nuevo cliente
    Cliente nuevoCliente = {1, "Juan", "Perez", "juan@example.com", "123456789", "13-08-2002", 0};
    registrarCliente(listaClientes, &tamactual, nuevoCliente);

    // Realizar aserciones sobre la nueva configuración de listaClientes y tamactual
    REQUIRE(tamactual == 1);
    REQUIRE(listaClientes != nullptr);
    REQUIRE(listaClientes[0].idCliente == 1);
    REQUIRE(listaClientes[0].nombre == "Juan");
    REQUIRE(listaClientes[0].apellido == "Perez");
    REQUIRE(listaClientes[0].email == "juan@example.com");
    REQUIRE(listaClientes[0].telefono == "123456789");
    REQUIRE(listaClientes[0].fechaNac == "13-08-2002");
    REQUIRE(listaClientes[0].estado == 0);


    delete[] listaClientes;
   // REQUIRE(0 == 0);
}
*/
