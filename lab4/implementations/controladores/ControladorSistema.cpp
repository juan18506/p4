#include "../../headers/controladores/ControladorSistema.h"
#include "../../headers/manejadores/ManejadorCliente.h"
#include "../../headers/manejadores/ManejadorProducto.h"
#include "../../headers/manejadores/ManejadorPromocion.h"
#include "../../headers/manejadores/ManejadorUsuario.h"
#include "../../headers/manejadores/ManejadorVendedor.h"

ControladorSistema::ControladorSistema() {}

ControladorSistema *ControladorSistema::instance = NULL;

ControladorSistema *ControladorSistema::getInstance() {
    if (ControladorSistema::instance == NULL)
        ControladorSistema::instance = new ControladorSistema();
    return instance;
}

void ControladorSistema::agregarFecha(DTFecha fecha) { this->fecha = fecha; }

DTFecha ControladorSistema::getFecha() { return fecha; };

void ControladorSistema::limpiarTodo() {
    ManejadorPromocion *mpm = ManejadorPromocion::getInstance();
    std::map<std::string, Promocion *> pms = mpm->obtenerPromociones();
    for (auto &&stpm : pms) {
        Promocion *pm = stpm.second;
        for (auto &&pmpd : pm->getProductos())
            delete pmpd;
        delete pm;
    }
    ManejadorProducto *mpd = ManejadorProducto::getInstance();
    std::map<int, Producto *> pds = mpd->obtenerProductos();
    for (auto &&stpd : pds) {
        Producto *pd = stpd.second;
        std::vector<DTComentario> dtComentarios = pd->obtenerComentarios();
        for (auto &&dtCom : dtComentarios)
            delete pd->buscarComentario(dtCom.getId());
        delete pd;
    }

    ManejadorVendedor *mv = ManejadorVendedor::getInstance();
    std::map<std::string, Vendedor *> vs = mv->obtenerVendedores();
    for (auto &&stv : vs) {
        Vendedor *v = stv.second;
        delete v;
    }
    ManejadorCliente *mc = ManejadorCliente::getInstance();
    std::map<std::string, Cliente *> cs = mc->obtenerClientes();
    for (auto &&stc : cs) {
        Cliente *c = stc.second;
        std::vector<Compra *> compras = c->getCompras();
        for (auto cp : compras) {
            std::vector<CompraProducto *> cppds = cp->getProductos();
            for (auto cppd : cppds)
                delete cppd;
            delete cp;
        }
        delete c;
    }
}
