#include "estruturaDeDados.h"
#include <stdlib.h>
#include <stdbool.h>

// LISTA
Lista *listaInicia(){
  Lista *pLista = (Lista *)malloc(sizeof(Lista));

  pLista->pCabeca = (Celula *)malloc(sizeof(Celula));
  pLista->pCauda = (Celula *)malloc(sizeof(Celula));

  
}

void listaLibera(Lista *pLista);

bool listaEhVazia(Lista *pLista);

int listaTamanho(Lista *pLista);

bool listaInsereNoInicio(Lista *pLista, void *pItem);

bool listaInsereNoFinal(Lista *pLista, void *pItem);

bool listaRemoveDoInicio(Lista *pLista, void *pItem);

bool listaRemoveDoFinal(Lista *pLista, void *pItem);

void listaImprime(Lista *pLista);

// FILA
Fila *filaInicia();

void filaLibera(Fila *pFila);

bool filaEhVazia(Fila *pFila);

int filaTamanho(Fila *pFila);

bool filaEnfileira(Fila *pFila, void *pItem);

bool filaDesenfileira(Fila *pFila, void *pItem);

void filaImprime(Fila *pFila);

// PILHA
Pilha *pilhaInicia();

void pilhaLibera(Pilha *pPilha);

bool pilhaEhVazia(Pilha *pPilha);

int pilhaTamanho(Pilha *pPilha);

bool pilhaPush(Pilha *pPilha, void *pItem);

bool pilhaPop(Pilha *pPilha, void *pItem);

void pilhaImprime(Pilha *pPilha);

