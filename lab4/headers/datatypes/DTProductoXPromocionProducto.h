#ifndef DTPRODUCTOXPROMOCIONPRODUCTO
#define DTPRODUCTOXPROMOCIONPRODUCTO

#include "DTProducto.h"
#include "DTPromocionProducto.h"

class DTProductoXPromocionProducto {
  private:
    DTProducto producto;
    DTPromocionProducto promocionProducto;

  public:
    DTProductoXPromocionProducto(DTProducto producto,
                                 DTPromocionProducto promocionProducto);
    DTProducto getProducto();
    DTPromocionProducto getPromocionProducto();
};

#endif
