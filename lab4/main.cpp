#include "headers/datatypes/DTCliente.h"
#include "headers/datatypes/DTComentario.h"
#include "headers/datatypes/DTFecha.h"
#include "headers/datatypes/DTNotificacion.h"
#include "headers/datatypes/DTProducto.h"
#include "headers/datatypes/DTProductoXPromocionProducto.h"
#include "headers/datatypes/DTPromocion.h"
#include "headers/datatypes/DTPromocionProducto.h"
#include "headers/datatypes/DTVendedor.h"
#include "headers/datatypes/TipoProducto.h"
#include "headers/fabrica.h"
#include "headers/interfaces/IContComentario.h"
#include "headers/interfaces/IContCompra.h"
#include "headers/interfaces/IContProducto.h"
#include "headers/interfaces/IContPromocion.h"
#include "headers/interfaces/IContSistema.h"
#include "headers/interfaces/IContUsuario.h"
#include <cstdio>
#include <iostream>
#include <string>

bool validarFecha(int dia, int mes, int anio);
void ejecutarCargarLote();
void ejecutarAltaUsuario(Fabrica *f);
void ejecutarDejarComentario(Fabrica *fabrica);
void ejecutarEliminarComentario(Fabrica *fabrica);
void ejecutarListarUsuarios(Fabrica *f);
void ejecutarEliminarSuscripcion(Fabrica *f);
void ejecutarSuscribirse(Fabrica *f);
void ejecutarExpediente(Fabrica *f);
void ejecutarConsultarNotificacion(Fabrica *f);

void ejecutarCrearPromocion(Fabrica *fabrica);
void ejecutarConsultarPromocion(Fabrica *fabrica);
void ejecutarAltaProducto(Fabrica *fabrica);
void ejecutarConsultarProducto(Fabrica *fabrica);
void ejecutarEnviarProducto(Fabrica *fabrica);
void ejecutarRealizarCompra(Fabrica *fabrica);

int main(void) {
    // Inicializa la fecha del sistema
    bool fechaValida = false;
    int dia, mes, anio;
    while (!fechaValida) {
        std::cout << "Ingrese la fecha actual de la forma dia mes año"
                  << std::endl;
        std::cin >> dia >> mes >> anio;
        if (validarFecha(dia, mes, anio))
            fechaValida = true;
        else
            std::cout << "Fecha invalida. Intente nuevamente" << std::endl;
    }
    DTFecha fecha = DTFecha(dia, mes, anio);
    Fabrica *f = Fabrica::getInstance();
    IConSistema *s = f->getIContSistema();
    s->agregarFecha(fecha);

    bool cargarLote;
    std::cout << "1 para cargar lote, 0 para no cargarlo: ";
    std::cin >> cargarLote;
    if (cargarLote)
        ejecutarCargarLote();

    int salida = 0;
    while (salida != 15) {
        std::cout << "Seleccione el caso de uso\n";
        std::cout << "  1-Alta De Usuario\n";
        std::cout << "  2-Listado De Usuarios\n";
        std::cout << "  3-Alta De Producto\n";
        std::cout << "  4-Consultar Producto\n";
        std::cout << "  5-Crear Promocion\n";
        std::cout << "  6-Consultar Promocion\n";
        std::cout << "  7-Realizar Compra\n";
        std::cout << "  8-Dejar Comentario\n";
        std::cout << "  9-Eliminar Comentario\n";
        std::cout << "  10-Enviar Producto\n";
        std::cout << "  11-Expediente De Usuario\n";
        std::cout << "  12-Suscribirse A Notificaciones\n";
        std::cout << "  13-Consulta De Notificaciones\n";
        std::cout << "  14-Eliminar Suscripcion\n";
        std::cout << "  15-Salir\n";
        std::cin >> salida;
        std::cin.ignore();

        switch (salida) {
        case 1: {
            // Alta De Usuario
            ejecutarAltaUsuario(f);
            break;
        }
        case 2: {
            // Listado De Usuarios
            ejecutarListarUsuarios(f);
            break;
        }
        case 3: {
            // Alta De Producto
            ejecutarAltaProducto(f);
            break;
        }
        case 4: {
            ejecutarConsultarProducto(f);
            break;
        }
        case 5: {
            // Crear Promocion
            ejecutarCrearPromocion(f);
            break;
        }
        case 6: {
            // Consultar Promocion
            ejecutarConsultarPromocion(f);
            break;
        }
        case 7:
            // Realizar Compra
            ejecutarRealizarCompra(f);
            break;
        case 8:
            ejecutarDejarComentario(f);
            break;
        case 9:
            ejecutarEliminarComentario(f);
            break;
        case 10: {
            ejecutarEnviarProducto(f);
            break;
        }
        case 11: {
            // Expediente De Usuario
            ejecutarExpediente(f);
            break;
        }
        case 12: {
            // Suscribirse A Notificaciones
            ejecutarSuscribirse(f);
            break;
        }
        case 13: {
            // Consulta De Notificaciones
            ejecutarConsultarNotificacion(f);
            break;
        }
        case 14: {
            // Eliminar Suscripcion
            ejecutarEliminarSuscripcion(f);
            break;
        }
        default:
            break;
        }
    }
    s->limpiarTodo();
    return 0;
}

