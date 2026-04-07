#ifndef CHATGPT
#define CHATGPT

#include "informacion.h"

class ChatGPT : public Informacion {
  private:
    std::string pregunta;
    std::string respuesta;

  public:
    ChatGPT(int identificador, DTFecha fecha, std::string pregunta,
            std::string respuesta);
    std::string toString();
};

#endif
