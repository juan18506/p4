#include "../../headers/datatypes/DTInfoCliente.h"

DTInfoCliente::DTInfoCliente() {}

DTInfoCliente::DTInfoCliente(std::string nick, DTFecha nacimiento,
                             std::string calle, int puerta, std::string ciudad,
                             std::vector<DTCompra> compras)
    : cliente(DTCliente(nick, nacimiento, calle, puerta, ciudad)) {
    this->compras = compras;
}

std::string DTInfoCliente::imprimir() {
    std::string a;
    for (DTCompra c : compras) {
        a = a + " " + c.imprimir();
    };
    return cliente.imprimir() + a + "\n";
}