void ejecutarSuscribirse(Fabrica *f) {
    std::string nick;
    IConUsuario *u = f->getIContUsuario();
    std::vector<DTCliente> ususarios = u->listarClientes();
    for (DTCliente us : ususarios) {
        std::cout << "  " << us.imprimir();
    }
    std::cout << "Ingrese el nickname de un Cliente\n";
    std::cin >> nick;
    IConNotificacion *n = f->getIContNotificacion();
    std::vector<DTVendedor> ven = n->ListarVendedoresNoSuscriptos(nick);
    for (auto v : ven) {
        std::cout << v.imprimir() << "\n";
    }
    int aux = 0;
    while (aux != 1) {
        std::cout << "Ingrese el nickname de un Vendedor\n";
        std::string vendedor;
        std::cin >> vendedor;
        n->agregarSuscripcion(vendedor);
        std::cout << "Si desea ingresar otro vendedor ingrese 0\n";
        std::cout << "si desea salir ingrese 1\n";
        std::cin >> aux;
    }
    n->liberarUsuario();
    delete u;
    delete n;
}

void ejecutarEliminarSuscripcion(Fabrica *f) {
    std::string nick;
    IConUsuario *u = f->getIContUsuario();
    std::vector<DTCliente> ususarios = u->listarClientes();
    for (DTCliente us : ususarios) {
        std::cout << "  " << us.imprimir();
    }
    std::cout << "Ingrese el nickname de un Cliente\n";
    std::cin >> nick;
    IConNotificacion *n = f->getIContNotificacion();
    std::vector<DTVendedor> ven = n->listarSuscripciones(nick);
    if (!ven.empty()) {
        for (auto v : ven) {
            std::cout << v.imprimir() << "\n";
        }
        int aux = 0;
        std::string nickven;
        while (aux != 1) {
            std::cout << "Ingrese el nickname de un Vendedor" << "\n";
            std::cin >> nickven;
            n->seleccionarVendedores(nickven);
            std::cout << "si desea agregar otro Vendedor ingrese 0\n";
            std::cout << "si desea salir ingrese 1" << "\n";
            std::cin >> aux;
        }
        n->eliminarSuscripcion();
    } else {
        std::cout << "El cliente no esta sucripto a nadie\n";
    }
    delete u;
    delete n;
}

