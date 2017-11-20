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
#include "Fecha.h"

using namespace std;

const int MAX_CONTRATACIONES = 20, MAX_SERVICIOS = 10;

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
    bool found;
    int indexServicio;

    cout << "Mostrando la lista de contrataciones:" << endl;
    for (int i = 0; i < totalContrataciones; i++){
        found = false;
        for (int j = 0; j < totalServicios && !found; j++){
            if (contrataciones[i].getClave() == servicios[j]->getClave()){
                found = true;
                indexServicio = j;
            }
        }
        cout << "\n\n\nContratacion #" << i + 1 << ":\n" << endl;
        if (found){
            cout << "*INFORMACION DEL SERVICIO*" << endl;
            servicios[indexServicio]->muestra();
        }
        else{
            cout << "No se encontro ningun servicio con clave " << contrataciones[i].getClave() << endl;
        }
        cout << "\n*INFORMACION DE LA CONTRATACION*";
        cout << "\nID del cliente: " << contrataciones[i].getIdCliente();
        cout << "\nFecha de contratacion: " << contrataciones[i].getFechaContrato();
        cout << "\nFecha de terminacion: " << contrataciones[i].calcularFinContrato() << endl;
        if(found){
            cout << "Costo: $" << servicios[indexServicio]->calculaCosto(contrataciones[i].getDiasDuracion()) << endl;
        }
    }
    cout << "\nPresione Enter para regresar al menu..." << flush;
    cin.sync();
    cin.get();
}

void consultaContServicio(Contratacion *contrataciones, int totalContrataciones, Servicio **servicios, int totalServicios){
    bool foundContratacion = false, foundServicio = false;
    int indexServicio;
    string clave;

    cout << "Dame la clave del servicio:" << endl;
    cin.sync();
    cin >> clave;

    for (int i = 0; i < totalServicios && !foundServicio; i++){
        if (servicios[i]->getClave() == clave){
            indexServicio = i;
            foundServicio = true;
        }
    }

    cout << "\nDatos del servicio:\n" << endl;
    if (foundServicio){
        servicios[indexServicio]->muestra();
    }
    else{
        cout << "No se encontro ningun servicio con clave " << clave << endl;
    }

    cout << "\nDatos de las contrataciones del servicio:" << endl;
    for (int i = 0; i < totalContrataciones; i++){
        if (contrataciones[i].getClave() == clave){
            foundContratacion = true;
            cout << "\nContratacion #" << i + 1;
            cout << "\nID del cliente: " << contrataciones[i].getIdCliente();
            cout << "\nFecha de contratacion: " << contrataciones[i].getFechaContrato();
            cout << "\nFecha de terminacion: " << contrataciones[i].calcularFinContrato() << endl;
        }
    }
    if (!foundContratacion){
        cout << "\nNo se encontro ninguna contratacion con clave " << clave << endl;
    }
    cout << "\nPresione Enter para regresar al menu..." << flush;
    cin.sync();
    cin.get();
}

void consultaContFecha(Contratacion *contrataciones, int totalContrataciones, Servicio **servicios){
    Fecha fecha;
    bool foundContratacion;
    int indexServicio;
    
    cout << "Dame la fecha" << endl;
    cin.sync();
    cin >> fecha;
    
    for (int i = 0; i < totalContrataciones && !foundContratacion; i++){
        if (contrataciones[i].getFechaContrato() == fecha){
            servicios[i]->muestra();
            indexServicio = i;
            foundContratacion = true;
        }
    }
}

bool hacerContratacion(Contratacion *contrataciones, int totalContrataciones, Servicio **servicios, int totalServicios){
    int idCliente, diasDuracion, indexServicio;
    bool foundClave = false, isEmpresa = false, success = false;
    char answer;
    string clave;
    Fecha fechaContrato;
    Contratacion contrato;

    if (totalContrataciones < MAX_CONTRATACIONES){
        cout << "Dame el ID del cliente:" << endl;
        cin >> idCliente;

        while (!foundClave && !cin.fail()){
            cout << "Dame la clave del servicio:" << endl;
            cin >> clave;
            for (int i = 0; i < totalServicios && !foundClave; i++){
                if (servicios[i]->getClave() == clave){
                    foundClave = true;
                    indexServicio = i;
                }
            }
            if (!foundClave){
                cout << "No se encontro ningun servicio con clave " << clave << ". Intente otra vez." << endl;
            }
        }

        if (servicios[indexServicio]->getTipo() == 'V' || servicios[indexServicio]->getTipo() == 'D'  || servicios[indexServicio]->getTipo() == 'N'){
            isEmpresa = true;
        }

        cout << "Dame la fecha de contratacion:" << endl;
        cin >> fechaContrato;

        cout << "Dame los dias que deseas contratar el servicio:" << endl;
        cin >> diasDuracion;

        if (isEmpresa && diasDuracion < 30){
            cout << "Este servicio se contrata con minimo de un mes (30 dias). ¿Esta de acuerdo con esto? (Y/N)" << endl;
            cin.sync();
            cin >> answer;
            switch (answer){
            case 'Y':
            case 'y':
            case 'S':
            case 's':
                diasDuracion = 30;
                success = true;
                break;
            default:
                cout << "Cancelando la contratacion..." << endl;
            }
        }
        else{
            if (diasDuracion > 0){
                success = true;
            }
            else{
                cout << "La cantidad de dia debe ser mayor que cero." << endl;
            }
        }
        if (success){
            cout << "Se hara una contratacion con costo de: $" << servicios[indexServicio]->calculaCosto(diasDuracion) << endl;
            cout << "¿Quiere hacer la contratacion? (Y/N)" << endl;
            cin.sync();
            cin >> answer;
            switch (answer){
            case 'Y':
            case 'y':
            case 'S':
            case 's':
                break;
            default:
                cout << "Cancelando la contratacion..." << endl;
                success = false;
            }
            if (success){
                contrato.setClave(clave);
                contrato.setIdCliente(idCliente);
                contrato.setFechaContrato(fechaContrato);
                contrato.setDiasDuracion(diasDuracion);
                contrataciones[totalContrataciones] = contrato;
                cout << "Contratacion exitosa." << endl;
            }

        }
    }
    else{
        cout << "No hay espacio para mas contrataciones. (max. " << MAX_CONTRATACIONES << ")." << endl;
    }
    return success;
}

