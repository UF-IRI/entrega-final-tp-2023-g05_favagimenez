#include "funciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

void registrarCliente(Cliente*& listaClientes, int& N) {
    N=N+1;
    Cliente* aux= new Cliente[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=listaClientes[i];
    }

    delete[] listaClientes;
    listaClientes=aux;
}
void agregar_clases(Clases*& clase, int& N){

    N=N+1;
    Clases* aux= new Clases[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=clase[i];
    }

    delete[] clase;
    clase=aux;
}
void resizeAsistencia(sAsistencia*& asistencias, int& N)
{
    N=N+1;
    sAsistencia* aux= new sAsistencia[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=asistencias[i];
    }
    delete[] asistencias;
    asistencias=aux;
}
void resizeInscripcion(Inscripcion*& inscripciones, int& N)
{
    N=N+1;
    Inscripcion* aux= new Inscripcion[N];
    for(int i=0; i<N-1;i++)
    {
        aux[i]=inscripciones[i];
    }
    delete[] inscripciones;
    inscripciones=aux;
}
sAsistencia* leerAsistencias(string archibinrd) {
      sAsistencia* lista_asistencia=new sAsistencia[1000];

      int i=0;
   ifstream f(archibinrd, ios::out | ios::binary);
  //  cout<<"vqer"<<endl;
    cout<<archibinrd;
    if (f.is_open()) {

        sAsistencia asistencia;

        while (f.read((char*)&asistencia, sizeof(sAsistencia))) {


            cout << "ID del cliente: " << asistencia.idCliente << endl;
            cout << "Cantidad de cursos a los que se inscribio: "<< asistencia.cantInscriptos << endl;

          int cantinscriptos=0;
            Inscripcion*lista_inscripciones=new Inscripcion[1000];
            for (int i = 0; i < asistencia.cantInscriptos; i++) {
                Inscripcion inscripcion;
                f.read((char*)&inscripcion, sizeof(Inscripcion));
                cout << "ID clase: " << inscripcion.idClase<< endl;
                cout << "Fecha de inscripcion: "<< inscripcion.fechaInscripcion << endl;
                lista_inscripciones[i]=inscripcion;

            }

            asistencia.CursosInscriptos=lista_inscripciones;
            lista_asistencia[i++]=asistencia;


        }
    }
    else
        cout<<"Error al leer archivo";

    f.close();

    return lista_asistencia;
}



void leerClases(ifstream& archi, Clases* &clase, int &tamC){
    if(!archi.is_open())
    {
        cout<<"No se pudo abrir el archivo";
    }


    stringstream ss;
    string encabezado;
    string auxiliarlinea;
    char delimiter=',';
    string auxIdClase;
    string auxNombreClase;
    string auxHorario;


    getline(archi,encabezado);


    while(!archi.eof() && getline(archi,auxiliarlinea))
    {

        agregar_clases(clase,tamC);
        ss.clear();
        ss<<auxiliarlinea;
        getline(ss,auxIdClase,delimiter);
        clase[tamC-1].idClase=stoi(auxIdClase);
        getline(ss,auxNombreClase,delimiter);
        clase[tamC-1].nombre=auxNombreClase;
        getline(ss,auxHorario,delimiter);
        clase[tamC-1].horario=stof(auxHorario);
        cout<<auxIdClase<<delimiter<<auxNombreClase<<delimiter<<auxHorario<<endl;
    }

}

void leercliente(ifstream& archi, Cliente* &cliente, int &tamC) {
    if(!archi.is_open())
    {
        cout<<"No se pudo abrir el archivo";
    }


    stringstream ss;
    string encabezado;
    string auxiliarlinea;
    char coma=',';
    string auxIdCliente;
    string auxNombre;
    string auxApellido;
    string auxEmail;
    string auxTelefono;
    string auxFechaNac;
    string auxEstado;


    getline(archi,encabezado);


    while(!archi.eof() && getline(archi,auxiliarlinea))
    {

        registrarCliente(cliente,tamC);
        ss.clear();
        ss<<auxiliarlinea;
        getline(ss,auxIdCliente,coma);
        cliente[tamC-1].idCliente=stoi(auxIdCliente);
        getline(ss,auxNombre,coma);
        cliente[tamC-1].nombre=auxNombre;
        getline(ss,auxApellido,coma);
        cliente[tamC-1].apellido=auxApellido;
        getline(ss,auxEmail,coma);
        cliente[tamC-1].email=auxEmail;
        getline(ss,auxTelefono,coma);
        cliente[tamC-1].telefono=auxTelefono;
        getline(ss,auxFechaNac,coma);
        cliente[tamC-1].fechaNac=auxFechaNac;
        getline(ss,auxEstado,coma);
        cliente[tamC-1].estado=stoi(auxEstado);

        cliente[tamC-1].clases= new Clases[0]; //inicializar la lista en 0
        int N=0;
        cliente[tamC-1].cantClases=&N;
        cout<<auxIdCliente<<coma<<auxNombre<<coma<<auxApellido<<coma<<auxEmail<<coma<<auxTelefono<<coma<<auxFechaNac<<coma<<auxEstado<<endl;
    }


}


