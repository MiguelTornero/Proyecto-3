//
//  main.cpp
//  ProyectoTres
//
//  Created by Mario Alberto Chavez Cabello on 11/13/17.
//  Copyright © 2017 Mario Alberto Chavez Cabello. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Contratacion.h"
#include "Empresa.h"
#include "Hogar.h"

using namespace std;

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
    int total;
    Servicio *servicios[20];

    total = cargarServicios(servicios, 20);

    for (int i = 0; i < total; i++)
    {
        servicios[i]->muestra();
        cout << endl;
    }

    return 0;
}
