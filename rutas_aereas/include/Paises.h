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

  class const_iterator;

  class iterator {
  private:
    set<Pais>::iterator p;

  public:
    friend class Paises;
    friend class const_iterator;
    iterator();
    iterator(Paises &P);
    iterator(Paises::iterator &it);
    iterator begin();
    iterator end();
    iterator find(const Pais &p);
    iterator find(const Punto &p);
  };

  class const_iterator {
  private:
    set<Pais>::const_iterator p;

  public:
    friend class Paises;
    friend class iterator;
    const_iterator();
    const_iterator(Paises &P);
    const_iterator(Paises::const_iterator &it);
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator find(const Pais &p);
    const_iterator find(const Punto &p);
  };

  // TODO:
  iterator operator*();
  const_iterator operator*() const;
  iterator operator++();
  const_iterator operator++() const;

  friend istream &operator>>(istream &is, Paises &R);
  friend ostream &operator<<(ostream &os, const Paises &R);

  friend class iterator;
  friend class const_iterator;
};

#endif
