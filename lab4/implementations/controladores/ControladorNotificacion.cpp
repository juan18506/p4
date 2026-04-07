#include "../../headers/controladores/ControladorNotificacion.h"
#include "../../headers/cliente.h"
#include "../../headers/manejadores/ManejadorCliente.h"
#include "../../headers/manejadores/ManejadorVendedor.h"
#include "../../headers/vendedor.h"

std::vector<DTVendedor>
ControladorNotificacion::ListarVendedoresNoSuscriptos(std::string nickname) {
    this->nickname = nickname;
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    std::map<std::string, Vendedor *> sv = mv->getVendedores();
    std::vector<DTVendedor> res;
    std::map<std::string, Vendedor *>::iterator it;
    for (it = sv.begin(); it != sv.end(); ++it) {
        if (!(it->second->estaSuscripto(nickname))) {
            DTVendedor aux = it->second->getDTVendedor();
            res.push_back(aux);
        }
    }
    return res;
};

void ControladorNotificacion::agregarSuscripcion(std::string nickvendedor) {
    ManejadorCliente *mc = ManejadorCliente::getInstance();
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    Cliente *sus = mc->getCliente(this->nickname);
    Vendedor *you = mv->getVendedor(nickvendedor);
    you->agregarSuscriptor(sus);
};

void ControladorNotificacion::liberarUsuario() { this->nickname = ""; };

std::vector<DTNotificacion>
ControladorNotificacion::listarYEliminarNotificaciones(std::string nickname) {
    ManejadorCliente *mc = ManejadorCliente::getInstance();
    Cliente *c = mc->getCliente(nickname);
    return c->imprimiryborrar();
};

std::vector<DTVendedor>
ControladorNotificacion::listarSuscripciones(std::string nickname) {
    this->nickname = nickname;
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    std::map<std::string, Vendedor *> sv = mv->getVendedores();
    std::vector<DTVendedor> res;
    std::map<std::string, Vendedor *>::iterator it;
    for (it = sv.begin(); it != sv.end(); it++) {
        if (it->second->estaSuscripto(nickname)) {
            DTVendedor aux = it->second->getDTVendedor();
            res.push_back(aux);
        }
    }
    return res;
};

void ControladorNotificacion::seleccionarVendedores(std::string nickvendedor) {
    nickvendedores.push_back(nickvendedor);
};

void ControladorNotificacion::eliminarSuscripcion() {
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    std::vector<Vendedor *> sv = mv->getVendedoresEsp(this->nickvendedores);
    for (Vendedor *v : sv) {
        v->borrarSuscripcion(nickname);
    }
    nickname = "";
    nickvendedores.clear();
};
