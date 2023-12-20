/**
 * @file Pais.h
 * @brief Fichero de cabeceras para Pais.h
 *
 * Contiene la informacion de un Pais
 */
#ifndef _PAIS_H_
#define _PAIS_H_

#include "Punto.h"

/**
   * @section datos_sec Acceso a datos
   * Para obtener más información sobre el acceso a datos, consulta el
   * @ref DatosPais "Getter y Setters de Pais"
   */

class Pais
{
private:
  Punto p;
  string pais;
  string bandera;

public:
  /**
   * @brief Constructor por defecto de Pais
   */
  Pais();

  /**
   * @brief Constructor por copia de Pais
   */
  Pais(const Pais &P);

  /**
   * @defgroup DatosPais Getter y Setters de Pais
   * @brief Funciones para acceder y modificar datos de la clase Pais
   */

  /**
   * @ingroup DatosPais
   * @brief Obtiene el punto
   * @return Un objeto Punto
   */
  Punto GetPunto() const;

  /**
   * @ingroup DatosPais
   * @brief Obtiene el país
   * @return El nombre del pais
   */
  string GetPais() const;

  /**
   * @ingroup DatosPais
   * @brief Obtiene la bandera
   * @return Nombre del archivo de la bandera
   */
  string GetBandera() const;

  /**
   * @ingroup DatosPais
   * @brief Establece el punto
   * @param P El nuevo punto a establecer
   */
  void SetPunto(Punto P);

  /**
   * @ingroup DatosPais
   * @brief Establece el país
   * @param P El nombre del país
   */
  void SetPais(string P);

  /**
   * @ingroup DatosPais
   * @brief Establece la bandera
   * @param B El nombre del archivo de la bandera
   */
  void SetBandera(string B);

  /**
   * @brief Sobrecarga del operador <
   * @param P Otro objeto Pais con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator<(const Pais &P) const;

  /**
   * @brief Sobrecarga del operador ==
   * @param P Otro objeto Pais con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator==(const Pais &P) const;

  /**
   * @brief Sobrecarga del operador !=
   * @param P Otro objeto Pais con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator!=(const Pais &P) const;

  /**
   * @brief Sobrecarga del operador ==
   * @param P Un objeto Punto con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator==(const Punto &P) const;

  /**
   * @brief Sobrecarga del operador !=
   * @param P Un objeto Punto con el que comparar
   * @return Devuelve true o false si cumple o no la condicion
   */
  bool operator!=(const Punto &P) const;


  /**
   * @brief Sobrecarga del **operator>>**
   * 
   * Sobrecarga que permite la escritura de datos dentro de sus atributos
   * 
   * La entrada de datos vendra desde un archivo de formato .txt, por lo que tenemos que filtrar lo que recibe P
   * 
   * @param is Flujo de entrada de datos
   * @param P Objeto Pais en el que queremos guardar los datos
   * 
   * @return El flujo de entrada correcto
  */
  friend istream &operator>>(istream &is, const Pais &P);

  /**
   * @brief Sobrecarga del **operator<<**
   * 
   * Sobrecarga que permite la salida de datos de la clase Pais
   * 
   * @param os Flujo de salida de datos
   * @param P Objeto Pais del que queremos ver su contenido
   * 
   * @return El flujo de salida con el formato que queremos y con los datos que queremos
  */
  friend ostream &operator<<(ostream &os, const Pais &P);
};

#include "../src/Pais.cpp"
#endif
