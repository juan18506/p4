#ifndef PROMOCION_H
#define PROMOCION_H

#include "datatypes/DTFecha.h"
#include "datatypes/DTPromocion.h"
#include "vendedor.h"
#include <string>
#include <vector>

class PromocionProducto;
class Vendedor;

class Promocion {
  private:
    float descuento;
    std::string nombre;
    std::string descripcion;
    DTFecha fin = DTFecha(0, 0, 0);
    std::vector<PromocionProducto *> productos;
    Vendedor *vendedor;

  public:
    float getDescuento();
    std::string getNombre();
    std::string getDescripcion();
    DTFecha getFin();
    std::vector<PromocionProducto *> getProductos();
    Vendedor *getVendedor();
    Promocion(std::string nombre, std::string descripcion, float descuento,
              DTFecha fin);
    DTPromocion getDTPromocion();
    void asociarProducto(PromocionProducto *pmpd);
};

#include "promocionProducto.h"

#endif
