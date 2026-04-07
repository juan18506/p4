#include "../headers/compraProducto.h"

bool CompraProducto::getEntregados() { return this->entregados; }

Compra *CompraProducto::getCompra() { return this->compra; }

void CompraProducto::setEntregados(bool a) { this->entregados = a; }

Producto *CompraProducto::getProducto() { return this->producto; }

CompraProducto::CompraProducto(int cantidad, bool entregados, Compra *compra,
                               Producto *producto)
    : cantidad(cantidad), entregados(entregados), compra(compra),
      producto(producto) {}

int CompraProducto::getCant() { return this->cantidad; }
