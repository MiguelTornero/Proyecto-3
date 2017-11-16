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
//#include "Contratacion.h"

using namespace std;

int main()
{
    Fecha fecha1, fecha2(3, 3, 3), fecha3;
    
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
