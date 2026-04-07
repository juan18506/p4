#include "../../headers/datatypes/DTVendedor.h"
#include "../../headers/datatypes/DTFecha.h"

DTVendedor::DTVendedor() {}

std::string DTVendedor::getRut() { return this->rut; }

std::string DTVendedor::getNickname() { return this->nickname; }

DTVendedor::DTVendedor(std::string nickname, DTFecha nacimiento,
                       std::string rut)
    : nacimiento(nacimiento) {
    this->nickname = nickname;
    this->rut = rut;
}

DTVendedor::DTVendedor(const DTVendedor &vendedor)
    : nacimiento(vendedor.nacimiento) {
    nickname = vendedor.nickname;
    rut = vendedor.rut;
}

std::string DTVendedor::imprimir() {
    std::string a = this->nickname;
    std::string b = this->rut;
    return this->nickname + " " + nacimiento.imprimirFecha() + " " + this->rut +
           "\n";
}