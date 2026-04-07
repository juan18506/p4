#ifndef COMPRA
#define COMPRA

#include "datatypes/DTCompra.h"
#include "datatypes/DTFecha.h"

class Cliente;
class CompraProducto;

class Compra {
  private:
    DTFecha fecha = DTFecha(0, 0, 0);
    float monto;
    Cliente *cliente;
    std::vector<CompraProducto *> productos;

  public:
    Compra(Cliente *cliente, DTCompra dtCompra);
    DTFecha getFecha();
    float getMonto();
    Cliente *getCliente();
    std::vector<CompraProducto *> getProductos();
    void agregarCompraProducto(CompraProducto *cp);
    DTCompra getDTCompra();
    void asociarProducto(CompraProducto *cppd);
};

#include "cliente.h"
#include "compraProducto.h"

#endif
