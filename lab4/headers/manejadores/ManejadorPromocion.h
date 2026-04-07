#ifndef MANEJADORPROMOCION
#define MANEJADORPROMOCION

#include "../promocion.h"
#include <map>

class ManejadorPromocion {
  private:
    std::map<std::string, Promocion *> promociones;
    static ManejadorPromocion *instance;
    ManejadorPromocion();

  public:
    static ManejadorPromocion *getInstance();
    void agregarPromocion(Promocion *promocion);
    Promocion *buscarPromocion(std::string nombre);
    std::map<std::string, Promocion *> obtenerPromociones();
};

#endif
