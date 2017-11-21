#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include "Servicio.h"

class Empresa:public Servicio{
public:
    //Constructores
    Empresa();//Default
    Empresa(string, char, double, int, string, double);
    //Getters y setters
    void setCostoXMes(double);
    void setCantPersonas(int);
    void setDescripcion(string);
    void setAdicional(double);

    double getCostoXMes();
    int getCantPersonas();
    string getDescripcion();
    double getAdicional();
    //Métodos
    void muestra();
    double calculaCosto(int);
private:
    double costoXMes;
    int cantPersonas;
    string descripcion;
    double adicional;
};
//Constructores
Empresa::Empresa():Servicio(){
    costoXMes = 0.0;
    cantPersonas = 0;
    descripcion = "N/A";
    adicional = 0.0;
}
//Default
Empresa::Empresa(string clave, char tipo, double costoXMes, int cantPersonas, string descripcion, double adicional):Servicio(clave, tipo){
    this->costoXMes = costoXMes;
    this->cantPersonas = cantPersonas;
    this->descripcion = descripcion;
    this->adicional = adicional;
}
//Getters y setters
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
//Métodos
void Empresa::muestra(){
    cout << "Servicio: Empresa";
    cout << "\nClave: " << clave;
    cout << "\nTipo: " << tipo;
    cout << "\nCosto por mes: $" << costoXMes;
    cout << "\nCantidad de personas: " << cantPersonas;
    cout << "\nDescripcion: " << descripcion;
    cout << "\nAdicional: $" << adicional << endl;
}

double Empresa::calculaCosto(int diasDuracion){
    int mesesDuracion;
    mesesDuracion = diasDuracion / 30;
    if (cantPersonas > 200){
        return (cantPersonas - 200) * adicional + costoXMes * mesesDuracion;
    }
    return costoXMes * mesesDuracion;
}

#endif // EMPRESA_H_INCLUDED
