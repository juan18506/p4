#include "../headers/utils.h"

std::vector<DTInfoEstudiante>
listadoPolimorfismo(std::vector<Informacion *> informaciones) {
    std::vector<DTInfoEstudiante> listado;

    for (Informacion *informacion : informaciones) {
        if (informacion->toString().find("polimorfismo") != std::string::npos)
            for (Estudiante *estudiante : informacion->getEstudiantes())
                listado.push_back(DTInfoEstudiante(
                    estudiante->getCI(), estudiante->getNombre(),
                    informacion->getIdentificador()));
    }

    return listado;
}

void borrarLinksConInformacion(std::vector<Estudiante *> &estudiantes,
                               Informacion *informacion) {
    for (Estudiante *estudiante : estudiantes)
        if (estudiante->tieneInformacion(informacion))
            estudiante->eliminarInformacion(informacion);
}

void borrarLinksConEstudiante(std::vector<Informacion *> &informaciones,
                              Estudiante *estudiante) {
    for (Informacion *informacion : informaciones)
        if (informacion->tieneEstudiante(estudiante))
            informacion->eliminarEstudiante(estudiante);
}

void borrarInformacionGlobal(std::vector<Informacion *> &informaciones,
                             Informacion *informacion) {
    int i = 0;
    while (i < informaciones.size() && informaciones.at(i) != informacion)
        i++;

    if (i < informaciones.size())
        informaciones.erase(informaciones.begin() + i);
}

void borrarEstudianteGlobal(std::vector<Estudiante *> &estudiantes,
                            Estudiante *estudiante) {
    int i = 0;
    while (i < estudiantes.size() && estudiantes.at(i) != estudiante)
        i++;

    if (i < estudiantes.size())
        estudiantes.erase(estudiantes.begin() + i);
}
