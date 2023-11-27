#include "../include/Almacen_Rutas.h"
#include "../include/Paises.h"
#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

void mostrar_rutas(const Almacen_Rutas &A, const Paises &P) {
  cout << "Rutas disponibles: " << endl;
  Almacen_Rutas::const_iterator it;
  Ruta::const_iterator it2;

  for (it = A.cbegin(); it != A.cend(); ++it) {
    Ruta aux = *it;

    cout << aux.getCode() << endl;

    for (it2 = aux.cbegin(); it2 != aux.cend(); ++it2) {
      Paises::iterator pais;

      pais = P.find(*it2);
        if(it2!= aux.cend())
          cout << *pais;
          else cout << "No encontradao" << endl;
    }

    cout << endl;
  }
}

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

  lista_paises >> p;

  lista_paises.close();

  /////////////////////////////////////////////////////////////////////////////////

  mostrar_rutas(a, p);

  return 0;
}
