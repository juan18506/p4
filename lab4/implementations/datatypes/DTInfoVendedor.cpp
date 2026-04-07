#include "../../headers/datatypes/DTInfoVendedor.h"

DTInfoVendedor::DTInfoVendedor() {}

DTInfoVendedor::DTInfoVendedor(DTVendedor vendedor,
                               std::vector<DTProducto> productos,
                               std::vector<DTPromocion> promociones)
    : vendedor(vendedor) {
    this->productos = productos;
    this->promociones = promociones;
}

std::string DTInfoVendedor::imprimir() {
    std::string a;
    std::string b;
    for (auto p : productos) {
        a = a + " " + p.imprimir();
    }
    for (DTPromocion pr : promociones) {
        b = b + " " + pr.imprimir();
    }
    return vendedor.imprimir() + " " + a + " " + b + "\n";
}
