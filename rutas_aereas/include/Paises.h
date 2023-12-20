/**
 * @file Paises.h
 * @brief Fichero de cabeceras de la clase Paises
 *
 * Permite el almacenamiento de Paises
 * @see Pais.h
 */

#ifndef _PAISES_H_
#define _PAISES_H_

#include "Pais.h"
#include <cmath>
#include <set>

using namespace std;

/**
 * @brief Conjunto ordenado de paises
 */
class Paises {
private:
  set<Pais> datos;
  const double UMBRAL = 1.0e-5;

public:
  /**
   * @brief Contructor por defecto de Paises
   */
  Paises();

  /**
   * @brief Contructor por copia de Paises
   */
  Paises(const Paises &P);

  /**
   * @brief Metodo Insertar
   *
   * Inserta un Pais dentro de la estructura: **set<Pais> datos**
   *
   * @param P Objeto de la clase Pais a Insertar
   */
  void Insertar(const Pais &P);

  /**
   * @brief Metodo Borrar
   *
   * Borra un Pais dentro de la estructura: **set<Pais> datos**
   *
   * @param P Objeto de la clase Pais a Borrar
   */
  void Borrar(const Pais &P);

  /**
   * @brief Clase Iterator
   *
   * Iterador creado para poder iterar sobre la estructura **set<Pais> datos**
   * dentro de Paises
   */
  class iterator {
  private:
    set<Pais>::iterator p;

  public:
    friend class Paises;
    /**
     * @brief Operador de dereferencia del iterador
     * @return el objeto al que apunta el puntero
     */
    Pais operator*();
    /**
     * @brief Operador de acceso a miembro
     */
    const Pais *operator->();
    /**
     * @brief operador de incremento del iterador
     */
    iterator operator++();
    /**
     * @brief Compara dos iteradores para igualdad
     */
    bool operator==(const iterator &it) const;
    /**
     * @brief Compara dos iteradores para desigualdad
     */
    bool operator!=(const iterator &it) const;
  };

  /**
   * @brief Clase Const_Iterator
   *
   * Iterador creado para poder iterar sobre la estructura **set<Pais> datos**
   * dentro de Paises
   */
  class const_iterator {
  private:
    set<Pais>::const_iterator p;

  public:
    friend class Paises;
    /**
     * @brief Operador de dereferencia del iterador
     * @return el objeto al que apunta el puntero
     */
    const Pais operator*() const;
    /**
     * @brief Operador de acceso a miembro
     */
    const Pais *operator->() const;
    /**
     * @brief operador de incremento del iterador
     */
    const_iterator operator++();
    /**
     * @brief Compara dos iteradores para igualdad
     */
    bool operator==(const const_iterator &it) const;
    /**
     * @brief Compara dos iteradores para desigualdad
     */
    bool operator!=(const const_iterator &it) const;
  };

  /**
   * @brief Metodo begin para la clase iterator
   *
   * @return Un iterador apuntando al principio de la estructura **set<Pais>
   * datos**
   */
  iterator begin() const;

  /**
   * @brief Metodo cbegin para la clase const_iterator
   *
   * @return Un iterador apuntando al principio de la estructura **set<Pais>
   * datos**
   */
  const_iterator cbegin() const;

  /**
   * @brief Metodo end para la clase iterator
   *
   * @return Un iterador apuntando al final de la estructura **set<Pais> datos**
   */
  iterator end() const;

  /**
   * @brief Metodo cend para la clase const_iterator
   *
   * @return Un iterador apuntando al final de la estructura **set<Pais> datos**
   */
  const_iterator cend() const;

  /**
   * @brief Metodo find para pais
   *
   * Busca un pais dentro de la estructura **set<Pais> datos**
   * @param p Pais a encontrar
   * @return Un iterador apuntando al Pais encontrado (Sino lo encuentra
   * apuntara al final)
   */
  iterator find(const Pais &p) const;

  /**
   * @brief Metodo find para punto
   *
   * Busca un punto dentro de la estructura **set<Pais> datos**
   * @param p Punto a encontrar
   * @return Un iterador apuntando al Punto encontrado (Sino lo encuentra
   * apuntara al final)
   */
  iterator find(const Punto &p) const;

  /**
   * @brief Sobrecarga del **operator>>**
   *
   * Sobrecarga que permite la escritura de datos dentro de la estructura
   * **set<Pais> datos**
   *
   * La entrada de datos vendra desde un archivo de formato .txt, por lo que
   * tenemos que filtrar lo que recibe R
   *
   * @param is Flujo de entrada de datos
   * @param R Objeto Paises en el que queremos guardar los datos
   *
   * @return El flujo de entrada correcto
   */
  friend istream &operator>>(istream &is, Paises &R);

  /**
   * @brief Sobrecarga del **operator<<**
   *
   * Sobrecarga que permite la salida de datos dentro de la estructura
   * **set<Pais> datos**
   *
   * @param os Flujo de salida de datos
   * @param R Objeto Paises del que queremos ver su contenido
   *
   * @return El flujo de salida con el formato que queremos y con los datos que
   * queremos
   */
  friend ostream &operator<<(ostream &os, const Paises &R);
};

#include "../src/Paises.cpp"
#endif
