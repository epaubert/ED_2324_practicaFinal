#!/bin/bash

num=$((1 + $RANDOM % 5))
./ruta_aerea datos/paises.txt datos/imagenes/mapas/mapa1.ppm datos/imagenes/banderas datos/almacen_rutas.txt datos/imagenes/aviones/avion$num.ppm datos/imagenes/aviones/mascara_avion$num.pgm