void ejecutarAltaUsuario(Fabrica *f) {
    std::cout << "Ingrese 1 si quiere ingresar un Vendedor\n";
    std::cout << "Ingrese 2 si quiere ingresar un Cliente\n";
    int aux;
    std::cin >> aux;
    switch (aux) {
    case 1: {
        IConUsuario *u = f->getIContUsuario();
        std::string nick, contrasenia, rut;
        int dia, mes, anio;
        int aux = 0;
        while (aux != 1) {
            std::cout << "Ingrese el nickname,contraseña,nacimiento y rut del "
                         "vendedor que desea crear\n";
            std::cout
                << "ingreselo de la forma nick contraseña dia mes año rut\n";
            std::cin >> nick >> contrasenia >> dia >> mes >> anio >> rut;
            bool esta = u->AltaVendedor(nick, contrasenia, dia, mes, anio, rut);
            if (esta) {
                std::cout << "El vendedor ya fue previamente ingresado\n";
                std::cout << "Intentar de nuevo 0\n";
                std::cout << "Salir 1\n";
                std::cin >> aux;
            } else {
                std::cout << "El vendedor fue agregado\n";
                aux = 1;
            }
        }
        delete u;
        break;
    }
    case 2: {
        IConUsuario *u = f->getIContUsuario();
        std::string nick, contrasenia, calle, ciudad;
        int dia, mes, anio, puerta;
        int aux2 = 0;
        while (aux2 != 1) {
            std::cout
                << "Ingrese el nickname,contraseña,nacimiento,calle,puerta y "
                   "ciudad del cliente que desea crear\n";
            std::cout << "ingreselo de la forma nick contraseña dia mes año "
                         "calle puerta ciudad\n";
            std::cin >> nick >> contrasenia >> dia >> mes >> anio >> calle >>
                puerta >> ciudad;
            bool esta = u->AltaCliente(nick, contrasenia, dia, mes, anio, calle,
                                       puerta, ciudad);
            if (esta) {
                std::cout << "El cliente ya fue previamente ingresado\n";
                std::cout << "Intentar de nuevo 0\n";
                std::cout << "Salir 1\n";
                std::cin >> aux2;
            } else {
                std::cout << "El cliente fue agregado";
                aux2 = 1;
            }
        }
        delete u;
        break;
    }
    default:
        std::cout << "numero incorrecto intente de nuevo\n";
    }
}

std::string
listarYSeleccionarNicknameUsuario(std::vector<std::string> nicknames) {
    std::cout << "\nUsuarios en el sistema: \n";
    for (auto &&nickname : nicknames)
        std::cout << nickname << "\n";
    std::cout << "\n";

    std::string nickname;
    bool nicknameValido = true;
    do {
        if (nicknameValido)
            std::cout
                << "Indique el nickname del usuario que desea seleccionar: ";
        else
            std::cout << "El nickname que selecciono no es valido, seleccione "
                         "un nickname valido: ";
        std::cin >> nickname;

        int i = 0;
        while (i < (int)nicknames.size() && nicknames.at(i) != nickname)
            i++;

        nicknameValido = (i != (int)nicknames.size());
    } while (!nicknameValido);

    return nickname;
}

int listarYSeleccionarComentario(std::vector<DTComentario> comentarios) {
    std::cout << "\nComentarios en el producto seleccionado: \n";
    for (auto &&comentario : comentarios)
        std::cout << comentario.toString() << "\n";
    std::cout << "\n";

    int id;
    bool idValido = true;
    do {
        if (idValido)
            std::cout << "Ingrese el id del comentario que desea seleccionar: ";
        else
            std::cout << "El id que selecciono no es valido, seleccione un id "
                         "valido: ";

        std::cin >> id;
        int i = 0;
        while (i < (int)comentarios.size() && comentarios.at(i).getId() != id)
            i++;
        idValido = (i != (int)comentarios.size());
    } while (!idValido);

    return id;
}

