#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "DTFecha.h"
#include <string>
// #include "DTUsuario.h"

class DTVendedor /*: public DTUsuario*/ {
  private:
    std::string nickname;
    DTFecha nacimiento;
    std::string rut;

  public:
    DTVendedor();
    DTVendedor(std::string nickname, DTFecha nacimiento, std::string rut);
    DTVendedor(const DTVendedor &vendedor);
    std::string getRut();
    std::string getNickname();
    std::string imprimir();
};

#endif
