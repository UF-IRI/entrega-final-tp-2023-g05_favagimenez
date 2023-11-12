/*
 ../OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClasesGYM";
../OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClientesGYM";
..//OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"asistencias_1697673600000";
*/
int main(int argc, char *argv[]) {
    // "../gngng/
    int cantidadClientes;
    Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", cantidadClientes);
    delete[] listaClientes;

    return 0;
}
