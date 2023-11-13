#include "funciones.h"
#include <iostream>

using namespace std;

void registrarCliente(Cliente*& listaClientes, int *tamactual,  Cliente nuevoCliente) {
    *tamactual=*tamactual+1;
    Cliente* aux = new Cliente[*tamactual];
    int i=0;
    while (i < *tamactual - 1 && *tamactual - 1 != 0) {
        aux[i] = listaClientes[i];
        i++;
    }
    aux[i] = nuevoCliente;
    delete[] listaClientes;
    listaClientes = aux;
}
void agregar_clases(Clases*&lista_clases, Clases clase, int*tamactual){
    *tamactual=*tamactual+1;
    int i=0;
    Clases*aux=new Clases[*tamactual];
    while(i<*tamactual-1&&*tamactual-1!=0){
        aux[i]=lista_clases[i];
        i++;
    }
    aux[i]=clase;
    delete[]lista_clases;
    lista_clases=aux;

}
void resize(Cliente*& clientes, unsigned int& tamC){
    if(clientes==nullptr){
        if(tam<=0){
            clientes = new Cliente[++tam];
        }
        return;
    }

    Cliente* temporal = new Cliente[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = clientes[i];

    delete[] clientes;

    clientes = temporal;
}
void read_archivo_clientes(ifstream &archi, Cliente *&clientes, unsigned int *tamC){
    string linea;
    stringstream ss;

    if (archi.is_open()) {
        getline(archi, linea); // Leer encabezado, si es necesario

        while (getline(archi, linea)) {
            ss.clear();
            ss << linea;

            // Incrementar el tamaño del arreglo de clientes
            resize(clientes, tamC);

            // Leer los campos y asignarlos a la estructura Cliente
            ss >> clientes[tamC - 1].idCliente;
            ss.ignore(); // Ignorar la coma
            getline(ss, clientes[tamC - 1].nombre, ',');
            getline(ss, clientes[tamC - 1].apellido, ',');              //VER
            getline(ss, clientes[tamC - 1].email, ',');
            getline(ss, clientes[tamC - 1].telefono, ',');
            ss >> clientes[tamC - 1].fechaNac;
            ss.ignore(); // Ignorar la coma
            ss >> clientes[tamC - 1].estado;
        }
    }
}
sAsistencia*leerArchivoBinario(string nombreArchivo, int* cantAsistencias){
    ifstream archibinrd(nombreArchivo, ios::binary);

    if (!archibinrd.is_open()) {
       cout << "Error al abrir el archivo para lectura." <<endl;
        return nullptr;
    }
     sAsistencia* asistencias = new sAsistencia[*cantAsistencias];

    for (int i = 0; i < *cantAsistencias; ++i) {
        archibinrd.read((char*)asistencias[i].idCliente, sizeof(unsigned int));
        archibinrd.read((char*)asistencias[i].cantInscriptos, sizeof(unsigned int));

        asistencias[i].CursosInscriptos = new Inscripcion[asistencias[i].cantInscriptos];

        archibinrd.read((char*)asistencias[i].CursosInscriptos,
                        sizeof(Inscripcion) * asistencias[i].cantInscriptos);
    }

    archibinrd.close();

    return asistencias;
}
/*
Clases* cargarClases(string& archivo, int& cantidadClases) {
    int MAX_CLASES = 6;
    Clases* listaClases = new Clases[MAX_CLASES];
    cantidadClases = 0;
    ifstream infile(archivo);
    if (!infile.is_open()) {
        std::cout << "Error al leer archivo";
        return nullptr;
    }
    string line;
    getline(infile, line);//////
    while (cantidadClases < MAX_CLASES && getline(infile, line)) {
        stringstream ss(line);
        ss >> listaClases[cantidadClases].Nombre_clase >> listaClases[cantidadClases].sala;
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                ss >> listaClases[cantidadClases].horarios[j][k];
            }
        }
        ss >> listaClases[cantidadClases].cupoMax;
        listaClases[cantidadClases].cupo = 0;
        cantidadClases++;
    }
    infile.close();
    return listaClases;
}*/
/*Cliente* guardarCliente(string& archivo, int& cantidadClientes) {
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
}*/
tm* obtenerFechaHora(string cadena)
{
    tm* ltm = new tm;
    int i = 0;
    int j = 0;
    string dia, mes, anio, hora, minuto = " ";
    while (i<cadena.length()) {
        char aux = cadena[i];
        if (aux !='/'&&aux != ' '&&aux!=':') {
            if (j==0)
                dia += aux;
            else if (j==1)
                mes += aux;
            else if (j==2)
                anio += aux;
            else if (j==3)
                hora += aux;
            else if (j==4)
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
