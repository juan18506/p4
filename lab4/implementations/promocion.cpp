#include "../headers/promocion.h"

Promocion::Promocion(std::string nombre, std::string descripcion,
                     float descuento, DTFecha fin) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->descuento = descuento;
    this->fin = fin;
}

std::string Promocion::getNombre() { return this->nombre; }

DTFecha Promocion::getFin() { return this->fin; }

std::vector<PromocionProducto *> Promocion::getProductos() {
    return this->productos;
}

DTPromocion Promocion::getDTPromocion() {
    return DTPromocion(this->nombre, this->descripcion, this->descuento,
                       this->fin);
}
std::string Promocion::getDescripcion() { return this->descripcion; }
float Promocion::getDescuento() { return this->descuento; }
Vendedor *Promocion::getVendedor() { return this->vendedor; }

void Promocion::asociarProducto(PromocionProducto *pmpd) {
    this->productos.push_back(pmpd);
}
