#include "../../headers/datatypes/DTCliente.h"

DTCliente::DTCliente() {}

DTCliente::DTCliente(std::string nick, DTFecha nacimiento, std::string calle,
                     int puerta, std::string ciudad)
    : nacimiento(nacimiento) {
    nickname = nick;
    this->calle = calle;
    this->puerta = puerta;
    this->ciudad = ciudad;
}

std::string DTCliente::getCalle() { return calle; }

int DTCliente::getPuerta() { return puerta; }

std::string DTCliente::getCiudad() { return ciudad; }

std::string DTCliente::getNickname() { return this->nickname; };
DTFecha DTCliente::getNacimiento() { return this->nacimiento; }

DTCliente::DTCliente(const DTCliente &cliente)
    : nacimiento(cliente.nacimiento) {
    nickname = cliente.nickname;
    calle = cliente.calle;
    puerta = cliente.puerta;
    ciudad = cliente.ciudad;
}

std::string DTCliente::imprimir() {
    std::string a = std::to_string(this->puerta);
    return this->getNickname() + " " + this->getNacimiento().imprimirFecha() +
           " " + calle + " " + a + " " + ciudad + "\n";
};
