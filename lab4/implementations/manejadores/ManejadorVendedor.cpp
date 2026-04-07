#include "../../headers/manejadores/ManejadorVendedor.h"

ManejadorVendedor *ManejadorVendedor::instance = NULL;

ManejadorVendedor::ManejadorVendedor() {}

std::map<std::string, Vendedor *> ManejadorVendedor::obtenerVendedores() {
    std::map<std::string, Vendedor *> vendedores;
    vendedores.insert(this->vendedores.begin(), this->vendedores.end());
    return vendedores;
}

ManejadorVendedor *ManejadorVendedor::getInstance() {
    if (instance == NULL)
        instance = new ManejadorVendedor();
    return instance;
}

Vendedor *ManejadorVendedor::getVendedor(std::string nickname) {
    return this->vendedores.at(nickname);
};

std::map<std::string, Vendedor *> ManejadorVendedor::getVendedores() {
    std::map<std::string, Vendedor *> vendedores;
    vendedores.insert(this->vendedores.begin(), this->vendedores.end());
    return vendedores;
};

std::vector<Vendedor *>
ManejadorVendedor::getVendedoresEsp(std::vector<std::string> nickvendedores) {
    std::vector<Vendedor *> aux;
    for (std::string v : nickvendedores) {
        aux.push_back(this->vendedores.at(v));
    }
    return aux;
};

void ManejadorVendedor::recibirVendedor(Vendedor *vendedor) {
    this->vendedores.insert({vendedor->getNickname(), vendedor});
};

bool ManejadorVendedor::esta(std::string nickname) {
    return vendedores.find(nickname) != vendedores.end();
};
