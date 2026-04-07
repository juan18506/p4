#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

class Producto;
class Compra;

class CompraProducto {
  private:
    int cantidad;
    bool entregados;
    Compra *compra;
    Producto *producto;

  public:
    CompraProducto(int cantidad, bool entregados, Compra *compra,
                   Producto *producto);
    bool getEntregados();
    Compra *getCompra();
    void setEntregados(bool);
    Producto *getProducto();
    int getCant();
};

#include "compra.h"
#include "producto.h"

#endif
