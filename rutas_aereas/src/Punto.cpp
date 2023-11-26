#include "../include/Punto.h"
#include <assert.h>

Punto::Punto() {}
Punto::Punto(float _lat, float _lng, string s) {
  lat = _lat;
  lng = _lng;
  nom = s;
};
Punto::Punto(const Punto &p) {
  lat = p.lat;
  lng = p.lng;
  nom = p.nom;
}

Punto::~Punto() {}

bool Punto::operator==(const Punto &p) const {
  return lat == p.lat && lng == p.lng;
}

bool Punto::operator!=(const Punto &p) const {
  return lat != p.lat && lng != p.lng;
}

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
  os << "(" << p.lat << ", " << p.lng << ")" << endl;
  return os;
}

double Punto::getLatitud() const { return lat; }
double Punto::getLongitud() const { return lng; }
string Punto::getNombre() const { return nom; }

void Punto::setLatitud(double l) { lat = l; }
void Punto::setLongitud(double l) { lng = l; }
void Punto::setNombre(string n) { nom = n; }
