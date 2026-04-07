#ifndef CONTROLADORCOMENTARIO
#define CONTROLADORCOMENTARIO

#include "../comentario.h"
#include "../datatypes/DTComentario.h"
#include "../interfaces/IContComentario.h"
#include <string>
#include <vector>

class ControladorComentario : public IConComentario {
  private:
    static int siguienteIdentificador;
    std::string nickname;
    int codigoProducto;
    int id = -1;

  public:
    Comentario *cargarLote(Usuario *autor, Producto *producto, DTFecha fecha,
                           std::string texto, Comentario *padre);
    std::vector<std::string> listarNicknamesUsuarios();
    void seleccionarUsuario(std::string nickname);
    void seleccionarProducto(int codigo);
    void seleccionarComentario(int id);
    void crearComentario(std::string texto);
    std::vector<DTComentario> listarComentariosProducto(std::string nickname);
    std::vector<DTComentario> listarComentariosUsuario(std::string nickname);
    void eliminarComentarioYDescendientes(int id);
    std::vector<Comentario *> *crearSetAuxiliar(Comentario *c);
    static int getSiguienteIdentificador();
    static void incrementarIdentificador();
};

#endif
