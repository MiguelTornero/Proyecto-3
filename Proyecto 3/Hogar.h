#ifndef HOGAR_H_INCLUDED
#define HOGAR_H_INCLUDED

#include "Servicio.h"

class Hogar:public Servicio{
public:
    Hogar();
    Hogar(string, char, double, string);

    void setCostoXDia(double);
    void setDescripcion(string);

    double getCostoXDia();
    string getDescripcion();

    void muestra();
    double calculaCosto(int);
private:
    double costoXDia;
    string descripcion;
};

Hogar::Hogar():Servicio(){
    costoXDia = 0.0;
    descripcion = "N/A";
}

Hogar::Hogar(string clave, char tipo, double costoXDia, string descripcion):Servicio(clave, tipo){
    this->costoXDia = costoXDia;
    this->descripcion = descripcion;
}

void Hogar::setCostoXDia(double costoXDia){
    this->costoXDia = costoXDia;
}

void Hogar::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

double Hogar::getCostoXDia(){
    return costoXDia;
}

string Hogar::getDescripcion(){
    return descripcion;
}

void Hogar::muestra(){
    cout << "Servicio: Hogar";
    cout << "\nClave: " << clave;
    cout << "\nTipo: " << tipo;
    cout << "\nCosto por dia: " << costoXDia;
    cout << "\nDescripcion: " << descripcion << endl;
}

double Hogar::calculaCosto(int diasDuracion){
    return costoXDia * diasDuracion;
}

#endif // HOGAR_H_INCLUDED
