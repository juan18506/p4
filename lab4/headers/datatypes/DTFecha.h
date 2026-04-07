#ifndef DTFECHA
#define DTFECHA

#include <string>

class DTFecha {
  private:
    int dia;
    int mes;
    int anio;

  public:
    DTFecha();
    DTFecha(int a, int b, int c);
    int getDia();
    int getMes();
    int getAnio();
    std::string imprimirFecha();
    bool LaFechaEsPosteriorA(DTFecha desde); // esta se iria no?
    bool operator<=(DTFecha fecha);
    DTFecha operator=(const DTFecha &fecha);
};

#endif
