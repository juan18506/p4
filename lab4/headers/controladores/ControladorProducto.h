#ifndef CONTROLADORPRODUCTO
#define CONTROLADORPRODUCTO

#include "../../headers/producto.h"
#include "../../headers/vendedor.h"
#include "../datatypes/DTCompra.h"
#include "../datatypes/DTProducto.h"
#include "../interfaces/IContProducto.h"
#include "../manejadores/ManejadorCliente.h"
#include "../manejadores/ManejadorProducto.h"
#include "../manejadores/ManejadorVendedor.h"
#include "../producto.h"
#include <string>
#include <vector>

class ControladorProducto : public IConProducto {
  private:
    static int Prox_codigo;
    int codigoProdEnv;

  public:
    std::vector<std::string> obtenerNicksVendedores();
    static void incrementarCodigo();
    static int getProxCodigo();
    void agregarProducto(std::string nickname, std::string nombre, float precio,
                         int stock, std::string descripcion, TipoProducto Tipo);
    std::vector<DTProducto> listarProducto();
    DTProducto obtenerDatosProducto(int codigo);
    std::vector<DTProducto> listarProdEnvioPend(std::string nickname);
    std::vector<DTCompra> listarComprasEnvioPend(int codigo);
    void selEnviado(std::string nickCliente, int anio, int mes, int dia);
    Producto *cargarLote(int codigo, std::string nombre,
                         std::string descripcion, int stock, float precio,
                         TipoProducto tipo, Usuario *usuario);
};

#endif
