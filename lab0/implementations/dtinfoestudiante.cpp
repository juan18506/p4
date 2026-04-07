#include "../headers/dtinfoestudiante.h"

DTInfoEstudiante::DTInfoEstudiante(int ci, std::string nombreEst,
                                   int identificadorInfo)
    : ci(ci), nombreEst(nombreEst), identificadorInfo(identificadorInfo) {}

std::ostream &operator<<(std::ostream &output, DTInfoEstudiante &est) {
    output << std::to_string(est.getCI()) << ", " << est.getNombreEst() << ", "
           << std::to_string(est.getIdentificadorInfo());
    return output;
}

int DTInfoEstudiante::getCI() { return this->ci; }

std::string DTInfoEstudiante::getNombreEst() { return this->nombreEst; }

int DTInfoEstudiante::getIdentificadorInfo() { return this->identificadorInfo; }
