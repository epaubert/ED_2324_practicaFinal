#include "../include/imagen.h"

Pixel mediaPixeles(Pixel *p, int tam) {
  Pixel out;
  int auxR, auxG, auxB;
  auxR = auxR = auxB = 0;

  for (int i = 0; i < tam; i++) {
    auxR += p[i].r;
    auxG += p[i].g;
    auxB += p[i].b;
  }

  out.r = auxR / tam;
  out.g = auxG / tam;
  out.b = auxB / tam;

  return out;
}

Imagen Imagen::Crop(int nrow, int ncol, int height, int width) const {
  Imagen out(height, width);
  for (int i = nrow; i < nrow + height; i++) {
    for (int j = ncol; j < ncol + width; j++) {
      out.data[i - nrow][j - ncol] = data[i][j];
    }
  }

  return out;
}

Imagen Imagen::Zoom2X() const {
  Imagen out(nf * 2 - 1, nc * 2 - 1);
  for (int i = 0; i < nc; i++) {
    for (int j = 0; j < nf; j++) {
      if (i * 2 < out.nc && j * 2 < out.nf)
        out.data[i * 2][j * 2] = data[i][j];
    }
  }

  for (int i = 0; i < out.nf; i++) {
    for (int j = 0; j < out.nc; j++) {
      if (i % 2 == 0 && j % 2 != 0) {
        Pixel aux[] = {out.data[i][j - 1], out.data[i][j + 1]};
        out.data[i][j] = mediaPixeles(aux, 2);
      }
    }
  }

  for (int i = 0; i < out.nf; i++) {
    for (int j = 0; j < out.nc; j++) {
      if (i % 2 != 0 && i < out.nf - 1) {
        Pixel aux[] = {out.data[i - 1][j], out.data[i + 1][j]};
        out.data[i][j] = mediaPixeles(aux, 2);
      }
    }
  }

  return out;
}

Pixel Imagen::Mean(int i, int j, int height, int width) const {
  Pixel out;
  int auxR, auxG, auxB, auxT;
  auxR = auxR = auxB = 0;

  for (int k = 0; k < height; k++) {
    for (int l = 0; l < width; l++) {
      auxR += (data[i + k][j + l].r);
      auxG += (data[i + k][j + l].g);
      auxB += (data[i + k][j + l].r);
      auxT += (data[i + k][j + l].transp);
    }
  }

  out.r = auxR / (height * width);
  out.g = auxG / (height * width);
  out.b = auxB / (height * width);
  out.transp = auxT / (height * width); //< 200 ? 0 : 255;

  return out;
}

Imagen Imagen::Subsample(int factor) const {
  Imagen out(nf / factor, nc / factor);

  for (int i = 0; i < out.nf; i++) {
    for (int j = 0; j < out.nc; j++) {
      out.data[i][j] = Mean(i * factor, j * factor, factor, factor);
    }
  }

  return out;
}
