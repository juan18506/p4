#ifndef DTINFOESTUDIANTE
#define DTINFOESTUDIANTE

#include <ostream>
#include <string>

class DTInfoEstudiante {
  private:
    int ci;
    std::string nombreEst;
    int identificadorInfo;

  public:
    DTInfoEstudiante(int ci, std::string nombreEst, int identificadorInfo);
    int getCI();
    std::string getNombreEst();
    int getIdentificadorInfo();
};

std::ostream &operator<<(std::ostream &output, DTInfoEstudiante &est);

#endif
