#include "../include/Ruta.h"

Ruta::Ruta() {}

void Ruta::Insertar(const Punto &n) { puntos.push_back(n); }
void Ruta::Borrar(const Punto &n) { puntos.remove(n); }

string Ruta::getCode() const { return code; }
void Ruta::setCode(const string &code) { this->code = code; }

bool Ruta::operator==(const Ruta &R) const { return this->code == R.getCode(); }
bool Ruta::operator<(const Ruta &R) const {
  return this->puntos.size() < R.puntos.size();
}

Ruta::iterator Ruta::begin() {
  Ruta::iterator it;
  it.p = puntos.begin();
  return it;
}

Ruta::const_iterator Ruta::begin() const {
  Ruta::const_iterator it;
  it.p = puntos.cbegin();
  return it;
}

Ruta::iterator Ruta::end() {
  Ruta::iterator it;
  it.p = puntos.end();
  return it;
}

Ruta::const_iterator Ruta::end() const {
  Ruta::const_iterator it;
  it.p = puntos.cend();
  return it;
}

Ruta::iterator Ruta::find(const Punto &P) {
  iterator it;
  list<Punto>::iterator i;
  for (i = puntos.begin(); i != puntos.end() && !((*i) == P); ++i)
    ;
  it.p = i;
  return it;
}

istream &operator>>(istream &is, Ruta &R) {
  cerr << "Ruta \n";
  string s;
  int size;
  Punto p;

  is >> s;
  R.setCode(s);

  is >> size;
  for (int i = 0; i < size; i++) {
    is >> p;
    R.Insertar(p);
  }

  return is;
}

ostream &operator<<(ostream &os, const Ruta &R) {
  os << R.getCode() << "\t" << R.puntos.size() << "\t";
  for (const auto punto : R.puntos) {
    os << punto << " ";
  }
}
