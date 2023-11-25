#include "../include/Almacen_Rutas.h"

Almacen_Rutas::Almacen_Rutas() {}
void Almacen_Rutas::Insertar(const Ruta &R) { rutas.emplace(R.getCode(), R); }
void Almacen_Rutas::Borrar(const Ruta &R) {
  rutas.erase(rutas.find(R.getCode()));
}
Ruta Almacen_Rutas::GetRuta(const std::string &s) {
  return rutas.find(s)->second;
}

Almacen_Rutas::iterator Almacen_Rutas::begin() {
  Almacen_Rutas::iterator it;
  it.p = rutas.begin();
  return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin() const {
  Almacen_Rutas::const_iterator it;
  it.p = rutas.cbegin();
  return it;
}
Almacen_Rutas::iterator Almacen_Rutas::end() {
  Almacen_Rutas::iterator it;
  it.p = rutas.end();
  return it;
}
Almacen_Rutas::const_iterator Almacen_Rutas::end() const {
  Almacen_Rutas::const_iterator it;
  it.p = rutas.cend();
  return it;
}

Ruta &Almacen_Rutas::iterator::operator*() { return p->second; }

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator++() {
  ++p;
  return *this;
}

bool Almacen_Rutas::iterator::operator==(const iterator &it) const {
  return *p == *it.p;
}

bool Almacen_Rutas::iterator::operator!=(const iterator &it) const {
  return *p != *it.p;
}

const Ruta &Almacen_Rutas::const_iterator::operator*() const {
  return p->second;
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator++() {

  ++p;
  return *this;
}

bool Almacen_Rutas::const_iterator::operator==(const const_iterator &it) const {

  return *p == *it.p;
}
bool Almacen_Rutas::const_iterator::operator!=(const const_iterator &it) const {
  return *p != *it.p;
}

std::istream &operator>>(std::istream &is, Almacen_Rutas &R) {
  Ruta r;
  while (!is.eof()) {
    if (is.peek() == '#') {
      is.ignore(8, '\n');
    } else {
      is >> r;
      R.Insertar(r);
    }
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Almacen_Rutas &R) {
  Almacen_Rutas::const_iterator it;
  for (it = R.begin(); it != R.end(); ++it) {
    os << *it << "\n";
  }
  return os;
}
