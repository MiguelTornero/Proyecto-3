#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

using namespace std;

class Fecha {
public:
    //Constructores
    Fecha(); //Default
    Fecha(int dia, int mes, int anio);
    //Getters y setters
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    //Sobrecarga +
    Fecha operator + (int dias);
    //Sobrecarga <<
    friend ostream& operator << (ostream &salida, Fecha fecha);
    //Sobreecarga >>
    friend istream& operator >> (istream &entrada, Fecha& fecha);
private:
    int dia;
    int mes;
    int anio;
};

//Constructores
Fecha::Fecha() { //Default
    dia = 0;
    mes = 0;
    anio = 0;
}
Fecha::Fecha(int dia, int mes, int anio) {
    this-> dia = dia;
    this-> mes = mes;
    this-> anio = anio;
}
//Getters y setters
int Fecha::getDia() {
    return dia;
}
int Fecha::getMes() {
    return mes;
}
int Fecha::getAnio() {
    return anio;
}
void Fecha::setDia(int dia) {
    this-> dia = dia;
}
void Fecha::setMes(int mes) {
    this-> mes = mes;
}
void Fecha::setAnio(int anio) {
    this-> anio = anio;
}
//Sobrecarga +
Fecha Fecha::operator + (int dias) {
    int d, m, a, meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    d = dia + dias;
    m = mes;
    a = anio;
    
    for (int i = 0; d > meses[m-1]; i++) {
        //Valida si el año es bisiesto y si es así agrega un día más a el mes de febrero
        if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) {
            meses[1]++;
        }
        
        d -= meses[m-1];
        m++;
        
        if(m == 13) {
            a++;
            m = 1;
        }
    }
    
    Fecha nuevaFecha(d, m, a);
    return nuevaFecha;
}
//Sobrecarga <<
ostream& operator << (ostream &salida, Fecha fecha) {
    salida << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return salida;
}
//Sobreecarga >>
istream& operator >> (istream &entrada, Fecha& fecha) {
    int d, m , a, maxD = 0;
    bool bisiesto = false;
    
    cout << "Año:";
    entrada >> a;
    
    if (a > 0) {
        fecha.anio = a;
        if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
            bisiesto = true;
        
        cout << "Mes:";
        entrada >> m;
        
        if (m <= 12 &&  m > 0) {
            fecha.mes = m;
            
            switch (m) {
                case 1:
                    maxD = 31;
                    break;
                case 2:
                    if (bisiesto)
                        maxD = 29;
                    else maxD = 28;
                    break;
                case 3:
                    maxD = 31;
                    break;
                case 4:
                    maxD = 30;
                    break;
                case 5:
                    maxD = 31;
                    break;
                case 6:
                    maxD = 30;
                    break;
                case 7:
                    maxD = 31;
                    break;
                case 8:
                    maxD = 31;
                    break;
                case 9:
                    maxD = 30;
                    break;
                case 10:
                    maxD = 31;
                    break;
                case 11:
                    maxD = 30;
                    break;
                case 12:
                    maxD = 31;
                    break;
                default:
                    break;
            }
            cout << "Día:";
            entrada >> d;
            
            if (d <= maxD && d > 0) {
                fecha.dia = d;
            } else cout << "Error. Día invalido\n";
        } else cout << "Error. Mes invalido.\n";
    } else cout << "Error. Año invalido\n";
    
    return entrada;
}
#endif // FECHA_H_INCLUDED
