#include "../headers/chatGPT.h"

ChatGPT::ChatGPT(int identificador, DTFecha fecha, std::string pregunta,
                 std::string respuesta)
    : Informacion(identificador, fecha), pregunta(pregunta),
      respuesta(respuesta) {}

std::string ChatGPT::toString() {
    std::string id = std::to_string(this->getIdentificador());
    std::string fecha = this->getFecha().fechaConFormato();
    return id + ", " + fecha + ", " + this->pregunta + ", " + this->respuesta;
}
