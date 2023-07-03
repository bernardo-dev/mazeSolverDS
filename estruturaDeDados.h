#ifndef ESTRUTURADEDADOS_H
#define ESTRUTURADEDADOS_H

#include "item.h"
#include <stdbool.h>

typedef struct Celula{
  Item item;
  struct Celula *pProximo;
  struct Celula *pAnterior;
} Celula;

typedef struct {
  Celula *pCabeca;
  Celula *pCauda;
  int tamanho;
} Lista;

// LISTA
Lista *listaInicia();

void listaLibera(Lista *);

bool listaEhVazia(Lista *);

int listaTamanho(Lista *);

bool listaInsereNoInicio(Lista *, void *);

bool listaInsereNoFinal(Lista *, void *);

bool listaRemoveDoInicio(Lista *, void *);

bool listaRemoveDoFinal(Lista *, void *);

void listaImprime(Lista *);

// FILA
Lista *filaInicia();

void filaLibera(Lista *);

bool filaEhVazia(Lista *);

int filaTamanho(Lista *);

bool filaEnfileira(Lista *, void *);

bool filaDesenfileira(Lista *, void *);

void filaImprime(Lista *);

// PILHA
Lista *pilhaInicia();

void pilhaLibera(Lista *);

bool pilhaEhVazia(Lista *);

int pilhaTamanho(Lista *);

bool pilhaPush(Lista *, void *);

bool pilhaPop(Lista *, void *);

void pilhaImprime(Lista *);

#endif // ESTRUTURADEDADOS_H