#ifndef COMENTARIO
#define COMENTARIO

#include "datatypes/DTComentario.h"
#include "datatypes/DTFecha.h"
#include <map>
#include <string>
#include <vector>

class Producto;
class Usuario;

class Comentario {
  private:
    int id;
    std::string texto;
    DTFecha fecha = DTFecha(0, 0, 0);
    Usuario *autor;
    Producto *producto;
    Comentario *padre;
    std::map<int, Comentario *> respuestas;

  public:
    DTComentario crearDTComentario();
    void
    eliminarDescendientesDirectos(std::vector<Comentario *> *descendientes);
    void borrarLinkComentario(int id);
    void borrarLinkAutor();
    void borrarLinkProducto();
    void borrarLinkPadre();
    int getId();
    Comentario(Usuario *autor, Producto *producto, DTFecha fecha,
               std::string texto, Comentario *padre);
    Comentario(std::string texto, int codigoProducto, std::string nicknameAutor,
               Comentario *padre);
    ~Comentario();
};

#include "producto.h"
#include "usuario.h"

#endif
