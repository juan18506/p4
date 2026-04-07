#ifndef INFORMACION
#define INFORMACION

#include "dtfecha.h"
#include <vector>

class Estudiante;

class Informacion {
  private:
    int identificador;
    DTFecha fecha;
    std::vector<Estudiante *> estudiantes;

  public:
    Informacion(int identificador, DTFecha fecha);
    virtual std::string toString() = 0;
    void agregarEstudiante(Estudiante *estudiante);
    void eliminarEstudiante(Estudiante *estudiante);
    bool tieneEstudiante(Estudiante *estudiante);
    int getIdentificador();
    DTFecha getFecha();
    std::vector<Estudiante *> getEstudiantes();
    virtual ~Informacion() = 0;
};

#include "estudiante.h"

#endif
