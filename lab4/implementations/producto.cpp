#include "../headers/producto.h"

Producto::Producto(int stock, float precio, std::string nombre,
                   std::string descripcion, TipoProducto tipo,
                   std::string nicknameVend) {
    ControladorProducto::incrementarCodigo();
    this->codigo = ControladorProducto::getProxCodigo();
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->promovigente = NULL;
    this->promosnovigentes = std::vector<PromocionProducto *>();
    ManejadorVendedor *manejadorVendedor = ManejadorVendedor::getInstance();
    Vendedor *vendedor = manejadorVendedor->getVendedor(nicknameVend);
    this->vendedor = vendedor;
    manejadorVendedor = NULL;
}

void Producto::agregarCompra(CompraProducto *compra) {
    this->compras.push_back(compra);
}

void Producto::setStock(int stock) { this->stock = stock; }

std::vector<DTComentario> Producto::obtenerComentarios() {
    std::vector<DTComentario> dtComentarios;

    for (auto &&comentario : this->comentarios)
        dtComentarios.push_back(comentario.second->crearDTComentario());

    return dtComentarios;
}

Comentario *Producto::buscarComentario(int id) {
    return this->comentarios.at(id);
}

void Producto::agregarComentario(Comentario *comentario) {
    this->comentarios.insert({comentario->getId(), comentario});
}

// Pre: existe el link
void Producto::borrarLinkComentario(int id) {
    this->comentarios.at(id) = NULL;
    this->comentarios.erase(id);
}

int Producto::getCodigo() { return this->codigo; }

int Producto::getStock() { return this->stock; }

float Producto::getPrecio() { return this->precio; }

std::string Producto::getNombre() { return this->nombre; }

std::string Producto::getDescripcion() { return this->descripcion; }

TipoProducto Producto::getTipo() { return this->tipo; }

Vendedor *Producto::getVendedor() { return this->vendedor; }

std::vector<CompraProducto *> Producto::getCompras() { return this->compras; }

DTProducto Producto::getDTProducto() {
    DTProducto dtProd = DTProducto(this->codigo, this->stock, this->precio,
                                   this->nombre, this->descripcion, this->tipo,
                                   this->vendedor->getNickname());
    return dtProd;
}

void Producto::nuevaCompraProducto(int cantidad, Compra *compra) {
    CompraProducto *compraProducto =
        new CompraProducto(cantidad, false, compra, this);
    this->compras.push_back(compraProducto);
    compra->agregarCompraProducto(compraProducto);
}

bool Producto::tienePromocionVigente() { return this->promovigente != NULL; }

DTProductoLinea Producto::getDTProductoLinea() {
    return DTProductoLinea(this->codigo, this->nombre);
}

void Producto::asociarPromocion(PromocionProducto *pmpd) {
    this->promovigente = pmpd;
}

void Producto::asociarCompra(CompraProducto *cppd) {
    this->compras.push_back(cppd);
}

void Producto::actualizarVigenciaPromocion(DTFecha fecha) {
    if (this->promovigente == NULL)
        return;
    if (not(this->promovigente->getPromocion()->getFin() <= fecha)) {
        this->promosnovigentes.push_back(this->promovigente);
        this->promovigente = NULL;
    }
}
