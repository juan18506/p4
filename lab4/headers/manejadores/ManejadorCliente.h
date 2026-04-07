#ifndef MANEJADORCLIENTE
#define MANEJADORCLIENTE

#include "../cliente.h"
#include <string>
#include <vector>

class ManejadorCliente {
  private:
    std::map<std::string, Cliente *> clientes;
    static ManejadorCliente *instance;
    ManejadorCliente();

  public:
    static ManejadorCliente *getInstance();
    Cliente *getCliente(std::string nickname);
    void recibirCliente(Cliente *cliente);
    bool esta(std::string nickname);
    std::map<std::string, Cliente *> obtenerClientes();
};

#endif