#include "../headers/compra.h"

Compra::Compra(Cliente *cliente, DTCompra dtCompra) {
    this->cliente = cliente;
    this->monto = dtCompra.getMonto();
    this->fecha = dtCompra.getFecha();
    this->productos = std::vector<CompraProducto *>();
}

DTFecha Compra::getFecha() { return this->fecha; }

float Compra::getMonto() { return this->monto; }

Cliente *Compra::getCliente() { return this->cliente; }

std::vector<CompraProducto *> Compra::getProductos() { return this->productos; }

void Compra::agregarCompraProducto(CompraProducto *cp) {
    this->productos.push_back(cp);
}

DTCompra Compra::getDTCompra() {
    std::vector<CompraProducto *> CompraProds = this->productos;
    std::vector<DTProdSeleccion> vecProdSel;
    for (CompraProducto *compraProd : CompraProds) {
        vecProdSel.push_back(DTProdSeleccion(
            compraProd->getCant(), compraProd->getProducto()->getDTProducto()));
    }

    return DTCompra(this->getCliente()->getNickname(), this->getMonto(),
                    this->getFecha(), vecProdSel);
};

void Compra::asociarProducto(CompraProducto *cppd) {
    this->productos.push_back(cppd);
}