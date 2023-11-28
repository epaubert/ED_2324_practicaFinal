#include "../include/Punto.h"
#include <assert.h>

Punto::Punto() {}
Punto::Punto(float _lat, float _lng, string s) {
  lat = _lat;
  lng = _lng;
  nom = s;
}

Punto::Punto(const Punto &p) {
  lat = p.lat;
  lng = p.lng;
  nom = p.nom;
}

Punto::~Punto() {}

bool Punto::operator==(const Punto &p) const {
  if (lat == p.lat && lng == p.lng)
    return true;
  else {
    const double error = 1.0e-4;
    bool lat_iguales = abs(lat - p.lat) < error;
    bool lng_iguales = abs(lng - p.lng) < error;
    return lat_iguales && lng_iguales;
  }
}

bool Punto::operator!=(const Punto &p) const { return !(operator==(p)); }

istream &operator>>(istream &is, Punto &p) {
  double d[2];
  int i = 0;

  while (is.peek() != ')') {
    switch (is.peek()) {
    case '(':
    case ',':
    case ' ':
    case '\t':
    case '\n':
    case '\r':
      is.get();
      break;
    default:
      assert(i <= 2);
      is >> d[i];
      i++;
      break;
    }
  }
  is.get();

  p.setLatitud(d[0]);
  p.setLongitud(d[1]);
  return is;
}

ostream &operator<<(ostream &os, const Punto &p) {
  os << "(" << p.lat << ", " << p.lng << ")";
  return os;
}

double Punto::getLatitud() const { return lat; }
double Punto::getLongitud() const { return lng; }
string Punto::getNombre() const { return nom; }

void Punto::setLatitud(double l) { lat = l; }
void Punto::setLongitud(double l) { lng = l; }
void Punto::setNombre(string n) { nom = n; }
