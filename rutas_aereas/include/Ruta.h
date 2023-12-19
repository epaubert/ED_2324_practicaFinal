#ifndef _RUTA_H_
#define _RUTA_H_

#include "../include/Paises.h"
#include "../include/Punto.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Ruta {
private:
  list<Punto> puntos;
  string code;

public:
  Ruta();
  Ruta(const Ruta &R);
  void Insertar(const Punto &n);
  void Borrar(const Punto &n);

  string getCode() const;
  void setCode(const string &code);
  void mostrarRuta(const Paises &P, Paises &rutaPaises) const;

  bool operator==(const Ruta &R) const;
  bool operator!=(const Ruta &R) const;
  bool operator<(const Ruta &R) const;

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

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

  iterator find(const Punto &P);

  friend istream &operator>>(istream &is, Ruta &R);
  friend ostream &operator<<(ostream &os, const Ruta &R);
};

#include "../src/Ruta.cpp"

#endif
