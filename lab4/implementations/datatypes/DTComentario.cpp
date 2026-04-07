#include "../../headers/datatypes/DTComentario.h"
#include <string>

DTComentario::DTComentario(int id, std::string texto, DTFecha fecha) {
    this->id = id;
    this->texto = texto;
    this->fecha = fecha;
}

std::string DTComentario::getTexto() { return this->texto; }

DTFecha DTComentario::getFecha() { return this->fecha; }

int DTComentario::getId() { return this->id; }

std::string DTComentario::toString() {
    return std::to_string(this->id) + ": " + this->texto;
}
