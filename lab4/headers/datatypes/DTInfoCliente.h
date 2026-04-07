#ifndef DTINFOCLIENTE
#define DTINFOCLIENTE

#include <iostream>
// #include "DTInfoExpediente.h"
#include "DTCliente.h"
#include "DTCompra.h"
#include "DTProducto.h" // pude que no sea necesario
#include <vector>

class DTInfoCliente {
  private:
    DTCliente cliente;
    std::vector<DTCompra> compras;

  public:
    DTInfoCliente();
    DTInfoCliente(std::string nick, DTFecha nacimiento, std::string calle,
                  int puerta, std::string ciudad,
                  std::vector<DTCompra> compras);
    std::string imprimir();
};

#endif