void ejecutarCargarLote() {
    Fabrica *fabrica = Fabrica::getInstance();
    IConProducto *controladorProducto = fabrica->getIContProducto();
    IConComentario *controladorComentario = fabrica->getIContComentario();
    IConPromocion *controladorPromocion = fabrica->getIContPromocion();
    IConCompra *controladorCompra = fabrica->getIContCompra();
    IConUsuario *controladorUsuario = fabrica->getIContUsuario();

    const TipoProducto R = TipoProducto::Ropa;
    const TipoProducto E = TipoProducto::Electrodomesticos;
    const TipoProducto O = TipoProducto::Otro;
#include "cargarLote.h"

    delete controladorProducto;
    delete controladorCompra;
    delete controladorComentario;
    delete controladorPromocion;
    delete controladorUsuario;
}

void ejecutarDejarComentario(Fabrica *fabrica) {
    IConComentario *interfazComentario = fabrica->getIContComentario();
    IConProducto *interfazProducto = fabrica->getIContProducto();

    // Selecciona el usuario
    std::vector<std::string> nicknames =
        interfazComentario->listarNicknamesUsuarios();
    std::string nickname = listarYSeleccionarNicknameUsuario(nicknames);
    interfazComentario->seleccionarUsuario(nickname);

    // Selecciona el producto
    std::vector<DTProducto> productos = interfazProducto->listarProducto();
    std::cout << "\nProductos en el sistema: \n";
    for (auto &&producto : productos)
        std::cout << producto.toString_cod_nom() << "\n";
    std::cout << "\n";

    int codigo;
    bool codigoValido = true;
    do {
        if (codigoValido)
            std::cout
                << "Indique el codigo del producto que desea seleccionar: ";
        else
            std::cout << "El codigo que selecciono no es valido, seleccione un "
                         "codigo valido: ";

        std::cin >> codigo;
        int i = 0;
        while (i < (int)productos.size() &&
               productos.at(i).getCodigo() != codigo)
            i++;

        codigoValido = (i != (int)productos.size());
    } while (!codigoValido);

    interfazComentario->seleccionarProducto(codigo);

    // Crear Comentario
    // 1: comentario nuevo
    // 2: comentario respuesta a otro

    int opcion;
    bool opcionValida = true;
    do {
        if (opcionValida)
            std::cout << "Indique 1 para crear un nuevo comentario o 2 para "
                         "crear una respuesta a otro comentario: ";
        else
            std::cout << "La opcion que selecciono no es valida, seleccione "
                         "una opcion valida: ";

        std::cin >> opcion;
        opcionValida = (opcion == 1 || opcion == 2);
    } while (!opcionValida);

    if (opcion == 2) {
        std::vector<DTComentario> comentarios =
            interfazComentario->listarComentariosProducto(nickname);
        if (!comentarios.empty()) {
            int id = listarYSeleccionarComentario(comentarios);
            interfazComentario->seleccionarComentario(id);
        } else {
            std::cout << "No hay comentarios para responder en este producto, "
                         "por lo que se va a crear un nuevo comentario\n";
        }
    }

    std::string texto;
    std::cout << "Ingrese el cuerpo(texto) del comentario: ";
    std::cin.ignore();
    std::getline(std::cin, texto);
    interfazComentario->crearComentario(texto);

    delete interfazComentario;
    delete interfazProducto;
}

void ejecutarEliminarComentario(Fabrica *fabrica) {
    IConComentario *interfazComentario = fabrica->getIContComentario();

    std::vector<std::string> nicknames =
        interfazComentario->listarNicknamesUsuarios();
    std::string nickname = listarYSeleccionarNicknameUsuario(nicknames);
    interfazComentario->seleccionarUsuario(nickname);

    std::vector<DTComentario> comentarios =
        interfazComentario->listarComentariosUsuario(nickname);
    if (!comentarios.empty()) {
        int id = listarYSeleccionarComentario(comentarios);
        interfazComentario->eliminarComentarioYDescendientes(id);
    } else {
        std::cout
            << "El usuario seleccionado no tiene comentarios para borrar.\n\n";
    }
    delete interfazComentario;
}

