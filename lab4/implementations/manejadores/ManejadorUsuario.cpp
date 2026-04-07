#include "../../headers/manejadores/ManejadorUsuario.h"

ManejadorUsuario *ManejadorUsuario::instance = NULL;

ManejadorUsuario::ManejadorUsuario() {
    this->usuarios = std::map<std::string, Usuario *>();
}

ManejadorUsuario *ManejadorUsuario::getInstance() {
    if (ManejadorUsuario::instance == NULL)
        ManejadorUsuario::instance = new ManejadorUsuario();
    return ManejadorUsuario::instance;
}

void ManejadorUsuario::agregarUsuario(Usuario *usuario) {
    this->usuarios.insert({usuario->getNickname(), usuario});
}

bool ManejadorUsuario::esta(std::string nickname) {
    return usuarios.find(nickname) != usuarios.end();
};

Usuario *ManejadorUsuario::buscarUsuario(std::string nickname) {
    return this->usuarios.at(nickname);
}

std::map<std::string, Usuario *> ManejadorUsuario::obtenerUsuarios() {
    std::map<std::string, Usuario *> usuarios;
    usuarios.insert(this->usuarios.begin(), this->usuarios.end());
    return usuarios;
}
