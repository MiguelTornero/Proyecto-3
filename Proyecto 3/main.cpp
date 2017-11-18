//
//  Proyecto Final
//
//  Created by Mario Alberto Chavez Cabello and Miguel Angel Tornero Carrillo on 11/13/17.
//

#include <iostream>
#include <fstream>

<<<<<<< HEAD
#include "Fecha.h"
#include "Contratacion.h"
#include "Servicio.h"

using namespace std;

//Carga los datos de los archivos
void cargarContrataciones(Contratacion contrataciones[]) {
    ifstream datosContratacion;
    datosContratacion.open("Contratacion.txt");
    
    string clave;
    int idCliente, diasDuracion, dia, mes, anio;
    Fecha fechaContrato;
    
    for (int i = 0; i < 2 && !datosContratacion.eof(); i++) {
=======
#include "Contratacion.h"
#include "Empresa.h"
#include "Hogar.h"

using namespace std;

void consultaServicios(Servicio **servicios, int tam){
    cout << "Mostrando la lista de servicios:\n" << endl;
    for (int i = 0; i < tam; i++)
    {
        servicios[i]->muestra();
        cout << endl;
    }
    cout << "\nPresione Enter para regresar al menu..." << flush;
    cin.sync();
    cin.get();
}

void consultaContrataciones(Contratacion *contrataciones, int totalContrataciones, Servicio **servicios, int totalServicios){
    bool found = false;
    int indexServicio;

    cout << "Mostrando la lista de contrataciones:" << endl;
    for (int i = 0; i < totalContrataciones; i++){
        for (int j = 0; j < totalServicios && !found; j++){
            if (contrataciones[i].getClave() == servicios[j]->getClave())
            {
                found = true;
                indexServicio = j;
            }
        }
        if (found){
            cout << "\n*INFORMACION DEL SERVICIO*" << endl;
            servicios[indexServicio]->muestra();
        }
        else{
            cout << "Servicio no encontrado." << endl;
        }
        cout << "*INFORMACION DE LA CONTRATACION*";
        cout << "\nID del cliente: " << contrataciones[i].getIdCliente();
        cout << "\nFecha de contratacion: " << contrataciones[i].getFechaContrato();
        cout << "\nFecha de terminacion: " << contrataciones[i].calcularFinContrato() << endl;
        if(found){
            cout << "Costo: " << servicios[indexServicio]->calculaCosto(contrataciones[i].getDiasDuracion()) << endl;
        }
    }
    cout << "\nPresione Enter para regresar al menu..." << flush;
    cin.sync();
    cin.get();
}

void consultaContServicio(){}

void consultaContFecha(){}

void hacerContratacion(){}

char menuOpciones(){
    char opcion;
    cout << "\nElige una opción del menú\n"
    << "-------------------------------------------\n"
    << "|                   Menú                  |\n"
    << "-------------------------------------------\n"
    << "A) Consultar la lista de servicios\n"
    << "B) Consultar la lista de contrataciones\n"
    << "C) Consultar las contrataciones de un servicio dado\n"
    << "D) Consulta las contrataciones de una fecha específica\n"
    << "E) Hacer una contratación\n"
    << "F) Terminar el programa\n"
    << "-------------------------------------------\n";
    cin >> opcion;
    return opcion;
}

int cargarServicios(Servicio *servicios[], int tam){
    ifstream inputFile;
    int inInt, counter = 0;
    double inDouble1, inDouble2;
    char inChar;
    string inString1, inString2, auxString;

    inputFile.open("Servicios.txt");

    for (int i = 0; i < tam && !inputFile.eof(); i++){
        inputFile >> inString1 >> inChar >> inDouble1;
        if (inputFile >> inInt){
            inputFile >> inString2;
            while (!(inputFile >> inDouble2)){
                inputFile.clear();
                inputFile >> auxString;
                inString2 += ' ' + auxString;
            }
            servicios[i] = new Empresa(inString1, inChar, inDouble1, inInt, inString2, inDouble2);
            counter++;
        }
        else{
            inputFile.clear();
            getline(inputFile, inString2);
            servicios[i] = new Hogar(inString1, inChar, inDouble1, inString2);
            counter++;
        }
    }
    inputFile.close();
    return counter;
}

int cargarContrataciones(Contratacion contrataciones[], int tam) {
    ifstream datosContratacion;
    datosContratacion.open("Contratacion.txt");

    string clave;
    int idCliente, diasDuracion, dia, mes, anio, counter = 0;
    Fecha fechaContrato;

    for (int i = 0; i < tam && !datosContratacion.eof(); i++) {
>>>>>>> master
        datosContratacion >> clave;
        datosContratacion >> idCliente;
        datosContratacion >> dia;
        datosContratacion >> mes;
        datosContratacion >> anio;
        datosContratacion >> diasDuracion;
<<<<<<< HEAD
        
        fechaContrato = {dia, mes, anio};
=======

        fechaContrato.setDia(dia);
        fechaContrato.setMes(mes);
        fechaContrato.setAnio(anio);
>>>>>>> master
        contrataciones[i].setClave(clave);
        contrataciones[i].setIdCliente(idCliente);
        contrataciones[i].setFechaContrato(fechaContrato);
        contrataciones[i].setDiasDuracion(diasDuracion);
<<<<<<< HEAD
    }
    
    datosContratacion.close();
}

//Muestra el menÃº
void muestraMenu() {
    cout << "\nElige una opciÃ³n del menÃº\n"
    << "-------------------------------------------\n"
    << "|                   MenÃº                  |\n"
    << "-------------------------------------------\n"
    << "1) Consultar la lista de Servicios\n"
    << "2) Consultar la lista de contrataciones\n"
    << "3) Consultar las contrataciones de un servicio dado\n"
    << "4) Consulta las contrataciones de una fecha especÃ­fica\n"
    << "5) Hacer una contrataciÃ³n,\n"
    << "6) Terminar\n"
    << "-------------------------------------------\n";
}


int main()
{
    Fecha fecha1;
    Servicio *servicios[10];
    Contratacion contrataciones[20];
    
    
//    ifstream arch1;
//    string x;
//
//    arch1.open("Servicios.txt");
//
//    for (int i = 0; i < 7 ;i++) {
//        arch1 >> x;
//        cout << x << endl;
//    }
//
//    arch1.close();
    
    cin >> fecha1;
    cout << fecha1 << endl;
    Contratacion contratacion("f34", 21, fecha1, 10);
    cout << contratacion.calcularFinContrato();
    
=======
        counter++;
    }

    datosContratacion.close();
    return counter;
}

int main()
{
    const int maxServicios = 10, maxContrataciones = 20;
    int totalServicios, totalContrataciones;
    char opcion;
    Servicio *servicios[maxServicios];
    Contratacion contrataciones[maxContrataciones];

    totalServicios = cargarServicios(servicios, maxServicios);

    totalContrataciones = cargarContrataciones(contrataciones, maxContrataciones);

    do{
        opcion = menuOpciones();

        switch (opcion){
        case 'a':
        case 'A':
        case '1':
            consultaServicios(servicios, totalServicios);
            break;
        case 'b':
        case 'B':
        case '2':
            consultaContrataciones(contrataciones, totalContrataciones, servicios, totalServicios);
            break;
        case 'c':
        case 'C':
        case '3':
            consultaContServicio();
            break;
        case 'd':
        case 'D':
        case '4':
            consultaContFecha();
            break;
        case 'e':
        case 'E':
        case '5':
            hacerContratacion();
            break;
        case 'f':
        case 'F':
        case '6':
            cout << "Terminando el programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente otra vez." << endl;
        }
    }
    while (opcion != 'F' && opcion != 'f' && opcion != '6' && !cin.fail());
>>>>>>> master
    return 0;
}
