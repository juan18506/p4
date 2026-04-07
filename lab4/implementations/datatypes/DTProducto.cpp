#include "../../headers/datatypes/DTProducto.h"

DTProducto::DTProducto(const DTProducto &dp) {
    codigo = dp.codigo;
    nombre = dp.nombre;
    precio = dp.precio;
    stock = dp.stock;
    descripcion = dp.descripcion;
    tipo = dp.tipo;
    nickvendedor = dp.nickvendedor;
}

DTProducto::DTProducto(int codigo, int stock, float precio, std::string nombre,
                       std::string descripcion, TipoProducto tipo,
                       std::string nicknameVend)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre),
      descripcion(descripcion), tipo(tipo), nickvendedor(nicknameVend) {}
int DTProducto::getCodigo() { return this->codigo; }
int DTProducto::getStock() { return this->stock; }
float DTProducto::getPrecio() { return this->precio; }
std::string DTProducto::getNombre() { return this->nombre; }
std::string DTProducto::getDescripcion() { return this->descripcion; }
TipoProducto DTProducto::getTipo() { return this->tipo; }
std::string DTProducto::getNicknameVend() { return this->nickvendedor; }

std::string DTProducto::imprimir() {
    std::string a = std::to_string(this->codigo);
    std::string b = std::to_string(this->stock);
    std::string c = std::to_string(this->tipo);
    std::string d = std::to_string(this->precio);
    return "  " + nombre + " " + descripcion + " " + a + " " + b + " " + c +
           " " + d + "\n";
};
std::string DTProducto::toString_cod_nom() {
    return "Cód: " + std::to_string(this->codigo) + ", Nom: " + this->nombre;
}

std::string DTProducto::toString_StDescCatVen() {
    std::string cat;
    if (this->tipo == 0)
        cat = "Ropa";
    else if (this->tipo == 1)
        cat = "Electrodoméstico";
    else if (this->tipo == 2)
        cat = "Otro";

    return "Stock: " + std::to_string(this->stock) +
           "\nDescripción: " + this->descripcion + "\nCategoría: " + cat +
           "\nVendedor: " + this->nickvendedor + "\n";
}
