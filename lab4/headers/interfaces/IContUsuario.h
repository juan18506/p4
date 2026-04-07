#ifndef ICONUSUARIO
#define ICONUSUARIO

#include "../../headers/cliente.h"
#include "../../headers/datatypes/DTFecha.h"
#include "../../headers/vendedor.h"
#include "../datatypes/DTInfoExpediente.h"
#include "../usuario.h"
#include <iostream>
#include <vector>
// #include "../../headers/datatypes/DTUsuario.h"
#include "../../headers/datatypes/DTCliente.h"
#include "../../headers/datatypes/DTVendedor.h"

class IConUsuario {
  public:
    virtual bool AltaCliente(std::string nickname, std::string contrasena,
                             int dia, int mes, int anio, std::string calle,
                             int puerta, std::string ciudad) = 0;
    virtual bool AltaVendedor(std::string nickname, std::string contrasena,
                              int dia, int mes, int anio, std::string rut) = 0;
    virtual DTInfoExpediente getExpediente(std::string nick) = 0;
    virtual std::vector<std::string> listarNicknamesUsuarios() = 0;
    virtual Usuario *cargarLote(bool a, std::string b, std::string c,
                                DTFecha f) = 0;
    virtual void asociarVendedorLote(Usuario *v, std::string r) = 0;
    virtual void asociarClienteLote(Usuario *cl, std::string a, int b,
                                    std::string c) = 0;
    // virtual std::vector<DTCliente> listarUsuarios()=0;
    virtual std::vector<DTCliente> listarClientes() = 0;
    virtual std::vector<DTVendedor> listarVendedores() = 0;
    virtual ~IConUsuario() {};
};

#endif