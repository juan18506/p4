#ifndef DTPROMOCION
#define DTPROMOCION

#include "DTFecha.h"
#include "DTProducto.h"
#include <string>
#include <vector>

class DTPromocion {
  private:
    float descuento;
    std::string nombre;
    std::string descripcion;
    DTFecha fin = DTFecha(0, 0, 0);
    // conjunto(DTProducto) productos; //luego se ve si es necesario y si es un
    // set ,vector o otra cosa string nickvendedor ; // si llega a se necesario
  public:
    // DTPromocion();
    DTPromocion(const DTPromocion &promo);
    std::string imprimir();
    DTPromocion(std::string nombre, std::string descripcion, float descuento,
                DTFecha fin);
    std::string getNombre();
    std::string getDescripcion();
    float getDescuento();
    DTFecha getFin();
};

#endif
