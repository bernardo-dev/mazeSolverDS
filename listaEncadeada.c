#include "listaEncadeada.h"
#include <stdlib.h>

Lista *listaInicia() {
  Lista *pLista = (Lista *)malloc(sizeof(Lista));

  pLista->pCabeca = (Celula *)malloc(sizeof(Celula));
  pLista->pCauda = (Celula *)malloc(sizeof(Celula));

  pLista->pCabeca->pProximo = pLista->pCauda;
  pLista->pCabeca->pAnterior = NULL;

  pLista->pCabeca->pProximo = NULL;
  pLista->pCauda->pAnterior = pLista->pCabeca;

  pLista->tamanho = 0;

  return pLista;
}

void listaLibera(Lista **ppLista) {
  Celula *pAux = (*ppLista)->pCabeca->pProximo;
  while ((*ppLista)->pCabeca->pProximo != (*ppLista)->pCauda) {
    (*ppLista)->pCabeca->pProximo = (*ppLista)->pCabeca->pProximo->pProximo;
    free(pAux);
    pAux = (*ppLista)->pCabeca->pProximo;
  }
  free((*ppLista)->pCabeca);
  free((*ppLista)->pCauda);
  free((*ppLista));
  *ppLista = NULL;
}

int listaTamanho(Lista *pLista){
  return pLista->tamanho;
}

bool listaInsereNoFinal(Lista *pLista, Posicao posicao){
  Celula *pNovaCelula = NULL;
  pNovaCelula = (Celula *)malloc(sizeof(Celula));

  // Veririca se a alocacao foi um uma nova celula foi bem sucedida
  if (pNovaCelula == NULL){
    return false;
  }

  pNovaCelula->

  pNovaCelula->pProximo = pLista->pCauda;
  pNovaCelula->pAnterior = pLista->pCauda->pAnterior;

  pLista->pCauda->pAnterior->pProximo = pNovaCelula;
  pLista->pCauda->pAnterior = pNovaCelula;

  pLista->tamanho++;

  return true;
}



bool listaEhVazia(Lista *pLista){
  return (pLista->pCabeca->pProximo == pLista->pCauda);
}