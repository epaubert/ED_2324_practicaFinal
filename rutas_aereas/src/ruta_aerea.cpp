#include "../include/Almacen_Rutas.h"
#include "../include/Paises.h"
#include "../include/imagen.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

Ruta menu(const Almacen_Rutas &A, const Paises &p);
Imagen Rota(const Imagen &Io, double angulo);

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

  cerr << "ejecutando" << endl;

  Ruta r = menu(a, p);

  //cout << endl << "Ruta elejida: " << r << endl;
  //paisesRuta sera la lista de paises que conforman la ruta
  Paises paisesRuta;
  r.mostrarRuta(p, paisesRuta);

  /////////////////////NUEVO/////////////////////////////////////
  Imagen mapa, bandera, avion;
  Tipo_Pegado tp = BLENDING;

  mapa.LeerImagen(argv[2]);
  avion.LeerImagen(argv[5], argv[6]);

  int posi, posj;

  for(auto it = paisesRuta.cbegin(); it != paisesRuta.cend(); ++it){

    string direccion_bandera = argv[3];
    direccion_bandera += "/";
    direccion_bandera += (*it).GetBandera();

    

    posi = (mapa.num_filas() / 180.0) * (90 - (*it).GetPunto().getLatitud());
    posj = (mapa.num_cols() / 360.0) * (180 + (*it).GetPunto().getLongitud());  

    bandera.LeerImagen(direccion_bandera.c_str());

    
    mapa.PutImagen(posi, posj, bandera);
    
  }
  
  double angulo, x, y;

  for(auto it = r.cbegin(); it != r.cend(); ++it){

    if(it != r.cend()){
      auto it2 = it;
      ++it2;
      x = abs((*it2).getLatitud() - (*it).getLatitud());
      y = abs((*it2).getLongitud() - (*it).getLongitud());
      angulo = atan(y - x) * (180 / M_PI);
    }

    Imagen avionRotado = Rota(avion, angulo);
    posi = (mapa.num_filas() / 180.0) * (90 - (*it).getLatitud());
    posj = (mapa.num_cols() / 360.0) * (180 + (*it).getLongitud()); 

    mapa.PutImagen(posi, posj, avionRotado, tp);
  }

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

Imagen Rota(const Imagen &Io, double angulo) {
  double rads = angulo;
  double coseno = cos(angulo);
  double seno = sin(angulo);
  // Para obtener las dimensiones de la imagen
  int rcorners[4], ccorners[4];
  int newimgrows, newimgcols;
  double new_row_min, new_col_min, new_row_max, new_col_max;
  double inter, inter1;
  rcorners[0] = 0;
  rcorners[1] = 0;
  ccorners[0] = 0;
  ccorners[2] = 0;
  rcorners[2] = Io.num_filas() - 1;
  rcorners[3] = Io.num_filas() - 1;
  ccorners[1] = Io.num_cols() - 1;
  ccorners[3] = Io.num_cols() - 1;
  new_row_min = 0;
  new_col_min = 0;
  new_row_max = 0;
  new_col_max = 0;
  newimgrows = 0;
  newimgcols = 0;
  for (int count = 0; count < 4; count++) {
    inter = rcorners[count] * coseno + ccorners[count] * seno;

    if (inter < new_row_min)
      new_row_min = inter;
    if (inter > new_row_max)
      new_row_max = inter;
    inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

    if (inter1 < new_col_min)
      new_col_min = inter1;
    if (inter1 > new_col_max)
      new_col_max = inter1;
  }

  newimgrows = (unsigned)ceil((double)new_row_max - new_row_min);
  newimgcols = (unsigned)ceil((double)new_col_max - new_col_min);

  Imagen Iout(newimgrows, newimgcols);
  for (int rows = 0; rows < newimgrows; rows++) {
    for (int cols = 0; cols < newimgcols; cols++) {
      float oldrowcos = ((float)rows + new_row_min) * cos(-rads);
      float oldrowsin = ((float)rows + new_row_min) * sin(-rads);
      float oldcolcos = ((float)cols + new_col_min) * cos(-rads);
      float oldcolsin = ((float)cols + new_col_min) * sin(-rads);
      float old_row = oldrowcos + oldcolsin;
      float old_col = -oldrowsin + oldcolcos;
      old_row = ceil((double)old_row);
      old_col = ceil((double)old_col);
      if ((old_row >= 0) && (old_row < Io.num_filas()) && (old_col >= 0) &&
          (old_col < Io.num_cols())) {
        Iout(rows, cols) = Io(old_row, old_col);

      } else
        Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = 255;
    }
  }
  return Iout;
}