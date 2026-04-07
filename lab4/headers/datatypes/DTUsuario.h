#ifndef DTUSUARIO
#define DTUSUARIO

#include "DTFecha.h"
#include <string>

class DTUsuario {
  private:
    std::string nickname;
    DTFecha nacimiento;

  public:
    DTUsuario();
    DTUsuario(std::string nickname, DTFecha nacimiento);
    DTUsuario(const DTUsuario &usuario);
    std::string getNickname();
    DTFecha getNacimiento();
    virtual std::string imprimir() = 0;
};

#endif