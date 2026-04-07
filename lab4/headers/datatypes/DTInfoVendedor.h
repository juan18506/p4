#ifndef DTINFOVENDEDOR
#define DTINFOVENDEDOR

#include <iostream>
#include <vector>
// #include "DTInfoExpediente.h"
#include "DTProducto.h"
#include "DTPromocion.h"
#include "DTVendedor.h"

class DTInfoVendedor {
  private:
    DTVendedor vendedor;
    std::vector<DTProducto> productos;
    std::vector<DTPromocion> promociones;

  public:
    DTInfoVendedor();
    DTInfoVendedor(DTVendedor vendedor, std::vector<DTProducto> productos,
                   std::vector<DTPromocion> promociones);
    std::string imprimir();
};

#endif