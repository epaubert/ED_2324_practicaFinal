#include "../include/Almacen_Rutas.h"

Almacen_Rutas::Almacen_Rutas() {}
void Almacen_Rutas::Insertar(const Ruta &R) { rutas.emplace(R.getCode(), R); }
void Almacen_Rutas::Borrar(const Ruta &R) {
  rutas.erase(rutas.find(R.getCode()));
}
Ruta Almacen_Rutas::GetRuta(const std::string &s) {
  return rutas.find(s)->second;
}

void Almacen_Rutas::mostrarRutas(const Paises &P) const {
  cout << endl << "Rutas disponibles: " << endl << endl;
  Almacen_Rutas::const_iterator it;
  Ruta::const_iterator it2;

  for (it = cbegin(); it != cend(); ++it) {
    Ruta ruta = *it;

    cout << "Ruta " << ruta.getCode() << endl;
    for (it2 = ruta.cbegin(); it2 != ruta.cend(); ++it2) {
      auto aux = P.find(*it2);
      if (aux != P.end()) {
        cout << (*aux).GetPais() << " / ";
      }
    }
    cout << endl << endl;
  }
}

Almacen_Rutas::const_iterator
Almacen_Rutas::elijeRuta(const string &opcion) const {
  Almacen_Rutas::const_iterator it;
  it.p = rutas.find(opcion);
  return it;
}

Almacen_Rutas::iterator Almacen_Rutas::begin() {
  Almacen_Rutas::iterator it;
  it.p = rutas.begin();
  return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::cbegin() const {
  Almacen_Rutas::const_iterator it;
  it.p = rutas.cbegin();
  return it;
}
Almacen_Rutas::iterator Almacen_Rutas::end() {
  Almacen_Rutas::iterator it;
  it.p = rutas.end();
  return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::cend() const {
  Almacen_Rutas::const_iterator it;
  it.p = rutas.cend();
  return it;
}

Ruta Almacen_Rutas::iterator::operator*() { return p->second; }
Ruta *Almacen_Rutas::iterator::operator->() { return &(p->second); }

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator++() {
  p++;
  return *this;
}

bool Almacen_Rutas::iterator::operator==(const iterator &it) const {
  return p == it.p;
}

bool Almacen_Rutas::iterator::operator!=(const iterator &it) const {
  return p != it.p;
}

const Ruta Almacen_Rutas::const_iterator::operator*() const {
  return p->second;
}

const Ruta *Almacen_Rutas::const_iterator::operator->() const {
  return &(p->second);
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator++() {
  ++p;
  return *this;
}

bool Almacen_Rutas::const_iterator::operator==(const const_iterator &it) const {

  return p == it.p;
}
bool Almacen_Rutas::const_iterator::operator!=(const const_iterator &it) const {
  return p != it.p;
}

/* Almacen_Rutas::iterator Almacen_Rutas::find(const std::string &s) const { */
/*   Almacen_Rutas::iterator it; */
/*   auto aux = rutas.find(s); */
/*   it.p = aux; */
/*   return it; */
/* } */

istream &operator>>(istream &is, Almacen_Rutas &R) {
  while (!is.eof()) {
    Ruta r;
    if (is.peek() != 'R') {
      is.ignore(8, '\n');
    } else {
      is >> r;
      R.Insertar(r);
    }
  }
  return is;
}

ostream &operator<<(ostream &os, const Almacen_Rutas &R) {
  Almacen_Rutas::const_iterator it;
  for (it = R.cbegin(); it != R.cend(); ++it) {
    os << *it << endl;
  }
  return os;
}
