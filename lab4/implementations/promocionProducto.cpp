#include "../headers/promocionProducto.h"

PromocionProducto::PromocionProducto(int minimo) { this->minimo = minimo; }

int PromocionProducto::getMin() { return this->minimo; }

Producto *PromocionProducto::getProducto() { return this->producto; }

Promocion *PromocionProducto::getPromocion() { return this->promocion; }

void PromocionProducto::asociarProducto(Producto *pd) { this->producto = pd; }

void PromocionProducto::asociarPromocion(Promocion *pm) {
    this->promocion = pm;
}
