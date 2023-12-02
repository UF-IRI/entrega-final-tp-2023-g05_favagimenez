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


