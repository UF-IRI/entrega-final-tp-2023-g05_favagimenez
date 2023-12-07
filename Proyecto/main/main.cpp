#include<iostream>
#include<fstream>
#include "funciones.h"
using namespace std;

int main() {
    cout<<"hola"<<endl;
    ifstream archivobinario;
  archivobinario.open("asistencia.dat", ios::binary);
  int cantasistencia=2;
  sAsistencia*arrayasistencia=new sAsistencia[cantasistencia];
 arrayasistencia= leerAsistencias("asistencias.dat");


   //ABRO ARCHIVO CLASES
   ifstream archivo_clase;
   archivo_clase.open("iriClasesGYM.csv");
   int N=0;
   Clases*lista_clases=new Clases[N];
   leerClases(archivo_clase,lista_clases,N);

   //ABRIR ARCHIVO CLIENTE
   ifstream archivo_cliente;
     archivo_cliente.open("iriClientesGYM.csv");
   int cantclientes=0;
    Cliente*lista_clientes=new Cliente[cantclientes];
   //leo el archivo de clientes
   leercliente(archivo_cliente,lista_clientes,cantclientes);


   //los siguientes for son para verificar que la lista este bien
  /*  for(int i=0;i<cantasistencia;i++){
        cout<<arrayasistencia[i].idCliente<<endl;
    }
    for(int j=0;j<N;j++){
        cout<<lista_clases[j].idClase<<endl;
    }
    for(int k=0;k<cantclientes;k++){
        cout<<lista_clientes[k].nombre<<endl;
    }*/ //imprime todo okkk

    lista_clases[0].nombre="Spinning";
    lista_clases[0].cupoMax=45;
    lista_clases[1].nombre="Yoga";
    lista_clases[1].cupoMax=25;
    lista_clases[2].nombre="Pilates";
    lista_clases[2].cupoMax=15;
    lista_clases[3].nombre="Stretching";
    lista_clases[3].cupoMax=40;
    lista_clases[4].nombre="Zumba";
    lista_clases[4].cupoMax=50;
    lista_clases[5].nombre="Boxeo";
    lista_clases[5].cupoMax=30;
    lista_clases[6].nombre="Musculacion";
    lista_clases[6].cupoMax=30;

    //PARA RESERVAR CLASE

    int PersonasAInscribirse=5;
 if(existeidcliente(lista_clientes,cantclientes,lista_clientes->idCliente)&&!existeSuperposicion(lista_clientes,lista_clases)){
    for(int i=0 ; i<PersonasAInscribirse;i++){

        Cliente* clienteActual=&lista_clientes[0];
        Clases* ClaseElegida=&lista_clases[0];
        Reserva(clienteActual,ClaseElegida,arrayasistencia,cantasistencia);

        std::cout<<"La Reserva fue exitosa, para el cliente con id:"<<clienteActual->idCliente<<"Para la clase"<<ClaseElegida->nombre<<"a las"<<ClaseElegida->horario<< endl;
    }
    }
    time_t now = time(0);
    tm* today = localtime(&now);
    // Restar un día (86400 segundos) para obtener la fecha de ayer
    time_t yesterday_time = now - 86400;
    tm* yesterday = localtime(&yesterday_time);
    tm* fecha_reset=yesterday;

   reseteararchivo("iriClientes.csv", fecha_reset);
  resetearbinario("asistencia.dat", fecha_reset);


    archivobinario.close();
    archivo_clase.close();
    archivo_cliente.close();
    delete[]arrayasistencia;
    delete[]lista_clases;
    delete[]lista_clientes;
     return 0;
}


