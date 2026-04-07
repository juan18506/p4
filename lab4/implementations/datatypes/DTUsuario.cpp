#include "../../headers/datatypes/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, DTFecha nacimiento)
    : nacimiento(DTFecha(nacimiento)) {
    this->nickname = nickname;
}

DTUsuario::DTUsuario() : nacimiento(DTFecha(0, 0, 0)) {}

DTUsuario::DTUsuario(const DTUsuario &usuario)
    : nacimiento(DTFecha(usuario.nacimiento)) {
    nickname = usuario.nickname;
};

std::string DTUsuario::getNickname() { return nickname; }

DTFecha DTUsuario::getNacimiento() { return nacimiento; }
