#include "../../headers/controladores/ControladorCompra.h"
#include "../../headers/controladores/ControladorSistema.h"
#include "../../headers/datatypes/DTFecha.h"
#include "../../headers/manejadores/ManejadorCliente.h"
#include "../../headers/manejadores/ManejadorProducto.h"
#include "../../headers/manejadores/ManejadorPromocion.h"

std::vector<std::string> ControladorCompra::obtenerNicknamesClientes() {
    ManejadorCliente *manejadorCliente = ManejadorCliente::getInstance();
    std::map<std::string, Cliente *> clientes =
        manejadorCliente->obtenerClientes();

    std::vector<std::string> nicknamesClientes;
    for (auto &&cliente : clientes) {
        nicknamesClientes.push_back(cliente.first);
    }

    return nicknamesClientes;
}

void ControladorCompra::seleccionarCliente(std::string nickname) {
    this->nickname = nickname;
}

std::vector<DTProducto> ControladorCompra::obtenerProductos() {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    std::map<int, Producto *> productos = manejadorProducto->obtenerProductos();

    std::vector<DTProducto> datosProductos;
    for (auto &&producto : productos) {
        datosProductos.push_back(producto.second->getDTProducto());
    }

    return datosProductos;
}

void ControladorCompra::confirmarCompra() {
    ManejadorCliente *manejadorCliente = ManejadorCliente::getInstance();

    Cliente *cliente = manejadorCliente->getCliente(this->nickname);
    Compra *compra = new Compra(cliente, this->dtCompra);
    cliente->nuevaCompraCliente(compra);

    std::map<int, Producto *> productos =
        this->buscarProductos(this->prodCarrito);
    for (auto &&dtProdSel : this->prodCarrito) {
        int codigo = dtProdSel.getDTProducto().getCodigo();
        productos.at(codigo)->setStock(dtProdSel.getDTProducto().getStock() -
                                       dtProdSel.getCantidad());
        productos.at(codigo)->nuevaCompraProducto(dtProdSel.getCantidad(),
                                                  compra);
    }
}

std::map<int, Producto *>
ControladorCompra::buscarProductos(std::vector<DTProdSeleccion> prodCarrito) {
    ManejadorProducto *ManejadorProducto = ManejadorProducto::getInstance();
    std::map<int, Producto *> productosManejador =
        ManejadorProducto->obtenerProductos();

    std::map<int, Producto *> productos = std::map<int, Producto *>();
    for (auto &&dtProductoSelec : prodCarrito) {
        DTProducto dtProducto = dtProductoSelec.getDTProducto();
        productos.insert({dtProducto.getCodigo(),
                          productosManejador.at(dtProducto.getCodigo())});
    }

    return productos;
}

void ControladorCompra::agregarProductoCompra(int codigo, int cant) {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    Producto *productoSeleccionado = manejadorProducto->buscarProducto(codigo);

    this->prodCarrito.push_back(
        DTProdSeleccion(cant, productoSeleccionado->getDTProducto()));
}

bool ControladorCompra::existeProductoEnCompra(int cod) {
    bool existe = false;
    for (auto &&dtProdSelec : this->prodCarrito) {
        if (dtProdSelec.getDTProducto().getCodigo() == cod) {
            existe = true;
            break;
        }
    }
    return existe;
}

bool ControladorCompra::cantValidaDeProducto(int cant, int cod) {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    Producto *productoSeleccionado = manejadorProducto->buscarProducto(cod);
    bool cantValida = true;
    if (cant > productoSeleccionado->getStock()) {
        cantValida = false;
    }
    return cantValida;
}

DTCompra ControladorCompra::obtenerCompra() {
    ControladorSistema *controladorSistema = ControladorSistema::getInstance();
    DTFecha fecha = controladorSistema->getFecha();
    ManejadorPromocion *manejadorPromocion = ManejadorPromocion::getInstance();
    std::map<std::string, Promocion *> promociones =
        manejadorPromocion->obtenerPromociones();
    std::vector<DTProdSeleccion> noEncontrados = this->prodCarrito;
    float monto = 0;
    for (auto &&promocion : promociones) {
        if (fecha <= promocion.second->getFin()) {
            std::vector<PromocionProducto *> promProds =
                promocion.second->getProductos();
            std::map<int, int> prCodMins;
            for (auto &&promProd : promProds) {
                int min = promProd->getMin();
                int codigoProd = promProd->getProducto()->getCodigo();
                prCodMins.insert({codigoProd, min});
            }
            bool aplica = true;
            std::vector<DTProdSeleccion> aux;
            int i = 0;
            for (auto &&prCodMin : prCodMins) {
                while (i < (int)noEncontrados.size() &&
                       noEncontrados.at(i).getDTProducto().getCodigo() !=
                           prCodMin.first) {
                    i++;
                }

                if (i != (int)noEncontrados.size() &&
                    noEncontrados.at(i).getCantidad() >= prCodMin.second) {
                    aux.push_back(noEncontrados.at(i));
                    noEncontrados.erase(noEncontrados.begin() + i);
                } else {
                    aplica = false;
                }
            }

            float res = 0;
            for (auto &&prodMin : aux) {
                res +=
                    prodMin.getDTProducto().getPrecio() * prodMin.getCantidad();
            }
            if (aplica) {
                monto =
                    monto +
                    (res * ((100 - promocion.second->getDescuento()) / 100));
            } else {
                monto += res;
            }
        }
    }

    for (auto &&noEncontrado : noEncontrados) {
        monto = monto + noEncontrado.getDTProducto().getPrecio() *
                            noEncontrado.getCantidad();
    }

    DTCompra carrito =
        DTCompra(this->nickname, monto, fecha, this->prodCarrito);
    return carrito;
}

/************ FIN REALIZAR COMPRA ************/

Compra *ControladorCompra::cargarLote(Usuario *usuario, DTFecha fecha,
                                      float monto, Promocion *promocion) {
    Cliente *cliente = dynamic_cast<Cliente *>(usuario);
    Compra *compra =
        new Compra(cliente, DTCompra(cliente->getNickname(), monto, fecha,
                                     std::vector<DTProdSeleccion>()));
    cliente->nuevaCompraCliente(compra);
    return compra;
}

CompraProducto *ControladorCompra::asociarLote(Compra *compra,
                                               Producto *producto, int cantidad,
                                               bool entregados) {
    CompraProducto *cppd =
        new CompraProducto(cantidad, entregados, compra, producto);
    compra->asociarProducto(cppd);
    producto->asociarCompra(cppd);
    return cppd;
}
