#include "../../headers/controladores/ControladorProducto.h"

int ControladorProducto::Prox_codigo = 0;

void ControladorProducto::incrementarCodigo() {
    ControladorProducto::Prox_codigo++;
}

int ControladorProducto::getProxCodigo() {
    return ControladorProducto::Prox_codigo;
}

/************ 1- INICIO ALTA PRODUCTO ************/

std::vector<std::string> ControladorProducto::obtenerNicksVendedores() {
    ManejadorVendedor *manejadorVendedor = ManejadorVendedor::getInstance();
    std::map<std::string, Vendedor *> vendedores =
        manejadorVendedor->obtenerVendedores();
    std::vector<std::string> nicknamesVendedores;
    for (auto &&vendedor : vendedores) {
        nicknamesVendedores.push_back(vendedor.first);
    }
    manejadorVendedor = NULL;
    return nicknamesVendedores;
}

void ControladorProducto::agregarProducto(std::string nicknameVend,
                                          std::string nombre, float precio,
                                          int stock, std::string descripcion,
                                          TipoProducto tipo) {
    Producto *producto =
        new Producto(stock, precio, nombre, descripcion, tipo, nicknameVend);
    ManejadorVendedor *manejadorVendedor = ManejadorVendedor::getInstance();
    Vendedor *vendedor = manejadorVendedor->getVendedor(nicknameVend);
    vendedor->agregarProducto(producto);
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    manejadorProducto->agregarProductoCol(producto);
    manejadorVendedor = NULL;
    manejadorProducto = NULL;
}

/************ FIN ALTA PRODUCTO *****************/

/************ 2- INICIO CONSULTAR PRODUCTO *********/

std::vector<DTProducto> ControladorProducto::listarProducto() {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    std::map<int, Producto *> productos = manejadorProducto->obtenerProductos();
    std::vector<DTProducto> datosProductos;
    for (auto &&producto : productos) {
        datosProductos.push_back(DTProducto(
            producto.second->getCodigo(), -1, -1, producto.second->getNombre(),
            "", producto.second->getTipo(), ""));
    }
    return datosProductos; // listar codigo y nombre!!
}

DTProducto ControladorProducto::obtenerDatosProducto(int codigo) {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    Producto *producto = manejadorProducto->buscarProducto(codigo);
    DTProducto DatosProducto = DTProducto(
        producto->getCodigo(), producto->getStock(), producto->getPrecio(),
        producto->getNombre(), producto->getDescripcion(), producto->getTipo(),
        producto->getVendedor()->getNickname());
    return DatosProducto;
}
/************ FIN CASO CONSULTAR PRODUCTO ************/

/************ 3 - INICIO CASO ENVIAR PRODUCTO ************/
// obtener Nicksvendedores

std::vector<DTProducto>
ControladorProducto::listarProdEnvioPend(std::string nickname) {
    ManejadorVendedor *manejadorVendedor = ManejadorVendedor::getInstance();
    Vendedor *vendedor = manejadorVendedor->getVendedor(nickname);
    std::map<int, Producto *> productos = vendedor->getProductos();
    std::vector<DTProducto> PendienteEnvio;
    std::map<int, Producto *>::iterator it;
    for (it = productos.begin(); it != productos.end(); it++) {
        std::vector<CompraProducto *> comprasProd = it->second->getCompras();
        for (CompraProducto *compraP : comprasProd) {
            if (compraP->getEntregados() == false) {
                PendienteEnvio.push_back(DTProducto(
                    it->second->getCodigo(), it->second->getStock(),
                    it->second->getPrecio(), it->second->getNombre(),
                    it->second->getDescripcion(), it->second->getTipo(),
                    it->second->getVendedor()->getNickname()));
                break;
            }
        }
    }
    return PendienteEnvio;
}

std::vector<DTCompra> ControladorProducto::listarComprasEnvioPend(int codigo) {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    Producto *producto = manejadorProducto->buscarProducto(codigo);
    std::vector<CompraProducto *> comprasProd = producto->getCompras();
    std::vector<DTCompra> PendienteCompra;
    for (CompraProducto *compraP : comprasProd) {
        if (compraP->getEntregados() == false) {
            Compra *compra = compraP->getCompra();
            PendienteCompra.push_back(DTCompra(
                compra->getCliente()->getNickname(), compra->getMonto(),
                compra->getFecha(), std::vector<DTProdSeleccion>()));
        }
    }
    this->codigoProdEnv = codigo;
    return PendienteCompra;
}

void ControladorProducto::selEnviado(std::string nickCliente, int anio, int mes,
                                     int dia) {
    ManejadorCliente *manejadorCliente = ManejadorCliente::getInstance();
    Cliente *cliente = manejadorCliente->getCliente(nickCliente);
    std::vector<Compra *> compras = cliente->getComprasCl();
    for (Compra *compra : compras) {
        if (compra->getFecha().getDia() == dia &&
            compra->getFecha().getMes() == mes &&
            compra->getFecha().getAnio() == anio) {
            std::vector<CompraProducto *> comprasProd = compra->getProductos();
            for (CompraProducto *compraP : comprasProd) {
                if (compraP->getProducto()->getCodigo() == this->codigoProdEnv)
                    compraP->setEntregados(true);
            }
        }
    }
}
/************ FIN CASO ENVIAR PRODUCTO ************/

Producto *ControladorProducto::cargarLote(int codigo, std::string nombre,
                                          std::string descripcion, int stock,
                                          float precio, TipoProducto tipo,
                                          Usuario *usuario) {
    Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
    std::string nicknameVend = vendedor->getNickname();
    ControladorProducto::Prox_codigo = codigo - 1;
    Producto *producto =
        new Producto(stock, precio, nombre, descripcion, tipo, nicknameVend);
    vendedor->agregarProducto(producto);
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    manejadorProducto->agregarProductoCol(producto);
    return producto;
}
