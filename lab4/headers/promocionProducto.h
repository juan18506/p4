#ifndef PROMOCIONPRODUCTO
#define PROMOCIONPRODUCTO

#include "producto.h"
#include "promocion.h"

class Promocion;
class Producto;

class PromocionProducto {
  private:
    int minimo;
    Producto *producto;
    Promocion *promocion;

  public:
    int getMin();
    Producto *getProducto();
    Promocion *getPromocion();
    PromocionProducto(int minimo);
    void asociarProducto(Producto *pd);
    void asociarPromocion(Promocion *pm);
};

#endif
