#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
#include <string>

using namespace std;

class Punto {
private:
  double lat, lng;
  string nom;

public:
  Punto();
  Punto(float _lat, float _lng, string s = "") {
    lat = _lat;
    lng = _lng;
    nom = s;
  };
  Punto(const Punto &p) {
    lat = p.lat;
    lng = p.lng;
    nom = p.nom;
  }
  ~Punto();

  bool operator==(const Punto &p) const { return lat == p.lat && lng == p.lng; }

  friend ostream &operator<<(ostream &os, const Punto &p) {
    os << p.lat << " " << p.lng << " " << p.nom << endl;
    return os;
  }

  double getLatitud() const { return lat; }
  double getLongitud() const { return lng; }
  string getNombre() const { return nom; }

  void setLatitud(double l) { lat = l; }
  void setLongitud(double l) { lng = l; }
  void setNombre(double n) { nom = n; }
};

#endif
