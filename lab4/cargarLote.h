Usuario *US1 = controladorUsuario->cargarLote(true, "ana23", "qwer1234",
                                              DTFecha(15, 5, 1988));
Usuario *US2 = controladorUsuario->cargarLote(true, "carlos78", "asdfghj",
                                              DTFecha(18, 6, 1986));
Usuario *US3 = controladorUsuario->cargarLote(true, "diegom", "zxcvbn",
                                              DTFecha(28, 7, 1993));
Usuario *US4 = controladorUsuario->cargarLote(false, "juan87", "1qaz2wsx",
                                              DTFecha(20, 10, 1992));
Usuario *US5 = controladorUsuario->cargarLote(false, "laura", "3edc4rfv",
                                              DTFecha(22, 9, 1979));
Usuario *US6 = controladorUsuario->cargarLote(true, "maria01", "5tgb6yhn",
                                              DTFecha(25, 3, 1985));
Usuario *US7 = controladorUsuario->cargarLote(false, "natalia", "poiuyt",
                                              DTFecha(14, 4, 1982));
Usuario *US8 = controladorUsuario->cargarLote(false, "pablo10", "lkjhgv",
                                              DTFecha(30, 11, 1995));
Usuario *US9 = controladorUsuario->cargarLote(false, "roberto", "mnbvcx",
                                              DTFecha(12, 8, 1990));
Usuario *US10 = controladorUsuario->cargarLote(true, "sofia25", "1234asdf",
                                               DTFecha(7, 12, 1983));
controladorUsuario->asociarClienteLote(US4, "Av. 18 de Julio", 456, "Melo");
controladorUsuario->asociarClienteLote(US5, "Rondeau", 1617, "Montevideo");
controladorUsuario->asociarClienteLote(US7, "Paysandú", 2021, "Salto");
controladorUsuario->asociarClienteLote(US8, "Av. Rivera", 1819, "Mercedes");
controladorUsuario->asociarClienteLote(US9, "Av. Brasil", 1011, "Montevideo");
controladorUsuario->asociarVendedorLote(US1, "212345678001");
controladorUsuario->asociarVendedorLote(US2, "356789012345");
controladorUsuario->asociarVendedorLote(US3, "190123456789");
controladorUsuario->asociarVendedorLote(US6, "321098765432");
controladorUsuario->asociarVendedorLote(US10, "445678901234");
Producto *PR1 = controladorProducto->cargarLote(
    1, "Camiseta Azul", "Camiseta de poliester, color azul", 50, 1400, R, US2);
Producto *PR2 = controladorProducto->cargarLote(
    2, "Televisor LED", "Televisor LED 55 pulgadas", 30, 40500, E, US1);
Producto *PR3 = controladorProducto->cargarLote(
    3, "Chaqueta de Cuero", "Chaqueta de cuero, color negro", 20, 699.99, R,
    US2);
Producto *PR4 = controladorProducto->cargarLote(
    4, "Microondas Digital", "Microondas digital, 30L", 15, 1199.99, E, US1);
Producto *PR5 = controladorProducto->cargarLote(
    5, "Luz LED", "Luz Bluetooth LED", 40, 599.99, O, US3);
Producto *PR6 = controladorProducto->cargarLote(
    6, "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", 25, 60, R, US2);
Producto *PR7 = controladorProducto->cargarLote(
    7, "Auriculares Bluetooth", "Auriculares bluethooth para celular", 35,
    199.99, O, US3);
Producto *PR8 = controladorProducto->cargarLote(
    8, "Refrigerador", "Refrigerador de doble puerta", 10, 15499, E, US1);
Producto *PR9 = controladorProducto->cargarLote(
    9, "Cafetera", "Cafetera de goteo programable", 50, 23000, E, US1);
Producto *PR10 = controladorProducto->cargarLote(
    10, "Zapatillas Deportivas", "Zapatillas para correr, talla 42", 20, 5500,
    R, US2);
Producto *PR11 = controladorProducto->cargarLote(
    11, "Mochila", "Mochila de viaje, 40L", 30, 9000, O, US2);
Producto *PR12 = controladorProducto->cargarLote(
    12, "Plancha de Ropa", "Plancha a vapor, 1500W", 25, 2534, E, US3);
Producto *PR13 = controladorProducto->cargarLote(
    13, "Gorra", "Gorra para deportes, color rojo", 50, 200, R, US10);