void actualizarContrataciones(Contratacion *contrataciones, int total){
    ofstream outputFile;
    outputFile.open("Contratacion.txt");
    for (int i = 0; i < total; i++){
        outputFile << contrataciones[i].getClave()
                   << ' ' << contrataciones[i].getIdCliente()
                   << ' ' << contrataciones[i].getFechaContrato().getDia()
                   << ' ' << contrataciones[i].getFechaContrato().getMes()
                   << ' ' << contrataciones[i].getFechaContrato().getAnio()
                   << ' ' << contrataciones[i].getDiasDuracion() << endl;
    }
    outputFile.close();
}

char menuOpciones(){
    char opcion;
    cout << "\nElija una opción del menú\n"
    << "-------------------------------------------\n"
    << "|                   Menú                  |\n"
    << "-------------------------------------------\n"
    << "A) Consultar la lista de servicios\n"
    << "B) Consultar la lista de contrataciones\n"
    << "C) Consultar las contrataciones de un servicio dado\n"
    << "D) Consulta las contrataciones de una fecha específica\n"
    << "E) Hacer una contratación\n"
    << "F) Terminar el programa\n"
    << "-------------------------------------------" << endl;
    cin.sync();
    cin >> opcion;
    return opcion;
}

int cargarServicios(Servicio *servicios[]){
    ifstream inputFile;
    int cantPersonas, counter = 0;
    double costo, adicional;
    char tipo;
    string clave, descripcion, auxString;

    inputFile.open("Servicios.txt");

    for (int i = 0; i < MAX_SERVICIOS && inputFile >> clave; i++){
        inputFile >> tipo >> costo;
        if (tipo == 'V' || tipo == 'D' || tipo == 'N'){
            inputFile >> cantPersonas >> descripcion;
            while (!(inputFile >> adicional)){
                inputFile.clear();
                inputFile >> auxString;
                descripcion += ' ' + auxString;
            }
            servicios[i] = new Empresa(clave, tipo, costo, cantPersonas, descripcion, adicional);
            counter++;
        }
        else{
            inputFile.ignore();
            getline(inputFile, descripcion);
            servicios[i] = new Hogar(clave, tipo, costo, descripcion);
            counter++;
        }
    }
    inputFile.close();
    return counter;
}

int cargarContrataciones(Contratacion contrataciones[]) {
    ifstream datosContratacion;
    datosContratacion.open("Contratacion.txt");

    string clave;
    int idCliente, diasDuracion, dia, mes, anio, counter = 0;
    Fecha fechaContrato;

    for (int i = 0; i < MAX_CONTRATACIONES && datosContratacion >> clave; i++) {
        datosContratacion >> idCliente;
        datosContratacion >> dia;
        datosContratacion >> mes;
        datosContratacion >> anio;
        datosContratacion >> diasDuracion;

        fechaContrato.setDia(dia);
        fechaContrato.setMes(mes);
        fechaContrato.setAnio(anio);
        contrataciones[i].setClave(clave);
        contrataciones[i].setIdCliente(idCliente);
        contrataciones[i].setFechaContrato(fechaContrato);
        contrataciones[i].setDiasDuracion(diasDuracion);
        counter++;
    }

    datosContratacion.close();
    return counter;
}

int main()
{
    int totalServicios, totalContrataciones;
    char opcion;
    Servicio *servicios[MAX_SERVICIOS];
    Contratacion contrataciones[MAX_CONTRATACIONES];

    totalServicios = cargarServicios(servicios);

    totalContrataciones = cargarContrataciones(contrataciones);

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
            consultaContServicio(contrataciones, totalContrataciones, servicios, totalServicios);
            break;
        case 'd':
        case 'D':
        case '4':
            consultaContFecha(contrataciones, totalContrataciones, servicios);
            break;
        case 'e':
        case 'E':
        case '5':
            if (hacerContratacion(contrataciones, totalContrataciones, servicios, totalServicios)){
                totalContrataciones++;
            }
            break;
        case 'f':
        case 'F':
        case '6':
            cout << "Actualizando contrataciones..." << endl;
            actualizarContrataciones(contrataciones, totalContrataciones);
            cout << "Contratacion.txt fue actualizada. Terminando el programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente otra vez." << endl;
        }
    }
    while (opcion != 'F' && opcion != 'f' && opcion != '6' && !cin.fail());
    return 0;
}
