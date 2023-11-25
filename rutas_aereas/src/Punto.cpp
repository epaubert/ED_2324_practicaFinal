#include "../include/Punto.h"

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

ostream &operator<<(ostream &os, const Punto &p) {
  os << p.lat << " " << p.lng << " " << p.nom << endl;
  return os;
}

double Punto::getLatitud() const { return lat; }
double Punto::getLongitud() const { return lng; }
string Punto::getNombre() const { return nom; }

void Punto::setLatitud(double l) { lat = l; }
void Punto::setLongitud(double l) { lng = l; }
void Punto::setNombre(double n) { nom = n; }
