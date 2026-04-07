#include "../headers/paginaWeb.h"

PaginaWeb::PaginaWeb(int identificador, DTFecha fecha, std::string titulo,
                     std::string link, std::string text)
    : Informacion(identificador, fecha), titulo(titulo), link(link),
      text(text) {}

std::string PaginaWeb::toString() {
    std::string id = std::to_string(this->getIdentificador());
    std::string fecha = this->getFecha().fechaConFormato();
    return id + ", " + fecha + ", " + this->titulo + ", " + this->link + ", " +
           this->text;
}
