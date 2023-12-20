/**
 * @file Ruta.h
 * @brief Fichero de cabeceras para Ruta.h
 * 
 * Contiene informacion sobre una Ruta
*/

#ifndef _RUTA_H_
#define _RUTA_H_

#include "../include/Paises.h"
#include "../include/Punto.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
   * @section datos_sec Acceso a datos
   * Para obtener más información sobre el acceso a datos, consulta el
   * @ref DatosRuta "Getter y Setters de Ruta"
   */

class Ruta {
private:
  list<Punto> puntos;
  string code;

public:
  /**
   * @brief Constructor por defecto de Ruta
  */
  Ruta();
  
  /**
   * @brief Constructor por copia de Ruta
  */
  Ruta(const Ruta &R);

  /**
   * @brief Metodo Insertar
   * 
   * Inserta un punto dentro de la estructura **list<Punto> puntos**
   * @param n El punto a insertar
  */
  void Insertar(const Punto &n);

  /**
   * @brief Metodo Borrar
   * 
   * Borra un punto dentro de la estructura **list<Punto> puntos**
   * @param n El punto a borrar
  */
  void Borrar(const Punto &n);

  /**
   * @defgroup DatosRuta Getter y Setters de Ruta
   * @brief Funciones para acceder y modificar datos de la clase Ruta
   */

  /**
   * @ingroup DatosRuta
   * @brief Obtiene el codigo de la Ruta
   * @return El codigo de la ruta
   */
  string getCode() const;

  /**
   * @ingroup DatosRuta
   * @brief Establece un nuevo codigo para la ruta
   * @param code El nuevo codigo de la ruta
   */
  void setCode(const string &code);


  /**
   * @brief Metodo mostrarRuta
   * Muestra informacion de la ruta mostrando:
   * Nombre de la ruta elegida
   * Numero de paises visitados
   * Nombre de los paises que seran visitados
   * 
   * @param P Lista de todos los paises
   * @param rutaPaises Objeto donde guardaremos los resultados de la busqueda dentro de P
  */
  void mostrarRuta(const Paises &P, Paises &rutaPaises) const;

  /**
   * @brief Sobrecarga del operador ==
   * @param R Un objeto Ruta con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator==(const Ruta &R) const;

  /**
   * @brief Sobrecarga del operador !=
   * @param R Un objeto Ruta con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator!=(const Ruta &R) const;

  /**
   * @brief Sobrecarga del operador <
   * @param R Un objeto Ruta con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator<(const Ruta &R) const;

  /**
   * @brief Clase Iterator
   * 
   * Iterador creado para poder iterar sobre la estructura **list<Punto> puntos** dentro de Ruta
  */
  class iterator {
  private:
    list<Punto>::iterator p;

  public:
    friend class Ruta;
    Punto operator*();
    Punto *operator->();
    iterator operator++();
    bool operator==(const iterator &it) const;
    bool operator!=(const iterator &it) const;
  };

  /**
   * @brief Clase Const_Iterator
   * 
   * Iterador creado para poder iterar sobre la estructura **list<Punto> puntos** dentro de Ruta
  */
  class const_iterator {
  private:
    list<Punto>::const_iterator p;

  public:
    friend class Ruta;
    const Punto operator*() const;
    const Punto *operator->() const;
    const_iterator operator++();
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
  };

  /**
   * @brief Metodo begin para la clase iterator
   * 
   * @return Un iterador apuntando al principio de la estructura **list<Punto> puntos**
  */
  iterator begin();

  /**
   * @brief Metodo cbegin para la clase const_iterator
   * 
   * @return Un iterador apuntando al principio de la estructura **list<Punto> puntos**
  */
  const_iterator cbegin() const;

  /**
   * @brief Metodo end para la clase iterator
   * 
   * @return Un iterador apuntando al final de la estructura **list<Punto> puntos**
  */
  iterator end();

  /**
   * @brief Metodo cend para la clase const_iterator
   * 
   * @return Un iterador apuntando al final de la estructura **list<Punto> puntos**
  */
  const_iterator cend() const;

  /**
   * @brief Metodo find
   * 
   * Encuentra un Punto dentro de la estructura **list<Punto> puntos**
   * @param P El punto a encontrar
   * @return Un iterador apuntado al Punto encontrado (si no es encontrado apuntara al final)
  */
  iterator find(const Punto &P);

  /**
   * @brief Sobrecarga del **operator>>**
   * 
   * Sobrecarga que permite la escritura de datos dentro de la estructura **list<Punto> puntos**
   * 
   * La entrada de datos vendra desde un archivo de formato .txt, por lo que tenemos que filtrar lo que recibe R
   * 
   * @param is Flujo de entrada de datos
   * @param R Objeto Ruta en el que queremos guardar los datos
   * 
   * @return El flujo de entrada correcto
  */
  friend istream &operator>>(istream &is, Ruta &R);

  /**
   * @brief Sobrecarga del **operator<<**
   * 
   * Sobrecarga que permite la salida de datos dentro de la estructura **list<Punto> puntos**
   * 
   * @param os Flujo de salida de datos
   * @param R Objeto Ruta del que queremos ver su contenido
   * 
   * @return El flujo de salida con el formato que queremos y con los datos que queremos
  */
  friend ostream &operator<<(ostream &os, const Ruta &R);
};

#include "../src/Ruta.cpp"

#endif
