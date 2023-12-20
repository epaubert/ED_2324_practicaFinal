#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <math.h>
#include <string>

enum Tipo_Pegado { OPACO, BLENDING };

using namespace std;

/**
 * @brief representa un pixel
 *
 */
struct Pixel {
  unsigned char r; /**< Componente rojo del pixel */
  unsigned char g; /**< Componente verde del pixel*/
  unsigned char b; /**< Componente azul del pixel*/
  unsigned char
      transp; /**< Componente de transparencia del pixel. 0 es no y 255 es si*/
};

// La media de tam píxeles:
Pixel mediaPixeles(Pixel *p, int tam);

/**
 * @brief Clase que permite trabajar con imágenes ppm o pgm
 */
class Imagen {
private:
  Pixel **data;
  int nf, nc;
  void Borrar();
  void Copiar(const Imagen &I);

public:
  /**
   * @brief Constructor por defecto
   */
  Imagen();

  /**
   * @brief Constructor con parametros
   * @param f Número de filas tendrá la imagen
   * @param c Número de columnas tendrá la imagen
   */
  Imagen(int f, int c);

  /**
   * @brief Constructor por copia
   */
  Imagen(const Imagen &I);

  /**
   * @brief Operador de copia
   */
  Imagen &operator=(const Imagen &I);

  /**
   * @brief Destructor
   */
  ~Imagen();

  /**
   * @brief Set y get para un pixel
   * @param i fila del pixel que queremos acceder
   * @param j columna del pixel que queremos acceder
   */
  Pixel &operator()(int i, int j);

  /**
   * @brief Get para un pixel de una imagen constante
   * @param i fila del pixel que queremos acceder
   * @param j columna del pixel que queremos acceder
   */
  const Pixel &operator()(int i, int j) const;

  /**
   * @brief Escribe una imagen a un archivo
   * @param nombre nombre del archivo
   */
  void EscribirImagen(const char *nombre);

  /**
   * @brief Lee una imagen de un archivo
   * @param nombre nombre del archivo
   * @param nombremascara nombre de la máscara de la imagen
   */
  void LeerImagen(const char *nombre, const string &nombremascara = "");

  /* void LimpiarTransp(); */
  /**
   * @brief getter de las filas
   */
  int num_filas() const { return nf; }
  /**
   * @brief getter de las columnas
   */
  int num_cols() const { return nc; }
  /**
   * @brief Pega una imagen en otra
   * @param posi coordenada i desde donde se va a pegar la imagen
   * @param posj coordenada j desde donde se va a pegar la imagen
   * @param I imagen a pegar
   * @param tippegado Tipo de pegado, OPACO o BLENDING
   */
  void PutImagen(int posi, int posj, const Imagen &I,
                 Tipo_Pegado tippegado = OPACO);

  /* Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj); */

  /**
   * @brief Crea una copia de la imagen pero rotada
   * @param a Ángulo que se quiere rotar la imagen
   * @return La imagen rotada
   */
  Imagen Rota(double a) const;

  /**
   * @brief Calcula la media de los píxeles de una imagen entera o de un
   * fragmento de ésta.
   * @param i fila del primer pixel
   * @param j columna del primer pixel
   * @param height altura de la subimagen
   * @param width anchura de la subimagen
   * @return devuelve la media
   */
};

#endif