Producto *PR14 = controladorProducto->cargarLote(
    14, "Tablet", "Tablet Android de 10 pulgadas", 15, 15000, E, US3);
Producto *PR15 = controladorProducto->cargarLote(
    15, "Reloj de Pared", "Reloj de pared vintage", 20, 150.50, O, US10);
Promocion *PM1 = controladorPromocion->cargarLote(
    "Casa nueva", "Para que puedas ahorrar en la casa nueva", 30,
    DTFecha(25, 10, 2024));
Promocion *PM2 = controladorPromocion->cargarLote(
    "Fiesta", "Para que no te quedes sin ropa para las fiestas", 20,
    DTFecha(26, 10, 2024));
Promocion *PM3 = controladorPromocion->cargarLote(
    "Domotica", "Para modernizar tu casa", 10, DTFecha(26, 10, 2024));
Promocion *PM4 = controladorPromocion->cargarLote(
    "Liquidacion", "Hasta agotar stock", 10, DTFecha(26, 3, 2024));
PromocionProducto *PP1 = controladorPromocion->asociarLote(PM1, PR2, 1);
PromocionProducto *PP2 = controladorPromocion->asociarLote(PM1, PR4, 1);
PromocionProducto *PP3 = controladorPromocion->asociarLote(PM1, PR8, 1);
PromocionProducto *PP4 = controladorPromocion->asociarLote(PM2, PR3, 2);
PromocionProducto *PP5 = controladorPromocion->asociarLote(PM2, PR6, 3);
PromocionProducto *PP6 = controladorPromocion->asociarLote(PM3, PR5, 2);
PromocionProducto *PP7 = controladorPromocion->asociarLote(PM4, PR14, 1);
Compra *CO1 =
    controladorCompra->cargarLote(US4, DTFecha(1, 5, 2024), 68389.293, PM1);
Compra *CO2 =
    controladorCompra->cargarLote(US4, DTFecha(1, 5, 2024), 599.99, NULL);
Compra *CO3 =
    controladorCompra->cargarLote(US5, DTFecha(15, 5, 2024), 150000, NULL);
Compra *CO4 =
    controladorCompra->cargarLote(US7, DTFecha(25, 4, 2024), 11734, NULL);
Compra *CO5 =
    controladorCompra->cargarLote(US4, DTFecha(20, 5, 2024), 1263.984, PM2);
Compra *CO6 =
    controladorCompra->cargarLote(US5, DTFecha(12, 5, 2024), 2800, NULL);
Compra *CO7 =
    controladorCompra->cargarLote(US7, DTFecha(13, 5, 2024), 4200, NULL);
Compra *CO8 =
    controladorCompra->cargarLote(US8, DTFecha(14, 5, 2024), 5600, NULL);
Compra *CO9 =
    controladorCompra->cargarLote(US9, DTFecha(15, 5, 2024), 7000, NULL);
CompraProducto *CP1 = controladorCompra->asociarLote(CO1, PR2, 2, true);
CompraProducto *CP2 = controladorCompra->asociarLote(CO1, PR4, 1, false);
CompraProducto *CP3 = controladorCompra->asociarLote(CO1, PR8, 1, false);
CompraProducto *CP4 = controladorCompra->asociarLote(CO2, PR5, 1, true);
CompraProducto *CP5 = controladorCompra->asociarLote(CO3, PR14, 10, true);
CompraProducto *CP6 = controladorCompra->asociarLote(CO4, PR11, 1, true);
CompraProducto *CP7 = controladorCompra->asociarLote(CO4, PR12, 1, true);
CompraProducto *CP8 = controladorCompra->asociarLote(CO4, PR13, 1, true);
CompraProducto *CP13 = controladorCompra->asociarLote(CO5, PR3, 2, false);
CompraProducto *CP14 = controladorCompra->asociarLote(CO5, PR6, 3, true);
CompraProducto *CP9 = controladorCompra->asociarLote(CO6, PR1, 2, false);
CompraProducto *CP10 = controladorCompra->asociarLote(CO7, PR1, 3, true);
CompraProducto *CP11 = controladorCompra->asociarLote(CO8, PR1, 4, false);
CompraProducto *CP12 = controladorCompra->asociarLote(CO9, PR1, 5, false);
Comentario *CM1 = controladorComentario->cargarLote(
    US4, PR1, DTFecha(1, 6, 2024),
    "¿La camiseta azul esta disponible en talla M?", NULL);
