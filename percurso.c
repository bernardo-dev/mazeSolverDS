#include "percurso.h"
#include "posicao.h"
#include <stdlib.h>

Percurso *alocarPercurso(int n){
  Percurso *pPercurso = (Percurso *) malloc(sizeof(Percurso));
  pPercurso->pPosicoes = alocarPosicoes(n);
  return pPercurso;
}

void desalocaPercurso(Percurso **pPercurso){
  desalocaPosicao((*pPercurso)->pPosicoes);
  (*pPercurso)->pPosicoes = NULL;
  free(*pPercurso);
  *pPercurso = NULL;
}

void copiaPercurso(Percurso *pDestino, Percurso *pFonte){
  pDestino->tamanho = pFonte->tamanho;
  for (int i = 0; i < pFonte->tamanho; i++){
    pDestino->pPosicoes[i].linha = pFonte->pPosicoes[i].linha;
    pFonte->pPosicoes[i].coluna = pFonte->pPosicoes[i].coluna;
  }
}