#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Servicio {
public:
    //Constructores
    Servicio();//Default
    Servicio(string, char);
    //Getters y setters
    void setClave(string);
    void setTipo(char);
    string getClave();
    char getTipo();
    //Métodos
    virtual void muestra() = 0;
    virtual double calculaCosto(int) = 0;
protected:
    string clave;
    char tipo;
};
//Constructores
Servicio::Servicio(){
    clave = "N/A";
    tipo = 0;
}
//Default
Servicio::Servicio(string clave, char tipo){
    this->clave = clave;
    this->tipo = tipo;
}
//Getters y setters
void Servicio::setClave(string clave){
    this->clave = clave;
}

void Servicio::setTipo(char tipo){
    this->tipo = tipo;
}

string Servicio::getClave(){
    return clave;
}

char Servicio::getTipo(){
    return tipo;
}

#endif // SERVICIO_H_INCLUDED
