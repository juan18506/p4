#ifndef CONTROLADORCOMPRA
#define CONTROLADORCOMPRA

#include "../compra.h"
#include "../interfaces/IContCompra.h"
#include <string>
#include <vector>
/*#include "../datatypes/DTCompra.h"
#include "../datatypes/DTProducto.h"*/

class ControladorCompra : public IConCompra {
  private:
    std::string nickname;
    DTCompra dtCompra;
    std::vector<DTProdSeleccion> prodCarrito;

  public:
    std::vector<std::string> obtenerNicknamesClientes();
    void seleccionarCliente(std::string nickname);
    std::vector<DTProducto> obtenerProductos();
    void agregarProductoCompra(int codigo, int cant);
    bool existeProductoEnCompra(int cod);
    bool cantValidaDeProducto(int cant, int cod);
    DTCompra obtenerCompra();
    void confirmarCompra();
    std::map<int, Producto *>
    buscarProductos(std::vector<DTProdSeleccion> prodCarrito);
    Compra *cargarLote(Usuario *usuario, DTFecha fecha, float monto,
                       Promocion *promocion);
    CompraProducto *asociarLote(Compra *compra, Producto *producto,
                                int cantidad, bool entregados);
};

#endif
