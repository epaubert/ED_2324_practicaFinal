/**
 * @file AuxFnc.h
 * @brief Fichero de cabeceras para el archivo ruta_aerea.cpp
 *
 * Funciones auxiliares que se tendran que utilizar mas de una vez
 *
 * @see ruta_aerea.cpp
 */

#include "Almacen_Rutas.h"
#include "imagen.h"

#ifndef _AUX_FNC_H
#define _AUX_FNC_H

/**
 * @brief tipo de pegado utilizado por defecto
 */
const Tipo_Pegado tp = BLENDING;
/**
 * @brief string que se utiliza para salir del programa
 */
const string EXIT = "Exit";

/**
 * @brief Funcion Menu
 *
 * Muestra un menu con las diferentes rutas que existen
 * Hasta que no se introduzca @c Exit, el programa continuará en ejecución
 */
Almacen_Rutas::const_iterator menu(const Almacen_Rutas &A, const Paises &p);

/**
 * @brief Funcion coordenadas
 *
 * Al introducirse las coordenadas de un punto de la ruta,
 * se calculan junto al tamaño del mapa la posicion de X y de Y de dicha ruta
 *
 * @param p Coordenas del punto de la ruta
 * @param mapa Mapa elegido donde se colocaran las banderas y los aviones
 *
 * @return Un **pair** que tiene las coordenadas del punto transformadas para
 * poder colocarlas dentro del mapa
 */
pair<double, double> coordenadas(const Punto &p, const Imagen &mapa);

/**
 * @brief Funcion calculaAngulo
 *
 * Al introducir dos puntos, calcularemos el angulo de inclinacion
 * entre dichos puntos, permitiendo orientar el avion en el mapa
 *
 * @param p1, p2 Los dos puntos de los que queremos averiguar el angulo de
 * inclinacion que tienen
 * @param mapa Imagen del mapa
 *
 * @return Un double que es el angulo entre los dos puntos
 */
double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa);

/**
 * @brief Funcion pintaBanderasAviones
 *
 * Esta funcion recorre la ruta y pinta todas las banderas y aviones en el mapa
 *
 * @param ruta Es la ruta seleccionada la cual pintaremos sus puntos en el mapa
 * @param paises La lista de paises que conforman la ruta
 * @param avion Imagen del avion seleccionado y su tipo de pegado
 * @param directorioBanderas Ruta relativa donde se encuentra el directorio de
 * banderas
 * @param mapa Mapa en el que pintaremos los aviones y las banderas.
 * Seleccionado al principio
 */
void pintaBanderasAviones(const Ruta &ruta, const Paises &paises,
                          const Imagen &avion, const string &directorioBanderas,
                          Imagen &mapa);

/**
 * @brief Metodo centrarCoordenadas
 *
 *
 */
pair<double, double> centrarCoordenadas(const pair<double, double> &c2,
                                        const Imagen &i);

#endif
