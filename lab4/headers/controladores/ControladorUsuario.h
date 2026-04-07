#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "../interfaces/IContUsuario.h"

class ControladorUsuario : public IConUsuario {
  private:
  public:
    bool AltaCliente(std::string nickname, std::string contrasena, int dia,
                     int mes, int anio, std::string calle, int puerta,
                     std::string ciudad);
    bool AltaVendedor(std::string nickname, std::string contrasena, int dia,
                      int mes, int anio, std::string rut);
    DTInfoExpediente getExpediente(std::string nick);
    std::vector<std::string> listarNicknamesUsuarios();
    // std::vector<DTCliente> listarUsuarios();
    Usuario *cargarLote(bool a, std::string b, std::string c, DTFecha f);
    void asociarVendedorLote(Usuario *v, std::string r);
    void asociarClienteLote(Usuario *cl, std::string a, int b, std::string c);
    std::vector<DTCliente> listarClientes();
    std::vector<DTVendedor> listarVendedores();
    //~IConUsuario(){};
};

#endif