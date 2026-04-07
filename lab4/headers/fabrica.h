#ifndef FABRICA
#define FABRICA
#include "interfaces/IContComentario.h"
#include "interfaces/IContCompra.h"
#include "interfaces/IContNotificacion.h"
#include "interfaces/IContProducto.h"
#include "interfaces/IContPromocion.h"
#include "interfaces/IContSistema.h"
#include "interfaces/IContUsuario.h"

class Fabrica {
  private:
    static Fabrica *instance;
    Fabrica();

  public:
    static Fabrica *getInstance();
    IConNotificacion *getIContNotificacion();
    IConUsuario *getIContUsuario();
    IConSistema *getIContSistema();
    IConProducto *getIContProducto();
    IConComentario *getIContComentario();
    IConPromocion *getIContPromocion();
    IConCompra *getIContCompra();
};

#endif