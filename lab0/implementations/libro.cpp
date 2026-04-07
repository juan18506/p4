#include "../headers/libro.h"

Libro::Libro(int identificador, DTFecha fecha, std::string titulo,
             std::set<std::string> autores, std::string resumen)
    : Informacion(identificador, fecha), titulo(titulo), autores(autores),
      resumen(resumen) {}

std::string Libro::toString() {
    std::string id = std::to_string(this->getIdentificador());
    std::string fecha = this->getFecha().fechaConFormato();
    std::string libroStr = id + ", " + fecha + ", " + this->titulo + ",";

    for (std::string autor : this->autores)
        libroStr += " " + autor;

    libroStr += ", " + this->resumen;
    return libroStr;
}
