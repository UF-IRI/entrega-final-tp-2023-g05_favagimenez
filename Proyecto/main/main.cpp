/*
 ../OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClasesGYM";
../OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"iriClientesGYM";
..//OneDrive - Universidad Favaloro/entrega-final-tp-2023-g05_favagimenez/Proyecto/"asistencias_1697673600000";
*/
int main(int argc, char *argv[]) {
    // "../gngng/
    int cantidadClientes;
    int cantidadClases;
    Cliente* listaClientes = guardarCliente("iriClientesGYM.csv", cantidadClientes);
    delete[] listaClientes;
    int cantidadClases;
    Clases* listaClases = cargarClases("iriClasesGYM", cantidadClases);
    delete[] listaClases;
    return 0;
}
