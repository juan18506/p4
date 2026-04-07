#ifndef CONTROLADORPROMOCION_H
#define CONTROLADORPROMOCION_H

/*#include <string>
#include <vector>

#include "../datatypes/DTFecha.h"
#include "../datatypes/DTProductoLinea.h"
#include "../datatypes/DTPromocion.h"*/
#include "../datatypes/DTProductoXPromocionProducto.h"
#include "../datatypes/DTPromocion.h"
#include "../datatypes/DTVendedor.h"
#include "../interfaces/IContPromocion.h"
#include "../promocion.h"
#include "../promocionProducto.h"

class ControladorPromocion : public IConPromocion {
  private:
    std::string promoNombre;
    std::string promoDescripcion;
    float promoDescuento;
    DTFecha promoFin = DTFecha(0, 0, 0);
    std::string vendedorNick;
    std::vector<int> productosCodigo;
    std::vector<int> productosMinimo;

  public:
    void iniciarCrearPromocion(std::string nombre, std::string descripcion,
                               float descuento, DTFecha fin);
    std::vector<std::string> obtenerNicksVendedores();
    std::vector<DTProductoLinea>
    obtenerProductosSinPromoVigenteVendedor(std::string nickname);
    void seleccionarProductoPromocion(int codigo, int minimo);
    void terminarCrearPromocion();
    std::vector<DTPromocion> obtenerPromocionesVigentes();
    std::vector<DTProducto> obtenerDatosPromocion(std::string nombre);
    std::vector<DTProductoXPromocionProducto>
    obtenerProductosPromocion(std::string nombre);
    DTVendedor obtenerVendedorPromocion(std::string nombre);
    Promocion *cargarLote(std::string nombre, std::string descripcion,
                          int descuento, DTFecha fin);
    PromocionProducto *asociarLote(Promocion *pm, Producto *pd, int minimo);
};

#endif
