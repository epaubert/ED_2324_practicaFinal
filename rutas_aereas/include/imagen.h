#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <math.h>
#include <string>

enum Tipo_Pegado { OPACO, BLENDING };

using namespace std;

struct Pixel {
  unsigned char r, g, b;
  unsigned char transp; // 0 no 255 si
};

// La media de tam píxeles:
Pixel mediaPixeles(Pixel *p, int tam);

class Imagen {
private:
  Pixel **data;
  int nf, nc;
  void Borrar();
  void Copiar(const Imagen &I);

public:
  Imagen();

  Imagen(int f, int c);

  Imagen(const Imagen &I);

  Imagen &operator=(const Imagen &I);

  ~Imagen();

  // set y get
  Pixel &operator()(int i, int j);

  const Pixel &operator()(int i, int j) const;

  void EscribirImagen(const char *nombre);

  void LeerImagen(const char *nombre, const string &nombremascara = "");
  void LimpiarTransp();
  int num_filas() const { return nf; }
  int num_cols() const { return nc; }
  void PutImagen(int posi, int posj, const Imagen &I,
                 Tipo_Pegado tippegado = OPACO);
  Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);

  Imagen Rota(double angulo) const;

  /**
   * @brief Calcula la media de los píxeles de una imagen entera o de un
   * fragmento de ésta.
   * @param i fila del primer pixel
   * @param j columna del primer pixel
   * @param height altura de la subimagen
   * @param width anchura de la subimagen
   * @return devuelve la media
   */
  Pixel Mean(int i, int j, int height, int width) const;

  /**
   * @brief Genera un icono como reducción de una imagen.
   * @param factor cuánto se reduce la imagen
   * @return devuelve el icono
   */
  Imagen Subsample(int factor) const;

  /**
   * @brief Genera una subimagen recortada de la imagen original
   * @param nrow fila donde se empieza a recortar
   * @param ncol columna donde se empieza a recortar
   * @param height altura de la subimagen
   * @param widht anchura de la subimagen
   * @return Devuelve un objeto Imagen con la subimagen
   */
  Imagen Crop(int nrow, int ncol, int height, int width) const;

  /**
   * @brief Hace zoom x2 al objeto imagen.
   * @return una nueva imagen con el doble del tamaño de la original, con
   * pixeles generados por interpolación.
   */
  Imagen Zoom2X() const;

  /**
   * @brief Baraja pseudoaleatoriamente las filas del objeto imagen.
   */
  void ShuffleRows();
};

#endif
