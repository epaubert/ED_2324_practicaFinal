#!/bin/bash

for i in $(seq 0 45 360); do
	./pruebarotacion datos/imagenes/aviones/avion1.ppm $i pruebas/avion1rotado_$i.ppm
done

feh pruebas/avion1rotado_*.ppm