Comentario *CM2 = controladorComentario->cargarLote(
    US2, PR1, DTFecha(1, 6, 2024), "Si, tenemos la camiseta azul en talla M.",
    CM1);
Comentario *CM3 = controladorComentario->cargarLote(
    US5, PR1, DTFecha(2, 6, 2024),
    "¿Es de buen material? Me preocupa la durabilidad.", CM2);
Comentario *CM4 = controladorComentario->cargarLote(
    US4, PR1, DTFecha(2, 6, 2024), "He comprado antes y la calidad es buena.",
    CM3);
Comentario *CM5 = controladorComentario->cargarLote(
    US7, PR1, DTFecha(2, 6, 2024),
    "¿Como es el ajuste? ¿Es ajustada o holgada?", NULL);
Comentario *CM6 = controladorComentario->cargarLote(
    US5, PR2, DTFecha(2, 6, 2024), "¿Cual es la resolucion del Televisor LED?",
    NULL);
Comentario *CM7 = controladorComentario->cargarLote(
    US1, PR2, DTFecha(2, 6, 2024),
    "El televisor LED tiene una resolucion de 4K UHD.", CM6);
Comentario *CM8 = controladorComentario->cargarLote(
    US8, PR2, DTFecha(3, 6, 2024), "¿Tiene soporte para HDR10?", NULL);
Comentario *CM9 = controladorComentario->cargarLote(
    US1, PR2, DTFecha(3, 6, 2024), "Si, soporta HDR10.", CM8);
Comentario *CM10 = controladorComentario->cargarLote(
    US7, PR3, DTFecha(3, 6, 2024),
    "¿La chaqueta de cuero es resistente al agua?", NULL);
Comentario *CM11 = controladorComentario->cargarLote(
    US2, PR3, DTFecha(3, 6, 2024),
    "No, la chaqueta de cuero no es resistente al agua.", CM10);
Comentario *CM12 = controladorComentario->cargarLote(
    US5, PR3, DTFecha(4, 6, 2024), "¿Viene en otros colores?", CM10);
Comentario *CM13 = controladorComentario->cargarLote(
    US2, PR3, DTFecha(4, 6, 2024), "Si, tambien esta disponible en marron.",
    CM12);
Comentario *CM14 = controladorComentario->cargarLote(
    US9, PR3, DTFecha(4, 6, 2024), "¿Es adecuada para climas frios?", CM10);
Comentario *CM15 = controladorComentario->cargarLote(
    US8, PR4, DTFecha(4, 6, 2024),
    "¿El microondas digital tiene funcion de descongelacion rapida?", NULL);
Comentario *CM16 = controladorComentario->cargarLote(
    US1, PR4, DTFecha(4, 6, 2024),
    "Si, el microondas digital incluye una funcion de descongelacion rapida.",
    CM15);
Comentario *CM17 = controladorComentario->cargarLote(
    US7, PR4, DTFecha(5, 6, 2024), "¿Cuantos niveles de potencia tiene?", CM15);
Comentario *CM18 = controladorComentario->cargarLote(
    US1, PR4, DTFecha(5, 6, 2024), "Tiene 10 niveles de potencia.", CM17);
Comentario *CM19 = controladorComentario->cargarLote(
    US9, PR4, DTFecha(5, 6, 2024), "¿Es facil de limpiar?", CM15);
Comentario *CM20 = controladorComentario->cargarLote(
    US9, PR5, DTFecha(5, 6, 2024),
    "¿La luz LED se puede controlar con una aplicacion movil?", NULL);
Comentario *CM21 = controladorComentario->cargarLote(
    US3, PR5, DTFecha(5, 6, 2024),
    "Si, la luz LED se puede controlar a traves de una aplicacion movil.",
    CM20);
Comentario *CM22 = controladorComentario->cargarLote(
    US8, PR5, DTFecha(6, 6, 2024), "¿Es compatible con Alexa o Google Home?",
    CM20);
Comentario *CM23 = controladorComentario->cargarLote(
    US3, PR5, DTFecha(6, 6, 2024), "Si, es compatible con ambos.", CM22);
Comentario *CM24 = controladorComentario->cargarLote(
    US7, PR5, DTFecha(6, 6, 2024), "¿Cuanto dura la bateria?", CM20);
Comentario *CM25 = controladorComentario->cargarLote(
    US8, PR5, DTFecha(7, 6, 2024), "¿La aplicacion movil es facil de usar?",
    CM20);
