#ifndef _PAIS_H_
#define _PAIS_H_

#include "Punto.h"

class Pais {
private:
  Punto p;
  string pais;
  string bandera;

public:
  Pais() ;
  Pais(const Pais &P) ;

  Punto GetPunto() const ;
  string GetPais() const ;
  string GetBandera() const ;

  void SetPunto(Punto P);
  void SetPais(string P) ;
  void SetBandera(string B) ;

  bool operator<(const Pais &P) const ;

  bool operator==(const Pais &P) const ;

  bool operator!=(const Pais &P) const ;

  bool operator==(const Punto &P) const ;

  bool operator!=(const Punto &P) const ;

  friend istream &operator>>(istream &is, const Pais &P) ;  

  friend ostream &operator<<(ostream &os, const Pais &P) ;
};

#include "../src/Pais.cpp"
#endif
