#include "../headers/cliente.h"
#include "../headers/datatypes/DTInfoCliente.h"

Cliente::Cliente(std::string nickname, std::string contrasena, int dia, int mes,
                 int anio, std::string calle, int puerta, std::string ciudad)
    : Usuario(nickname, contrasena, dia, mes, anio) {
    this->calle = calle;
    this->puerta = puerta;
    this->ciudad = ciudad;
}

std::vector<DTNotificacion> Cliente::imprimiryborrar() {
    std::vector<DTNotificacion> aux;
    notificaciones.swap(aux);
    return aux;
}

std::string Cliente::getNickname() { return this->Usuario::getNickname(); };

DTCliente Cliente::getDTCliente() {
    return DTCliente(this->getNickname(), this->getNacimiento(), calle, puerta,
                     ciudad);
}

void Cliente::notificar(DTNotificacion notificacion) {
    notificaciones.push_back(notificacion);
}

std::string Cliente::getCalle() { return calle; }

int Cliente::getPuerta() { return puerta; }

std::string Cliente::getCiudad() { return ciudad; }

std::vector<Compra *> Cliente::getCompras() {
    std::vector<Compra *> aux;
    for (Compra *c : this->compras) {
        aux.push_back(c);
    }
    return aux;
}

std::vector<DTCompra> Cliente::getDTCompras() {
    std::vector<DTCompra> aux;
    for (Compra *c : compras) {
        DTCompra aux2 = c->getDTCompra();
        aux.push_back(aux2);
    }
    return aux;
}

DTInfoExpediente Cliente::expediente() {
    return DTInfoExpediente(DTInfoCliente(
        this->getNickname(), this->getNacimiento(), this->getCalle(),
        this->getPuerta(), this->getCiudad(), this->getDTCompras()));
}

void Cliente::nuevaCompraCliente(Compra *compra) {
    this->compras.push_back(compra);
}
std::vector<Compra *> Cliente::getComprasCl() { return this->compras; }

void Cliente::setcalle(std::string c) { this->calle = c; };
void Cliente::setpuerta(int p) { this->puerta = p; };
void Cliente::setciudad(std::string c) { this->ciudad = c; };
