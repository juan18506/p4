#ifndef VENDEDOR
#define VENDEDOR

#include "producto.h"
#include "usuario.h"
#include <map>
#include <vector>
// #include "datatypes/DTFecha"
// #include "datatypes/DTUsuario.h"
#include "datatypes/DTInfoVendedor.h"
#include "datatypes/DTNotificacion.h"
#include "datatypes/DTProducto.h"
#include "datatypes/DTPromocion.h"
#include "datatypes/DTVendedor.h"
#include "interfaces/IObserver.h"

class Cliente;
class Promocion;

class Vendedor : public Usuario {
  private:
    std::string rut;
    std::vector<IObserver *> suscriptores;
    void notificarObserve(DTNotificacion notificacion);
    std::map<int, Producto *> productos;
    std::map<std::string, Promocion *> promociones;

  public:
    // std::string getNickname();
    std::map<int, Producto *> getProductos();
    void agregarProducto(Producto *producto);
    void asociarPromocion(Promocion *promocion);
    Vendedor(std::string nickname, std::string contrasena, int dia, int mes,
             int anio, std::string rut);
    void agregarSuscriptor(IObserver *cliente);
    void borrarSuscripcion(std::string nickCliente);
    bool estaSuscripto(std::string nickCliente);
    DTVendedor getDTVendedor();
    bool estaPromo(std::string nombre);
    // DTUsuario getDTUsuario();
    std::string getRut();
    DTInfoExpediente expediente();
    void setRut(std::string r);
};

#include "cliente.h"
#include "promocion.h"

#endif
