#ifndef DTCOMPRA
#define DTCOMPRA

#include "DTFecha.h"
#include "DTProdSeleccion.h"
#include <string>
#include <vector>

class DTCompra {
  private:
    std::string nickCliente;
    float monto;
    DTFecha fecha = DTFecha(0, 0, 0);
    std::vector<DTProdSeleccion> prodCompra;

  public:
    DTCompra();
    // DTCompra(const DTCompra& com);
    DTCompra(std::string nickCliente, float monto, DTFecha fecha,
             std::vector<DTProdSeleccion> prodCompra);
    std::string getNickCliente();
    DTFecha getFecha();
    float getMonto();
    std::string imprimir();
    std::vector<DTProdSeleccion> getProdCompra();
    std::string toString_ClFe_();
};

#endif
