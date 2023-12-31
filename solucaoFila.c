#include "solucaoFila.h"
#include "estruturaDeDados.h"
#include "labirinto.h"
#include "limits.h"
#include "matriz.h"
#include "percurso.h"
#include "posicao.h"
#include <stdio.h>

bool estaLivre(Labirinto *pLabirinto, char **pVisitados, int linha,
               int coluna) {

  // Verifica se a posicao está dentro dos limtes do labirinto
  if (linha < 0 || linha >= pLabirinto->linhas)
    return false;
  if (coluna < 0 || coluna >= pLabirinto->colunas)
    return false;

  // Verifica se é uma parede ou um ponto já visitado
  if (pLabirinto->pMatriz[linha][coluna] == '*' ||
      pVisitados[linha][coluna] == 'o') {
    return false;
  }

  return true;
}

Percurso *resolverPorBFS(Labirinto *pLabirinto) {
  // Inicializa uma matriz do tamanho do labirinto,
  // sendo todas as posicoes nao vistadas
  char **pVisitados = alocarMatriz(pLabirinto->linhas, pLabirinto->colunas);

  for (int i = 0; i < pLabirinto->linhas; i++) {
    for (int j = 0; j < pLabirinto->colunas; j++) {
      pVisitados[i][j] = ' ';
    }
  }

  Percurso *pPercurso = alocarPercurso(pLabirinto->caminhosVazios + 1);
  pPercurso->tamanho = 0;

  Lista *pFila = filaInicia();

  Posicao posicaoInicial;
  posicaoInicial.linha = pLabirinto->comecoLinha;
  posicaoInicial.coluna = pLabirinto->comecoColuna;

  filaEnfileira(pFila, posicaoInicial);

  Posicao posicaoAtual;
  Posicao proximaPosicao;
  int linha, coluna;

  while (!filaEhVazia(pFila)) {
    filaDesenfileira(pFila, &posicaoAtual);

    linha = posicaoAtual.linha;
    coluna = posicaoAtual.coluna;

    pVisitados[linha][coluna] = 'o';

    pPercurso->pPosicoes[pPercurso->tamanho].linha = linha;
    pPercurso->pPosicoes[pPercurso->tamanho].coluna = coluna;
    pPercurso->tamanho++;

    // Verifica se chegou na saida
    if (linha == pLabirinto->saidaLinha &&
        coluna == pLabirinto->saidaColuna) {
      desalocarMatriz(pVisitados, pLabirinto->linhas);
      filaLibera(&pFila);
      return pPercurso;
    }

    // DIREITA
    if (estaLivre(pLabirinto, pVisitados, linha, coluna + 1)) {
      proximaPosicao.linha = linha;
      proximaPosicao.coluna = coluna + 1;

      filaEnfileira(pFila, proximaPosicao);
    }

    // BAIXO
    if (estaLivre(pLabirinto, pVisitados, linha + 1, coluna)) {
      proximaPosicao.linha = linha + 1;
      proximaPosicao.coluna = coluna;

      filaEnfileira(pFila, proximaPosicao);
    }

    // ESQUERDA
    if (estaLivre(pLabirinto, pVisitados, linha, coluna - 1)) {
      proximaPosicao.linha = linha;
      proximaPosicao.coluna = coluna - 1;

      filaEnfileira(pFila, proximaPosicao);
    }

    // CIMA
    if (estaLivre(pLabirinto, pVisitados, linha - 1, coluna)) {
      proximaPosicao.linha = linha - 1;
      proximaPosicao.coluna = coluna;

      filaEnfileira(pFila, proximaPosicao);
    }
  }

  desalocarMatriz(pVisitados, pLabirinto->linhas);
  filaLibera(&pFila);

  return pPercurso;
}
