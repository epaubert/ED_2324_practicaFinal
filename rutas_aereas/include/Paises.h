#ifndef _PAISES_H_
#define _PAISES_H_

#include "Pais.h"
#include <set>

using namespace std;

class Paises {
private:
  set<Pais> datos;

public:
  Paises() {}
  Paises(const Paises &P) { datos = P.datos; }
  void Insertar(const Pais &P) { datos.insert(P); }
  void Borrar(const Pais &P) { datos.erase(P); }

  class const_iterator;

  class iterator {  
  private:
    set<Pais>::iterator p;

  public:
    friend class Paises;
    friend class const_iterator;
  };

  class const_iterator {
  private:
    set<Pais>::const_iterator p;

  public:
    friend class Paises;
  };

  iterator begin() {
    iterator it;
    it.p = datos.begin();
    return it;
  }

  const_iterator begin() const {
    const_iterator it;
    it.p = datos.cbegin();
    return it;
  }

  iterator end() {
    iterator it;
    it.p = datos.end();
    return it;
  }

  const_iterator end() const {
    const_iterator it;
    it.p = datos.cend();
    return it;
  }

  iterator find(const Pais &p) {
    iterator it;
    set<Pais>::iterator i;
    for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
      ;
    it.p = i;
    return it;
  }

  iterator find(const Punto &p) {
    iterator it;
    set<Pais>::iterator i;
    for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
      ;
    it.p = i;
    return it;
  }

  // TODO:
  iterator operator*();
  const_iterator operator*();
  iterator operator++();
  const_iterator operator++();

  friend istream &operator>>(istream &is, Paises &R) {
    Paises rlocal;
    // leemos el comentario
    if (is.peek() == '#') {
      string a;
      getline(is, a);
    }

    Pais P;
    while (is >> P) {
      rlocal.Insertar(P);
    }
    R = rlocal;
    return is;
  }

  friend ostream &operator<<(ostream &os, const Paises &R) {

    Paises::const_iterator it;
    for (it = R.begin(); it != R.end(); ++it) {
      os << *it << "\t";
    }
    return os;
  }
};

#endif