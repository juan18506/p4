#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "../usuario.h"
#include <map>

class ManejadorUsuario {
  private:
    // clave: nickname
    static ManejadorUsuario *instance;
    std::map<std::string, Usuario *> usuarios;
    ManejadorUsuario();

  public:
    static ManejadorUsuario *getInstance();
    void agregarUsuario(Usuario *usuario);
    bool esta(std::string nickname);
    Usuario *buscarUsuario(std::string nickname);
    std::map<std::string, Usuario *> obtenerUsuarios();
};

#endif
