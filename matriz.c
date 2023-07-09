#include "matriz.h"
#include <stdlib.h>

char **alocarMatriz(int linhas, int colunas) {
  char **pMatriz = (char **)malloc(sizeof(char *) * linhas);

  for (int i = 0; i < linhas; i++) {
    pMatriz[i] = (char*)malloc(colunas * sizeof(char));
  }

  return pMatriz;
}

void desalocarMatriz(char **pMatriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(pMatriz[i]);
  }
  free(pMatriz);
}