void ejecutarListarUsuarios(Fabrica *f) {
    IConUsuario *u = f->getIContUsuario();
    std::vector<DTCliente> ususarios = u->listarClientes();
    std::vector<DTVendedor> ven = u->listarVendedores();
    for (DTCliente us : ususarios) {
        std::cout << "  " << us.imprimir();
    }
    for (DTVendedor v : ven) {
        std::cout << "  " << v.imprimir();
    }
    delete u;
};

void ejecutarRealizarCompra(Fabrica *fabrica) {
    IConCompra *icompra = fabrica->getIContCompra();
    // listar nicknames de los clientes
    std::vector<std::string> nicksClientes =
        icompra->obtenerNicknamesClientes();
    for (std::string nickCliente : nicksClientes) {
        std::cout << nickCliente;
        std::cout << "\n";
    }

    // seleccionar cliente
    std::string nickCliente;
    bool clienteEncontrado = false;
    while (!clienteEncontrado) {
        std::cout << "Seleccione cliente: ";
        std::cin >> nickCliente;
        for (auto &&nick : nicksClientes) {
            if (nick == nickCliente) {
                clienteEncontrado = true;
            }
        }
        if (!clienteEncontrado) {
            std::cout
                << "El nickname del cliente no existe. Intente nuevamente."
                << std::endl;
        }
    }

    icompra->seleccionarCliente(nickCliente);
    // imprimir datos de los productos
    std::vector<DTProducto> productos = icompra->obtenerProductos();
    std::cout << "Listado de productos:";
    std::cout << "\n";
    for (auto &&dtProd : productos) {
        std::cout << dtProd.toString_cod_nom();
        std::cout << "\n";
        std::cout << "Precio: ";
        std::cout << dtProd.getPrecio();
        std::cout << "\n";
        std::cout << dtProd.toString_StDescCatVen();
        std::cout << "\n";
    }

    // agregar producto a la compra
    int aux = 0;
    do {
        std::cout
            << "Seleccione producto a comprar en formato \"codigo cantidad\": ";
        int codigo, cant;
        std::cin >> codigo >> cant;
        bool productoEncontrado = false;
        for (auto &&producto : productos) {
            if (producto.getCodigo() == codigo) {
                productoEncontrado = true;
                break;
            }
        }
        if (!productoEncontrado) {
            std::cout << "El codigo de producto no existe. Intente nuevamente"
                      << std::endl;
        } else if (icompra->existeProductoEnCompra(codigo)) {
            std::cout << "No se puede agregar productos ya existentes en la "
                         "compra. Intente nuevamente"
                      << std::endl;
        } else if (!icompra->cantValidaDeProducto(cant, codigo)) {
            if (cant <= 0) {
                std::cout << "Debe agregar al menos una unidad del producto. "
                             "Intente nuevamente"
                          << std::endl;
            } else {
                std::cout << "No hay suficiente stock del producto para la "
                             "cantidad pedida. Intente nuevamente"
                          << std::endl;
            }
        } else {
            icompra->agregarProductoCompra(codigo, cant);
        }
        std::cout << "Si desea agregar otro producto a la compra ingrese 0, "
                     "sino ingrese 1: ";
        std::cin >> aux;
        std::cout << "\n";
    } while (aux != 1);

    // imprimir datos de la compra
    DTCompra compra = icompra->obtenerCompra();
    std::vector<DTProdSeleccion> productosCompra = compra.getProdCompra();
    std::cout << "Compra:" << std::endl;
    std::cout << "\t Cliente: " << compra.getNickCliente() << std::endl;
    std::cout << "\t Monto total: " << compra.getMonto()
              << "\n\t Fecha: " << compra.getFecha().imprimirFecha()
              << std::endl;
    std::cout << "\t Productos seleccionados: " << std::endl;
    for (auto &&prod : productosCompra) {
        std::cout << "\t" << prod.getDTProducto().toString_cod_nom()
                  << " Cantidad: " << prod.getCantidad();
        std::cout << "\n";
    }

    // confirmar la compra
    int confirmar = 0;
    std::cout << "Ingrese 1 para confirmar la compra" << std::endl;
    std::cin >> confirmar;
    if (confirmar == 1) {
        icompra->confirmarCompra();
    }

    delete icompra;
}

