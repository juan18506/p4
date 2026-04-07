#ifndef INTCONTSISTEMA
#define INTCONTSISTEMA

#include "../datatypes/DTFecha.h"

class IConSistema {
  public:
    virtual void agregarFecha(DTFecha fecha) = 0;
    virtual DTFecha getFecha() = 0;
    virtual void limpiarTodo() = 0;
};

#endif
