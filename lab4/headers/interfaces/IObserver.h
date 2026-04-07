#ifndef IOBSERVER
#define IOBSERVER
#include "../datatypes/DTNotificacion.h"

class IObserver {
  public:
    virtual void notificar(DTNotificacion notificacion) = 0;
    virtual std::string getNickname() = 0;
    virtual ~IObserver() {};
};

#endif