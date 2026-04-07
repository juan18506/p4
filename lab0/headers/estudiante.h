#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "dtfecha.h"
#include "dtinfoestudiante.h"
#include <set>
#include <vector>

class Informacion;

class Estudiante {
  private:
    std::string nombre;
    int ci;
    std::string email;
    std::vector<Informacion *> informaciones;

  public:
    Estudiante(std::string nombre, int ci, std::string email);
    std::set<std::string> listarInfo(DTFecha desde);
    std::string toString();
    void agregarInformacion(Informacion *informacion);
    void eliminarInformacion(Informacion *informacion);
    bool tieneInformacion(Informacion *informacion);
    int getCI();
    std::string getNombre();
};

#include "informacion.h"

#endif
