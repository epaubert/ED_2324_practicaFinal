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
  Punto(float _lat, float _lng, string s = "");
  Punto(const Punto &p);
  ~Punto();

  bool operator==(const Punto &p) const;

  friend istream &operator>>(istream &is, Punto &p);
  friend ostream &operator<<(ostream &os, const Punto &p);

  double getLatitud() const;
  double getLongitud() const;
  string getNombre() const;

  void setLatitud(double l);
  void setLongitud(double l);
  void setNombre(string n);
};

#include "../src/Punto.cpp"

#endif
