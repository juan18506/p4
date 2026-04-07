#include "../../headers/manejadores/ManejadorProducto.h"

ManejadorProducto *ManejadorProducto::instance = NULL;

ManejadorProducto::ManejadorProducto() {
    this->productos = std::map<int, Producto *>();
}

ManejadorProducto *ManejadorProducto::getInstance() {
    if (instance == NULL)
        instance = new ManejadorProducto();
    return instance;
}

Producto *ManejadorProducto::buscarProducto(int codigo) {
    return this->productos.at(codigo);
}

std::map<int, Producto *> ManejadorProducto::obtenerProductos() {
    std::map<int, Producto *> productos;
    productos.insert(this->productos.begin(), this->productos.end());
    return productos;
}

void ManejadorProducto::agregarProductoCol(Producto *producto) {
    this->productos.insert({producto->getCodigo(), producto});
}
