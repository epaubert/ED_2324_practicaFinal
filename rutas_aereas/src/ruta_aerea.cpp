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
const string EXIT = "exit";

Almacen_Rutas::const_iterator menu(const Almacen_Rutas &A, const Paises &p);

pair<double, double> coordenadas(const Punto &p, const Imagen &mapa);

double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa);

void pintaBanderasAviones(const Ruta &ruta, const Paises &paises,
                          const Imagen &avion, const string &directorioBanderas,
                          Imagen &mapa);

pair<double, double> centrarCoordenadas(const pair<double, double> &c2,
                                        const Imagen &i);

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

  Almacen_Rutas::const_iterator r = menu(a, p);
  while (r != a.cend()) {
    Paises paisesRuta;
    r->mostrarRuta(p, paisesRuta);

    /////////////////////NUEVO/////////////////////////////////////

    Imagen mapa, avion;
    string directorioBanderas = argv[3];
    mapa.LeerImagen(argv[2]);
    cerr << "Tamaño del mapa: " << mapa.num_filas() << " x " << mapa.num_cols()
         << endl;
    avion.LeerImagen(argv[5], argv[6]);
    /* avion = avion.Subsample(2); // no funciona bien con las transparencias */

    pintaBanderasAviones(*r, paisesRuta, avion, directorioBanderas, mapa);

    mapa.EscribirImagen("pruebas/mapa_banderas.ppm");
    r = menu(a, p);
  }

  return 0;
}

Almacen_Rutas::const_iterator menu(const Almacen_Rutas &A, const Paises &P) {
  string s = "R0";
  Almacen_Rutas::const_iterator it = A.cend();
  do {
    cout << "Elija una ruta (exit para salir): " << endl;
    A.mostrarRutas(P);
    cin >> s;
    it = A.elijeRuta(s);
  } while (s != EXIT && it == A.cend());

  return it;
}

void pintaBanderasAviones(const Ruta &ruta, const Paises &paises,
                          const Imagen &avion, const string &directorioBanderas,
                          Imagen &mapa) {
  double angulo = -90;
  Imagen bandera, avionRotado = avion;
  pair<double, double> pos, pos_ant, pos_a, pos_b;

  Ruta::iterator it_ant;
  for (auto it = ruta.cbegin(); it != ruta.cend(); ++it) {
    auto pais = paises.find(*it);
    if (pais == paises.end()) {
      cerr << "ERROR: Pais no encontrado." << endl;
      exit(EXIT_FAILURE);
    }
    string direccionBandera = directorioBanderas;
    direccionBandera += "/";
    direccionBandera += pais->GetBandera();
    bandera.LeerImagen(direccionBandera.c_str());
    pos = coordenadas(pais->GetPunto(), mapa);

    auto it2 = it;
    ++it2;
    if (it != ruta.cend() && it2 != ruta.cend()) {
      Paises::iterator pais_sig = paises.find(*it2);
      pair<double, double> destino, pos_next, mitad;

      // Ángulo del avión
      cerr << pais->GetPais() << " -> " << pais_sig->GetPais() << endl;
      angulo = calculaAngulo(pais->GetPunto(), pais_sig->GetPunto(), mapa);
      avionRotado = avion.Rota(angulo);

      // Avion en el destino:
      destino = coordenadas(*it2, mapa);
      pos_next = centrarCoordenadas(destino, avionRotado);
      mapa.PutImagen(pos_next.first, pos_next.second, avionRotado, tp);

      // Avion en medio del camino:
      mitad = {(pos.first + destino.first) / 2,
               (pos.second + destino.second) / 2};
      mitad = centrarCoordenadas(mitad, avionRotado);
      mapa.PutImagen(mitad.first, mitad.second, avionRotado, tp);
    }

    // Posicion del avion centrado:
    pos_a = centrarCoordenadas(pos, avionRotado);
    // Posicion de la bandera centrado:
    pos_b = centrarCoordenadas(pos, bandera);

    /* cerr << "Pegando... " << endl; */
    mapa.PutImagen(pos_b.first, pos_b.second, bandera);
    mapa.PutImagen(pos_a.first, pos_a.second, avionRotado);
    /* cerr << "Pegado " << endl; */
  }
}

pair<double, double> coordenadas(const Punto &p, const Imagen &mapa) {
  pair<double, double> out;
  out.first = (mapa.num_filas() / 180.0) * (90.0 - p.getLatitud());
  out.second = (mapa.num_cols() / 360.0) * (180.0 + p.getLongitud());
  return out;
}

double calculaAngulo(const Punto &p1, const Punto p2, const Imagen &mapa) {
  double dx, dy;
  pair<double, double> pos1, pos2;
  pos1 = coordenadas(p1, mapa);
  pos2 = coordenadas(p2, mapa);
  dx = pos2.first - pos1.first;
  dy = pos2.second - pos1.second;

  return atan2(dx, dy);
}

pair<double, double> centrarCoordenadas(const pair<double, double> &c,
                                        const Imagen &i) {
  pair<double, double> out;
  out.first = c.first - i.num_filas() / 2.0;
  out.second = c.second - i.num_cols() / 2.0;
  return out;
}
