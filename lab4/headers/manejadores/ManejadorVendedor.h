#ifndef MANEJADORVENDEDOR
#define MANEJADORVENDEDOR

#include "../datatypes/DTFecha.h"
#include "../vendedor.h"
#include <map>
#include <vector>

class Vendedor;

class ManejadorVendedor {
  private:
    std::map<std::string, Vendedor *> vendedores;
    static ManejadorVendedor *instance;
    ManejadorVendedor();

  public:
    static ManejadorVendedor *getInstance();
    Vendedor *getVendedor(std::string nickname);
    std::map<std::string, Vendedor *> getVendedores();
    std::vector<Vendedor *>
    getVendedoresEsp(std::vector<std::string> nickvendedores);
    void recibirVendedor(Vendedor *vendedor);
    bool esta(std::string nickname);
    std::map<std::string, Vendedor *> obtenerVendedores();
};

#include "../vendedor.h"

#endif