time_t obtenerFechaHora()
{

time_t auxiliar_fecha = time(0);

return auxiliar_fecha;
}
void reseteararchivo(string rutaarchi, tm* fechadereset){
    time_t auxiliar_fecha = time(0);
    tm* hoy = localtime(&auxiliar_fecha);
   if(hoy->tm_mday!=fechadereset->tm_mday)
    {
        ofstream ofs;
        ofs.open("iriClientes.csv", ofstream::out | ofstream::trunc);
        *fechadereset=*hoy;
        ofs.close();
    }
}
void resetearbinario(string rutaarchi, tm* fechadereset){
    time_t auxiliar_fecha = time(0);
    tm* hoy = localtime(&auxiliar_fecha);
    if(hoy->tm_mday!=fechadereset->tm_mday)
    {
        ofstream ofs;
        ofs.open("asistencia.dat", ofstream::out | ofstream::trunc);
        *fechadereset=*hoy;
        ofs.close();
    }
}
bool existeSuperposicion(Cliente* cliente, Clases*clase){

    for(int i=0;i<*cliente->cantClases;i++){
        if(cliente[i].clases->horario==clase->horario){
            return true;
        }
        else
            return false;

    }
}


bool esta_clase(Clases*clases, int id, int tam){
    bool toR=false;
    int i=0;
    while(i<tam&&!toR){
        if(clases[i].idClase==id){
            toR=true;

        }
        else
            i++;
    }
    return toR;
}

Cliente* randomcliente(Cliente *cliente, int numClientes){
    if (numClientes <= 0) {
        return nullptr;  // No hay clientes disponibles
    }

    int ClienteAleatorio = rand() % 250;

    Cliente& CleinteSeleccionado = cliente[ClienteAleatorio];
    Cliente* punteroSCliente = new Cliente{CleinteSeleccionado.idCliente, CleinteSeleccionado.nombre, CleinteSeleccionado.apellido, CleinteSeleccionado.email ,CleinteSeleccionado.telefono, CleinteSeleccionado.fechaNac, CleinteSeleccionado.estado};
    return punteroSCliente;

    return punteroSCliente;
}
int existeidcliente(Cliente*& lista_clientes, int cantclientes, int id)
{
    int i;
    for(i=0; i<cantclientes; i++)
    {
        if(lista_clientes[i].idCliente == id)
            return 1; //se encontro, por lo tanto existe id
    }
    return -1; //no se encontro, por lo tanto no esta inscripto
}



void AgregarClienteArchivoInscri(Cliente*& cliente, sAsistencia*& asistPrev, int& n,int idCurso){
    int cont=0;
    for (int i=0;i<n;i++) //si esta el cliente subido con otra clase
    {
        if(asistPrev[i].idCliente==cliente->idCliente){ // Verifica si el cliente ya está inscripto
            cont++;
             // Incrementar la cantidad de cursos inscriptos para este cliente
            asistPrev[i].cantInscriptos=asistPrev[i].cantInscriptos+1;

            // Asignar memoria para el nuevo curso inscripto
            asistPrev[i].CursosInscriptos = new Inscripcion[asistPrev[i].cantInscriptos];

            // Asignar la fecha de inscripción y el ID del curso al nuevo curso inscripto
            asistPrev[i].CursosInscriptos[asistPrev[i].cantInscriptos - 1].fechaInscripcion = time(0);
            asistPrev[i].CursosInscriptos[asistPrev[i].cantInscriptos - 1].idClase = idCurso;
        }

    }
    if (cont==0){
        // No se encontró al cliente inscrito en ninguna clase anterior

        // Realizar un resize para darle lugar en memoria
        int N;
        N=(n)+1;
        sAsistencia *aux= new sAsistencia [N];
        // Copiar los elementos anteriores a la nueva memoria
        for(int i=0;i<N-1;i++){
            aux [i]= asistPrev [ i ];
        }
        aux[N-1].cantInscriptos=1;

        // Asignar memoria para el nuevo curso inscripto
        aux[N-1].CursosInscriptos = new Inscripcion[aux[N-1].cantInscriptos];

        // Asignar la fecha de inscripción y el ID del curso al nuevo curso inscripto
        aux[N-1].CursosInscriptos[aux[N-1].cantInscriptos - 1].fechaInscripcion = time(0);
        aux[N-1].CursosInscriptos[aux[N-1].cantInscriptos - 1].idClase = idCurso;
//liberar memoria
        delete [ ] asistPrev;
        asistPrev = aux;
    }
}
bool VerificarClase (Clases* clase){ //verifico que exista la clase a reservar
    if(clase==nullptr)
        return false;
    else if (clase->nombre != "Spinning" && clase->nombre != "Yoga" && clase->nombre != "Pilates"  && clase->nombre != "Stretching" && clase->nombre !="Zumba" && clase->nombre!="Boxeo" && clase->nombre !="Musculacion"){
        //clase invalida
        return false;
    }
    return true;
}
void Reserva(Cliente* cliente ,Clases* clase,sAsistencia* asistPrevia,int &n){

    bool ok=VerificarClase(clase);
    if(ok==false) {

        cout<<"Informacion invalida"<<endl;
    }
    //datos correctos

    //verificar espacio disp
    if(clase->cupo==clase->cupoMax){
        //no hay mas lugar
        cout<<"Cupo lleno"<<endl;
    }
    else if(clase->cupo<clase->cupoMax){
    //tengo lugar


        if (existeSuperposicion(cliente,clase)){
            cout<<"se superpone"<<endl;}

    //si esta todo en orden entonces:
    AgregarClienteArchivoInscri(cliente, asistPrevia,n,clase->idClase); //lo agrego
    clase->cupo=clase->cupo+1; //incremento cupo
    }

}
