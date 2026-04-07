#ifndef DTCLIENTE
#define DTCLIENTE

#include "DTFecha.h"
#include <string>
// #include "DTUsuario.h"

class DTCliente /*: public DTUsuario*/ {
  private:
    std::string nickname;
    DTFecha nacimiento;
    std::string calle;
    int puerta;
    std::string ciudad;

  public:
    DTCliente();
    DTCliente(std::string nick, DTFecha nacimiento, std::string calle,
              int puerta, std::string ciudad);
    DTCliente(const DTCliente &cliente);
    std::string getCalle();
    int getPuerta();
    std::string getNickname();
    DTFecha getNacimiento();
    std::string getCiudad();
    std::string imprimir();
};

#endif
