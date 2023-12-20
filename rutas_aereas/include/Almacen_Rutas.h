/**
 * @file Almacen_Rutas.h
 * @brief Fichero de cabecera para la clase Almacen_Rutas
 * 
 * Permite el almacenamiento de rutas
 * 
 * @see Ruta.h
*/


#include "../include/Paises.h"
#include "../include/Ruta.h"
#include <iostream>
#include <map>
#include <string>

#ifndef _ALMACEN_RUTAS_H_
#define _ALMACEN_RUTAS_H_

class Almacen_Rutas {
private:
  map<std::string, Ruta> rutas; // código de ruta y ruta
public:

  /**
   * @brief Constructor por defecto de la clase Almacen_Rutas
  */
  Almacen_Rutas();

  /**
   * @brief Metodo Insertar
   * 
   * Inserta una ruta dentro de la estructura: **map<std::string, Ruta> rutas**
   * 
   * @param R Objeto de la clase Ruta a Insertar
  */
  void Insertar(const Ruta &R);

  /**
   * @brief Metodo Borrar
   * 
   * Borra una ruta de la estructura: **map<std::string, Ruta> rutas**
   * 
   * @param R Objeto de la clase Ruta a Borrar
  */
  void Borrar(const Ruta &R);

  /**
   * @brief Metodo GetRuta
   * 
   * Devuelve una ruta
   * 
   * @param s Clave primaria dentro del Mapa que da nombre a la ruta a buscar
  */
  Ruta GetRuta(const std::string &s);

  /**
   * @brief Clase Iterator
   * 
   * Iterador creado para poder iterar sobre la estructura **map<std::string, Ruta> rutas** dentro de Almacen_Rutas
  */
  class iterator {
  private:
    map<std::string, Ruta>::iterator p;

  public:
    friend class Almacen_Rutas;
    Ruta operator*();
    Ruta *operator->();
    iterator operator++();
    bool operator==(const iterator &it) const;
    bool operator!=(const iterator &it) const;
  };

   /**
   * @brief Clase Const Iterator
   * 
   * Iterador creado para poder iterar sobre la estructura **map<std::string, Ruta> rutas** dentro de Almacen_Rutas
  */
  class const_iterator {
  private:
    map<std::string, Ruta>::const_iterator p;

  public:
    friend class Almacen_Rutas;
    const Ruta operator*() const;
    const Ruta *operator->() const;
    const_iterator operator++();
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
  };

  /**
   * @brief Metodo begin para la clase iterator
   * 
   * @return Un iterador apuntando al principio de la estructura **map<std::string, Ruta> rutas**
  */
  iterator begin();

  /**
   * @brief Metodo cbegin para la clase const_iterator
   * 
   * @return Un iterador constante apuntando al principio de la estructura **map<std::string, Ruta> rutas**
  */
  const_iterator cbegin() const;
  
  /**
   * @brief Metodo end para la clase iterator
   * 
   * @return Un iterador apuntando al final de la estructura **map<std::string, Ruta> rutas**
  */
  iterator end();
  
  /**
   * @brief Metodo cend para la clase iterator
   * 
   * @return Un iterador constante apuntando al final de la estructura **map<std::string, Ruta> rutas**
  */
  const_iterator cend() const;

  /**
   * @brief Metodo mostrarRutas
   * 
   * Muestra todas las rutas disponibles dentro de la estructura **map<std::string, Ruta> rutas**
   * 
   * Las rutas se mostraran con el siguiente formato:
   * 
   * <i>Nombre de la ruta</i> \n
   * <i>Pais de la ruta / Pais de la ruta / etc</i>
   * 
   * @param P Lista de Paises existentes para poder dar nombre y banderas a los puntos dentro de una Ruta 
  */
  void mostrarRutas(const Paises &P) const;

  /**
   * @brief Metodo elijeRuta
   * 
   * Metodo que busca y devuelve la ruta elegida
   * 
   * @param opcion Nombre de la Ruta que ha sido elegida
   * 
   * @return Un iterador que apunta a la ruta elegida
  */
  Almacen_Rutas::const_iterator elijeRuta(const string &opcion) const;


  /**
   * @brief Sobrecarga del **operator>>**
   * 
   * Sobrecarga que permite la escritura de datos dentro de la estructura **map<std::string, Ruta> rutas**
   * 
   * La entrada de datos vendra desde un archivo de formato .txt, por lo que tenemos que filtrar lo que recibe R
   * 
   * @param is Flujo de entrada de datos
   * @param R Objeto Almacen_Rutas en el que queremos guardar los datos
   * 
   * @return El flujo de entrada correcto
  */
  friend std::istream &operator>>(std::istream &is, Almacen_Rutas &R);

  /**
   * @brief Sobrecarga del **operator<<**
   * 
   * Sobrecarga que permite la salida de datos dentro de la estructura **map<std::string, Ruta> rutas**
   * 
   * @param os Flujo de salida de datos
   * @param R Objeto Almacen_Rutas del que queremos ver su contenido
   * 
   * @return El flujo de salida con el formato que queremos y con los datos que queremos
  */
  friend std::ostream &operator<<(std::ostream &os, const Almacen_Rutas &R);
};

#include "../src/Almacen_Rutas.cpp"
#endif
