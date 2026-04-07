#include "headers/chatGPT.h"
#include "headers/estudiante.h"
#include "headers/libro.h"
#include "headers/paginaWeb.h"
#include "headers/utils.h"
#include <iostream>

int main() {
    /************ INICIO PARTE A ************/
    PaginaWeb *informacion1 = new PaginaWeb(
        1, DTFecha(7, 3, 2024), "Programación 4 Guía Semana 1 (4/3)",
        "https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/"
        "Guia01_P42024_IntroCBasicos.pdf",
        "El objetivo de esta semana es contextualizar el paradigma de "
        "Orientación a Objetos (OO) en el marco de la Ingeniería de Software, "
        "así como comenzar a ver sus conceptos básicos y cómo éstos se "
        "implementan en C++.");

    PaginaWeb *informacion2 = new PaginaWeb(
        2, DTFecha(5, 3, 2024), "Programación orientada a objetos",
        "https://es.wikipedia.org/wiki/Programaci%C3%B3n_orientada_a_objetos",
        "La programación orientada a objetos (POO, en español) es un paradigma "
        "de programación que parte del concepto de \"objetos\" como base, los "
        "cuales contienen información en forma de campos (a veces también "
        "referidos como atributos o propiedades) y código en forma de métodos. "
        "Algunas características clave de la programación orientada a objetos "
        "son herencia, cohesión, abstracción, polimorfismo, acoplamiento y "
        "encapsulamiento.");
    /************ FINAL PARTE A ************/

    /************ INICIO PARTE B ************/
    ChatGPT *informacion3 = new ChatGPT(
        3, DTFecha(8, 3, 2024),
        "¿Qué es el polimorfismo en orientación a objetos?",
        "El polimorfismo en programación orientada a objetos se refiere a la "
        "capacidad de un objeto de tomar múltiples formas. Puede ser estático, "
        "resuelto en tiempo de compilación, basado en la herencia, o dinámico, "
        "resuelto en tiempo de ejecución, asociado a interfaces o métodos "
        "abstractos. En esencia, permite que objetos de diferentes clases "
        "respondan a la misma interfaz de manera coherente, facilitando la "
        "flexibilidad y extensibilidad del código.");

    ChatGPT *informacion4 = new ChatGPT(
        4, DTFecha(5, 3, 2024),
        "¿Qué es el acoplamiento en orientación a objetos?",
        "El acoplamiento en programación orientada a objetos se refiere al "
        "grado de dependencia entre las clases o módulos de un sistema. Un "
        "bajo acoplamiento es deseable, ya que implica que las clases son "
        "independientes entre sí, lo que facilita la modificación, "
        "mantenimiento y reutilización del código. Por otro lado, un alto "
        "acoplamiento indica una fuerte interdependencia entre las clases, lo "
        "que puede hacer que el sistema sea más difícil de entender, modificar "
        "y mantener.");
    /************ FINAL PARTE B ************/

    /************ INICIO PARTE C ************/
    Libro *informacion5 = new Libro(
        5, DTFecha(15, 3, 2024),
        "Applying UML and Patterns: An Introduction to Object-Oriented "
        "Analysis and Design and Iterative Development",
        std::set<std::string>({"Craig Larman"}),
        "Applying UML and Patterns is the world’s #1 business and college "
        "introduction to “thinking in objects”―and using that insight in "
        "real-world object- oriented analysis and design. Building on two "
        "widely acclaimed previous editions, Craig Larman has updated this "
        "book to fully reflect the new UML 2 standard, to help you master the "
        "art of object design, and to promote high-impact, iterative, and "
        "skillful agile modeling practices.");
    /************ FINAL PARTE C ************/

    /************ INICIO PARTE D ************/
    std::vector<Informacion *> informacionesGlobal(
        {informacion1, informacion2, informacion3, informacion4, informacion5});

    std::cout << "\n";
    for (Informacion *informacion : informacionesGlobal)
        std::cout << informacion->toString() << "\n\n";
    /************ FINAL PARTE D ************/

    /************ INICIO PARTE E ************/
    Estudiante *estudianteAlex =
        new Estudiante("Alex García", 52365899, "ag5678@gmail.com");

    Estudiante *estuadianteBetina =
        new Estudiante("Betina Gonzalez", 49891239, "beg999@gmail.com");

    std::vector<Estudiante *> estudiantesGlobal(
        {estudianteAlex, estuadianteBetina});
    /************ FINAL PARTE E ************/

    /************ INICIO PARTE F ************/
    estudianteAlex->agregarInformacion(informacion1);
    informacion1->agregarEstudiante(estudianteAlex);

    estudianteAlex->agregarInformacion(informacion2);
    informacion2->agregarEstudiante(estudianteAlex);

    estudianteAlex->agregarInformacion(informacion3);
    informacion3->agregarEstudiante(estudianteAlex);

    estuadianteBetina->agregarInformacion(informacion3);
    informacion3->agregarEstudiante(estuadianteBetina);

    estuadianteBetina->agregarInformacion(informacion4);
    informacion4->agregarEstudiante(estuadianteBetina);

    estuadianteBetina->agregarInformacion(informacion5);
    informacion5->agregarEstudiante(estuadianteBetina);
    /************ FINAL PARTE F ************/

    /************ INICIO PARTE G ************/
    DTFecha desde = DTFecha(8, 3, 2024);
    std::set<std::string> listadoAlex = estudianteAlex->listarInfo(desde);
    std::set<std::string> listadoBetina = estuadianteBetina->listarInfo(desde);

    std::cout << "Listado de Alex\n\n";
    for (std::string str : listadoAlex)
        std::cout << str << "\n\n";

    std::cout << "Listado de Betina\n\n";
    for (std::string str : listadoBetina)
        std::cout << str << "\n\n";
    /************ FINAL PARTE G ************/

    /************ INICIO PARTE H ************/
    std::cout << "Estudiantes con el termino Polimorfismo\n\n";
    for (DTInfoEstudiante infoEst : listadoPolimorfismo(informacionesGlobal))
        std::cout << infoEst << "\n\n";
    /************ FINAL PARTE H ************/

    /************ INICIO PARTE I ************/
    borrarLinksConInformacion(estudiantesGlobal, informacion3);
    borrarInformacionGlobal(informacionesGlobal, informacion3);
    delete informacion3;
    informacion3 = NULL;
    std::cout << "Estado de los estudiantes luego de borrar informacion 3\n\n";
    for (Estudiante *estudiante : estudiantesGlobal)
        std::cout << estudiante->toString() << "\n\n";

    std::cout << "Estudiantes con el termino Polimorfismo luego de borrar el "
                 "identificador 3\n\n";
    for (DTInfoEstudiante infoEst : listadoPolimorfismo(informacionesGlobal))
        std::cout << infoEst << "\n\n";
    /************ FINAL PARTE I ************/

    borrarLinksConInformacion(estudiantesGlobal, informacion1);
    borrarInformacionGlobal(informacionesGlobal, informacion1);
    delete informacion1;
    informacion1 = NULL;
    borrarLinksConInformacion(estudiantesGlobal, informacion2);
    borrarInformacionGlobal(informacionesGlobal, informacion2);
    delete informacion2;
    informacion2 = NULL;
    borrarLinksConInformacion(estudiantesGlobal, informacion4);
    borrarInformacionGlobal(informacionesGlobal, informacion4);
    delete informacion4;
    informacion4 = NULL;
    borrarLinksConInformacion(estudiantesGlobal, informacion5);
    borrarInformacionGlobal(informacionesGlobal, informacion5);
    delete informacion5;
    informacion5 = NULL;
    borrarLinksConEstudiante(informacionesGlobal, estudianteAlex);
    borrarEstudianteGlobal(estudiantesGlobal, estudianteAlex);
    delete estudianteAlex;
    estudianteAlex = NULL;
    borrarLinksConEstudiante(informacionesGlobal, estuadianteBetina);
    borrarEstudianteGlobal(estudiantesGlobal, estuadianteBetina);
    delete estuadianteBetina;
    estuadianteBetina = NULL;

    return 0;
}
