#ifndef ICONTROLADORPRODUCTO
#define ICONTROLADORPRODUCTO

#include "../datatypes/DTCompra.h"
#include "../datatypes/DTProducto.h"
#include "../producto.h"
#include "../usuario.h"
#include <string>
#include <vector>

class IConProducto {
  private:
  public:
    virtual Producto *cargarLote(int id, std::string algo, std::string algo2,
                                 int cantidad, float monto, TipoProducto tipo,
                                 Usuario *usuario) = 0;
    virtual std::vector<std::string> obtenerNicksVendedores() = 0;
    virtual void agregarProducto(std::string nickname, std::string nombre,
                                 float precio, int stock,
                                 std::string descripcion,
                                 TipoProducto Tipo) = 0;
    virtual std::vector<DTProducto> listarProducto() = 0;
    virtual DTProducto obtenerDatosProducto(int codigo) = 0;
    virtual std::vector<DTProducto>
    listarProdEnvioPend(std::string nickname) = 0;
    virtual std::vector<DTCompra> listarComprasEnvioPend(int codigo) = 0;
    virtual void selEnviado(std::string nickCliente, int anio, int mes,
                            int dia) = 0;
    virtual ~IConProducto() {};
};

#endif
