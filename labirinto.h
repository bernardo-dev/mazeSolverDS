#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "percurso.h"
#include <stdbool.h>

// Estrutura labirinto contendo uma matriz alocada dinamicamente
typedef struct {
  int linhas, colunas;
  int comecoLinha, comecoColuna;
  int saidaLinha, saidaColuna;
  int caminhosVazios;
  char **pMatriz;
} Labirinto;

// Aloca um labirinto m * n
Labirinto *alocarLabirinto(int, int);

// Desaloca um labirinto m * n
void desalocaLabirinto(Labirinto *);

// Le um labirinto m * n
void leLabirinto(Labirinto *);

// Imprime o percurso no labirinto
void imprimePercursoNoLabirinto(Labirinto *, Percurso *);

#endif // LABIRINTO_H