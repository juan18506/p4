#ifndef ICONTROLADORCOMENTARIO
#define ICONTROLADORCOMENTARIO

#include "../comentario.h"
#include "../datatypes/DTComentario.h"
#include <string>
#include <vector>

class IConComentario {
  private:
  public:
    virtual void crearComentario(std::string texto) = 0;
    virtual std::vector<std::string> listarNicknamesUsuarios() = 0;
    virtual std::vector<DTComentario>
    listarComentariosProducto(std::string nickname) = 0;
    virtual std::vector<DTComentario>
    listarComentariosUsuario(std::string nickname) = 0;
    virtual void eliminarComentarioYDescendientes(int id) = 0;
    virtual void seleccionarUsuario(std::string nickname) = 0;
    virtual void seleccionarProducto(int codigo) = 0;
    virtual void seleccionarComentario(int id) = 0;
    virtual Comentario *cargarLote(Usuario *autor, Producto *producto,
                                   DTFecha fecha, std::string texto,
                                   Comentario *padre) = 0;
    virtual ~IConComentario() {};
};

#endif
