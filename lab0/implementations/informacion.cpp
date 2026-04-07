#include "../headers/informacion.h"

Informacion::Informacion(int identificador, DTFecha fecha)
    : identificador(identificador), fecha(fecha) {}

void Informacion::agregarEstudiante(Estudiante *estudiante) {
    this->estudiantes.push_back(estudiante);
}

bool Informacion::tieneEstudiante(Estudiante *estudiante) {
    bool tieneEst = false;

    int i = 0;
    while (i < this->estudiantes.size() && !tieneEst) {
        if (this->estudiantes.at(i) == estudiante)
            tieneEst = true;
        i++;
    }

    return tieneEst;
}

// PRE: La informacion tiene al estudiante
void Informacion::eliminarEstudiante(Estudiante *estudiante) {
    int i = 0;
    while (this->estudiantes.at(i) != estudiante)
        i++;

    this->estudiantes.erase(this->estudiantes.begin() + i);
}

int Informacion::getIdentificador() { return this->identificador; }

DTFecha Informacion::getFecha() { return this->fecha; }

std::vector<Estudiante *> Informacion::getEstudiantes() {
    return this->estudiantes;
}

Informacion::~Informacion() {}
