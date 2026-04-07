#ifndef LIBRO
#define LIBRO

#include "informacion.h"

class Libro : public Informacion {
  private:
    std::string titulo;
    std::set<std::string> autores;
    std::string resumen;

  public:
    Libro(int identificador, DTFecha fecha, std::string titulo,
          std::set<std::string> autores, std::string resumen);
    std::string toString();
};

#endif
