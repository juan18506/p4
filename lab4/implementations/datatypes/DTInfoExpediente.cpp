#include "../../headers/datatypes/DTInfoExpediente.h"

DTInfoExpediente::DTInfoExpediente(DTInfoCliente cliente) {
    this->cliente = cliente;
    this->esCliente = true;
};

DTInfoExpediente::DTInfoExpediente(DTInfoVendedor vendedor) {
    this->vendedor = vendedor;
    this->esCliente = false;
};

std::string DTInfoExpediente::imprimir() {
    if (esCliente) {
        return cliente.imprimir();
    } else {
        return vendedor.imprimir();
    }
}