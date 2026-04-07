#ifndef CONTROLADORSISTEMA
#define CONTROLADORSISTEMA

#include "../interfaces/IContSistema.h"

class ControladorSistema : public IConSistema {
  private:
    static ControladorSistema *instance;
    DTFecha fecha = DTFecha(0, 0, 0);
    ControladorSistema();

  public:
    static ControladorSistema *getInstance();
    void agregarFecha(DTFecha fecha);
    DTFecha getFecha();
    void limpiarTodo();
};

#endif