void ejecutarCrearPromocion(Fabrica *fabrica) {
    IConPromocion *ipromo = fabrica->getIContPromocion();
    std::string nombre, descripcion;
    int descuento;
    int anio;
    int mes;
    int dia;
    std::cout << "Ingrese nombre de la promocion: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese descripcion de la promocion: ";
    std::getline(std::cin, descripcion);
    bool descuentoValido = false;
    while (!descuentoValido) {
        std::cout << "Ingrese descuento de la promocion: ";
        std::cin >> descuento;
        if (descuento > 0 && descuento <= 100)
            descuentoValido = true;
        else
            std::cout << "Descuento invalido, debe estar en el rango (0,100]. "
                         "Intente nuevamente."
                      << std::endl;
    }
    bool fechaValida = false;
    while (!fechaValida) {
        std::cout << "Ingrese fin de promocion en formato \"dia mes anio\": ";
        std::cin >> dia >> mes >> anio;
        if (validarFecha(dia, mes, anio))
            fechaValida = true;
        else
            std::cout << "Fecha invalida. Intente nuevamente." << std::endl;
    }
    ipromo->iniciarCrearPromocion(nombre, descripcion, (float)descuento,
                                  DTFecha(dia, mes, anio));
    std::vector<std::string> nicksVendedores = ipromo->obtenerNicksVendedores();
    std::cout << "Vendedores:" << std::endl;
    for (auto &&nick : nicksVendedores) {
        std::cout << "\t" << nick << std::endl;
    }
    std::string nickVendedor;
    bool vendedorEncontrado = false;
    while (!vendedorEncontrado) {
        std::cout << "Seleccione vendedor: ";
        std::cin >> nickVendedor;
        for (auto &&nick : nicksVendedores)
            if (nick == nickVendedor) {
                vendedorEncontrado = true;
            }
        if (!vendedorEncontrado)
            std::cout
                << "El nickname de vendedor no existe. Intente nuevamente."
                << std::endl;
    }
    std::vector<DTProductoLinea> productosSinPromo =
        ipromo->obtenerProductosSinPromoVigenteVendedor(nickVendedor);
    std::cout << "Productos:" << std::endl;
    for (auto &&dtpl : productosSinPromo) {
        std::cout << "\t" << dtpl.getCodigo() << " " << dtpl.getNombre()
                  << std::endl;
    }
    int cantidadProductos = 0;
    while (true) {
        bool encontrado = false;
        int codigo = 0, minimo;
        std::cout << "Seleccione producto a ingresar en formato \"codigo "
                     "minimo\", o 0 0 para terminar: ";
        std::cin >> codigo >> minimo;
        if (codigo == 0 || minimo == 0) {
            if (cantidadProductos > 0)
                break;
            else {
                std::cout
                    << "Debe ingresar por lo menos un producto a la promocion."
                    << std::endl;
                continue;
            }
        }
        for (auto &&dtpl : productosSinPromo) {
            if (dtpl.getCodigo() == codigo) {
                encontrado = true;
                cantidadProductos++;
                ipromo->seleccionarProductoPromocion(codigo, minimo);
            }
        }
        if (!encontrado)
            std::cout << "El codigo de producto no existe para " << nickVendedor
                      << ". Intente nuevamente." << std::endl;
    }
    ipromo->terminarCrearPromocion();
    delete ipromo;
    std::cout << std::endl;
}

