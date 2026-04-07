#include "../../headers/datatypes/DTPromocion.h"

DTPromocion::DTPromocion(const DTPromocion &promo) {
    this->nombre = promo.nombre;
    this->descripcion = promo.descripcion;
    this->descuento = promo.descuento;
    this->fin = promo.fin;
}

DTPromocion::DTPromocion(std::string nombre, std::string descripcion,
                         float descuento, DTFecha fin)
    : descuento(descuento), nombre(nombre), descripcion(descripcion), fin(fin) {
}

std::string DTPromocion::imprimir() {
    std::string a = std::to_string(this->descuento);
    return this->nombre + " " + this->descripcion + " " + a + " " +
           this->fin.imprimirFecha() + "\n";
}

std::string DTPromocion::getNombre() { return this->nombre; }

std::string DTPromocion::getDescripcion() { return this->descripcion; }

float DTPromocion::getDescuento() { return this->descuento; }

DTFecha DTPromocion::getFin() { return this->fin; }
