#include "../include/Paises.h"

Paises::Paises() {}
Paises::Paises(const Paises &P) { datos = P.datos; }

void Paises::Insertar(const Pais &P) { datos.insert(P); }
void Paises::Borrar(const Pais &P) { datos.erase(P); }

Paises::iterator Paises::begin() const {
  Paises::iterator it;
  it.p = datos.begin();
  return it;
}

Paises::const_iterator Paises::cbegin() const {
  Paises::const_iterator it;
  it.p = datos.cbegin();
  return it;
}

Paises::iterator Paises::end() const {
  Paises::iterator it;
  it.p = datos.end();
  return it;
}

Paises::const_iterator Paises::cend() const {
  Paises::const_iterator it;
  it.p = datos.cend();
  return it;
}

Paises::iterator Paises::find(const Pais &p) const {
  iterator it;
  set<Pais>::iterator i;
  for (i = datos.begin(); i != datos.end() && *i != p; ++i)
    /* for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i) */
    ;
  it.p = i;
  return it;
}

Pais Paises::find(const Punto &p) const {
  set<Pais>::const_iterator it;
  
  double lat, lng, result;
  double plat = abs(p.getLatitud()), plng = abs(p.getLongitud());

  for(it = datos.cbegin(); it != datos.cend(); ++it){
    bool iguales = true;

    lat = abs(it->GetPunto().getLatitud());
    lng = abs(it->GetPunto().getLongitud());

    if(lat > plat){
      result = lat - plat;
    }else{
      result = plat - lat;
    }

    if(result > UMBRAL){
      iguales = false;
    }

    if(lng > plng){
      result = lng - plng;
    }else{
      result = plng - lng;
    }

    if(result > UMBRAL){
      iguales = false;
    }

    if(iguales == true){
      return *it;
    }
  }
}

const Pais &Paises::iterator::operator*() { return *p; }

Paises::iterator Paises::iterator::operator++() {
  ++p;
  return *this;
}

bool Paises::iterator::operator==(const iterator &it) const {
  return p == it.p;
}

bool Paises::iterator::operator!=(const iterator &it) const {
  return p != it.p;
}

const Pais &Paises::const_iterator::operator*() const { return *p; }

Paises::const_iterator Paises::const_iterator::operator++() {
  ++p;
  return *this;
}

bool Paises::const_iterator::operator==(const const_iterator &it) const {
  return p == it.p;
}

bool Paises::const_iterator::operator!=(const const_iterator &it) const {
  return p != it.p;
}

istream &operator>>(istream &is, Paises &R) {

  while (!is.eof()) {
    if (is.peek() == '#') {
      string a;
      getline(is, a);
    } else {
      Pais P;
      is >> P;
      R.Insertar(P);
    }
  }

  return is;
}

ostream &operator<<(ostream &os, const Paises &R) {
  Paises::const_iterator it;

  for (it = R.cbegin(); it != R.cend(); ++it) {
    os << *it << endl;
  }

  return os;
}
