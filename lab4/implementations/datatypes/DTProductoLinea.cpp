#include "../../headers/datatypes/DTProductoLinea.h"

DTProductoLinea::DTProductoLinea(int codigo, std::string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

int DTProductoLinea::getCodigo() { return this->codigo; }

std::string DTProductoLinea::getNombre() { return this->nombre; }
