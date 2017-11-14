#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include "Servicio.h"

class Empresa:public Servicio{
public:
    Empresa();
    Empresa(string, char, double, int, string, double);

    void setCostoXMes(double);
    void setCantPersonas(int);
    void setDescripcion(string);
    void setAdicional(double);

    double getCostoXMes();
    int getCantPersonas();
    string getDescripcion();
    double getAdicional();

    void muestra();
    double calculaCosto(int);
private:
    double costoXMes;
    int cantPersonas;
    string descripcion;
    double adicional;
};

Empresa::Empresa():Servicio(){
    costoXMes = 0.0;
    cantPersonas = 0;
    descripcion = "N/A";
    adicional = 0.0;
}

Empresa::Empresa(string clave, char tipo, double costoXMes, int cantPersonas, string descripcion, double adicional):Servicio(clave, tipo){
    this->costoXMes = costoXMes;
    this->cantPersonas = cantPersonas;
    this->descripcion = descripcion;
    this->adicional = adicional;
}

void Empresa::setCostoXMes(double costoXMes){
    this->costoXMes = costoXMes;
}

void Empresa::setCantPersonas(int cantPersonas){
    this->cantPersonas = cantPersonas;
}

void Empresa::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

void Empresa::setAdicional(double adicional){
    this->adicional = adicional;
}

double Empresa::getCostoXMes(){
    return costoXMes;
}

int Empresa::getCantPersonas(){
    return cantPersonas;
}

string Empresa::getDescripcion(){
    return descripcion;
}

double Empresa::getAdicional(){
    return adicional;
}

void Empresa::muestra(){
    cout << "Servicio: Empresa";
    cout << "\nClave:" << clave;
    cout << "\nTipo: " << tipo;
    cout << "\nCosto por mes: " << costoXMes;
    cout << "\nCantidad de personas: " << cantPersonas;
    cout << "\nDescripcion: " << descripcion;
    cout << "\nAdicional: " << adicional << endl;
}

double Empresa::calculaCosto(int diasDuracion){
    diasDuracion %= 30;
    if (cantPersonas > 200){
        return (cantPersonas - 200) * adicional + costoXMes * diasDuracion;
    }
    return costoXMes * diasDuracion;
}

#endif // EMPRESA_H_INCLUDED
