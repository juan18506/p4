#ifndef UTILS
#define UTILS

#include "estudiante.h"
#include "informacion.h"

std::vector<DTInfoEstudiante>
listadoPolimorfismo(std::vector<Informacion *> informaciones);

void borrarLinksConInformacion(std::vector<Estudiante *> &estudiantes,
                               Informacion *informacion);
void borrarLinksConEstudiante(std::vector<Informacion *> &informaciones,
                              Estudiante *estudiante);

void borrarInformacionGlobal(std::vector<Informacion *> &informaciones,
                             Informacion *informacion);
void borrarEstudianteGlobal(std::vector<Estudiante *> &estudiantes,
                            Estudiante *estudiante);

#endif
