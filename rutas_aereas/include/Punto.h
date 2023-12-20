/**
 * @file Punto.h
 * @brief Fichero de cabeceras de Punto.h
 *
 * Contine informacion sobre un punto
 *
 */

#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * @section datos_sec Acceso a datos
 * Para obtener más información sobre el acceso a datos, consulta el
 * @ref DatosPunto "Getter y Setters de Punto"
 */

class Punto {
private:
  double lat, lng;
  string nom;

public:
  /**
   * @brief Contructor por defecto de la clase Punto
   */
  Punto();

  /**
   * @brief Contructor con parametros de la clase Punto
   */
  Punto(float _lat, float _lng, string s = "");

  /**
   * @brief Contructor por copia de la clase Punto
   */
  Punto(const Punto &p);

  /**
   * @brief Destructor de la clase Punto
   */
  ~Punto();

  /**
   * @brief Sobrecarga del operador ==
   * @param p Un objeto Punto con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator==(const Punto &p) const;

  /**
   * @brief Sobrecarga del operador !=
   * @param p Un objeto Punto con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator!=(const Punto &p) const;

  /**
   * @brief Sobrecarga del **operator>>**
   *
   * Sobrecarga que permite la escritura de datos dentro de sus atributos
   *
   * La entrada de datos vendra desde un archivo de formato .txt, por lo que
   * tenemos que filtrar lo que recibe p
   *
   * @param is Flujo de entrada de datos
   * @param p Objeto Punto en el que queremos guardar los datos
   *
   * @return El flujo de entrada correcto
   */
  friend istream &operator>>(istream &is, Punto &p);

  /**
   * @brief Sobrecarga del **operator<<**
   *
   * Sobrecarga que permite la salida de datos de la clase Punto
   *
   * @param os Flujo de salida de datos
   * @param p Objeto Punto del que queremos ver su contenido
   *
   * @return El flujo de salida con el formato que queremos y con los datos que
   * queremos
   */
  friend ostream &operator<<(ostream &os, const Punto &p);

  /**
   * @defgroup DatosPunto Getter y Setters de Punto
   * @brief Funciones para acceder y modificar datos de la clase Punto
   */

  /**
   * @ingroup DatosPunto
   * @brief Obtiene la latitud
   * @return Un double con la latitud
   */
  double getLatitud() const;

  /**
   * @ingroup DatosPunto
   * @brief Obtiene la longitud
   * @return Un double con la longitud
   */
  double getLongitud() const;

  /**
   * @ingroup DatosPunto
   * @brief Obtiene el nombre del punto
   * @return Un string con el nombre del punto
   */
  string getNombre() const;

  /**
   * @ingroup DatosPunto
   * @brief Establece la latitud
   * @param l La nueva latitud
   */
  void setLatitud(double l);

  /**
   * @ingroup DatosPunto
   * @brief Establece la longitud
   * @param l La nueva longitud
   */
  void setLongitud(double l);

  /**
   * @ingroup DatosPunto
   * @brief Establece un nuevo nombre para el punto
   * @param n El nuevo nombre
   */
  void setNombre(string n);
};

#include "../src/Punto.cpp"

#endif
