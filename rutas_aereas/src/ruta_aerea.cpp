#include "../include/Almacen_Rutas.h"
#include "../include/Paises.h"
#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

const Tipo_Pegado tp = BLENDING;

Ruta menu(const Almacen_Rutas &A, const Paises &p);

pair<double, double> coordenadas(const Punto &p, const Imagen &mapa);

double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa);

void pintaBanderasAviones(const Paises &paisesRuta, const Imagen &avion,
                          const string &directorioBanderas, Imagen &mapa);

int main(int argc, char *argv[]) {
  if (argc != 7) {
    cout << "Los parametros son :" << endl;
    cout << "1.-Archivo de Paises" << endl;
    cout << "2.-Mapa del Mundo" << endl;
    cout << "3.-Directorio de las banderas" << endl;
    cout << "4.-Almacen de Rutas" << endl;
    cout << "5.-Imagen del Avion" << endl;
    cout << "6.-Mascara del avion" << endl;
    return 0;
  }

  ///// LEYENDO RUTAS
  cout << "leyendo rutas..." << endl;
  ifstream rutasDisponibles(argv[4]);
  if (!rutasDisponibles.is_open()) {
    cerr << "No se pudo abrir el archivo de rutas" << endl;
    return 1;
  }
  Almacen_Rutas a;
  rutasDisponibles >> a;
  rutasDisponibles.close();

  ///// LEYENDO PAISES
  cout << "leyendo paises..." << endl;
  ifstream lista_paises(argv[1]);
  if (!lista_paises.is_open()) {
    cerr << "No se pudo abrir el archivo de paises" << endl;
    return 1;
  }
  Paises p;
  lista_paises >> p;
  lista_paises.close();

  Ruta r = menu(a, p);

  Paises paisesRuta;
  r.mostrarRuta(p, paisesRuta);

  /////////////////////NUEVO/////////////////////////////////////

  Imagen mapa, avion;
  string directorioBanderas = argv[3];
  mapa.LeerImagen(argv[2]);
  cerr << "Tamaño del mapa: " << mapa.num_filas() << " x " << mapa.num_cols()
       << endl;
  avion.LeerImagen(argv[5], argv[6]);
  /* avion = avion.Subsample(2); // no funciona bien con las transparencias */

  pintaBanderasAviones(paisesRuta, avion, directorioBanderas, mapa);

  mapa.EscribirImagen("pruebas/mapa_banderas.ppm");

  return 0;
}

Ruta menu(const Almacen_Rutas &A, const Paises &P) {
  string s = "R0";
  Almacen_Rutas::const_iterator it = A.cend();
  do {
    cout << "Elija una ruta: " << endl;
    A.mostrarRutas(P);
    cin >> s;
    it = A.elijeRuta(s);
  } while (it == A.cend());

  return *it;
}

void pintaBanderasAviones(const Paises &paisesRuta, const Imagen &avion,
                          const string &directorioBanderas, Imagen &mapa) {
  double angulo = 0;
  Imagen bandera, avionRotado = avion;
  pair<double, double> pos, pos_a, pos_b;

  for (auto it = paisesRuta.cbegin(); it != paisesRuta.cend(); ++it) {
    string direccionBandera = directorioBanderas;
    direccionBandera += "/";
    direccionBandera += it->GetBandera();
    bandera.LeerImagen(direccionBandera.c_str());
    pos = coordenadas(it->GetPunto(), mapa);

    /* cerr << "// Ángulo del avión " << endl; */
    auto it2 = it;
    ++it2;
    if (it != paisesRuta.cend() && it2 != paisesRuta.cend()) {
      angulo = calculaAngulo(it->GetPunto(), it2->GetPunto(), mapa);
      // TODO aqui tendríamos que calcular donde va el avión intermedio y tal
      // vez dibujarlo?
      avionRotado = avion.Rota(angulo);
    }

    /* cerr << "// Pais: " << it->GetPais() << endl; */
    /* cerr << "// Posicion de la bandera centrada en el pais: " << endl; */
    pos_b.first = pos.first - bandera.num_filas() / 2.0;
    pos_b.second = pos.second - bandera.num_cols() / 2.0;
    /* cerr << "// Posicion del avion centrado" << endl; */
    pos_a.first = pos.first - avion.num_filas() / 2.0;
    pos_a.second = pos.second - avion.num_cols() / 2.0;

    mapa.PutImagen(pos_b.first, pos_b.second, bandera);
    mapa.PutImagen(pos_a.first, pos_a.second, avionRotado, tp);
  }
}

pair<double, double> coordenadas(const Punto &p, const Imagen &mapa) {
  pair<double, double> out;
  out.first = (mapa.num_filas() / 180.0) * (90.0 - p.getLatitud());
  out.second = (mapa.num_cols() / 360.0) * (180.0 + p.getLongitud());
  /* cerr << "Coordenadas: (" << out.first << "), (" << out.second << ")" <<
   * endl; */
  return out;
}

double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa) {
  double dx, dy, out;
  pair<double, double> pos1, pos2;
  pos1 = coordenadas(p1, mapa);
  pos2 = coordenadas(p2, mapa);
  dx = pos2.first - pos1.first;
  dy = pos2.second - pos1.second;

  /* out = atan(dx / dy); */
  out = atan2(dx, dy);
  cerr << "dx: " << dx << "\tdy: " << dy << "\tÁngulo: " << out * 180 / M_PI
       << "º \tRads: " << out << endl;

  return out;
}
