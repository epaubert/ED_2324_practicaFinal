#include "../include/imagen.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 9) {
    cout << "Los parametros son :" << endl;
    cout << "1.-La imagen de fondo" << endl;
    cout << "2.-La imagen a pegar" << endl;
    cout << "3.-La máscara de la imagen a pegar" << endl;
    cout << "4.-El nombre de la imagen de salida" << endl;
    cout << "5.-La fila donde pegar" << endl;
    cout << "6.-La columna donde pegar" << endl;
    cout << "7.- 0: Pegado Opaco 1: Pegado Blending" << endl;
    cout << "8.- Ángulo de rotación " << endl;
    return 0;
  }
  Imagen I, Ip;
  I.LeerImagen(argv[1]);
  Ip.LeerImagen(argv[2], argv[3]);
  int i, j;
  i = atoi(argv[5]);
  j = atoi(argv[6]);
  int a = atoi(argv[8]);

  Tipo_Pegado tp = OPACO; // variable de tipo Tipo_Pegado que es un enumerado
                          // con los valores OPACO y 	BLENDING
  int au = atoi(argv[7]);
  if (au != 0)
    tp = BLENDING;

  Imagen Iout = Ip.Rota(a);
  I.PutImagen(i, j, Iout, tp);
  I.EscribirImagen(argv[4]);
}
