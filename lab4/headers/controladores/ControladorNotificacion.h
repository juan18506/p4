#ifndef CONTROLADORNOTIFICACIONES
#define CONTROLADORNOTIFICACIONES

#include "../datatypes/DTNotificacion.h"
#include "../datatypes/DTVendedor.h"
#include "../interfaces/IContNotificacion.h"
#include <vector>

class ControladorNotificacion : public IConNotificacion {
  private:
    std::string nickname;
    std::vector<std::string> nickvendedores;

  public:
    std::vector<DTVendedor> ListarVendedoresNoSuscriptos(std::string nickname);
    void agregarSuscripcion(std::string nickvendedor);
    void liberarUsuario();
    std::vector<DTNotificacion>
    listarYEliminarNotificaciones(std::string nickname);
    std::vector<DTVendedor> listarSuscripciones(std::string nickname);
    void seleccionarVendedores(std::string nickvendedor);
    void eliminarSuscripcion();
};

#endif