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
  Almacen_Rutas();
  void Insertar(const Ruta &R);
  void Borrar(const Ruta &R);
  Ruta GetRuta(const std::string &s);

  class iterator {
  private:
    map<std::string, Ruta>::iterator p;

  public:
    friend class Almacen_Rutas;
    Ruta &operator*();
    iterator operator++();
    bool operator==(const iterator &it) const;
    bool operator!=(const iterator &it) const;
  };

  class const_iterator {
  private:
    map<std::string, Ruta>::const_iterator p;

  public:
    friend class Almacen_Rutas;
    const Ruta &operator*() const;
    const_iterator operator++();
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
  };

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

  friend std::istream &operator>>(std::istream &is, Almacen_Rutas &R);
  friend std::ostream &operator<<(std::ostream &os, const Almacen_Rutas &R);
};

#include "../src/Almacen_Rutas.cpp"
#endif