void ejecutarConsultarPromocion(Fabrica *fabrica) {
    IConPromocion *ipromo = fabrica->getIContPromocion();

    std::vector<DTPromocion> promosvigentes =
        ipromo->obtenerPromocionesVigentes();

    std::cout << "Promociones:" << std::endl;
    for (auto &&dtpm : promosvigentes) {
        std::cout << "\t" << dtpm.getNombre() << ": " << dtpm.getDescuento()
                  << "\% off hasta " << dtpm.getFin().imprimirFecha() << " - "
                  << dtpm.getDescripcion() << std::endl;
    }

    std::string nombrePromo;
    bool seleccionado = false;
    while (!seleccionado) {
        std::cout << "Consultar detalle (vacio para salir)? ";
        std::getline(std::cin, nombrePromo);

        if (nombrePromo == "")
            break;

        for (auto &&dtpm : promosvigentes) {
            if (dtpm.getNombre() == nombrePromo) {
                seleccionado = true;
                break;
            }
        }

        if (!seleccionado)
            std::cout << "El nombre de la promocion no es correcto. Intente "
                         "nuevamente."
                      << std::endl;
    }

    if (nombrePromo != "") {
        std::vector<DTProductoXPromocionProducto> prods =
            ipromo->obtenerProductosPromocion(nombrePromo);
        std::cout << "Productos:" << std::endl;
        for (auto &&dtpx : prods) {
            DTProducto prod = dtpx.getProducto();
            DTPromocionProducto pp = dtpx.getPromocionProducto();
            std::cout << "\t [min " << pp.getMinimo() << "] #"
                      << prod.getCodigo() << " " << prod.getNombre() << " $"
                      << prod.getPrecio() << " " << std::endl;
        }

        DTVendedor vendedor = ipromo->obtenerVendedorPromocion(nombrePromo);
        std::cout << "Vendedor: " << vendedor.getNickname() << " (RUT "
                  << vendedor.getRut() << ")" << std::endl;
    }
    delete ipromo;

    std::cout << std::endl;
}

bool validarFecha(int dia, int mes, int anio) {
    if (dia < 1 || dia > 31)
        return false;
    if (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia == 31)
            return false;
    }
    if (mes == 2 && dia > 28)
        return false;
    if (mes < 1 || mes > 12)
        return false;
    if (anio < 1)
        return false;
    return true;
}

void ejecutarExpediente(Fabrica *f) {
    IConUsuario *u = f->getIContUsuario();
    std::vector<std::string> usu = u->listarNicknamesUsuarios();
    for (auto u : usu) {
        std::cout << u << "\n";
    }
    std::cout << "Ingrese el nickname del usuario seleccionado\n";
    std::string aux2;
    std::cin >> aux2;
    DTInfoExpediente exp = u->getExpediente(aux2);
    std::cout << exp.imprimir();

    delete u;
}

void ejecutarConsultarNotificacion(Fabrica *f) {
    IConUsuario *u = f->getIContUsuario();
    std::vector<DTCliente> ususarios = u->listarClientes();
    for (DTCliente us : ususarios) {
        std::cout << "  " << us.imprimir();
    }
    std::cout << "Ingrese el nickname de un Cliente\n";
    IConNotificacion *n = f->getIContNotificacion();
    std::string nick;
    std::cin >> nick;
    std::vector<DTNotificacion> v = n->listarYEliminarNotificaciones(nick);
    for (auto dtn : v) {
        std::cout << dtn.imprimir() << "\n";
    }

    delete u;
    delete n;
}

