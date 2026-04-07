#!/bin/bash
awk -F";" -- '{ split($5, date, "/"); print "Usuario *" $1 " = controladorUsuario->cargarLote(" ($2 == "V" ? "true" : "false") ",\"" $3 "\",\"" $4 "\"," "DTFecha("date[1]+0","date[2]+0","date[3]+0")" ");" }' CSVs/2024Usuarios.csv | tail -n +2
awk -F";" -- '{ print "controladorUsuario->asociarClienteLote(" $1 ",\"" $2 "\"," $3 ",\"" $4 "\");" }' CSVs/2024Usuarios-Clientes.csv | tail -n +2
awk -F";" -- '{ print "controladorUsuario->asociarVendedorLote(" $1 ",\"" $2 "\");" }' CSVs/2024Usuarios-Vendedores.csv | tail -n +2
awk -F";" -- '{ print "Producto *" $1 " = controladorProducto->cargarLote(" $2 ",\"" $3 "\",\"" $4 "\"," $5 "," $6 "," $7 "," $8 ");" }' CSVs/2024Productos.csv | tail -n +2
awk -F";" -- '{ split($5, date, "/"); print "Promocion *" $1 " = controladorPromocion->cargarLote(\"" $2 "\",\"" $3 "\"," $4 "," "DTFecha("date[1]+0","date[2]+0","date[3]+0")" ");" }' CSVs/2024Promociones.csv | tail -n +2
awk -F";" -- '{ print "PromocionProducto *" $1 " = controladorPromocion->asociarLote(" $2 "," $3 "," $4 ");" }' CSVs/2024Promociones-Producto.csv | tail -n +2
awk -F";" -- '{ split($3, date, "/"); print "Compra *" $1 " = controladorCompra->cargarLote(" $2 "," "DTFecha("date[1]+0","date[2]+0","date[3]+0")" "," $4 "," ($5=="-" ? "NULL" : $5) ");" }' CSVs/2024Compras.csv | tail -n +2
awk -F";" -- '{ print "CompraProducto *" $1 " = controladorCompra->asociarLote(" $2 "," $3 "," $4 "," ($5 == "No" ? "false" : "true") ");" }' CSVs/2024Compras-Producto.csv | tail -n +2
awk -F";" -- '{ split($4, date, "/"); print "Comentario *" $1 " = controladorComentario->cargarLote(" $2 "," $3 "," "DTFecha("date[1]+0","date[2]+0","date[3]+0")" ",\"" $5 "\"," ($6 == "" || $6==" " ? "NULL" : $6) ");" }' CSVs/2024Comentarios.csv | tail -n +2
