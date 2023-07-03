#ifndef POSICAO_H
#define POSICAO_H

typedef struct {
  int linha;
  int coluna;
} Posicao;

Posicao *alocarPosicoes(int);

void desalocaPosicao(Posicao *);

#endif // POSICAO_H