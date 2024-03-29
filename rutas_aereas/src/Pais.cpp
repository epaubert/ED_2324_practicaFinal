#include "../include/Pais.h"
#include "../include/Punto.h"
#include <iostream>
#include <string>

Pais::Pais() {}

Pais::Pais(const Pais &P) {
  p = P.GetPunto();
  pais = P.GetPais();
  bandera = P.GetBandera();
}

Punto Pais::GetPunto() const { return p; }

string Pais::GetPais() const { return pais; }

string Pais::GetBandera() const { return bandera; }

void Pais::SetBandera(string B) { bandera = B; }

void Pais::SetPais(string P) { pais = P; }

void Pais::SetPunto(Punto P) {
  p.setLatitud(P.getLatitud());
  p.setLongitud(P.getLongitud());
  p.setNombre(P.getNombre());
}

bool Pais::operator<(const Pais &P) const {
  if (p.getLatitud() != P.GetPunto().getLatitud()) {
    return p.getLatitud() < P.GetPunto().getLatitud();
  } else
    return p.getLongitud() < P.GetPunto().getLongitud();
}

bool Pais::operator==(const Pais &P) const {
  return GetPunto() == P.GetPunto();
}

bool Pais::operator!=(const Pais &P) const {
  return GetPunto() != P.GetPunto();
}

bool Pais::operator==(const Punto &P) const { return GetPunto() == P; }

bool Pais::operator!=(const Punto &P) const { return GetPunto() != P; }

istream &operator>>(istream &is, Pais &P) {
  double lat, lng;
  string pais, bandera;

  is >> lat >> lng >> pais >> bandera;

  P.SetBandera(bandera);
  P.SetPais(pais);
  P.SetPunto(Punto(lat, lng, pais));
  return is;
}

ostream &operator<<(ostream &os, const Pais &P) {
  os << P.p << " " << P.pais << " " << P.bandera;
  return os;
}
