#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
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

  //Para pruebas el primer argumento es el archivo de rutas, modificar el argv para que coincida con la entrada adecuada

  ifstream rutasDisponibles(argv[1]);

  cout << argv[1] << endl;

  if(!rutasDisponibles.is_open()){
    cerr << "No se pudo abrir el archivo de rutas" << endl;
    return 1;
  }

  string line;

  while (getline(rutasDisponibles, line))
  {
    if(line[0] == 'R'){
      //Hacer poda de strings
      cout << line << endl;
    }
  }
  
  rutasDisponibles.close();

}