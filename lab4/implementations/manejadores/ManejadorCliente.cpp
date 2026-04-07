#include "../../headers/manejadores/ManejadorCliente.h"

ManejadorCliente *ManejadorCliente::instance = NULL;

ManejadorCliente::ManejadorCliente() {}

ManejadorCliente *ManejadorCliente::getInstance() {
    if (instance == NULL)
        instance = new ManejadorCliente();
    return instance;
}

Cliente *ManejadorCliente::getCliente(std::string nickname) {
    return this->clientes.at(nickname);
}

void ManejadorCliente::recibirCliente(Cliente *cliente) {
    this->clientes.insert({cliente->getNickname(), cliente});
};

bool ManejadorCliente::esta(std::string nickname) {
    return clientes.find(nickname) != clientes.end();
};

std::map<std::string, Cliente *> ManejadorCliente::obtenerClientes() {
    std::map<std::string, Cliente *> clientes;
    clientes.insert(this->clientes.begin(), this->clientes.end());
    return clientes;
}
