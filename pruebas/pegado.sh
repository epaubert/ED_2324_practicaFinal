#!/bin/bash

for i in $(seq 0 45 360); do
	./pruebapegado datos/imagenes/banderas/espana_reshigh.ppm datos/imagenes/aviones/avion2.ppm datos/imagenes/aviones/mascara_avion2.pgm pruebas/espana_avion2_blending"$i".ppm 0 20 0 "$i"
done

# feh pruebas/espana_avion2_blending*.ppm
