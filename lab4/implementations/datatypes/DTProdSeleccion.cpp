#include "../../headers/datatypes/DTProdSeleccion.h"

DTProdSeleccion::DTProdSeleccion(int cantidad, const DTProducto &datosProduct)
    : datosProducto(datosProduct) {
    this->cantidad = cantidad;
}

DTProdSeleccion::DTProdSeleccion(const DTProdSeleccion &dtPS)
    : datosProducto(dtPS.datosProducto) {
    this->cantidad = dtPS.cantidad;
}

DTProducto DTProdSeleccion::getDTProducto() { return this->datosProducto; }

int DTProdSeleccion::getCantidad() { return this->cantidad; }
