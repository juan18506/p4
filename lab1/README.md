# Lab1

Para generar el diagrama de modelo a partir del código se utiliza PlantUML: https://plantuml.com
Está disponible en paquetería en linux.

Una vez instalado, se genera simplemente con:
```sh
plantuml modelo.puml
```

### Pendientes / dudas
- Cómo modelar los envios (el control a nivel de cada compra, cada tipo de producto o cada producto individual).
- Cómo modelar las promos en las compras (se compra una promo? o hay que chequear si los productos comprados cumplen los requisitos de una promo? Y si hay más de una promo admisible?).
- Explicitar nombres en relaciones / atributos.
- Cardinales entre asociaciones.
- Restricciones (lenguage natural).
