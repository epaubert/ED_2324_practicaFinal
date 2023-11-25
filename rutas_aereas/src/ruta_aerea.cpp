#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include<list>
using namespace std;

void mostrar_rutas(ifstream &archivo) {
  string line, aux = "";
  list<string> lista_rutas;
  bool leyendo;
  while (getline(archivo, line)) {
    
    if (line[0] != '#') {
      if(line[0] == 'R'){
        cout << aux << endl;
        aux = "";
      }
      for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i])){
          aux += line[i];
        }
      }
    }
  }
  cout << aux << endl;
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

  mostrar_rutas(rutasDisponibles);

  rutasDisponibles.close();

  return 0;
}
