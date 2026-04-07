#ifndef PRODUCTO
#define PRODUCTO

#include "compraProducto.h"
#include <map>
#include <string>
#include <vector>
// #include "promocionProducto.h"
#include "controladores/ControladorProducto.h"
#include "datatypes/DTComentario.h"
#include "datatypes/DTProductoLinea.h"
#include "datatypes/TipoProducto.h"

class Comentario;
class Vendedor;
class CompraProducto;
class PromocionProducto;

class Producto {
  private:
    int codigo;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    TipoProducto tipo;
    Vendedor *vendedor;
    std::map<int, Comentario *> comentarios;
    std::vector<CompraProducto *> compras;
    std::vector<PromocionProducto *> promosnovigentes;
    PromocionProducto *promovigente;

  public:
    Producto(int stock, float precio, std::string nombre,
             std::string descripcion, TipoProducto tipo,
             std::string nicknameVend);
    void agregarCompra(CompraProducto *compra);
    // void agregarPromocion(PromocionProducto *promocion);
    Comentario *buscarComentario(int id);
    std::vector<DTComentario> obtenerComentarios();
    void agregarComentario(Comentario *comentario);
    void borrarLinkComentario(int id);
    int getCodigo();
    int getStock();
    float getPrecio();
    void setStock(int stock);
    std::string getNombre();
    std::string getDescripcion();
    TipoProducto getTipo();
    Vendedor *getVendedor();
    std::vector<CompraProducto *> getCompras();
    DTProducto getDTProducto();
    DTProductoLinea getDTProductoLinea();
    void nuevaCompraProducto(int cantidad, Compra *compra);
    void actualizarVigenciaPromocion(DTFecha fecha);
    bool tienePromocionVigente();
    void asociarPromocion(PromocionProducto *pmpd);
    void asociarCompra(CompraProducto *cppd);
};

#include "comentario.h"
#include "compraProducto.h"
#include "promocionProducto.h"
#include "vendedor.h"

#endif
