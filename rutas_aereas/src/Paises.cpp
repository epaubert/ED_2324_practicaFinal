#include "../include/Paises.h"

Paises::Paises() {}
Paises::Paises(const Paises &P) { datos = P.datos; }
void Paises::Insertar(const Pais &P) { datos.insert(P); }
void Paises::Borrar(const Pais &P) { datos.erase(P); }

Paises::iterator Paises::iterator::begin() {
  iterator it;
  it.p = datos.begin();
  return it;
}

Paises::const_iterator Paises::const_iterator::begin() const {
  Paises::const_iterator it;
  it.p = datos.cbegin();
  return it;
}

Paises::iterator Paises::iterator::end() {
  iterator it;
  it.p = datos.end();
  return it;
}

Paises::const_iterator Paises::const_iterator::end() const {
  const_iterator it;
  it.p = datos.cend();
  return it;
}

Paises::iterator Paises::iterator::find(const Pais &p) {
  iterator it;
  set<Pais>::iterator i;
  for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
    ;
  it.p = i;
  return it;
}

Paises::iterator Paises::iterator::find(const Punto &p) {
  iterator it;
  set<Pais>::iterator i;
  for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
    ;
  it.p = i;
  return it;
}

// TODO:
Paises::iterator Paises::iterator::operator*() {}
Paises::const_iterator Paises::const_iterator::operator*() const {}
Paises::iterator Paises::iterator::operator++() {}
Paises::const_iterator Paises::const_iterator::operator++() const {}

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
