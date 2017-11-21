#ifndef HOGAR_H_INCLUDED
#define HOGAR_H_INCLUDED

#include "Servicio.h"

class Hogar:public Servicio{
public:
    //Constructores
    Hogar(); //Default
    Hogar(string, char, double, string);
    //Getters y setters
    void setCostoXDia(double);
    void setDescripcion(string);
    double getCostoXDia();
    string getDescripcion();
    //Métodos
    void muestra();
    double calculaCosto(int);
private:
    double costoXDia;
    string descripcion;
};
//Constructores
Hogar::Hogar():Servicio(){
    costoXDia = 0.0;
    descripcion = "N/A";
}
//Default
Hogar::Hogar(string clave, char tipo, double costoXDia, string descripcion):Servicio(clave, tipo){
    this->costoXDia = costoXDia;
    this->descripcion = descripcion;
}
//Getters y setters
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
//Métodos
void Hogar::muestra(){
    cout << "Servicio: Hogar";
    cout << "\nClave: " << clave;
    cout << "\nTipo: " << tipo;
    cout << "\nCosto por dia: $" << costoXDia;
    cout << "\nDescripcion: " << descripcion << endl;
}

double Hogar::calculaCosto(int diasDuracion){
    return costoXDia * diasDuracion;
}

#endif // HOGAR_H_INCLUDED
