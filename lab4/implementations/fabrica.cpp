#include "../headers/fabrica.h"
#include "../headers/controladores/ControladorComentario.h"
#include "../headers/controladores/ControladorCompra.h"
#include "../headers/controladores/ControladorNotificacion.h"
#include "../headers/controladores/ControladorProducto.h"
#include "../headers/controladores/ControladorPromocion.h"
#include "../headers/controladores/ControladorSistema.h"
#include "../headers/controladores/ControladorUsuario.h"

Fabrica *Fabrica::instance = NULL;

Fabrica::Fabrica() {}

Fabrica *Fabrica::getInstance() {
    if (instance == NULL)
        instance = new Fabrica();
    return instance;
}

IConNotificacion *Fabrica::getIContNotificacion() {
    return new ControladorNotificacion();
};

IConUsuario *Fabrica::getIContUsuario() { return new ControladorUsuario(); };

IConSistema *Fabrica::getIContSistema() {
    return ControladorSistema::getInstance();
}

IConProducto *Fabrica::getIContProducto() { return new ControladorProducto(); };

IConComentario *Fabrica::getIContComentario() {
    return new ControladorComentario();
};

IConPromocion *Fabrica::getIContPromocion() {
    return new ControladorPromocion();
};

IConCompra *Fabrica::getIContCompra() { return new ControladorCompra(); };