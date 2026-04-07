#include "../../headers/datatypes/DTCompra.h"
#include "../../headers/datatypes/DTProdSeleccion.h"

DTCompra::DTCompra() {}

DTCompra::DTCompra(std::string nickCliente, float monto, DTFecha fecha,
                   std::vector<DTProdSeleccion> prodCompra) {
    this->nickCliente = nickCliente;
    this->monto = monto;
    this->fecha = fecha;
    for (DTProdSeleccion pC : prodCompra) {
        this->prodCompra.push_back(pC);
    }
}

std::string DTCompra::getNickCliente() { return this->nickCliente; }
DTFecha DTCompra::getFecha() { return this->fecha; }
float DTCompra::getMonto() { return this->monto; }

std::vector<DTProdSeleccion> DTCompra::getProdCompra() {
    return this->prodCompra;
}

std::string DTCompra::imprimir() {
    std::string a;
    for (auto p : prodCompra) {
        a = a + p.getDTProducto().imprimir() + "\n";
    }
    return "Compra:" + this->fecha.imprimirFecha() + " " +
           std::to_string(monto) + " " + "productos=\n" + a;
}

std::string DTCompra::toString_ClFe_() {
    return "Cliente: " + this->nickCliente + "," +
           "Fecha de compra:" + this->fecha.imprimirFecha();
}
