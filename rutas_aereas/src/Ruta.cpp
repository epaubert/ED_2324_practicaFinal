#include "../include/Ruta.h"

Ruta::Ruta() {}
Ruta::Ruta(const Ruta &R) {
  puntos = R.puntos;
  code = R.code;
}

void Ruta::Insertar(const Punto &n) { puntos.push_back(n); }
void Ruta::Borrar(const Punto &n) { puntos.remove(n); }

string Ruta::getCode() const { return code; }
void Ruta::setCode(const string &_code) { code = _code; }

void Ruta::mostrarRuta(const Paises &P, Paises &paisesRuta) {
  const_iterator it;

  cout << endl << "Ruta elegida: " << code << endl;
  cout << "Numero de destinos de la ruta: " << puntos.size() << endl;
  cout << "Paises que seran visitados:" << endl;

  for (it = cbegin(); it != cend(); ++it) {
    auto pais = P.find(*it);
    if (it != cbegin())
      cout << " -> ";
    cout << (*pais).GetPais();
    paisesRuta.Insertar(*pais);
  }
  cout << endl << endl << "Generando mapa..." << endl;
}

bool Ruta::operator==(const Ruta &R) const { return getCode() == R.getCode(); }
bool Ruta::operator!=(const Ruta &R) const { return getCode() != R.getCode(); }
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

Punto Ruta::iterator::operator*() { return *p; }

Punto *Ruta::iterator::operator->() { return &(*p); }

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

const Punto Ruta::const_iterator::operator*() const { return *p; }

const Punto *Ruta::const_iterator::operator->() const { return &(*p); }

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
  Ruta::const_iterator it;
  for (it = R.cbegin(); it != R.cend(); ++it) {
    os << *it << " ";
  }
  return os;
}
