#include "../../headers/controladores/ControladorComentario.h"
#include "../../headers/manejadores/ManejadorProducto.h"
#include "../../headers/manejadores/ManejadorUsuario.h"
#include "../../headers/usuario.h"

int ControladorComentario::siguienteIdentificador = 0;

void ControladorComentario::incrementarIdentificador() {
    ControladorComentario::siguienteIdentificador++;
}

int ControladorComentario::getSiguienteIdentificador() {
    return ControladorComentario::siguienteIdentificador;
}

Comentario *ControladorComentario::cargarLote(Usuario *autor,
                                              Producto *producto, DTFecha fecha,
                                              std::string texto,
                                              Comentario *padre) {
    Comentario *comentario =
        new Comentario(autor, producto, fecha, texto, padre);
    return comentario;
}

std::vector<std::string> ControladorComentario::listarNicknamesUsuarios() {
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    std::map<std::string, Usuario *> usuarios =
        manejadorUsuario->obtenerUsuarios();

    std::vector<std::string> nicknamesUsuarios;
    for (auto &&usuario : usuarios)
        nicknamesUsuarios.push_back(usuario.first);

    return nicknamesUsuarios;
}

void ControladorComentario::seleccionarUsuario(std::string nickname) {
    this->nickname = nickname;
}

void ControladorComentario::seleccionarProducto(int codigo) {
    this->codigoProducto = codigo;
}

void ControladorComentario::seleccionarComentario(int id) { this->id = id; }

void ControladorComentario::crearComentario(std::string texto) {
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();

    Comentario *padre = NULL;
    if (this->id != -1) {
        padre = manejadorProducto->buscarProducto(this->codigoProducto)
                    ->buscarComentario(this->id);
        this->id = -1;
    }

    new Comentario(texto, this->codigoProducto, this->nickname, padre);
}

std::vector<DTComentario>
ControladorComentario::listarComentariosUsuario(std::string nickname) {
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    Usuario *usuario = manejadorUsuario->buscarUsuario(nickname);
    return usuario->obtenerComentarios();
}

std::vector<DTComentario>
ControladorComentario::listarComentariosProducto(std::string nickname) {
    this->nickname = nickname;

    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    Producto *producto =
        manejadorProducto->buscarProducto(this->codigoProducto);
    return producto->obtenerComentarios();
}

void ControladorComentario::eliminarComentarioYDescendientes(int id) {
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    Usuario *usuario = manejadorUsuario->buscarUsuario(this->nickname);
    Comentario *comentario = usuario->buscarComentario(id);
    std::vector<Comentario *> *descendientes =
        this->crearSetAuxiliar(comentario);

    comentario->borrarLinkPadre();
    while (!descendientes->empty()) {
        comentario->eliminarDescendientesDirectos(descendientes);
        comentario->borrarLinkAutor();
        comentario->borrarLinkProducto();
        delete comentario;
        comentario = NULL;
        if (!descendientes->empty())
            comentario = descendientes->at(0);
    }

    delete descendientes;
    descendientes = NULL;
}

std::vector<Comentario *> *
ControladorComentario::crearSetAuxiliar(Comentario *c) {
    std::vector<Comentario *> *setAuxiliar = new std::vector<Comentario *>();
    setAuxiliar->push_back(c);
    return setAuxiliar;
}
