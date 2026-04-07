#ifndef ICONTROLADORCOMPRA
#define ICONTROLADORCOMPRA

#include "../cliente.h"
#include "../datatypes/DTCompra.h"
#include "../datatypes/DTProducto.h"
#include "../promocion.h"
#include <string>
#include <vector>

class IConCompra {
  public:
    virtual Compra *cargarLote(Usuario *usuario, DTFecha fecha, float monto,
                               Promocion *promocion) = 0;
    virtual CompraProducto *asociarLote(Compra *compra, Producto *producto,
                                        int cantidad, bool entregados) = 0;
    virtual std::vector<std::string> obtenerNicknamesClientes() = 0;
    virtual void seleccionarCliente(std::string nickname) = 0;
    virtual std::vector<DTProducto> obtenerProductos() = 0;
    virtual void agregarProductoCompra(int codigo, int cant) = 0;
    virtual DTCompra obtenerCompra() = 0;
    virtual void confirmarCompra() = 0;
    virtual ~IConCompra() {};
    virtual bool existeProductoEnCompra(int cod) = 0;
    virtual bool cantValidaDeProducto(int cant, int cod) = 0;
    virtual std::map<int, Producto *>
    buscarProductos(std::vector<DTProdSeleccion> prodCarrito) = 0;
};

#endif
