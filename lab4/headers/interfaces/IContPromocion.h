#ifndef ICONTPROMOCION
#define ICONTPROMOCION
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTProductoLinea.h"
#include "../datatypes/DTProductoXPromocionProducto.h"
#include "../datatypes/DTPromocion.h"
#include "../datatypes/DTVendedor.h"
#include "../promocion.h"
#include <string>
#include <vector>

class IConPromocion {
  private:
  public:
    virtual Promocion *cargarLote(std::string nombre, std::string descripcion,
                                  int descuento, DTFecha fin) = 0;
    virtual PromocionProducto *asociarLote(Promocion *pm, Producto *pd,
                                           int minimo) = 0;
    virtual void iniciarCrearPromocion(std::string nombre,
                                       std::string descripcion, float descuento,
                                       DTFecha fin) = 0;
    virtual std::vector<std::string> obtenerNicksVendedores() = 0;
    virtual std::vector<DTProductoLinea>
    obtenerProductosSinPromoVigenteVendedor(std::string nickname) = 0;
    virtual void seleccionarProductoPromocion(int codigo, int minimo) = 0;
    virtual void terminarCrearPromocion() = 0;
    virtual std::vector<DTPromocion> obtenerPromocionesVigentes() = 0;
    virtual std::vector<DTProducto>
    obtenerDatosPromocion(std::string nombre) = 0;
    virtual std::vector<DTProductoXPromocionProducto>
    obtenerProductosPromocion(std::string nombre) = 0;
    virtual DTVendedor obtenerVendedorPromocion(std::string nombre) = 0;
    virtual ~IConPromocion() {}
};

#endif
