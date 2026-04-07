#ifndef PAGINAWEB
#define PAGINAWEB

#include "informacion.h"

class PaginaWeb : public Informacion {
  private:
    std::string titulo;
    std::string link;
    std::string text;

  public:
    PaginaWeb(int identificador, DTFecha fecha, std::string titulo,
              std::string link, std::string text);
    std::string toString();
};

#endif
