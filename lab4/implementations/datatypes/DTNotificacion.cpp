#include "../../headers/datatypes/DTNotificacion.h"

DTNotificacion::DTNotificacion(std::string nick, std::string nomb,
                               std::vector<DTProducto> prod) {
    nickname = nick;
    nombre = nomb;
    productos = prod;
}

std::string DTNotificacion::imprimir() {
    std::string a;
    for (DTProducto p : this->productos) {
        a = a + " " + p.imprimir() + "\n";
    }
    return nickname + " " + nombre + " " + a + "\n";
}