void ejecutarAltaProducto(Fabrica *fabrica) {
    IConProducto *p = fabrica->getIContProducto();
    std::cout << "Listado de vendedores:";
    std::cout << "\n";
    std::vector<std::string> nicksVend = p->obtenerNicksVendedores();
    for (std::string nickVend : nicksVend) {
        std::cout << nickVend;
        std::cout << "\n";
    }
    std::string nickname, nombre, descripcion, TipoSt;
    float precio;
    int stock;
    // valida que el vend ingresado exista
    bool vendedorEncontrado = false;
    while (!vendedorEncontrado) {
        std::cout << "Seleccione vendedor: ";
        std::cin >> nickname;
        for (auto &&nick : nicksVend)
            if (nick == nickname) {
                vendedorEncontrado = true;
            }
        if (!vendedorEncontrado)
            std::cout
                << "El nickname de vendedor no existe. Intente nuevamente."
                << std::endl;
    }

    std::cout << "Ingrese los siguientes datos del producto:(nombre precio "
                 "stock Categoria). En categoria ingresar 'R', 'E', 'O' donde "
                 "R-Ropa, E-Electrodomésticos , O-Otro)";
    std::cout << "\n";
    std::cin >> nombre >> precio >> stock >> TipoSt;
    std::cout << "Ingrese la descripcion del producto: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);
    TipoProducto Tipo;
    if (TipoSt == "R") {
        Tipo = Ropa;
    } else if (TipoSt == "E") {
        Tipo = Electrodomesticos;
    } else if (TipoSt == "O") {
        Tipo = Otro;
    }
    std::cout << "\n";
    p->agregarProducto(nickname, nombre, precio, stock, descripcion, Tipo);
    delete p;
}

void ejecutarConsultarProducto(Fabrica *fabrica) {
    IConProducto *p = fabrica->getIContProducto();
    std::cout << "Listado de productos:";
    std::cout << "\n";
    std::vector<DTProducto> dtps = p->listarProducto();
    for (DTProducto dtp : dtps) {
        std::cout << dtp.toString_cod_nom();
        std::cout << "\n";
    }
    std::cout << "Ingrese el código del producto para ver sus datos:";
    std::cout << "\n";
    int codigo;
    std::cin >> codigo;
    std::cout << "\n";
    DTProducto dtp = p->obtenerDatosProducto(codigo);
    std::cout << dtp.toString_cod_nom();
    std::cout << "\n";
    std::cout << "Precio: ";
    std::cout << dtp.getPrecio();
    std::cout << "\n";
    std::cout << dtp.toString_StDescCatVen();
    std::cout << "\n";
    delete p;
}

void ejecutarEnviarProducto(Fabrica *fabrica) {
    IConProducto *p = fabrica->getIContProducto();
    std::vector<std::string> nicksVend = p->obtenerNicksVendedores();
    for (std::string nickVend : nicksVend) {
        std::cout << nickVend;
        std::cout << "\n";
    }
    // valida que el vend ingresado exista
    std::string nickname;
    bool vendedorEncontrado = false;
    while (!vendedorEncontrado) {
        std::cout << "Seleccione vendedor: ";
        std::cin >> nickname;
        for (auto &&nick : nicksVend)
            if (nick == nickname) {
                vendedorEncontrado = true;
            }
        if (!vendedorEncontrado)
            std::cout
                << "El nickname de vendedor no existe. Intente nuevamente."
                << std::endl;
    }

    std::vector<DTProducto> dtps = p->listarProdEnvioPend(nickname);
    if (!dtps.empty()) {
        std::cout << "El vendedor seleccionado tiene los siguientes productos "
                     "con al menos una compra con envío pendiente:";
        std::cout << "\n";
        for (DTProducto dtp : dtps) {
            std::cout << dtp.toString_cod_nom();
            std::cout << "\n";
        }
        std::cout << "Ingrese el código del producto que desea consultar:";
        std::cout << "\n";
        int codigo;
        std::cin >> codigo;
        std::vector<DTCompra> dtcs = p->listarComprasEnvioPend(codigo);
        for (DTCompra dtc : dtcs) {
            std::cout << dtc.toString_ClFe_();
            std::cout << "\n";
        }
        int dia, mes, anio;
        std::string nickCliente;
        std::cout << "Ingrese nickname del cliente y fecha de la compra "
                     "(nickname d m a):";
        std::cout << "\n";
        std::cin >> nickCliente >> dia >> mes >> anio;
        p->selEnviado(nickCliente, anio, mes, dia);
    } else {
        std::cout << "El vendedor no tiene compras pendientes de envío";
        std::cout << "\n";
    }
    delete p;
}
