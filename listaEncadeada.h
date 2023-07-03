#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "posicao.h"
#include <stdbool.h>

// typedef struct {
  
// } Item;

typedef struct celula{
  void* item;
  struct celula *pProximo;
  struct celula *pAnterior;
} Celula;

typedef struct {
  Celula *pCabeca;
  Celula *pCauda;
  int tamanho;
} Lista;

typedef struct {
  Celula *pInicio;
  Celula *pFim;
  int tamanho;
} Fila;

typedef struct {
  Celula *pTopo;
  int tamanho;
} Pilha;

Lista *listaInicia();

void listaLibera(Lista **);

int listaTamanho(Lista *);

bool listaInsereNoFinal(Lista *, Posicao posicao);

bool listaRetiraDoInicio(Lista *, Posicao *);

bool listaEhVazia(Lista *);

#endif // LISTAENCADEADA_H