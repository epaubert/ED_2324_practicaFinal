#ifndef _PAISES_H_
#define _PAISES_H_

#include "Pais.h"
#include <cmath>
#include <set>

using namespace std;

class Paises {
private:
  set<Pais> datos;
  const double UMBRAL = 1.0e-5;

public:
  Paises();
  Paises(const Paises &P);
  void Insertar(const Pais &P);
  void Borrar(const Pais &P);

  class iterator {
  private:
    set<Pais>::iterator p;

  public:
    friend class Paises;
    const Pais &operator*();
    iterator operator++();
    bool operator==(const iterator &it) const;
    bool operator!=(const iterator &it) const;
  };

  class const_iterator {
  private:
    set<Pais>::const_iterator p;

  public:
    friend class Paises;
    friend class Paises::iterator;
    const Pais &operator*() const;
    const_iterator operator++();
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
  };

  iterator begin() const;
  const_iterator cbegin() const;
  iterator end() const;
  const_iterator cend() const;
  iterator find(const Pais &p) const;
  iterator find(const Punto &p) const;

  /* friend class iterator; */
  /* friend class const_iterator; */

  friend istream &operator>>(istream &is, Paises &R);
  friend ostream &operator<<(ostream &os, const Paises &R);
};

#include "../src/Paises.cpp"
#endif
