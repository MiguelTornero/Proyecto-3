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
        datosContratacion >> clave;
        datosContratacion >> idCliente;
        datosContratacion >> dia;
        datosContratacion >> mes;
        datosContratacion >> anio;
        datosContratacion >> diasDuracion;
        
        fechaContrato = {dia, mes, anio};
        contrataciones[i].setClave(clave);
        contrataciones[i].setIdCliente(idCliente);
        contrataciones[i].setFechaContrato(fechaContrato);
        contrataciones[i].setDiasDuracion(diasDuracion);
    }
    
    datosContratacion.close();
}

//Muestra el menú
void muestraMenu() {
    cout << "\nElige una opción del menú\n"
    << "-------------------------------------------\n"
    << "|                   Menú                  |\n"
    << "-------------------------------------------\n"
    << "1) Consultar la lista de Servicios\n"
    << "2) Consultar la lista de contrataciones\n"
    << "3) Consultar las contrataciones de un servicio dado\n"
    << "4) Consulta las contrataciones de una fecha específica\n"
    << "5) Hacer una contratación,\n"
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
    
    return 0;
}
