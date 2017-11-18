//
//  Proyecto Final
//
//  Created by Mario Alberto Chavez Cabello and Miguel Angel Tornero Carrillo on 11/13/17.
//

#include <iostream>
#include <fstream>

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
    cout << "Presione cualquier tecla para regresar al menu..." << flush;
    cin.sync();
    cin.get();
}

void consultaContrataciones(){}

void consultaContServicio(){}

void consultaContFecha(){}

void hacerContratacion(){}

char menuOpciones(){
    char opcion;

    cout << "Selecciona la opcion deseada:" << endl
         << "\nA. Consultar la lista de servicios."
         << "\nB. Consultar la lista de contrataciones."
         << "\nC. Consultar las contrataciones de un servicio dado."
         << "\nD. Consulta las contrataciones de una fecha especifica."
         << "\nE. Hacer una contratacion."
         << "\nF. Terminar el programa." << endl;
    cin.sync();
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

int main()
{
    const int maxServicios = 10, maxContrataciones = 20;
    int totalServicios, totalContrataciones;
    char opcion;
    Servicio *servicios[maxServicios];
    Contratacion contrataciones[maxContrataciones];

    totalServicios = cargarServicios(servicios, maxServicios);

    do{
        opcion = menuOpciones();

        switch (opcion){
        case 'a':
        case 'A':
            consultaServicios(servicios, totalServicios);
            break;
        case 'b':
        case 'B':
            consultaContrataciones();
            break;
        case 'c':
        case 'C':
            consultaContServicio();
            break;
        case 'd':
        case 'D':
            consultaContFecha();
            break;
        case 'e':
        case 'E':
            hacerContratacion();
            break;
        case 'f':
        case 'F':
            cout << "Terminando el programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente otra vez." << endl;
        }
    }
    while (opcion != 'F' && opcion != 'f' && !cin.fail());
    return 0;
}
