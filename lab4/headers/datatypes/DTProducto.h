#ifndef DTPRODUCTO
#define DTPRODUCTO

#include "TipoProducto.h"
#include <string>
#include <vector>

class DTProducto {
  private:
    int codigo;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    TipoProducto tipo;
    std::string nickvendedor;

  public:
    DTProducto(const DTProducto &dp);
    DTProducto(int codigo, int stock, float precio, std::string nombre,
               std::string descripcion, TipoProducto tipo,
               std::string nicknameVend);
    int getCodigo();
    int getStock();
    float getPrecio();
    std::string imprimir();
    std::string getNombre();
    std::string getDescripcion();
    TipoProducto getTipo();
    std::string getNicknameVend();
    std::string toString_cod_nom();
    std::string toString_StDescCatVen();
};

#endif
