#include "../../headers/controladores/ControladorPromocion.h"
#include "../../headers/controladores/ControladorProducto.h"
#include "../../headers/controladores/ControladorSistema.h"
#include "../../headers/datatypes/DTFecha.h"
#include "../../headers/manejadores/ManejadorPromocion.h"

void ControladorPromocion::iniciarCrearPromocion(std::string nombre,
                                                 std::string descripcion,
                                                 float descuento, DTFecha fin) {
    this->promoNombre = nombre;
    this->promoDescripcion = descripcion;
    this->promoDescuento = descuento;
    this->promoFin = fin;
    this->productosCodigo = std::vector<int>();
    this->productosMinimo = std::vector<int>();
}

std::vector<std::string> ControladorPromocion::obtenerNicksVendedores() {
    ControladorProducto *cp = new ControladorProducto();
    std::vector<std::string> nicks = cp->obtenerNicksVendedores();
    delete cp;
    return nicks;
}

std::vector<DTProductoLinea>
ControladorPromocion::obtenerProductosSinPromoVigenteVendedor(
    std::string nickname) {
    this->vendedorNick = nickname;
    std::vector<DTProductoLinea> sinpromo;
    ControladorSistema *cs = ControladorSistema::getInstance();
    DTFecha fecha = cs->getFecha();
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    Vendedor *v = mv->getVendedor(nickname);
    std::map<int, Producto *> pds = v->getProductos();
    for (auto &&prod : pds) {
        prod.second->actualizarVigenciaPromocion(fecha);
        bool vg = prod.second->tienePromocionVigente();
        if (!vg)
            sinpromo.push_back(prod.second->getDTProductoLinea());
    }
    return sinpromo;
}

void ControladorPromocion::seleccionarProductoPromocion(int codigo,
                                                        int minimo) {
    this->productosCodigo.push_back(codigo);
    this->productosMinimo.push_back(minimo);
}

void ControladorPromocion::terminarCrearPromocion() {
    Promocion *pm = new Promocion(this->promoNombre, this->promoDescripcion,
                                  this->promoDescuento, this->promoFin);
    ManejadorPromocion *mpm = ManejadorPromocion::getInstance();
    mpm->agregarPromocion(pm);
    ManejadorProducto *mpd = ManejadorProducto::getInstance();
    for (unsigned int i = 0; i < this->productosCodigo.size(); i++) {
        int codigo = this->productosCodigo[i];
        int minimo = this->productosMinimo[i];
        Producto *pd = mpd->buscarProducto(codigo);
        PromocionProducto *pmpd = new PromocionProducto(minimo);
        pmpd->asociarProducto(pd);
        pmpd->asociarPromocion(pm);
        pd->asociarPromocion(pmpd);
        pm->asociarProducto(pmpd);
    }
    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    Vendedor *v = mv->getVendedor(this->vendedorNick);
    v->asociarPromocion(pm);
}

/************ 1- INICIO CONSULTAR PROMOCION ************/
std::vector<DTPromocion> ControladorPromocion::obtenerPromocionesVigentes() {
    ControladorSistema *controladorSistema = ControladorSistema::getInstance();
    DTFecha fecha_actual = controladorSistema->getFecha();
    ManejadorPromocion *manejadorPromocion = ManejadorPromocion::getInstance();
    std::map<std::string, Promocion *> promociones =
        manejadorPromocion->obtenerPromociones();
    std::vector<DTPromocion> datosPromociones;
    for (auto &&promocion : promociones) {
        if (fecha_actual <= promocion.second->getFin())
            datosPromociones.push_back(DTPromocion(
                promocion.second->getNombre(),
                promocion.second->getDescripcion(),
                promocion.second->getDescuento(), promocion.second->getFin()));
    }
    return datosPromociones;
}

std::vector<DTProducto>
ControladorPromocion::obtenerDatosPromocion(std::string nombre) {
    ManejadorPromocion *manejadorPromocion = ManejadorPromocion::getInstance();
    Promocion *promocion = manejadorPromocion->buscarPromocion(nombre);
    std::vector<PromocionProducto *> pproductos = promocion->getProductos();
    std::vector<DTProducto> datosProductos;
    for (PromocionProducto *pproducto : pproductos) {
        datosProductos.push_back(pproducto->getProducto()->getDTProducto());
    }
    return datosProductos;
}

std::vector<DTProductoXPromocionProducto>
ControladorPromocion::obtenerProductosPromocion(std::string nombre) {
    ManejadorPromocion *manejadorPromocion = ManejadorPromocion::getInstance();
    Promocion *promocion = manejadorPromocion->buscarPromocion(nombre);
    std::vector<PromocionProducto *> pproductos = promocion->getProductos();
    std::vector<DTProductoXPromocionProducto> datosProductos =
        std::vector<DTProductoXPromocionProducto>();
    for (PromocionProducto *pproducto : pproductos) {
        DTProducto dtp = pproducto->getProducto()->getDTProducto();
        DTPromocionProducto dtpp = DTPromocionProducto(pproducto->getMin());
        datosProductos.push_back(DTProductoXPromocionProducto(dtp, dtpp));
    }
    return datosProductos;
}

DTVendedor ControladorPromocion::obtenerVendedorPromocion(std::string nombre) {
    ManejadorPromocion *mpm = ManejadorPromocion::getInstance();
    Promocion *pm = mpm->buscarPromocion(nombre);
    std::vector<PromocionProducto *> pmpds = pm->getProductos();
    PromocionProducto *pmpd = pmpds.at(0);
    Producto *pd = pmpd->getProducto();
    Vendedor *v = pd->getVendedor();
    return v->getDTVendedor();
}

/************ FIN CONSULTAR PROMOCION ************/

Promocion *ControladorPromocion::cargarLote(std::string nombre,
                                            std::string descripcion,
                                            int descuento, DTFecha fin) {
    Promocion *promo =
        new Promocion(nombre, descripcion, (float)descuento, fin);
    ManejadorPromocion *mp = ManejadorPromocion::getInstance();
    mp->agregarPromocion(promo);
    return promo;
}

PromocionProducto *ControladorPromocion::asociarLote(Promocion *pm,
                                                     Producto *pd, int minimo) {
    PromocionProducto *pmpd = new PromocionProducto(minimo);
    pmpd->asociarProducto(pd);
    pmpd->asociarPromocion(pm);
    pm->asociarProducto(pmpd);
    pd->asociarPromocion(pmpd);
    Vendedor *v = pd->getVendedor();
    if (!v->estaPromo(pm->getNombre()))
        v->asociarPromocion(pm);
    return pmpd;
}
