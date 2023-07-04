#ifndef ESTRUTURADEDADOS_H
#define ESTRUTURADEDADOS_H

#include "posicao.h"
#include <stdbool.h>

typedef struct Celula {
  Posicao posicao;
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

void listaLibera(Lista **);

bool listaEhVazia(Lista *);

int listaTamanho(Lista *);

bool listaInsereNoInicio(Lista *, Posicao);

bool listaInsereNoFinal(Lista *, Posicao);

bool listaRemoveDoInicio(Lista *, Posicao *);

bool listaRemoveDoFinal(Lista *, Posicao *);

void listaImprime(Lista *);

// FILA
Lista *filaInicia();

void filaLibera(Lista **);

bool filaEhVazia(Lista *);

int filaTamanho(Lista *);

bool filaEnfileira(Lista *, Posicao);

bool filaDesenfileira(Lista *, Posicao *);

void filaImprime(Lista *);

// PILHA
Lista *pilhaInicia();

void pilhaLibera(Lista *);

bool pilhaEhVazia(Lista *);

int pilhaTamanho(Lista *);

bool pilhaPush(Lista *, Posicao);

bool pilhaPop(Lista *, Posicao);

void pilhaImprime(Lista *);

#endif // ESTRUTURADEDADOS_H