//
//  main.cpp
//  ProyectoTres
//
//  Created by Mario Alberto Chavez Cabello on 11/13/17.
//  Copyright © 2017 Mario Alberto Chavez Cabello. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Fecha.h"
#include "Empresa.h"
#include "Hogar.h"

using namespace std;

void cargarServicios(Servicio *servicios[], int tam){
    ifstream inputFile;
    int inInt, counter = 0;
    double inDouble1, inDouble2;
    char inChar;
    string inString1, inString2, auxString;

    inputFile.open("Servicios.txt");

    for (int i = 0; i < tam && !inputFile.eof(); i++){
        inputFile >> inString1 >> inChar >> inDouble1;
        cout << i << endl;
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

    for (int i = 0; i < 5; i++)
    {
        servicios[i]->muestra();
        cout << endl;
    }

}

int main()
{
    Fecha fecha1, fecha2(3, 3, 3), fecha3;
    Servicio *servicios[20];

    cargarServicios(servicios, 20);

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
    fecha1 = fecha1 + 365;
    cout << fecha1 << endl;

    return 0;
}
