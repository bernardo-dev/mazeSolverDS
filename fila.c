#include "listaEncadeada.h"
#include "posicao.h"
#include <stdbool.h>

Lista *filaInicia(){
  Lista *pLista = listaInicia();
  return pLista;
}

void filaLibera(Lista **ppLista){
  listaLibera(ppLista);
}

int filaTamanho(Lista *pLista){
  return listaTamanho(pLista);
}

bool filaEnfileira(Lista *pLista, Posicao posicao){
  return listaInsereNoFinal(pLista, posicao);
}

bool filaDesenfileira(Lista *pLista, Posicao *pPosicao){
  return listaRetiraDoInicio(pLista, pPosicao);
}

