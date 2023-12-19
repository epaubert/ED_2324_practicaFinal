#include "Almacen_Rutas.h"
#include "imagen.h"

#ifndef _AUX_FNC_H
#define _AUX_FNC_H

const Tipo_Pegado tp = BLENDING;
const string EXIT = "Exit";

Almacen_Rutas::const_iterator menu(const Almacen_Rutas &A, const Paises &p);

pair<double, double> coordenadas(const Punto &p, const Imagen &mapa);

double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa);

void pintaBanderasAviones(const Ruta &ruta, const Paises &paises,
                          const Imagen &avion, const string &directorioBanderas,
                          Imagen &mapa);

pair<double, double> centrarCoordenadas(const pair<double, double> &c2,
                                        const Imagen &i);

#endif
