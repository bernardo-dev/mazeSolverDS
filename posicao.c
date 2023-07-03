#include "posicao.h"
#include <stdlib.h>

Posicao *alocarPosicoes(int n){
  Posicao *pPosicao = (Posicao *) malloc(sizeof(Posicao) * n);
  return pPosicao;
}

void desalocaPosicao(Posicao *pPosicao){
  free(pPosicao);
}