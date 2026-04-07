#include "../../headers/datatypes/DTFecha.h"
#include <string>

DTFecha::DTFecha() {}

DTFecha::DTFecha(int a, int b, int c) {
    this->dia = a;
    this->mes = b;
    this->anio = c;
};

std::string DTFecha::imprimirFecha() {
    std::string a = std::to_string(dia) + "/";
    std::string b = std::to_string(mes) + "/";
    std::string c = std::to_string(anio);
    return a + b + c;
};

int DTFecha::getDia() { return dia; }
int DTFecha::getMes() { return mes; }

int DTFecha::getAnio() { return anio; }

bool DTFecha::LaFechaEsPosteriorA(DTFecha desde) {
    int a = desde.dia + desde.mes * 31 + desde.anio * (12 * 31);
    int b = this->dia + this->mes * 31 + this->anio * (12 * 31);

    return a < b;
};

bool DTFecha::operator<=(DTFecha fecha) {
    return ((this->anio < fecha.anio) ||
            (this->anio == fecha.anio && this->mes < fecha.mes) ||
            (this->anio == fecha.anio && this->mes == fecha.mes &&
             this->dia <= fecha.dia));
}

DTFecha DTFecha::operator=(const DTFecha &fecha) {
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
    return *this;
}
