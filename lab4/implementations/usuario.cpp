#include "../headers/usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, int dia, int mes,
                 int anio)
    : nacimiento(DTFecha(dia, mes, anio)) {
    this->nickname = nickname;
    this->contrasenia = contrasena;
};
void Usuario::agregarComentario(Comentario *comentario) {
    this->comentarios.insert({comentario->getId(), comentario});
}

std::vector<DTComentario> Usuario::obtenerComentarios() {
    std::vector<DTComentario> dtComentarios;
    for (auto &&comentario : this->comentarios) {
        dtComentarios.push_back(comentario.second->crearDTComentario());
    }
    return dtComentarios;
}

Comentario *Usuario::buscarComentario(int id) {
    return this->comentarios.at(id);
}

// Pre: existe el link
void Usuario::borrarLinkComentario(int id) {
    this->comentarios.at(id) = NULL;
    this->comentarios.erase(id);
}

std::string Usuario::getNickname() { return this->nickname; }

DTFecha Usuario::getNacimiento() { return this->nacimiento; }
