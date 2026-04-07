#ifndef MANEJADORPRODUCTO
#define MANEJADORPRODUCTO

#include "../producto.h"
#include <map>

class ManejadorProducto {
  private:
    std::map<int, Producto *> productos;
    static ManejadorProducto *instance;
    ManejadorProducto();

  public:
    static ManejadorProducto *getInstance();
    Producto *buscarProducto(int codigo);
    std::map<int, Producto *> obtenerProductos();
    void agregarProductoCol(Producto *Producto);
};

#endif
