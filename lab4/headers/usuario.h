#ifndef USUARIO
#define USUARIO

#include "datatypes/DTComentario.h"
#include "datatypes/DTFecha.h"
#include "datatypes/DTInfoExpediente.h"
#include "datatypes/DTUsuario.h"
#include <map>
#include <string>
#include <vector>

class Comentario;

class Usuario {
  private:
    std::string nickname;
    std::string contrasenia;
    DTFecha nacimiento;
    std::map<int, Comentario *> comentarios;

  public:
    Usuario(std::string nickname, std::string contrasena, int dia, int mes,
            int anio);
    virtual DTInfoExpediente expediente() = 0;
    std::vector<DTComentario> obtenerComentarios();
    void agregarComentario(Comentario *comentario);
    Comentario *buscarComentario(int id);
    // virtual DTUsuario getDTUsuario()=0;
    void borrarLinkComentario(int id);
    std::string getNickname();
    DTFecha getNacimiento();
};

#include "comentario.h"

#endif
