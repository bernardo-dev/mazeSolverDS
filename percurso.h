#ifndef PERCURSO_H
#define PERCURSO_H

#include "posicao.h"

typedef struct {
  // Vetor de posicoes
  Posicao *pPosicoes;
  unsigned int tamanho;
} Percurso;

Percurso *alocarPercurso(int);

void desalocaPercurso(Percurso **);

void copiaPercurso(Percurso *, Percurso *);

#endif // PERCURSO_H