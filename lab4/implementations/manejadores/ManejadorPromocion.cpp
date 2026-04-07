#include "../../headers/manejadores/ManejadorPromocion.h"

ManejadorPromocion *ManejadorPromocion::instance = NULL;

ManejadorPromocion::ManejadorPromocion() {
    this->promociones = std::map<std::string, Promocion *>();
}

ManejadorPromocion *ManejadorPromocion::getInstance() {
    if (ManejadorPromocion::instance == NULL)
        ManejadorPromocion::instance = new ManejadorPromocion();
    return ManejadorPromocion::instance;
}

void ManejadorPromocion::agregarPromocion(Promocion *promocion) {
    this->promociones.insert({promocion->getNombre(), promocion});
}

Promocion *ManejadorPromocion::buscarPromocion(std::string nombre) {
    return this->promociones.at(nombre);
}

std::map<std::string, Promocion *> ManejadorPromocion::obtenerPromociones() {
    std::map<std::string, Promocion *> promociones;
    promociones.insert(this->promociones.begin(), this->promociones.end());
    return promociones;
}
