#ifndef ICONTROLADORNOTIFICACION
#define ICONTROLADORNOTIFICACION

#include "../datatypes/DTNotificacion.h"
#include "../datatypes/DTVendedor.h"
#include <vector>

class IConNotificacion {
  public:
    virtual std::vector<DTVendedor>
    ListarVendedoresNoSuscriptos(std::string nickname) = 0;
    virtual void agregarSuscripcion(std::string nickvendedor) = 0;
    virtual void liberarUsuario() = 0;
    virtual std::vector<DTNotificacion>
    listarYEliminarNotificaciones(std::string nickname) = 0;
    virtual std::vector<DTVendedor>
    listarSuscripciones(std::string nickname) = 0;
    virtual void seleccionarVendedores(std::string nickvendedor) = 0;
    virtual void eliminarSuscripcion() = 0;
    virtual ~IConNotificacion() {};
};

#endif