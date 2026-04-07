#include "../headers/vendedor.h"
#include "../headers/datatypes/DTInfoVendedor.h"
#include "../headers/producto.h"

std::map<int, Producto *> Vendedor::getProductos() { return this->productos; }

void Vendedor::agregarProducto(Producto *producto) {
    this->productos.insert({producto->getCodigo(), producto});
}

Vendedor::Vendedor(std::string nickname, std::string contrasena, int dia,
                   int mes, int anio, std::string rut)
    : Usuario(nickname, contrasena, dia, mes, anio) {
    this->rut = rut;
}

void Vendedor::notificarObserve(DTNotificacion notificacion) {
    for (IObserver *o : suscriptores) {
        o->notificar(notificacion);
    }
};

void Vendedor::agregarSuscriptor(IObserver *cliente) {
    suscriptores.push_back(cliente);
}

void Vendedor::borrarSuscripcion(std::string nickCliente) {
    // ya se comprobo si esta el cliente
    int id = 0;
    for (IObserver *c : suscriptores) {
        if (c->getNickname() == nickCliente) {
            std::vector<IObserver *>::iterator it;
            it = suscriptores.begin() + id;
            suscriptores.erase(it);
            break;
        } else {
            id = id + 1;
        }
    }
}

bool Vendedor::estaSuscripto(std::string nickCliente) {
    bool res = false;
    for (IObserver *c : suscriptores) {
        if (c->getNickname() == nickCliente) {
            res = true;
            break;
        }
    }
    return res;
}

DTVendedor Vendedor::getDTVendedor() {
    return DTVendedor(this->getNickname(), this->getNacimiento(), rut);
}

DTInfoExpediente Vendedor::expediente() {
    std::map<int, Producto *>::iterator it;
    std::map<std::string, Promocion *>::iterator it2;
    std::vector<DTProducto> res1;
    std::vector<DTPromocion> res2;
    for (it = productos.begin(); it != productos.end(); it++) {
        // despues se ve si se nesecita cambiar los nombres
        DTProducto dtp = it->second->getDTProducto();
        res1.push_back(dtp);
    }
    for (it2 = promociones.begin(); it2 != promociones.end(); it2++) {
        // despues se cambian los nombres a los correctos
        DTPromocion dtp2 = it2->second->getDTPromocion();
        res2.push_back(dtp2);
    }
    return DTInfoExpediente(DTInfoVendedor(this->getDTVendedor(), res1, res2));
};

bool Vendedor::estaPromo(std::string nombre) {
    return promociones.find(nombre) != promociones.end();
};

std::string Vendedor::getRut() { return rut; }

void Vendedor::asociarPromocion(Promocion *pm) {
    std::vector<DTProducto> prod;
    std::vector<PromocionProducto *> a = pm->getProductos();
    for (auto p : a) {
        prod.push_back(p->getProducto()->getDTProducto());
    }
    DTNotificacion aux =
        DTNotificacion(this->getNickname(), pm->getNombre(), prod);
    notificarObserve(aux);
    this->promociones.insert({pm->getNombre(), pm});
}

void Vendedor::setRut(std::string r) { this->rut = r; };
