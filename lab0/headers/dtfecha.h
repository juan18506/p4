#ifndef DTFECHA
#define DTFECHA

#include <string>

class DTFecha {
  private:
    int dia, mes, anio;

  public:
    DTFecha(int dia, int mes, int anio);
    std::string fechaConFormato();
    bool operator>=(DTFecha fecha);
};

#endif
