#include "../headers/dtfecha.h"

DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

std::string DTFecha::fechaConFormato() {
    std::string diaStr = std::to_string(this->dia);
    std::string mesStr = std::to_string(this->mes);
    std::string anioStr = std::to_string(this->anio);
    return diaStr + "/" + mesStr + "/" + anioStr;
}

bool DTFecha::operator>=(DTFecha fecha) {
    return (this->anio > fecha.anio ||
            this->anio == fecha.anio && this->mes > fecha.mes ||
            this->anio == fecha.anio && this->mes == fecha.mes &&
                this->dia >= fecha.dia);
}
