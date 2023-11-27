#ifndef _PAISES_H_
#define _PAISES_H_

#include "Pais.h"
#include <set>

using namespace std;

class Paises {
private:
  set<Pais> datos;

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
    const Pais &operator*() const;
    const_iterator operator++();
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
  };

  // TODO:
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  iterator find(const Pais &p);
  iterator find(const Punto &p);

  /* friend class iterator; */
  /* friend class const_iterator; */

  friend istream &operator>>(istream &is, Paises &R);
  friend ostream &operator<<(ostream &os, const Paises &R);
};

#include "../src/Paises.cpp"
#endif
