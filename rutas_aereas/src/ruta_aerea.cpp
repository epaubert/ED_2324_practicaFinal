#include "../include/Almacen_Rutas.h"
#include "../include/Paises.h"
#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

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

  ifstream rutasDisponibles(argv[4]);

  if (!rutasDisponibles.is_open()) {
    cerr << "No se pudo abrir el archivo de rutas" << endl;
    return 1;
  }

  Almacen_Rutas a;

  cout << "leyendo..." << endl << endl;
  rutasDisponibles >> a;
  cout << "escribiendo" << endl;

  rutasDisponibles.close();

  ifstream lista_paises(argv[1]);
  Paises p;

  if (!lista_paises.is_open()) {
    cerr << "No se pudo abrir el archivo de paises" << endl;
    return 1;
  }

  /* cerr << "Paises antes de leer: \n"; */
  /* cerr << p; */

  lista_paises >> p;

  /* cerr << "Paises después de leer: \n"; */
  /* cerr << p; */

  lista_paises.close();

  /////////////////////////////////////////////////////////////////////////////////

  a.mostrarRutas(p);

  return 0;
}
