#ifndef DTINFOEXPEDIENTE
#define DTINFOEXPEDIENTE

#include "DTInfoCliente.h"
#include "DTInfoVendedor.h"
#include <string>

class DTInfoExpediente {
  private:
    DTInfoCliente cliente;
    DTInfoVendedor vendedor;
    bool esCliente;

  public:
    DTInfoExpediente(DTInfoCliente cliente);
    DTInfoExpediente(DTInfoVendedor vendedor);
    std::string imprimir();
};

#endif
