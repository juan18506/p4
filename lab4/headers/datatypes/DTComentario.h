#ifndef DTCOMENTARIO
#define DTCOMENTARIO

#include "DTFecha.h"
#include <string>

class DTComentario {
  private:
    int id;
    std::string texto;
    DTFecha fecha = DTFecha(0, 0, 0);

  public:
    DTComentario(int id, std::string texto, DTFecha fecha);
    std::string getTexto();
    DTFecha getFecha();
    int getId();
    std::string toString();
};

#endif
