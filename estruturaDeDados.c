#include "estruturaDeDados.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// LISTA
Lista *listaInicia() {
  /*Lista *pLista = malloc(sizeof(Lista));
    if (pLista == NULL) {
        return NULL;
    }

    pLista->pCabeca = malloc(sizeof(Celula));
    if (pLista->pCabeca == NULL) {
        free(pLista);
        return NULL;
    }

    pLista->pCauda = malloc(sizeof(Celula));
    if (pLista->pCauda == NULL) {
        free(pLista->pCabeca);
        free(pLista);
        return NULL;
    }

    pLista->pCabeca->pProximo = pLista->pCauda;
    pLista->pCabeca->pAnterior = NULL;
    pLista->pCauda->pProximo = NULL;
    pLista->pCauda->pAnterior = pLista->pCabeca;
    pLista->tamanho = 0;

    return pLista;*/

  Lista *pLista = (Lista *)malloc(sizeof(Lista));

  pLista->pCabeca = (Celula *)malloc(sizeof(Celula));
  pLista->pCauda = (Celula *)malloc(sizeof(Celula));

  pLista->pCabeca->pProximo = pLista->pCauda;
  pLista->pCabeca->pAnterior = NULL;

  pLista->pCauda->pProximo = NULL;
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

bool listaEhVazia(Lista *pLista) {
  return (pLista->pCabeca->pProximo == pLista->pCauda);
}

int listaTamanho(Lista *pLista) { return pLista->tamanho; }

bool listaInsereNoInicio(Lista *pLista, Posicao posicao) {
  Celula *pNovaCelula = NULL;
  pNovaCelula = (Celula *)malloc(sizeof(Celula));

  if (pNovaCelula == NULL) {
    return false;
  }

  pNovaCelula->posicao = posicao;

  pNovaCelula->pProximo = pLista->pCabeca->pProximo;
  pNovaCelula->pAnterior = pLista->pCabeca->pProximo->pAnterior;

  pLista->pCabeca->pProximo->pAnterior = pNovaCelula;
  pLista->pCabeca->pProximo = pNovaCelula;

  pLista->tamanho++;

  return true;
}

bool listaInsereNoFinal(Lista *pLista, Posicao posicao) {
  Celula *pNovaCelula = NULL;
  pNovaCelula = (Celula *)malloc(sizeof(Celula));

  if (pNovaCelula == NULL) {
    return false;
  }

  pNovaCelula->posicao = posicao;

  pNovaCelula->pProximo = pLista->pCauda;
  pNovaCelula->pAnterior = pLista->pCauda->pAnterior;

  pLista->pCauda->pAnterior->pProximo = pNovaCelula;
  pLista->pCauda->pAnterior = pNovaCelula;

  pLista->tamanho++;

  return true;
}

bool listaRemoveDoInicio(Lista *pLista, Posicao *pPosicao) {
  if (listaEhVazia(pLista)) {
    return false;
  }

  Celula *pAux = (Celula *)malloc(sizeof(Celula));

  if (pAux == NULL) {
    return false;
  }

  pAux = pLista->pCabeca->pProximo;

  *pPosicao = pAux->posicao;

  /*pAux->pProximo->pAnterior = pLista->pCabeca;
  pLista->pCabeca->pProximo = pAux->pProximo;*/

  pLista->pCabeca->pProximo = pAux->pProximo;
  pAux->pProximo->pAnterior = pLista->pCabeca;

  free(pAux);

  pLista->tamanho--;

  return true;
}

bool listaRemoveDoFinal(Lista *pLista, Posicao *pPosicao) {
  if (listaEhVazia(pLista)) {
    return false;
  }

  Celula *pAux = (Celula *)malloc(sizeof(Celula));

  if (pAux == NULL) {
    return false;
  }

  pAux = pLista->pCauda->pAnterior;

  *pPosicao = pAux->posicao;

  pAux->pAnterior->pProximo = pLista->pCauda;
  pLista->pCauda->pAnterior = pAux->pAnterior;

  free(pAux);
  
  return true;
}

void listaImprime(Lista *pLista) {
  Celula *pCelulaAtual = pLista->pCabeca;

  for (int i = 0; i < pLista->tamanho; i++) {
    pCelulaAtual = pCelulaAtual->pProximo;
    printf("(%d, %d)\n", pCelulaAtual->posicao.linha,
           pCelulaAtual->posicao.coluna);
  }

  pCelulaAtual = NULL;
}

// FILA
Lista *filaInicia(){
  return listaInicia();
}

void filaLibera(Lista **ppLista){
  listaLibera(ppLista);
}

bool filaEhVazia(Lista *pLista){
  return listaEhVazia(pLista);
}

int filaTamanho(Lista *pLista){
  return listaTamanho(pLista);
}

bool filaEnfileira(Lista *pLista, Posicao posicao){
  return listaInsereNoFinal(pLista, posicao);
}

bool filaDesenfileira(Lista *pLista, Posicao *pPosicao){
  return listaRemoveDoInicio(pLista, pPosicao);
}

void filaImprime(Lista *pLista){
  listaImprime(pLista);
}

// PILHA
Lista *pilhaInicia(){
  Lista *pPilha = listaInicia();
  if(pPilha == NULL){
    return NULL;
  }
  return pPilha;
}

void pilhaLibera(Lista **ppLista){
  return listaLibera(ppLista);
}

bool pilhaEhVazia(Lista *pLista){
  return listaEhVazia(pLista);
}

int pilhaTamanho(Lista *pLista){
  return listaTamanho(pLista);
}

bool pilhaPush(Lista *pLista, Posicao posicao){
  return listaInsereNoInicio(pLista, posicao);
}

bool pilhaPop(Lista *pLista, Posicao *pPosicao){
  return listaRemoveDoInicio(pLista, pPosicao);
}

void pilhaImprime(Lista *pLista){
  listaImprime(pLista);
}