#ifndef DTPRODUCTOLINEA_H
#define DTPRODUCTOLINEA_H

#include <string>

class DTProductoLinea {
  private:
    int codigo;
    std::string nombre;

  public:
    int getCodigo();
    std::string getNombre();
    DTProductoLinea(int codigo, std::string nombre);
};

#endif
