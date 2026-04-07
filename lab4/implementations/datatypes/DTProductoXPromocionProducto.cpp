#include "../../headers/datatypes/DTProductoXPromocionProducto.h"

DTProductoXPromocionProducto::DTProductoXPromocionProducto(
    DTProducto producto, DTPromocionProducto pp)
    : producto(producto), promocionProducto(pp) {}

DTProducto DTProductoXPromocionProducto::getProducto() {
    return this->producto;
}

DTPromocionProducto DTProductoXPromocionProducto::getPromocionProducto() {
    return this->promocionProducto;
}
