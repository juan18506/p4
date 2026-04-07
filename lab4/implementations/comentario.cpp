#include "../headers/comentario.h"
#include "../headers/controladores/ControladorComentario.h"
#include "../headers/controladores/ControladorSistema.h"
#include "../headers/manejadores/ManejadorProducto.h"
#include "../headers/manejadores/ManejadorUsuario.h"

DTComentario Comentario::crearDTComentario() {
    return DTComentario(this->id, this->texto, this->fecha);
}

void Comentario::borrarLinkPadre() {
    if (this->padre != NULL)
        this->padre->borrarLinkComentario(this->id);
}

void Comentario::borrarLinkAutor() {
    this->autor->borrarLinkComentario(this->id);
}

void Comentario::borrarLinkProducto() {
    this->producto->borrarLinkComentario(this->id);
}

void Comentario::borrarLinkComentario(int id) { this->respuestas.erase(id); }

void Comentario::eliminarDescendientesDirectos(
    std::vector<Comentario *> *descendientes) {
    descendientes->erase(descendientes->begin() + 0);

    for (auto &&respuesta : this->respuestas) {
        descendientes->push_back(respuesta.second);
    }

    this->respuestas.erase(respuestas.begin(), respuestas.end());
}

int Comentario::getId() { return this->id; }

Comentario::Comentario(Usuario *autor, Producto *producto, DTFecha fecha,
                       std::string texto, Comentario *padre) {
    ControladorComentario::incrementarIdentificador();
    this->id = ControladorComentario::getSiguienteIdentificador();
    this->autor = autor;
    this->producto = producto;
    this->fecha = fecha;
    this->texto = texto;
    this->respuestas = std::map<int, Comentario *>();
    this->padre = padre;
    if (this->padre != NULL)
        this->padre->respuestas.insert({this->id, this});

    producto->agregarComentario(this);
    autor->agregarComentario(this);
}

Comentario::Comentario(std::string texto, int codigoProducto,
                       std::string nicknameAutor, Comentario *padre) {
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    ManejadorProducto *manejadorProducto = ManejadorProducto::getInstance();
    ControladorSistema *controladorSistema = ControladorSistema::getInstance();

    ControladorComentario::incrementarIdentificador();
    this->id = ControladorComentario::getSiguienteIdentificador();
    this->fecha = controladorSistema->getFecha();
    this->texto = texto;
    this->autor = manejadorUsuario->buscarUsuario(nicknameAutor);
    this->producto = manejadorProducto->buscarProducto(codigoProducto);
    this->respuestas = std::map<int, Comentario *>();
    this->padre = padre;

    if (this->padre != NULL)
        this->padre->respuestas.insert({this->id, this});

    this->autor->agregarComentario(this);
    this->producto->agregarComentario(this);
}

Comentario::~Comentario() {
    this->autor = NULL;
    this->producto = NULL;
    this->padre = NULL;
    this->respuestas.erase(this->respuestas.begin(), this->respuestas.end());
}
