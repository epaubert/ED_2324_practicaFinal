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

Ruta::const_iterator Ruta::cbegin() const {
  Ruta::const_iterator it;
  it.p = puntos.cbegin();
  return it;
}

Ruta::iterator Ruta::end() {
  Ruta::iterator it;
  it.p = puntos.end();
  return it;
}

Ruta::const_iterator Ruta::cend() const {
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

Punto &Ruta::iterator::operator*() { return *p; }

Ruta::iterator Ruta::iterator::operator++() {
  ++p;
  return *this;
}

bool Ruta::iterator::operator==(const iterator &it) const {
  return *p == *it.p;
}

bool Ruta::iterator::operator!=(const iterator &it) const {
  return *p != *it.p;
}

const Punto &Ruta::const_iterator::operator*() const {
  return *p;
}

Ruta::const_iterator Ruta::const_iterator::operator++() {
  ++p;
  return *this;
}

bool Ruta::const_iterator::operator==(const const_iterator &it) const {
  return p == it.p;
}

bool Ruta::const_iterator::operator!=(const const_iterator &it) const {
  return p != it.p;
}


istream &operator>>(istream &is, Ruta &R) {
  string s;
  int size;
  Punto p;

  while (is.peek() != 'R') {
    is.get();
  }

  cerr << "Ruta encontrada" << endl;

  is >> s;
  R.setCode(s);

  is >> size;
  for (int i = 0; i < size; i++) {
    is >> p;
    R.Insertar(p);
  }

  /* cerr << "Ruta: "; */
  /* cerr << R << endl; */
  return is;
}

ostream &operator<<(ostream &os, const Ruta &R) {
  os << R.getCode() << "\t" << R.puntos.size() << "\t";
  for (auto it = R.cbegin(); it != R.cend(); ++it) {
    os << *it << " ";
  }
}
