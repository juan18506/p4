#ifndef PRODSELECCION
#define PRODSELECCION

#include "DTProducto.h"

class DTProdSeleccion {
  private:
    int cantidad;
    DTProducto datosProducto;

  public:
    DTProdSeleccion(int cantidad, DTProducto const &datosProducto);
    DTProdSeleccion(const DTProdSeleccion &dtPS);
    DTProducto getDTProducto();
    int getCantidad();
};

#endif
