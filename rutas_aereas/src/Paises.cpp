#include "../include/Paises.h"
#include <iterator>

Paises::Paises() {}
Paises::Paises(const Paises &P) { datos = P.datos; }

void Paises::Insertar(const Pais &P) { datos.insert(P); }
void Paises::Borrar(const Pais &P) { datos.erase(P); }

Paises::iterator Paises::begin() {
  Paises::iterator it;
  it.p = datos.begin();
  return it;
}

Paises::const_iterator Paises::begin() const {
  Paises::const_iterator it;
  it.p = datos.begin();
  return it;
}

Paises::iterator Paises::end() {
  Paises::iterator it;
  it.p = datos.begin();
  return it;
}

Paises::const_iterator Paises::end() const {
  Paises::const_iterator it;
  it.p = datos.end();
  return it;
}

Paises::iterator Paises::find(const Pais &p) {
  iterator it;
  set<Pais>::iterator i;
  for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
    ;
  it.p = i;
  return it;
}

Paises::iterator Paises::find(const Punto &p) {
  iterator it;
  set<Pais>::iterator i;
  for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
    ;
  it.p = i;
  return it;
}

const Pais &Paises::iterator::operator*() { return *p; }

Paises::iterator Paises::iterator::operator++() {
  ++p;
  return *this;
}

bool Paises::iterator::operator==(const iterator &it) const {
  return *p == *(it.p);
}

bool Paises::iterator::operator!=(const iterator &it) const {
  return *p != *(it.p);
}

const Pais &Paises::const_iterator::operator*() const { return *p; }

Paises::const_iterator Paises::const_iterator::operator++() {
  ++p;
  return *this;
}

bool Paises::const_iterator::operator==(const const_iterator &it) const {
  return *p == *(it.p);
}

bool Paises::const_iterator::operator!=(const const_iterator &it) const {
  return *p != *(it.p);
}

// TODO:
/* Pais Paises::iterator::operator*() { return *p; } */
/* Paises::const_iterator Paises::const_iterator::operator*() const {} */
/* const Pais Paises::iterator::operator++() { return *p; } */
/* Paises::const_iterator Paises::const_iterator::operator++() const {} */

istream &operator>>(istream &is, Paises &R) {
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

ostream &operator<<(ostream &os, const Paises &R) {
  Paises::const_iterator it;
  for (it = R.begin(); it != R.end(); ++it) {
    os << *it << "\t";
  }
  return os;
}
