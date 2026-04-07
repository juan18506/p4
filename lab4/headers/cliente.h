#ifndef CLIENTE
#define CLIENTE

#include "compra.h"
#include "datatypes/DTCliente.h"
#include "datatypes/DTCompra.h"
#include "datatypes/DTFecha.h"
#include "datatypes/DTInfoCliente.h"
#include "datatypes/DTInfoExpediente.h"
#include "datatypes/DTUsuario.h"
#include "interfaces/IObserver.h"
#include "usuario.h"
#include <string>
#include <vector>

class Cliente : public Usuario, public IObserver {
  private:
    std::string calle;
    int puerta;
    std::string ciudad;
    std::vector<DTNotificacion> notificaciones;
    std::vector<Compra *> compras;

  public:
    Cliente(std::string nickname, std::string contrasena, int dia, int mes,
            int anio, std::string calle, int puerta, std::string ciudad);
    std::vector<DTNotificacion> imprimiryborrar();
    void notificar(DTNotificacion notificacion);
    std::string getNickname();
    DTInfoExpediente expediente();
    DTCliente getDTCliente();
    // DTUsuario getDTUsuario();
    std::string getCalle();
    int getPuerta();
    std::string getCiudad();
    std::vector<Compra *> getCompras();
    std::vector<DTCompra> getDTCompras();
    void nuevaCompraCliente(Compra *compra);
    std::vector<Compra *> getComprasCl();
    void setcalle(std::string c);
    void setpuerta(int p);
    void setciudad(std::string c);
};

#endif
