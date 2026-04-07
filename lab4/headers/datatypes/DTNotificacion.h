#ifndef NOTIFICACION
#define NOTIFICACION

#include "DTProducto.h"
#include <string>
#include <vector>

class DTNotificacion {
  private:
    std::string nickname;
    std::string nombre;
    std::vector<DTProducto> productos;

  public:
    DTNotificacion(std::string nick, std::string nomb,
                   std::vector<DTProducto> prod);
    std::string imprimir();
};

#endif
