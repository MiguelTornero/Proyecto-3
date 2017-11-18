#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

#include "Fecha.h"

class Contratacion {
public:
    //Constuctores
    Contratacion(); //Default
    Contratacion(string clave, int idCliente, Fecha fechaContrato, int diasDuracion);
    //Getters y setters
    string getClave();
    int getIdCliente();
    Fecha getFechaContrato();
    int getDiasDuracion();
    void setClave(string clave);
    void setIdCliente(int idCliente);
    void setFechaContrato(Fecha fechaContrato);
    void setDiasDuracion(int diasDuracion);
    //Método
    Fecha calcularFinContrato();
private:
    string clave;
    int idCliente;
    Fecha fechaContrato;
    int diasDuracion;
};
//Constuctores
Contratacion::Contratacion() { //Default
    clave = "Sin clave";
    idCliente = 0;
    fechaContrato = Fecha();
    diasDuracion = 0;
}
Contratacion::Contratacion(string clave, int idCliente, Fecha fechaContrato, int diasDuracion) {
    this-> clave = clave;
    this-> idCliente = idCliente;
    this-> fechaContrato = fechaContrato;
    this-> diasDuracion = diasDuracion;
}
//Getters y setters
string Contratacion::getClave() {
    return clave;
}
int Contratacion::getIdCliente() {
    return idCliente;
}
Fecha Contratacion::getFechaContrato() {
    return fechaContrato;
}
int Contratacion::getDiasDuracion() {
    return diasDuracion;
}
void Contratacion::setClave(string clave) {
    this-> clave = clave;
}
void Contratacion::setIdCliente(int idCliente) {
    this-> idCliente = idCliente;
}
void Contratacion::setFechaContrato(Fecha fechaContrato) {
    this-> fechaContrato = fechaContrato;
}
void Contratacion::setDiasDuracion(int diasDuracion) {
    this-> diasDuracion = diasDuracion;
}
//Método
Fecha Contratacion::calcularFinContrato() {
    Fecha nuevaContratacion = fechaContrato + diasDuracion;;
    return nuevaContratacion;
}
#endif // CONTRATACION_H_INCLUDED
