#include "../../headers/controladores/ControladorUsuario.h"
#include "../../headers/cliente.h"
#include "../../headers/datatypes/DTFecha.h"
#include "../../headers/manejadores/ManejadorCliente.h"
#include "../../headers/manejadores/ManejadorUsuario.h"
#include "../../headers/manejadores/ManejadorVendedor.h"
#include "../../headers/vendedor.h"

std::vector<std::string> ControladorUsuario::listarNicknamesUsuarios() {
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    std::map<std::string, Usuario *> usuarios =
        manejadorUsuario->obtenerUsuarios();

    std::vector<std::string> nicknamesUsuarios;
    for (auto &&usuario : usuarios) {
        nicknamesUsuarios.push_back(usuario.first);
    }
    return nicknamesUsuarios;
}

bool ControladorUsuario::AltaCliente(std::string nickname,
                                     std::string contrasena, int dia, int mes,
                                     int anio, std::string calle, int puerta,
                                     std::string ciudad) {
    ManejadorCliente *mc = ManejadorCliente::getInstance();
    ManejadorUsuario *mu = ManejadorUsuario::getInstance();
    bool aux = mu->esta(nickname);
    if (!aux) {
        Cliente *cli = new Cliente(nickname, contrasena, dia, mes, anio, calle,
                                   puerta, ciudad);
        mc->recibirCliente(cli);
        mu->agregarUsuario(cli);
    }
    return aux;
};

bool ControladorUsuario::AltaVendedor(std::string nickname,
                                      std::string contrasena, int dia, int mes,
                                      int anio, std::string rut) {
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    ManejadorUsuario *mu = ManejadorUsuario::getInstance();
    bool aux = mu->esta(nickname);
    if (!aux) {
        Vendedor *ven = new Vendedor(nickname, contrasena, dia, mes, anio, rut);
        mv->recibirVendedor(ven);
        mu->agregarUsuario(ven);
    }
    return aux;
};

DTInfoExpediente ControladorUsuario::getExpediente(std::string nick) {
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    bool aux = mv->esta(nick);
    if (aux) {
        Vendedor *v = mv->getVendedor(nick);
        return v->expediente();
    } else {
        ManejadorCliente *mc = ManejadorCliente::getInstance();
        Cliente *c = mc->getCliente(nick);
        return c->expediente();
    }
};

Usuario *ControladorUsuario::cargarLote(bool a, std::string b, std::string c,
                                        DTFecha f) {
    ManejadorUsuario *mu = ManejadorUsuario::getInstance();
    if (a) {
        // vendedor
        ManejadorVendedor *mv = ManejadorVendedor::getInstance();
        Vendedor *ven =
            new Vendedor(b, c, f.getDia(), f.getMes(), f.getAnio(), "");
        mv->recibirVendedor(ven);
        mu->agregarUsuario(ven);
        return ven;
    } else {
        ManejadorCliente *mc = ManejadorCliente::getInstance();
        Cliente *cli =
            new Cliente(b, c, f.getDia(), f.getMes(), f.getAnio(), "", 0, "");
        mc->recibirCliente(cli);
        mu->agregarUsuario(cli);
        return cli;
    }
}

void ControladorUsuario::asociarVendedorLote(Usuario *v, std::string r) {
    Vendedor *ve = dynamic_cast<Vendedor *>(v);
    ve->setRut(r);
}

void ControladorUsuario::asociarClienteLote(Usuario *cl, std::string a, int b,
                                            std::string c) {
    Cliente *cli = dynamic_cast<Cliente *>(cl);
    cli->setcalle(a);
    cli->setpuerta(b);
    cli->setciudad(c);
};

std::vector<DTCliente> ControladorUsuario::listarClientes() {
    ManejadorCliente *ManejadorCliente = ManejadorCliente::getInstance();
    std::map<std::string, Cliente *> clientes =
        ManejadorCliente->obtenerClientes();
    std::vector<DTCliente> DTClientes;
    for (auto &&clientes : clientes) {
        DTClientes.push_back(clientes.second->getDTCliente());
    }
    return DTClientes;
};

std::vector<DTVendedor> ControladorUsuario::listarVendedores() {
    ManejadorVendedor *ManejadorVendedor = ManejadorVendedor::getInstance();
    std::map<std::string, Vendedor *> vendedores =
        ManejadorVendedor->obtenerVendedores();

    std::vector<DTVendedor> DTVendedor;
    for (auto &&vendedor : vendedores) {
        DTVendedor.push_back(vendedor.second->getDTVendedor());
    }
    return DTVendedor;
};
