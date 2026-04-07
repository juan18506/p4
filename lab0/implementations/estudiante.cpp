#include "../headers/estudiante.h"

Estudiante::Estudiante(std::string nombre, int ci, std::string email)
    : nombre(nombre), ci(ci), email(email) {}

std::set<std::string> Estudiante::listarInfo(DTFecha desde) {
    std::set<std::string> listado;

    for (Informacion *informacion : this->informaciones)
        if (informacion->getFecha() >= desde)
            listado.insert(informacion->toString());

    return listado;
}

std::string Estudiante::toString() {
    std::string estudianteStr =
        std::to_string(this->ci) + ", " + this->nombre + ", " + this->email;

    for (Informacion *informacion : this->informaciones)
        estudianteStr += ", " + informacion->toString();

    return estudianteStr;
}

void Estudiante::agregarInformacion(Informacion *informacion) {
    this->informaciones.push_back(informacion);
}

bool Estudiante::tieneInformacion(Informacion *informacion) {
    bool tieneInfo = false;

    int i = 0;
    while (i < this->informaciones.size() && !tieneInfo) {
        if (this->informaciones.at(i) == informacion)
            tieneInfo = true;
        i++;
    }

    return tieneInfo;
}

// PRE: El estudiante tiene la informacion
void Estudiante::eliminarInformacion(Informacion *informacion) {
    int i = 0;
    while (this->informaciones.at(i) != informacion)
        i++;

    this->informaciones.erase(this->informaciones.begin() + i);
}

int Estudiante::getCI() { return this->ci; }

std::string Estudiante::getNombre() { return this->nombre; }
